//FormAI DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PROCESS_PATH "/proc/"

struct proc_info {
    int pid;
    int ppid;
    char state;
    char cmd[BUFFER_SIZE];
};

// function declarations
int is_number(const char *string);
struct proc_info get_proc_info(char* pid);

int main() {
    DIR *proc_dir;
    struct dirent *entry;

    printf("PID\tPPID\tSTATE\tCOMMAND\n");

    proc_dir = opendir(PROCESS_PATH);

    if (proc_dir == NULL) {
        perror("Unable to open process directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(proc_dir))) {
        if (is_number(entry->d_name)) {
            struct proc_info proc = get_proc_info(entry->d_name);
            printf("%d\t%d\t%c\t%s\n", proc.pid, proc.ppid, proc.state, proc.cmd);
        }
    }

    closedir(proc_dir);

    return 0;
}

// check if a string is a number
int is_number(const char *string) {
    while (*string) {
        if (!isdigit(*string)) {
            return 0;
        }
        string++;
    }
    return 1;
}

// get process information
struct proc_info get_proc_info(char* pid) {
    char stat_file[BUFFER_SIZE];
    char cmd_file[BUFFER_SIZE];
    snprintf(stat_file, BUFFER_SIZE, "%s%s/%s", PROCESS_PATH, pid, "stat");
    snprintf(cmd_file, BUFFER_SIZE, "%s%s/%s", PROCESS_PATH, pid, "cmdline");

    FILE* stat_fp = fopen(stat_file, "r");
    FILE* cmd_fp = fopen(cmd_file, "r");

    if (stat_fp == NULL || cmd_fp == NULL) {
        perror("Unable to open process files");
        exit(EXIT_FAILURE);
    }

    struct proc_info proc;
    char buffer[BUFFER_SIZE];
    fscanf(stat_fp, "%d %s %c %d", &proc.pid, buffer, &proc.state, &proc.ppid);
    fgets(buffer, BUFFER_SIZE, cmd_fp);
    strncpy(proc.cmd, buffer, BUFFER_SIZE);

    fclose(stat_fp);
    fclose(cmd_fp);

    return proc;
}