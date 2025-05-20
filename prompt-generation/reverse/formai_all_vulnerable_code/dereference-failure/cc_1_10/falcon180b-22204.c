//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *host, *username, *password, *command;
    int port = DEFAULT_PORT;
    char buffer[BUFFER_SIZE];

    // Check if the correct number of arguments are provided
    if (argc!= 5) {
        printf("Usage: %s <host> <username> <password> <command>\n", argv[0]);
        return 1;
    }

    // Assign values to variables
    host = argv[1];
    username = argv[2];
    password = argv[3];
    command = argv[4];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send username and password
    char *auth_string = malloc(strlen(username) + strlen(password) + 3);
    sprintf(auth_string, "%s:%s", username, password);
    send(sock, auth_string, strlen(auth_string), 0);

    // Send command
    send(sock, command, strlen(command), 0);

    // Receive response
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sock);

    return 0;
}