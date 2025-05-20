//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#define _GNU_SOURCE
#include <arpa/inet.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>
#include <resolv.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define BUFSIZE 1024

static int sockfd;
static struct sockaddr_in server_addr;
static struct hostent *server;

static void *
smtp_client(void *arg)
{
        char buf[BUFSIZE];
        int n;

        while (true) {
                if ((n = recv(sockfd, buf, BUFSIZE - 1, 0)) < 0)
                        err(EXIT_FAILURE, "read");
                buf[n] = '\0';
                printf("%s", buf);
                if (strstr(buf, "221"))
                        break;
        }
        return (NULL);
}

int
main(int argc, char **argv)
{
        pthread_t tid;
        char *line = NULL;
        size_t len = 0;
        ssize_t n;

        if (argc < 3)
                err(EXIT_FAILURE, "usage: %s <hostname> <port>", argv[0]);

        if ((server = gethostbyname(argv[1])) == NULL)
                errx(EXIT_FAILURE, "gethostbyname");

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
        server_addr.sin_port = htons(atoi(argv[2]));

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
                err(EXIT_FAILURE, "socket");

        if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0)
                warn("fcntl");

        if (connect(sockfd, (struct sockaddr *)&server_addr,
                    sizeof(server_addr)) == 0) {
                printf("connected!\n");
                pthread_create(&tid, NULL, smtp_client, NULL);
        }

        while (true) {
                if ((n = getline(&line, &len, stdin)) < 0)
                        err(EXIT_FAILURE, "getline");
                if (n == 0)
                        break;
                if (write(sockfd, line, strlen(line)) < 0)
                        err(EXIT_FAILURE, "write");
        }

        if (line)
                free(line);
        close(sockfd);
        return (EXIT_SUCCESS);
}