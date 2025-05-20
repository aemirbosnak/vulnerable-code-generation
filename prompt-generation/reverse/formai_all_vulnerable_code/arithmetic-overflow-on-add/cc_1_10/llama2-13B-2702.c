//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct phone_book {
    char name[50];
    char number[50];
};

int main() {
    int sock, client_sock;
    struct phone_book phone_book[10];
    int i, j;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
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
        client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(1);
        }

        // Read the phone number from the client
        printf("Client: Enter your phone number: ");
        fgets(phone_book[i].number, 50, stdin);
        phone_book[i].name[0] = '\0';

        // Write the phone number back to the client
        send(client_sock, phone_book[i].number, strlen(phone_book[i].number), 0);

        // Increment the index for the next client
        i++;

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(sock);

    return 0;
}