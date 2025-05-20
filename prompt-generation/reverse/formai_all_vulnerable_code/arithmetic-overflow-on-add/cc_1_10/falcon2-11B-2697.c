//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    int server_fd;
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    int opt = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Socket failed");
        exit(1);
    }

    server_host = gethostbyname(argv[1]);
    if (server_host == NULL)
    {
        fprintf(stderr, "Hostname not found: %s\n", argv[1]);
        exit(1);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server_host->h_addr, server_host->h_length);
    server_addr.sin_port = htons(5000);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
    {
        perror("Bind failed");
        exit(1);
    }

    if (listen(server_fd, 3) == -1)
    {
        perror("Listen failed");
        exit(1);
    }

    int cli_sock = accept(server_fd, NULL, NULL);
    if (cli_sock == -1)
    {
        perror("Accept failed");
        exit(1);
    }

    printf("Connected to client\n");

    char buf[1024];
    while (1)
    {
        memset(buf, 0, sizeof(buf));

        if (select(cli_sock + 1, NULL, NULL, NULL, NULL) == -1)
        {
            perror("Select");
            exit(1);
        }

        if (read(cli_sock, buf, sizeof(buf) - 1) <= 0)
        {
            printf("Client disconnected\n");
            close(cli_sock);
            break;
        }

        buf[read(cli_sock, buf, sizeof(buf) - 1)] = '\0';
        printf("Received: %s\n", buf);

        write(cli_sock, "Hello, Client!", strlen("Hello, Client!"));
    }

    close(cli_sock);
    close(server_fd);

    return 0;
}