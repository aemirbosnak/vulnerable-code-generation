//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUF_SIZE 1024
#define MAX_MSG_SIZE 1024

struct sockaddr_in server_addr, client_addr;
int server_sock, client_sock;
int client_len;
char buffer[MAX_BUF_SIZE];
char message[MAX_MSG_SIZE];

void setup() {
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    if (listen(server_sock, 5) < 0) {
        perror("Failed to listen on socket");
        exit(1);
    }

    printf("Listening on port %d\n", PORT);
}

void handle_client(int client_sock) {
    client_len = sizeof(client_addr);
    int bytes_read;
    while ((bytes_read = recv(client_sock, buffer, MAX_BUF_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received message from client: %s\n", buffer);

        if (strcmp(buffer, "ON") == 0) {
            printf("Turning light on\n");
            // Code to turn light on
        } else if (strcmp(buffer, "OFF") == 0) {
            printf("Turning light off\n");
            // Code to turn light off
        } else {
            printf("Invalid message received\n");
        }
    }
}

int main() {
    setup();

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Failed to accept client");
            exit(1);
        }

        handle_client(client_sock);
        close(client_sock);
    }

    return 0;
}