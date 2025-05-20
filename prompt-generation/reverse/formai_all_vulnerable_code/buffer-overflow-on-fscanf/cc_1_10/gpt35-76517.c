//FormAI DATASET v1.0 Category: System process viewer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 16
#define MAX_PATH_LENGTH 1024

struct process {
    char pid[MAX_PID_LENGTH];
    char name[MAX_PATH_LENGTH];
};

int is_integer(const char *str) {
    // check if string is an integer
    int i = 0;
    if (str[0] == '-') {
        i = 1;
    }
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int get_processes(struct process **procs) {
    // get list of running processes
    int count = 0;
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR && is_integer(entry->d_name)) {
            struct process *proc = (struct process *) malloc(sizeof(struct process));
            strcpy(proc->pid, entry->d_name);
            char path[MAX_PATH_LENGTH];
            sprintf(path, "/proc/%s/cmdline", entry->d_name);
            FILE *fp = fopen(path, "r");
            if (fp == NULL) {
                perror("fopen");
            } else {
                fscanf(fp, "%s", proc->name);
                fclose(fp);
                (*procs)[count] = *proc; // add process to list
                count++;
            }
        }
    }
    closedir(dir);
    return count;
}

void print_processes(struct process *procs, int count) {
    // print list of running processes
    printf("PID\tName\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", procs[i].pid, procs[i].name);
    }
}

int main() {
    struct process *procs = NULL;
    int count = get_processes(&procs);
    if (count > 0) {
        print_processes(procs, count);
    } else {
        printf("No running processes found\n");
    }
    free(procs);
    return 0;
}