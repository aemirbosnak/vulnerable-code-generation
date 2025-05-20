//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

enum state {
    S_INITIAL,
    S_CONNECTED,
    S_LOGGED_IN,
    S_QUITTING
};

int main(int argc, char **argv)
{
    int sock_fd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int state = S_INITIAL;
    char *user = NULL;
    char *password = NULL;

    if(argc < 3) {
        fprintf(stderr, "Usage: ftp client [ip] [port]\n");
        exit(1);
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    state = S_CONNECTED;
    printf("Connected to server %s:%s\n", argv[1], argv[2]);

    while (state != S_QUITTING) {
        printf("ftp> ");
        fflush(stdout);

        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        char *cmd = strtok(buffer, " ");
        if (cmd && strcmp(cmd, "user") == 0) {
            user = strtok(NULL, " \r\n");
            if (user) {
                printf("User set to %s\n", user);
            } else {
                printf("Usage: user [username]\n");
            }
        } else if (cmd && strcmp(cmd, "pass") == 0) {
            password = strtok(NULL, " \r\n");
            if (password) {
                printf("Password set\n");
            } else {
                printf("Usage: pass [password]\n");
            }
        } else if (cmd && strcmp(cmd, "quit") == 0) {
            printf("Goodbye!\n");
            state = S_QUITTING;
            break;
        } else if (cmd && strcmp(cmd, "ls") == 0) {
            char *path = strtok(NULL, " \r\n");
            if (!path) {
                path = ".";
            }

            char ls_cmd[MAX_BUFFER_SIZE];
            snprintf(ls_cmd, MAX_BUFFER_SIZE, "ls -l %s", path);

            FILE *pipe = popen(ls_cmd, "r");
            if (pipe == NULL) {
                perror("popen");
            } else {
                int bytes_read;
                do {
                  bytes_read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, pipe);
                  if (bytes_read > 0) {
                    write(STDOUT_FILENO, buffer, bytes_read);
                  }
                } while(bytes_read == MAX_BUFFER_SIZE);
                pclose(pipe);
            }
        } else {
            printf("Unknown command\n");
        }
    }


    close(sock_fd);

    return 0;
}