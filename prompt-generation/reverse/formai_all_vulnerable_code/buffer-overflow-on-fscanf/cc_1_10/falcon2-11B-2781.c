//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <poll.h>
#include <time.h>

int main() {
    char *pidfile;
    pid_t pid;
    char buf[1024];
    FILE *fp;
    DIR *dp;
    struct dirent *entry;
    char *filename;
    int fd;
    struct pollfd pfds[1];
    struct pollfd *pfp;
    char *argv[1];
    int count = 0;
    int i;

    pidfile = "/tmp/myapp.pid";
    if (access(pidfile, F_OK)!= -1) {
        printf("pidfile %s already exists\n", pidfile);
        exit(1);
    }

    if (mkfifo(pidfile, 0600) == -1) {
        printf("mkfifo failed: %s\n", strerror(errno));
        exit(1);
    }

    fp = fopen(pidfile, "r");
    if (fp == NULL) {
        printf("Cannot open pidfile %s\n", pidfile);
        exit(1);
    }
    fscanf(fp, "%d", &pid);
    fclose(fp);

    if (pid!= -1) {
        printf("pidfile %s exists\n", pidfile);
        exit(1);
    }

    argv[0] = "process";
    argv[1] = "1";

    if (fork() == 0) {
        close(0);
        dup(1);
        close(1);
        dup(2);
        close(2);

        execvp(argv[0], argv);
    } else {
        fp = fopen(pidfile, "w");
        if (fp == NULL) {
            printf("Cannot open pidfile %s\n", pidfile);
            exit(1);
        }
        fprintf(fp, "%d", getpid());
        fclose(fp);

        printf("forked process %d\n", getpid());

        for (i = 1; i < 50; i++) {
            pid = fork();
            if (pid == 0) {
                close(0);
                dup(1);
                close(1);
                dup(2);
                close(2);

                execvp("sleep", "sleep");
            } else if (pid > 0) {
                waitpid(pid, NULL, 0);
            } else {
                printf("fork failed: %s\n", strerror(errno));
                exit(1);
            }
        }

        exit(0);
    }
}