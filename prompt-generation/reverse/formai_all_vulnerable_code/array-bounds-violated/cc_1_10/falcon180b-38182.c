//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_LINE];
    int n;

    if (argc!= 2) {
        printf("Usage:./ftp_client <server_ip>\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, MAX_LINE, stdin);
        send(sock, buffer, strlen(buffer), 0);
        n = recv(sock, buffer, MAX_LINE, 0);
        if (n <= 0) {
            printf("Server disconnected\n");
            break;
        }
        buffer[n] = '\0';
        printf("Server response: %s", buffer);
    }

    close(sock);
    return 0;
}