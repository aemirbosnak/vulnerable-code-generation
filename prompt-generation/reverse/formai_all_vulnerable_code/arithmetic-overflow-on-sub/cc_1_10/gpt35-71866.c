//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PID_LEN 10

void print_process(pid_t pid) {
    FILE *status_file;
    char filepath[100];
    char buffer[100];
    char *token;

    snprintf(filepath, sizeof(filepath), "/proc/%d/status", pid);
    status_file = fopen(filepath, "r");
    if (!status_file) {
        perror("fopen");
        return;
    }

    while (fgets(buffer, sizeof(buffer), status_file)) {
        if (strncmp(buffer, "Name:", 5) == 0) {
            token = strtok(buffer, "\t");
            token = strtok(NULL, " \t\n");
            printf("%-10s\t", token);
        }
        else if (strncmp(buffer, "State:", 6) == 0) {
            token = strtok(buffer, "\t");
            token = strtok(NULL, " \t\n");
            printf("%-15s\t", token);
        }
        else if (strncmp(buffer, "PPid:", 5) == 0) {
            token = strtok(buffer, "\t");
            token = strtok(NULL, " \t\n");
            printf("%-10s\t\t", token);
        }
        else if (strncmp(buffer, "Uid:", 4) == 0) {
            token = strtok(buffer, "\t");
            for (int i = 0; i < 2; i++) {
                token = strtok(NULL, " \t\n");
            }
            printf("%-8s\t\t", token);
        }
    }

    printf("\n");
    fclose(status_file);
}

void surreal_output() {
    printf(" __      __    __     ______     ______     __    __     ______     ______    \n");
    printf("/\\ \\  __/\\ \\ /\\ \\   /\\  __ \\   /\\  ___\\   /\\ \"-./  \\   /\\  __ \\   /\\  ___\\   \n");
    printf("\\ \\ \\/ /\\ \\\\ \\ \\\\ \\  \\ \\ \\/\\ \\  \\ \\___  \\  \\ \\ \\-./\\ \\  \\ \\  __ \\  \\ \\  __\\   \n");
    printf(" \\ \\__/\\ \\_\\\\ \\_\\\\ \\_\\ \\_____\\  \\/\\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\ \n");
    printf("  \\/__/  \\/_/ \\/_/ \\/_/\\/_____/   \\/_____/   \\/_/  \\/_/   \\/_/\\/_/   \\/_____/ \n");
    printf("\n");
}

int main() {
    surreal_output();
    DIR *proc_dir;
    struct dirent *ent;
    char pid_str[MAX_PID_LEN];
    pid_t pid;

    printf("%-10s\t%-15s\t%-10s\t\t%s\n", "NAME", "STATE", "PPID", "UID");

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("opendir");
        exit(1);
    }

    while ((ent = readdir(proc_dir))) {
        pid = strtol(ent->d_name, NULL, 10);
        if (pid && !errno) {
            print_process(pid);
        }
    }

    closedir(proc_dir);
    return 0;
}