//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define MAX_PROCESSES 1024

typedef struct {
    char name[16];
    int pid;
} process_t;

void read_processes(process_t *processes) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL && count < MAX_PROCESSES) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                strcpy(processes[count].name, ent->d_name);
                processes[count].pid = pid;
                count++;
            }
        }
        closedir(dir);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    int selected_process = 0;

    read_processes(processes);
    num_processes = count_processes(processes);

    printf("Retro Process Viewer\n");
    printf("=====================\n");
    printf("Number of processes: %d\n", num_processes);
    printf("\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d. %s (%d)\n", i+1, processes[i].name, processes[i].pid);
    }

    printf("\n");
    printf("Select a process to view details: ");
    scanf("%d", &selected_process);

    printf("\n");
    printf("Process Details\n");
    printf("================\n");
    printf("Name: %s\n", processes[selected_process-1].name);
    printf("PID: %d\n", processes[selected_process-1].pid);

    return 0;
}

int count_processes(process_t *processes) {
    int count = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid!= 0) {
            count++;
        }
    }
    return count;
}