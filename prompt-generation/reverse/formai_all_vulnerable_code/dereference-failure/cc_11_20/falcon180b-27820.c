//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *host;
    char *username;
    char *password;
    char *command;
    char response[MAX_LINE];
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int bytes_written;
    int connected = 0;

    if (argc!= 5) {
        printf("Usage:./ftp_client <host> <username> <password>\n");
        exit(1);
    }

    host = argv[1];
    username = argv[2];
    password = argv[3];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    connected = 1;

    send(sock, username, strlen(username), 0);
    send(sock, "\r\n", 2, 0);

    while (connected) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            printf("Error reading from server\n");
            break;
        }

        response[0] = '\0';
        strncat(response, buffer, bytes_read);

        if (strstr(response, "220")!= NULL) {
            printf("Connected to %s\n", host);
        } else if (strstr(response, "331")!= NULL) {
            printf("Password required for %s\n", host);
        } else if (strstr(response, "230")!= NULL) {
            printf("Login successful\n");
        } else if (strstr(response, "257")!= NULL) {
            printf("\"%s\" is current directory\n", response + 9);
        } else if (strstr(response, "550")!= NULL) {
            printf("File not found\n");
        } else if (strstr(response, "226")!= NULL) {
            printf("Transfer complete\n");
        } else if (strstr(response, "425")!= NULL) {
            printf("Open data connection failed\n");
        } else if (strstr(response, "426")!= NULL) {
            printf("Connection closed; transfer aborted\n");
        } else if (strstr(response, "500")!= NULL) {
            printf("Command not understood\n");
        } else if (strstr(response, "501")!= NULL) {
            printf("Syntax error in parameters or arguments\n");
        } else if (strstr(response, "502")!= NULL) {
            printf("Command not implemented\n");
        } else if (strstr(response, "421")!= NULL) {
            printf("Service not available, closing control connection\n");
            connected = 0;
        }
    }

    close(sock);

    return 0;
}