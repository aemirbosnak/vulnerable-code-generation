//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_PROCESS_ID_LENGTH 20

typedef struct {
    char process_name[MAX_PROCESS_NAME_LENGTH];
    char process_id[MAX_PROCESS_ID_LENGTH];
    int process_id_num;
} process_info;

void get_process_info(process_info *processes, int num_processes) {
    FILE *file;
    char line[100];
    char *token;
    int i = 0;

    file = popen("ps -e", "r");
    if (file == NULL) {
        printf("Error: Failed to run ps command.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, " ");
        strcpy(processes[i].process_name, token);
        token = strtok(NULL, " ");
        strcpy(processes[i].process_id, token);
        processes[i].process_id_num = atoi(processes[i].process_id);
        i++;
        if (i >= num_processes) {
            break;
        }
    }

    pclose(file);
}

void display_process_info(process_info *processes, int num_processes) {
    int i;

    printf("Process ID\tProcess Name\n");
    for (i = 0; i < num_processes; i++) {
        printf("%s\t%s\n", processes[i].process_id, processes[i].process_name);
    }
}

int main() {
    process_info processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes to display (up to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    get_process_info(processes, num_processes);
    display_process_info(processes, num_processes);

    return 0;
}