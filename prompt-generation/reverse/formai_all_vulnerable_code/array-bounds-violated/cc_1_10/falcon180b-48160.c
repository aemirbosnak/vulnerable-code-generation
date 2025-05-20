//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        return 1;
    }

    char *ip = argv[1];
    char *user = argv[2];
    char *pass = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    char login_msg[100];
    sprintf(login_msg, "USER %s\r\n", user);
    send(sock, login_msg, strlen(login_msg), 0);

    char pass_msg[100];
    sprintf(pass_msg, "PASS %s\r\n", pass);
    send(sock, pass_msg, strlen(pass_msg), 0);

    char buf[BUFFER_SIZE];
    while (1) {
        int bytes_recv = recv(sock, buf, BUFFER_SIZE, 0);
        if (bytes_recv <= 0) {
            break;
        }
        buf[bytes_recv] = '\0';
        printf("%s", buf);
    }

    close(sock);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}