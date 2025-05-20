//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100

typedef struct {
    pid_t pid;
    char name[16];
    int status;
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        printf("Enter PID or type 'exit' to quit: ");
        char input[16];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int pid = atoi(input);
        char name[16];
        snprintf(name, sizeof(name), "/proc/%d/cmdline", pid);

        FILE *fp = fopen(name, "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            continue;
        }

        fgets(name, sizeof(name), fp);
        name[strcspn(name, "\n")] = '\0';

        processes[num_processes].pid = pid;
        strncpy(processes[num_processes].name, name, 16);
        processes[num_processes].status = 0;
        num_processes++;

        fclose(fp);
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, WNOHANG);
    }

    print_processes(processes, num_processes);

    return 0;
}