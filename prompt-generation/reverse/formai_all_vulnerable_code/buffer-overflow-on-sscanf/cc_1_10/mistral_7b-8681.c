//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PROCESSES 10
#define PROCESS_NAME_LENGTH 32

typedef struct {
    pid_t pid;
    char name[PROCESS_NAME_LENGTH];
} Process;

void get_process_name(pid_t pid, char *name) {
    FILE *fp;
    char line[128];

    sprintf(name, "/proc/%ld/status", pid);
    fp = fopen(name, "r");

    if (fp == NULL) {
        strcpy(name, "<unknown>");
        return;
    }

    fgets(line, sizeof(line), fp);
    sscanf(line, "Name: %s", name);
    fclose(fp);
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("\033[1;1H\033[2J"); // ANSI escape codes to clear the terminal
    printf("\033[32m─────────────────────────────────────────────────────────────────────────────\n");
    printf("│                            Running Processes                           │\n");
    printf("│                                                                       │\n");
    printf("│ ID  │               Name                                           │\n");
    printf("│─────┼─────────────────────────────────────────────────────────────────────────────│\n");

    while (num_processes < MAX_PROCESSES) {
        pid_t pid = waitpid(-1, NULL, WNOHANG);

        if (pid > 0) {
            get_process_name(pid, processes[num_processes].name);
            printf("│ %-5d │ %-31s │\n", processes[num_processes].pid, processes[num_processes].name);
            num_processes++;
        } else if (pid == -1) {
            break;
        }
    }

    printf("│─────┴─────────────────────────────────────────────────────────────────────────────│\n");
    printf("└──────────────────────────────────────────────────────────────────────────────────┘\n");

    return 0;
}