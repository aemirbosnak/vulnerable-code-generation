//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pwd.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void update_processes(process_t *processes, int num_processes) {
    FILE *fp;
    char line[MAX_COMMAND_LENGTH];
    char *token;
    int i = 0;

    fp = popen("ps axo pid,command", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute ps command.\n");
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        processes[i].pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[i].command, token, MAX_COMMAND_LENGTH - 1);
        processes[i].command[MAX_COMMAND_LENGTH - 1] = '\0';
        i++;
    }

    pclose(fp);
}

void display_processes(process_t *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-5d %s\n", processes[i].pid, processes[i].command);
    }
}

int main(int argc, char *argv[]) {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    update_processes(processes, MAX_PROCESSES);
    num_processes = MAX_PROCESSES;

    display_processes(processes, num_processes);

    return 0;
}