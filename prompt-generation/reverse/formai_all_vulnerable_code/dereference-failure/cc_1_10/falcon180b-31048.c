//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PROC_NAME 16
#define MAX_CMD_LINE 1024
#define MAX_PROC_NUM 1024

typedef struct {
    int pid;
    char name[MAX_PROC_NAME];
    char cmdline[MAX_CMD_LINE];
    int status;
} proc_info_t;

void print_proc_info(proc_info_t *info, int num) {
    printf("PID: %d\n", info[num].pid);
    printf("Name: %s\n", info[num].name);
    printf("Command Line: %s\n", info[num].cmdline);
    printf("Status: %d\n\n", info[num].status);
}

int get_proc_info(int pid, char *name, char *cmdline, int *status) {
    char path[32];
    sprintf(path, "/proc/%d/", pid);
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory for process %d\n", pid);
        return -1;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char filename[32];
            sprintf(filename, "/proc/%d/%s", pid, ent->d_name);
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Failed to open file for process %d\n", pid);
                closedir(dir);
                return -1;
            }

            fscanf(file, "%s\n", name);
            fscanf(file, "%s\n", cmdline);
            *status = atoi(ent->d_name);

            fclose(file);
            closedir(dir);
            return 0;
        }
    }

    closedir(dir);
    return -1;
}

int main() {
    int num_procs = 0;
    proc_info_t info[MAX_PROC_NUM];

    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Failed to open /proc directory\n");
        return -1;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char path[32];
            sprintf(path, "/proc/%s", ent->d_name);
            int pid = atoi(ent->d_name);

            if (get_proc_info(pid, info[num_procs].name, info[num_procs].cmdline, &info[num_procs].status) == 0) {
                num_procs++;
            }
        }
    }

    closedir(dir);

    if (num_procs == 0) {
        printf("No processes found\n");
        return 0;
    }

    printf("Process List:\n");
    for (int i = 0; i < num_procs; i++) {
        print_proc_info(&info[i], i);
    }

    return 0;
}