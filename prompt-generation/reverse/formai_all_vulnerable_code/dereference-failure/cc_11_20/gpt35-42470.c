//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char** argv) {

    if (argc != 4) {
        printf("Usage: %s <server_address> <port> <username>\n", argv[0]);
        return -1;
    }

    // Retrieve arguments
    char* server_address = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];

    // Initialize socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create socket");
        return -1;
    }

    // Get host information
    struct hostent* server = gethostbyname(server_address);
    if (!server) {
        perror("Failed to get server information");
        return -1;
    }

    // Set up server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return -1;
    }

    // Read server greeting message
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send username to server
    sprintf(buffer, "USER %s\r\n", username);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        return -1;
    }

    // Read server response to username
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send password to server
    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        return -1;
    }

    // Read server response to password
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send command to list available messages
    sprintf(buffer, "LIST\r\n");
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        return -1;
    }

    // Read server response to list command
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send command to retrieve a message
    int message_id;
    printf("Enter message ID to retrieve: ");
    scanf("%d", &message_id);
    sprintf(buffer, "RETR %d\r\n", message_id);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        return -1;
    }

    // Read server response to retrieve command
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        return -1;
    }
    printf("%s", buffer);

    // Read message body
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
            perror("Failed to receive message from server");
            return -1;
        }
        if (strstr(buffer, "\r\n.\r\n") != NULL) { // End of message
            printf("%s", buffer);
            break;
        }
        printf("%s", buffer);
    }

    // Send quit command
    sprintf(buffer, "QUIT\r\n");
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        return -1;
    }

    // Read server response to quit command
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        return -1;
    }
    printf("%s", buffer);

    // Close socket
    if (close(client_socket) < 0) {
        perror("Failed to close socket");
        return -1;
    }

    return 0;
}