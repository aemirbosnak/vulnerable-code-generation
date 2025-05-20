//FormAI DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define PROC_DIR "/proc/"

int is_number(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

void process_info(const char* pid) {
    char filename[64];
    sprintf(filename, PROC_DIR "%s/status", pid);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    char line[256];
    char name[32];
    int ppid = -1;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            printf("Name: %s\n", name);
        } else if (sscanf(line, "PPid:\t%d", &ppid) == 1) {
            printf("Parent PID: %d\n", ppid);
        }
    }
    fclose(file);
}

void list_processes() {
    DIR* dir = opendir(PROC_DIR);
    if (dir == NULL) {
        printf("Failed to open directory " PROC_DIR "\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            process_info(entry->d_name);
        }
    }
    closedir(dir);
}

int main() {
    printf("===== Processes =====\n");
    list_processes();
    return 0;
}