//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 512
#define MAX_PROCESS_NAME_LENGTH 64
#define MAX_PROCESS_ID_LENGTH 16
#define MAX_PROCESS_STATE_LENGTH 32
#define MAX_PROCESS_PPID_LENGTH 16
#define MAX_PROCESS_CPU_TIME_LENGTH 32
#define MAX_PROCESS_MEMORY_LENGTH 32
#define MAX_PROCESS_START_TIME_LENGTH 32
#define MAX_PROCESS_COMMAND_LENGTH 1024

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    char id[MAX_PROCESS_ID_LENGTH];
    char state[MAX_PROCESS_STATE_LENGTH];
    char ppid[MAX_PROCESS_PPID_LENGTH];
    char cpu_time[MAX_PROCESS_CPU_TIME_LENGTH];
    char memory[MAX_PROCESS_MEMORY_LENGTH];
    char start_time[MAX_PROCESS_START_TIME_LENGTH];
    char command[MAX_PROCESS_COMMAND_LENGTH];
} Process;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    Process *process;
    int num_processes = 0;
    int max_processes = 100;
    process = malloc(max_processes * sizeof(Process));

    file = fopen("/proc/task", "r");
    if (file == NULL) {
        printf("Error: Could not open /proc/task.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, " ");
        strcpy(process[num_processes].id, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].name, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].state, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].ppid, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].cpu_time, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].memory, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].start_time, token);

        token = strtok(NULL, " ");
        strcpy(process[num_processes].command, token);

        num_processes++;
        if (num_processes >= max_processes) {
            printf("Error: Reached maximum number of processes.\n");
            exit(1);
        }
    }

    fclose(file);

    printf("Process ID\tProcess Name\tState\tPPID\tCPU Time\tMemory\tStart Time\tCommand\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
               process[i].id,
               process[i].name,
               process[i].state,
               process[i].ppid,
               process[i].cpu_time,
               process[i].memory,
               process[i].start_time,
               process[i].command);
    }

    free(process);
    return 0;
}