//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port> <file_name>\n");
        exit(1);
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);
    char *file_name = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(server_ip);
    if (host == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*)host->h_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char command[BUF_SIZE];
    sprintf(command, "RETR %s\r\n", file_name);

    send(sock, command, strlen(command), 0);

    char buffer[BUF_SIZE];
    int bytes_received = 0;

    while (bytes_received < strlen(file_name)) {
        bytes_received += recv(sock, buffer, BUF_SIZE - 1, 0);
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}