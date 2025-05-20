//FormAI DATASET v1.0 Category: System process viewer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_CMDLINE 2048

/* Struct to hold process information */
typedef struct {
    char name[256];
    char state[2];
    int pid;
    int ppid;
    char cmdline[MAX_CMDLINE];
} ProcessInfo;

/* Function to read and display process information */
static void read_proc_info(const char *pid) {
    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "/proc/%s/stat", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", path);
        return;
    }
    ProcessInfo info;
    fscanf(fp, "%d (%[^)]) %s %d %d", &info.pid, info.name, info.state, &info.ppid, &info.ppid);
    fclose(fp);
    snprintf(path, MAX_PATH, "/proc/%s/cmdline", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", path);
        return;
    }
    fgets(info.cmdline, MAX_CMDLINE, fp);
    fclose(fp);
    printf("%-7d %-7d %-8s %s\n", info.pid, info.ppid, info.state, info.cmdline);
}

/* Function to list all running processes */
void list_processes(void) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH];
    dir = opendir("/proc");
    if (dir == NULL) {
        fprintf(stderr, "Could not open directory: /proc\n");
        return;
    }
    printf("%-7s %-7s %-8s %s\n", "PID", "PPID", "STATE", "NAME");
    while ((ent = readdir(dir)) != NULL) {
        /* Check if it is a directory with a number as its name */
        if (isdigit(ent->d_name[0])) {
            read_proc_info(ent->d_name);
        }
    }
    closedir(dir);
}

int main(void) {
    list_processes();
    return 0;
}