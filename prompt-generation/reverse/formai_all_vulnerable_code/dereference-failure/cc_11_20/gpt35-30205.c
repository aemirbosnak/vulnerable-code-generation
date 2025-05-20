//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LEN 1024

int main(int argc, char* argv[]) {
    char input[MAX_LEN];
    char* cmd;
    char* ptr;
    int fd, n, status;
    pid_t pid;

    while(1) {
        printf("# ");
        fflush(stdout);

        if(fgets(input, MAX_LEN, stdin) == NULL) {
            break;
        }

        // remove newline
        if((ptr = strchr(input, '\n')) != NULL) {
            *ptr = '\0';
        }

        // split command and arguments
        cmd = strtok(input, " ");

        // execute command
        if(strcmp(cmd, "ls") == 0) {
            // list files in current directory
            char* args[] = {"ls", "-l", NULL};
            execvp(args[0], args);
        } else if(strcmp(cmd, "ps") == 0) {
            // list running processes
            char* args[] = {"ps", "-ef", NULL};
            execvp(args[0], args);
        } else if(strcmp(cmd, "cd") == 0) {
            // change directory
            char* dir = strtok(NULL, " ");
            if(dir == NULL) {
                printf("cd: missing argument\n");
                continue;
            }

            if(chdir(dir) < 0) {
                printf("cd: %s: %s\n", dir, strerror(errno));
            }
        } else if(strcmp(cmd, "cat") == 0) {
            char* file = strtok(NULL, " ");
            if(file == NULL) {
                printf("cat: missing argument\n");
                continue;
            }

            // open file
            if((fd = open(file, O_RDONLY)) < 0) {
                printf("cat: %s: %s\n", file, strerror(errno));
                continue;
            }

            // read file and print contents
            char buf[MAX_LEN];
            while((n = read(fd, buf, MAX_LEN)) > 0) {
                write(STDOUT_FILENO, buf, n);
            }

            close(fd);
        } else if(strcmp(cmd, "fork") == 0) {
            pid = fork();

            if(pid < 0) {
                printf("fork: %s\n", strerror(errno));
            } else if(pid == 0) {
                printf("child process: %d\n", getpid());
            } else {
                printf("parent process: %d\n", getpid());
            }
        } else if(strcmp(cmd, "exit") == 0) {
            // exit program
            exit(0);
        } else {
            printf("%s: command not found\n", cmd);
        }
    }

    return 0;
}