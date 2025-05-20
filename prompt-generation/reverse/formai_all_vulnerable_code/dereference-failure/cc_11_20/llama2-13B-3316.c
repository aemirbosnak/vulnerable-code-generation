//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct word {
    char *text;
    int count;
};

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[1024];
    struct word words[10];
    int i, j;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("Accept failed");
            exit(1);
        }

        // Read words from the client
        while (1) {
            recv(client_sock, buffer, 1024, 0);
            if (buffer[0] == '\0') {
                break;
            }

            // Add the word to the word list
            for (i = 0; i < 10; i++) {
                if (strcmp(words[i].text, buffer) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == 10) {
                // If the word list is full, discard the oldest word
                words[0].count--;
            }
        }

        // Send the word list back to the client
        for (i = 0; i < 10; i++) {
            if (words[i].count > 0) {
                send(client_sock, words[i].text, strlen(words[i].text), 0);
            }
        }

        // Close the client socket
        close(client_sock);
    }

    return 0;
}