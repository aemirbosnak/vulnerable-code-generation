//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

void sigchld_handler(int s)
{
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

int ping(char *host)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(7);

    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
        printf("Invalid address/host name\n");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("No connection\n");
        close(sock);
        return -1;
    }

    char buffer[BUF_SIZE];
    send(sock, "PING", strlen("PING"), 0);
    int bytes_received = recv(sock, buffer, BUF_SIZE, 0);

    if (bytes_received <= 0) {
        printf("No response from server\n");
        close(sock);
        return -1;
    }

    if (strcmp(buffer, "PONG")!= 0) {
        printf("Invalid response from server\n");
        close(sock);
        return -1;
    }

    close(sock);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <host> <timeout>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int timeout = atoi(argv[2]);

    signal(SIGCHLD, sigchld_handler);

    int status;
    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        ping(host);
        exit(0);
    } else {
        waitpid(child_pid, &status, WNOHANG);
    }

    if (WIFEXITED(status)) {
        if (WEXITSTATUS(status) == 0) {
            printf("%s is alive\n", host);
        } else {
            printf("%s is not alive\n", host);
        }
    } else if (WIFSIGNALED(status)) {
        printf("Child process terminated by signal %d\n", WTERMSIG(status));
    } else {
        printf("Unknown child status\n");
    }

    return 0;
}