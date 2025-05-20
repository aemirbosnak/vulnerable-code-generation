//FormAI DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 512

void print_header() {
    printf("%-10s %-10s %-20s %-10s %-20s\n", "PID", "PPID", "Name", "State", "Memory");
}

void read_stat_file(char *pid, char *pname, char *ppid, char *state) {
    char path[MAX_BUF];
    sprintf(path, "/proc/%s/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fscanf(fp, "%s %s %s", pid, pname, state);

    for (int i = 0; i < 3; i++) {
        fscanf(fp, "%s", ppid);
    }

    fclose(fp);
}

void read_status_file(char *pid, char *memory) {
    char path[MAX_BUF];
    sprintf(path, "/proc/%s/status", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_BUF];
    while (fgets(line, MAX_BUF, fp) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            strcpy(memory, line + 7);
            break;
        }
    }

    fclose(fp);
}

int main() {
    DIR *d = opendir("/proc");
    if (d == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *dir;
    char pid[MAX_BUF], pname[MAX_BUF], ppid[MAX_BUF], state[MAX_BUF], memory[MAX_BUF];

    print_header();

    while ((dir = readdir(d)) != NULL) {
        if (isdigit(dir->d_name[0])) {
            strcpy(pid, dir->d_name);

            read_stat_file(pid, pname, ppid, state);
            read_status_file(pid, memory);

            printf("%-10s %-10s %-20s %-10s %-20s\n", pid, ppid, pname, state, memory);
        }
    }

    closedir(d);
    return 0;
}