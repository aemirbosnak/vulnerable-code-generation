//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 1024

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen() failed");
        exit(1);
    }

    printf("Listening for clients...\n");

    while (1) {
        struct client *new_client;
        new_client = malloc(sizeof(struct client));
        new_client->sock = accept(sock, NULL, NULL);
        if (new_client->sock < 0) {
            perror("accept() failed");
            exit(1);
        }

        printf("New client connected: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int message_len = recv(new_client->sock, message, MAX_MESSAGE_LENGTH, 0);
            if (message_len < 0) {
                perror("recv() failed");
                exit(1);
            }

            printf("Received message from %s: %s\n", new_client->name, message);

            // Here's where the statistical twist comes in!
            int message_frequency[10];
            memset(message_frequency, 0, sizeof(message_frequency));
            for (int i = 0; i < message_len; i++) {
                message_frequency[message[i] - 'a']++;
            }

            // Print the most frequent letters in the message
            for (int i = 0; i < 10; i++) {
                if (message_frequency[i] > 0) {
                    printf("Most frequent letter %c appears %d times\n", i + 'a', message_frequency[i]);
                }
            }

            // Send a response back to the client
            char *response = "You said: ";
            for (int i = 0; i < message_len; i++) {
                response += message[i];
            }
            send(new_client->sock, response, strlen(response), 0);

            // Update the client's name
            strcpy(new_client->name, "");
            printf("Client disconnected: %s\n", new_client->name);
            free(new_client);
        }
    }

    close(sock);
    return 0;
}