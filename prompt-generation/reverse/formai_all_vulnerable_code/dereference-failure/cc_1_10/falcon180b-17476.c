//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 100

typedef struct {
    char name[MAX_ENTRY_LEN];
    int pid;
} entry_t;

void read_processes(entry_t entries[], int *num_entries) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_ENTRY_LEN];
    int count = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            snprintf(path, MAX_ENTRY_LEN, "/proc/%s", ent->d_name);
            if (access(path, F_OK) == 0) {
                if (count >= MAX_ENTRIES) {
                    printf("Maximum number of entries reached\n");
                    break;
                }
                entries[count].pid = atoi(ent->d_name);
                strncpy(entries[count].name, ent->d_name, MAX_ENTRY_LEN - 1);
                entries[count].name[MAX_ENTRY_LEN - 1] = '\0';
                count++;
            }
        }
    }

    *num_entries = count;
    closedir(dir);
}

void display_processes(entry_t entries[], int num_entries) {
    printf("PID\tName\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d\t%s\n", entries[i].pid, entries[i].name);
    }
}

void main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries;

    read_processes(entries, &num_entries);
    display_processes(entries, num_entries);

    printf("Exiting...\n");
}