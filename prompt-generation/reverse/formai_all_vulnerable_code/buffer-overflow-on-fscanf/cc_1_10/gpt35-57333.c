//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

struct Process {
    char pid[10];
    char name[100];
    char state[2];
    char priority[5];
    char memory[10];
};

void getProcessInfo(struct Process* process, char* pid) {
    char filename[30];
    sprintf(filename, "/proc/%s/stat", pid);
    FILE* file = fopen(filename, "r");
    if (file) {
        fscanf(file, "%s %s %s %s %s", process->pid, process->name, process->state, 
            process->priority, process->memory);
        fclose(file);
    }
}

int main() {
    DIR* proc = opendir("/proc");
    struct dirent* dir;
    char* pid;
    struct Process process;
    int line_count = 0;
    char line[MAX_LINE_SIZE];
    
    printf("PID\tNAME\t\tSTATE\tPRIORITY\tMEMORY\n");
    
    if(proc) {
        while ((dir = readdir(proc))) {
            if (isdigit(*dir->d_name)) {
                pid = dir->d_name;
                getProcessInfo(&process, pid);
                printf("%s\t%-12s\t%s\t%s\t\t%s\n", process.pid, process.name, process.state, 
                    process.priority, process.memory);
                line_count++;
            }
        }
        closedir(proc);
    }
    printf("Number of Processes: %d\n", line_count);

    return 0;
}