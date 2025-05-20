//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21

struct ftp_command
{
    const char *command;
    int arg_count;
    const char **args;
};

int ftp_connect(const char *host, const char *user, const char *pass)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(FTP_PORT);
    addr.sin_addr.s_addr = inet_addr(host);

    int status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if(status < 0)
    {
        perror("connect");
        close(sock);
        return -1;
    }

    char buf[512];
    status = recv(sock, buf, sizeof(buf) - 1, 0);
    if(status < 0)
    {
        perror("recv");
        close(sock);
        return -1;
    }

    buf[status] = '\0';
    printf("%s", buf);

    struct ftp_command commands[] =
    {
        {"USER", 1, {user}},
        {"PASS", 1, {pass}},
        {NULL, 0, NULL},
    };

    for(struct ftp_command *cmd = commands; cmd->command; cmd++)
    {
        sprintf(buf, "%s\n", cmd->command);
        status = send(sock, buf, strlen(buf), 0);
        if(status < 0)
        {
            perror("send");
            close(sock);
            return -1;
        }

        status = recv(sock, buf, sizeof(buf) - 1, 0);
        if(status < 0)
        {
            perror("recv");
            close(sock);
            return -1;
        }

        buf[status] = '\0';
        printf("%s", buf);
    }

    return sock;
}

void ftp_close(int sock)
{
    close(sock);
}

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        fprintf(stderr, "Usage: %s <host> <user> <pass>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sock = ftp_connect(argv[1], argv[2], argv[3]);
    if(sock < 0)
    {
        return EXIT_FAILURE;
    }

    ftp_close(sock);
    return EXIT_SUCCESS;
}