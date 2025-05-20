//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_OPEN_FILES 1024

void print_process_info(char* pid) {
    char filename[30];
    FILE* file;

    char process_name[256];
    char state;

    sprintf(filename, "/proc/%s/status", pid);

    file = fopen(filename, "r");

    if (file != NULL) {
        char line[256];

        while (fgets(line, sizeof(line), file) != NULL) {
            if (sscanf(line, "Name: %s", process_name) != 1) {
                sscanf(line, "State: %c", &state);
            }
        }

        fclose(file);

        printf("PID: %5s | Name: %-20s | State: %c\n", pid, process_name, state);
    }
}

void print_open_files(char* pid) {
    char filename[30];
    FILE* file;

    sprintf(filename, "/proc/%s/fd", pid);

    DIR* d = opendir(filename);
    if (d == NULL) {
        return;
    }

    struct dirent* entry;
    int i = 0;
    while ((entry = readdir(d)) != NULL) {
        char fd_path[128];

        int fd = atoi(entry->d_name);
        if (fd <= 2) {
            continue; // Ignore standard file descriptors
        }

        sprintf(fd_path, "/proc/%s/fd/%s", pid, entry->d_name);

        char link_target[256];
        ssize_t n = readlink(fd_path, link_target, sizeof(link_target) - 1);
        if (n == -1) {
            continue;
        }

        link_target[n] = '\0';

        printf("  %2d | %5s | %s\n", i++, entry->d_name, link_target);
    }

    closedir(d);
}

int main() {
    DIR* d;
    struct dirent* dir;
    char* pid;

    printf("%5s | %s | %s\n", "PID", "Process Name", "State");
    printf("------------------------------------------------------\n");

    d = opendir("/proc");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            pid = dir->d_name;
            if (isdigit(*pid)) {
                print_process_info(pid);
            }
        }

        closedir(d);
    }

    printf("\nFiles Opened By Processes:");
    printf("\n------------------------------------------------------\n");

    d = opendir("/proc");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            pid = dir->d_name;
            if (isdigit(*pid)) {
                printf("| Process %s:\n", pid);
                printf("  %2s |  FD  | File Name\n", "#");
                printf("  -------------------------------------------------\n");
                print_open_files(pid);
                printf("\n");
            }
        }

        closedir(d);
    } 

    return 0;
}