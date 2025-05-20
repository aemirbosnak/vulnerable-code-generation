//FormAI DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9000

int main() {
    printf("Welcome to the Mind-Bending Chatbot Server!\n");

    // Creating socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Server address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Binding socket to address and port
    int bind_status = bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status < 0) {
        perror("Failed to bind socket");
        close(server_fd);
        return 1;
    }

    // Listening for connections
    int listen_status = listen(server_fd, 5);
    if (listen_status < 0) {
        perror("Failed to listen for connections");
        close(server_fd);
        return 1;
    }
    printf("Listening for connections on port %d...\n", PORT);

    // Accepting incoming connections
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len);
    if (client_fd < 0) {
        perror("Failed to accept client connection");
        close(server_fd);
        return 1;
    }
    char *client_ip = inet_ntoa(client_address.sin_addr);
    printf("New client connected from %s:%d\n", client_ip, ntohs(client_address.sin_port));

    // Chatting with the client
    char message[1024];
    int message_len;

    while (1) {
        // Receiving message
        memset(message, 0, sizeof(message));
        message_len = recv(client_fd, message, sizeof(message), 0);
        if (message_len < 0) {
            perror("Failed to receive message");
            close(client_fd);
            close(server_fd);
            return 1;
        } else if (message_len == 0) {
            printf("Client disconnected\n");
            close(client_fd);
            close(server_fd);
            return 0;
        }

        // Processing message
        printf("%s", message);
        if (strstr(message, "exit") != NULL) {
            printf("Client requested to close connection\n");
            close(client_fd);
            close(server_fd);
            return 0;
        }

        // Sending response
        printf("Enter your response: ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message)-1] = '\0';
        message_len = send(client_fd, message, strlen(message), 0);
        if (message_len < 0) {
            perror("Failed to send response");
            close(client_fd);
            close(server_fd);
            return 1;
        }
    }

    return 0;
}