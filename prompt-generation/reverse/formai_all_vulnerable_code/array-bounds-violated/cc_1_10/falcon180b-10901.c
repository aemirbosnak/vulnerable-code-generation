//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELAY_SECONDS 2

void execute_command(char *command) {
    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        execlp(command, command, NULL);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_COMMAND_LENGTH];
    struct stat file_stat;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <boot_sequence_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (fstat(fileno(file), &file_stat) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    rewind(file);

    while (fgets(line, MAX_COMMAND_LENGTH, file)!= NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        execute_command(line);

        sleep(DELAY_SECONDS);
    }

    fclose(file);

    return 0;
}