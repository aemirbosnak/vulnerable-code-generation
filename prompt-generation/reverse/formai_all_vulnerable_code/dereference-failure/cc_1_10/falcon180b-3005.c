//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

char command[MAX_COMMAND_LENGTH];
char *argv[MAX_COMMAND_LENGTH];
int num_processes = 0;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        num_processes--;
    }
}

int launch_process(char *command) {
    pid_t pid;

    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Too many processes running.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        printf("Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(command, argv) == -1) {
            printf("Error: Execvp failed.\n");
            exit(1);
        }
    }

    num_processes++;
    return 0;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_COMMAND_LENGTH];

    signal(SIGCHLD, sigchld_handler);

    strcpy(path, "/proc");
    dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Could not open /proc directory.\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            sprintf(command, "ps -p %s", ent->d_name);
            launch_process(command);
        }
    }

    closedir(dir);

    while (num_processes > 0) {
        sleep(1);
    }

    return 0;
}