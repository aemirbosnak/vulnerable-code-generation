//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLEN 2048

void sigchld_handler(int s)
{
    // waitpid() might overwrite errno, so we save and restore it:
    int saved_errno = errno;
    while(waitpid(-1, NULL, WNOHANG) > 0);
    errno = saved_errno;
}

void set_non_blocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int listen_fd, conn_fd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    char buf[MAXLEN];
    int n;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1])) ;

    if(bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if(listen(listen_fd, 128) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct sigaction sa;
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if(sigaction(SIGCHLD, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    set_non_blocking(listen_fd);

    while(1)
    {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);

        if(conn_fd == -1)
        {
            if((errno == EAGAIN) || (errno == EWOULDBLOCK))
            {
                // non-blocking accept, no pending connections
                continue;
            }
            else
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }
        }

        printf("New connection from %s:%d\n",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        set_non_blocking(conn_fd);

        pid_t pid = fork();

        if(pid == 0)
        {
            close(listen_fd);
            while(1)
            {
                n = recv(conn_fd, buf, MAXLEN, 0);
                if(n == -1)
                {
                    if(errno == EAGAIN)
                    {
                        // no data available, try again later
                        continue;
                    }
                    else
                    {
                        perror("recv");
                        exit(EXIT_FAILURE);
                    }
                }

                if(n == 0)
                {
                    // connection closed by client
                    printf("Connection closed by %s:%d\n",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    close(conn_fd);
                    exit(EXIT_SUCCESS);
                }

                // add null terminator to received data
                buf[n] = '\0';

                printf("Received message from %s:%d : %s\n",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buf);

                // send back the received message to the client
                n = send(conn_fd, buf, strlen(buf), 0);
                if(n == -1)
                {
                    perror("send");
                    exit(EXIT_FAILURE);
                }
            }
        }
        else
        {
            close(conn_fd);
        }
    }
    return 0;
}