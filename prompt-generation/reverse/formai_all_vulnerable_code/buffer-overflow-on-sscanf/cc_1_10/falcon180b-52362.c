//Falcon-180B DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 1024

char *get_line(int fd) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char ch;

    line = malloc(1);
    if (line == NULL) {
        fprintf(stderr, "Error: malloc() failed.\n");
        exit(1);
    }

    while ((read = getdelim(&ch, &len, '\n', fd))!= -1) {
        if (len == 0) {
            /* Empty line */
            continue;
        }

        line = realloc(line, len + 1);
        if (line == NULL) {
            fprintf(stderr, "Error: realloc() failed.\n");
            exit(1);
        }

        memcpy(line + strlen(line), &ch, len);
        line[strlen(line) + len - 1] = '\0';
    }

    if (ferror(fd)) {
        fprintf(stderr, "Error: getdelim() failed.\n");
        exit(1);
    }

    return line;
}

int execute_command(const char *cmd, const char *args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork() failed.\n");
        return -1;
    } else if (pid == 0) {
        /* Child process */
        execlp(cmd, cmd, args, NULL);
        fprintf(stderr, "Error: execlp() failed.\n");
        exit(1);
    } else {
        /* Parent process */
        waitpid(pid, &status, 0);
        return status;
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;
    char cmd[MAX_CMD_LEN];
    char args[MAX_ARG_LEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <config_file> <command>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: fopen() failed.\n");
        exit(1);
    }

    while ((line = get_line(fileno(fp)))!= NULL) {
        sscanf(line, "%s %s", cmd, args);
        execute_command(cmd, args);
        free(line);
    }

    fclose(fp);
    return 0;
}