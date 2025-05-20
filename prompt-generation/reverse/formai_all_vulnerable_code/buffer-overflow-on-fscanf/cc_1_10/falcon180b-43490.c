//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESS_NAME_LENGTH 100
#define MAX_PROCESS_ID_LENGTH 10

typedef struct {
    char process_name[MAX_PROCESS_NAME_LENGTH];
    char process_id[MAX_PROCESS_ID_LENGTH];
    int process_status;
} process_info_t;

void read_processes(process_info_t *processes, int max_processes) {
    char proc_file[MAX_PROCESS_NAME_LENGTH + 1] = "/proc/";
    strcat(proc_file, "1");
    FILE *fp = fopen(proc_file, "r");

    if (fp == NULL) {
        printf("Error: could not open /proc/1\n");
        exit(1);
    }

    int num_processes = 0;
    while (fscanf(fp, "%s %s %d", processes[num_processes].process_name, processes[num_processes].process_id, &processes[num_processes].process_status)!= EOF) {
        num_processes++;
        if (num_processes >= max_processes) {
            break;
        }
    }

    fclose(fp);
}

void display_processes(process_info_t *processes, int num_processes) {
    printf("Process ID\tProcess Name\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%s\t%d\n", processes[i].process_id, processes[i].process_name, processes[i].process_status);
    }
}

int main() {
    process_info_t processes[100];
    int num_processes = 0;

    read_processes(processes, 100);

    display_processes(processes, num_processes);

    return 0;
}