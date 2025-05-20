//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *host;
    char *username;
    char *password;
    char *command;
    char *response;
    int port;
    int len;
    int i;

    // Initialize variables
    host = "localhost";
    username = "user";
    password = "password";
    port = 110;

    // Parse command line arguments
    i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-h") == 0) {
            host = argv[++i];
        } else if (strcmp(argv[i], "-u") == 0) {
            username = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0) {
            password = argv[++i];
        } else if (strcmp(argv[i], "-c") == 0) {
            command = argv[++i];
        } else {
            printf("Invalid argument: %s\n", argv[i]);
            exit(1);
        }
        i++;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    response = malloc(1024);
    memset(response, 0, 1024);
    len = sprintf(response, "USER %s\r\n", username);
    send(sock, response, len, 0);

    // Send PASS command
    response = malloc(1024);
    memset(response, 0, 1024);
    len = sprintf(response, "PASS %s\r\n", password);
    send(sock, response, len, 0);

    // Send command
    if (command!= NULL) {
        response = malloc(1024);
        memset(response, 0, 1024);
        len = sprintf(response, "%s\r\n", command);
        send(sock, response, len, 0);

        // Receive response
        response = malloc(1024);
        memset(response, 0, 1024);
        len = recv(sock, response, 1024, 0);
        printf("Response: %s", response);
    }

    // Close socket
    close(sock);

    return 0;
}