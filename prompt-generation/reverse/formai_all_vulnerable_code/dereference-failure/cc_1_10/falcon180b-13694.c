//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char *username = "username";
    char *password = "password";
    char *host_name = "ftp.example.com";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    host = gethostbyname(host_name);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to %s\n", host_name);

    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, buffer, BUF_SIZE, 0);
    printf("Server response: %s", buffer);

    close(sock);
    return 0;
}