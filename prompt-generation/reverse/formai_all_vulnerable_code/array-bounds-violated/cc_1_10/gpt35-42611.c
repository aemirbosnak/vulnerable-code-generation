//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void connect_to_server(int *fd, struct sockaddr_in *addr, char *server_ip)
{
    *fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(addr, 0, sizeof(*addr));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server_ip, &(addr->sin_addr));
    if (connect(*fd, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
        perror("Connect error!");
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    ssize_t r = recv(*fd, buffer, sizeof(buffer), 0);
    buffer[r] = '\0';
    printf("%s", buffer);
}

void send_command(int fd, char *command)
{
    char buffer[BUFFER_SIZE];
    send(fd, command, strlen(command), 0);
    ssize_t r = recv(fd, buffer, sizeof(buffer), 0);
    buffer[r] = '\0';
    printf("%s", buffer);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: pop3_client <server_ip> <username>\n");
        exit(EXIT_FAILURE);
    }
    int fd;
    struct sockaddr_in addr;
    char *server_ip = argv[1];
    char *username = argv[2];
    connect_to_server(&fd, &addr, server_ip);
    send_command(fd, "USER ");
    send_command(fd, username);
    send_command(fd, "\r\n");
    send_command(fd, "PASS ");
    char password[BUFFER_SIZE];
    fgets(password, BUFFER_SIZE, stdin);
    send_command(fd, password);
    send_command(fd, "\r\n");
    send_command(fd, "LIST\r\n");
    send_command(fd, "QUIT\r\n");
    close(fd);
    return 0;
}