//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFF_SIZE 1024
#define USER "anonymous"
#define PASS "anonymous@"
#define PASS_LEN strlen(PASS)
#define CMD_USER "USER "
#define CMD_PASS "PASS "
#define CMD_TYPE "TYPE I"
#define CMD_RETR "RETR "

int sock;
struct sockaddr_in server_addr;
char buff[BUFF_SIZE];
char *ptr;

void error_handling(char *message) {
    perror(message);
    exit(1);
}

void send_command(char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
}

void read_response() {
    bzero(buff, BUFF_SIZE);
    recv(sock, buff, BUFF_SIZE, 0);
    printf("%s", buff);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <file_name> <file_type>\n");
        exit(1);
    }

    char *server_ip = argv[1];
    char *file_name = argv[2];
    char *file_type = argv[3];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect failed");

    printf("Connected to %s\n", server_ip);

    send_command(CMD_USER);
    send_command(USER);
    read_response();

    send_command(CMD_PASS);
    send_command(PASS);
    read_response();

    send_command(CMD_TYPE);
    send_command(file_type);
    read_response();

    send_command(CMD_RETR);
    send_command(file_name);
    read_response();

    close(sock);
    return 0;
}