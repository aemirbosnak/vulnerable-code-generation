//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define PROC_PATH "/proc/"
#define BUF_SIZE 64

void print_stat(char *pid) {
    char filename[BUF_SIZE];
    FILE *f = NULL;

    sprintf(filename, PROC_PATH "%s/stat", pid);

    f = fopen(filename, "r");

    if(f == NULL) {
        printf("Cannot open %s\n", filename);
        return;
    }

    printf("PID            : %s\n", pid);

    char name[BUF_SIZE], state, ppid[BUF_SIZE];
    fscanf(f, "%s %s %c", name, ppid, &state);

    printf("Command Name   : %s\n", name);
    printf("State          : %c\n", state);

    fclose(f);
}

void print_cmdline(char *pid) {
    char filename[BUF_SIZE];
    FILE *f = NULL;

    sprintf(filename, PROC_PATH "%s/cmdline", pid);

    f = fopen(filename, "r");

    if(f == NULL) {
        printf("Cannot open %s\n", filename);
        return;
    }

    char cmdline[BUF_SIZE];
    fgets(cmdline, BUF_SIZE, f);
    fclose(f);

    printf("Command Line   : %s\n", cmdline);
}

void list_processes() {
    DIR *dir = NULL;
    struct dirent *ent = NULL;
    char pid[BUF_SIZE];

    dir = opendir(PROC_PATH);

    if(dir == NULL) {
        printf("Cannot open directory %s\n", PROC_PATH);
        return;
    }

    printf("List of Processes:\n");

    while((ent = readdir(dir))) {
        if(ent->d_type != DT_DIR)
            continue;

        if(!isdigit(*(ent->d_name)))
            continue;

        // process found, print its info
        strcpy(pid, ent->d_name);
        print_stat(pid);
        print_cmdline(pid);

        printf("\n");
    }

    closedir(dir);
}

int main() {
    list_processes();
    return 0;
}