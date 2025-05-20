//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main() {

    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket.");
        return EXIT_FAILURE;
    }

    // Setting server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("YOUR_FTP_SERVER_IP_HERE");
    server_addr.sin_port = htons(21);

    // Connecting to the server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to server.");
        return EXIT_FAILURE;
    }

    // Receiving server welcome message
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive data from server.");
        close(sock);
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Sending login credentials
    char username[] = "YOUR_USERNAME";
    char password[] = "YOUR_PASSWORD";
    char login_command[255];
    sprintf(login_command, "USER %s\r\n", username);
    if (send(sock, login_command, strlen(login_command), 0) == -1) {
        printf("Failed to send login data to server.");
        close(sock);
        return EXIT_FAILURE;
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive data from server.");
        close(sock);
        return EXIT_FAILURE;
    }
    printf("%s", buffer);
    sprintf(login_command, "PASS %s\r\n", password);
    if (send(sock, login_command, strlen(login_command), 0) == -1) {
        printf("Failed to send login data to server.");
        close(sock);
        return EXIT_FAILURE;
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive data from server.");
        close(sock);
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Change to passive mode to receive data
    if (send(sock, "PASV\r\n", strlen("PASV\r\n"), 0) == -1) {
        printf("Failed to send PASV command to server.");
        close(sock);
        return EXIT_FAILURE;
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive data from server.");
        close(sock);
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send command to list files on server
    if (send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        printf("Failed to send LIST command to server.");
        close(sock);
        return EXIT_FAILURE;
    }

    // Retrieve data from server and print it out
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive data from server.");
        close(sock);
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Close connection
    close(sock);

    return EXIT_SUCCESS;
}