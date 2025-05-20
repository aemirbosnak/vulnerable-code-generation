//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_LEN 256 // maximum line length for reading /proc file

// process information struct
typedef struct {
    int pid;
    char name[256];
    char state;
    int parent_pid;
    int n_threads;
    long int vmsize;
} process;

// function to get process information
void get_process_info(process* p, char* pid_str) {
    char filepath[256];
    char line[MAX_LINE_LEN];
    sprintf(filepath, "/proc/%s/stat", pid_str);

    // open process stat file
    FILE* f = fopen(filepath, "r");
    if (f == NULL) {
        printf("Error opening file %s\n", filepath);
        exit(-1);
    }

    // parse stat file contents
    fscanf(f, "%d %s %c %d %d", &(p->pid), p->name, &(p->state), &(p->parent_pid), &(p->n_threads));
    fclose(f);

    // get process memory usage
    sprintf(filepath, "/proc/%s/status", pid_str);
    f = fopen(filepath, "r");
    if (f != NULL) {
        while (fgets(line, MAX_LINE_LEN, f)) {
            if (strstr(line, "VmSize:")) {
                sscanf(line, "VmSize: %ld", &(p->vmsize));
                break;
            }
        }
        fclose(f);
    }
}

int main() {
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error opening /proc directory.\n");
        exit(-1);
    }

    // loop through all processes
    struct dirent* proc_entry;
    process p;
    printf("%-8s %-20s %-10s %-10s %s\n", "PID", "NAME", "STATE", "PARENT", "MEMORY");
    printf("------------------------------------------------------------\n");
    while ((proc_entry = readdir(proc_dir))) {
        if (!isdigit(proc_entry->d_name[0]))
            continue;
        get_process_info(&p, proc_entry->d_name);
        printf("%-8d %-20s %-10c %-10d %ld KB\n", p.pid, p.name, p.state, p.parent_pid, p.vmsize);
    }
    closedir(proc_dir);
    return 0;
}