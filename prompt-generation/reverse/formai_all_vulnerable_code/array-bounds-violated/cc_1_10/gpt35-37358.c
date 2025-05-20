//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(110);

    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Perform authentication
    char user_message[BUFFER_SIZE];
    sprintf(user_message, "USER %s\n", "cyberpunkuser");
    send(sock, user_message, strlen(user_message), 0);

    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);

    char pass_message[BUFFER_SIZE];
    sprintf(pass_message, "PASS %s\n", "cyberpunkpass");
    send(sock, pass_message, strlen(pass_message), 0);

    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);

    // Retrieve inbox messages
    send(sock, "LIST\n", 5, 0);

    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);

    close(sock);
    exit(EXIT_SUCCESS);
}