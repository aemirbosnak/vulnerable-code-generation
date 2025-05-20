//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define PORT 21
#define USER "anonymous"
#define PASS "anonymous@example.com"

char *get_line(int sock) {
    char line[MAX_LINE];
    memset(line, 0, MAX_LINE);
    int n = 0;
    char c;
    while ((n < MAX_LINE - 1) && ((c = fgetc(sock))!= '\n')) {
        line[n++] = c;
    }
    if (n > 0) {
        line[n] = '\0';
    }
    return strdup(line);
}

void send_command(int sock, char *cmd) {
    char *ptr = strchr(cmd, '\n');
    if (ptr) {
        *ptr = '\0';
    }
    write(sock, cmd, strlen(cmd));
    if (ptr) {
        write(sock, "\r\n", 3);
    }
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    send_command(sock, "USER " USER);
    char *response = get_line(sock);
    printf("Server response: %s\n", response);

    send_command(sock, "PASS " PASS);
    response = get_line(sock);
    printf("Server response: %s\n", response);

    send_command(sock, "SYST");
    response = get_line(sock);
    printf("Server response: %s\n", response);

    send_command(sock, "PWD");
    response = get_line(sock);
    printf("Server response: %s\n", response);

    send_command(sock, "LIST");
    response = get_line(sock);
    printf("Server response: %s\n", response);

    send_command(sock, "QUIT");
    response = get_line(sock);
    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}