//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

typedef struct process_info {
    int pid;
    char name[BUFFER_SIZE];
    int status;
} process_info_t;

void print_processes(process_info_t* processes, int num_processes) {
    printf("Process ID\tProcess Name\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    int num_processes = 0;
    process_info_t* processes = NULL;

    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Could not open /proc directory.\n");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_name[0] >= '0' && entry->d_name[0] <= '9') {
            char path[50];
            sprintf(path, "/proc/%s/status", entry->d_name);
            FILE* file = fopen(path, "r");

            if (file!= NULL) {
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, file);
                fclose(file);

                if (sscanf(buffer, "Name:\t%s", processes[num_processes].name) == 1) {
                    processes[num_processes].pid = atoi(entry->d_name);
                    processes[num_processes].status = 0;
                    num_processes++;
                }
            }
        }
    }

    closedir(dir);

    if (num_processes == 0) {
        printf("Error: No processes found.\n");
        return 1;
    }

    processes = realloc(processes, num_processes * sizeof(process_info_t));

    for (int i = 0; i < num_processes; i++) {
        char path[50];
        sprintf(path, "/proc/%d/stat", processes[i].pid);
        FILE* file = fopen(path, "r");

        if (file!= NULL) {
            char buffer[BUFFER_SIZE];
            fgets(buffer, BUFFER_SIZE, file);
            fclose(file);

            if (sscanf(buffer, "%d", &processes[i].status) == 1) {
                processes[i].status &= 0xff;
            }
        }
    }

    print_processes(processes, num_processes);

    free(processes);

    return 0;
}