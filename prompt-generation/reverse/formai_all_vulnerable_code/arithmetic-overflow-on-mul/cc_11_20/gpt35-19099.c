//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char *messages;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return -1;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        close(sock);
        return -1;
    }

    printf("POP3 Server connected\n");

    // Receive welcome message
    if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
        printf("Error: Could not receive message from server\n");
        close(sock);
        return -1;
    }

    printf("%s", buffer);

    // Login
    printf("Username: ");
    fgets(username, BUF_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUF_SIZE, stdin);

    snprintf(buffer, sizeof(buffer), "USER %s", username);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Could not send message to server\n");
        close(sock);
        return -1;
    }

    printf("Sent: %s", buffer);

    if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
        printf("Error: Could not receive message from server\n");
        close(sock);
        return -1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s", password);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Could not send message to server\n");
        close(sock);
        return -1;
    }

    printf("Sent: %s", buffer);

    if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
        printf("Error: Could not receive message from server\n");
        close(sock);
        return -1;
    }

    printf("%s", buffer);

    // List messages
    if (send(sock, "LIST", 4, 0) == -1) {
        printf("Error: Could not send message to server\n");
        close(sock);
        return -1;
    }

    if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
        printf("Error: Could not receive message from server\n");
        close(sock);
        return -1;
    }

    printf("%s", buffer);

    // Parse message count
    int msg_count = 0;
    sscanf(buffer, "+OK %d messages", &msg_count);

    // Allocate memory for messages
    messages = malloc(msg_count * BUF_SIZE);

    // Retrieve messages
    for (int i = 0; i < msg_count; i++) {
        snprintf(buffer, sizeof(buffer), "RETR %d", i+1);
        if (send(sock, buffer, strlen(buffer), 0) == -1) {
            printf("Error: Could not send message to server\n");
            close(sock);
            free(messages);
            return -1;
        }

        if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
            printf("Error: Could not receive message from server\n");
            close(sock);
            free(messages);
            return -1;
        }

        sprintf(messages + (i * BUF_SIZE), "%s", buffer);
    }

    // Print messages
    for (int i = 0; i < msg_count; i++) {
        printf("Message %d:\n%s\n", i+1, (messages + (i * BUF_SIZE)));
    }

    // Delete messages
    for (int i = 0; i < msg_count; i++) {
        snprintf(buffer, sizeof(buffer), "DELE %d", i+1);
        if (send(sock, buffer, strlen(buffer), 0) == -1) {
            printf("Error: Could not send message to server\n");
            close(sock);
            free(messages);
            return -1;
        }

        if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
            printf("Error: Could not receive message from server\n");
            close(sock);
            free(messages);
            return -1;
        }

        printf("%s", buffer);
    }

    // Quit
    if (send(sock, "QUIT", 4, 0) == -1) {
        printf("Error: Could not send message to server\n");
        close(sock);
        free(messages);
        return -1;
    }

    if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
        printf("Error: Could not receive message from server\n");
        close(sock);
        free(messages);
        return -1;
    }

    printf("%s", buffer);

    // Free memory
    free(messages);

    // Close socket
    close(sock);

    return 0;
}