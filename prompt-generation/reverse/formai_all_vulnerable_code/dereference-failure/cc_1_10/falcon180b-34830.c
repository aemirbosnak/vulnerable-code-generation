//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server;
    char *hostname;
    char buffer[BUF_SIZE];
    char *username, *password;
    int connected = 0;

    // Check arguments
    if (argc!= 6) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }
    connected = 1;

    // Send username and password
    send(sock, username, strlen(username), 0);
    send(sock, "\r\n", 2, 0);
    send(sock, password, strlen(password), 0);
    send(sock, "\r\n", 2, 0);

    // Receive response
    memset(buffer, 0, BUF_SIZE);
    if (recv(sock, buffer, BUF_SIZE, 0) <= 0) {
        printf("Error receiving response\n");
        close(sock);
        return 1;
    }
    printf("Response: %s", buffer);

    // Send command
    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUF_SIZE);
    if (recv(sock, buffer, BUF_SIZE, 0) <= 0) {
        printf("Error receiving response\n");
        close(sock);
        return 1;
    }
    printf("Response: %s", buffer);

    // Close connection
    close(sock);
    return 0;
}