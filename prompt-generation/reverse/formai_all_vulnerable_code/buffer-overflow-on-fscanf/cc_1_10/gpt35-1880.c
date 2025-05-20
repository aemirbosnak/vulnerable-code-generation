//FormAI DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct Process {
    int pid;
    char name[BUFFER_SIZE];
    char state;
};

int get_processes(struct Process *processes) {
    DIR* directory = opendir("/proc");
    struct dirent* entry;

    int count = 0;
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[BUFFER_SIZE];
            snprintf(path, BUFFER_SIZE, "/proc/%s/stat", entry->d_name);

            FILE* file = fopen(path, "r");
            if (file) {
                if (fscanf(file, "%d %s %c", &processes[count].pid, processes[count].name,
                           &processes[count].state) == 3) {
                    count++;
                }
                fclose(file);
            }
        }
    }

    closedir(directory);
    return count;
}

void print_processes(int count, struct Process *processes) {
    printf("PID\tName\tState\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%c\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

int main() {
    struct Process processes[BUFFER_SIZE];
    int count = get_processes(processes);
    print_processes(count, processes);
    return 0;
}