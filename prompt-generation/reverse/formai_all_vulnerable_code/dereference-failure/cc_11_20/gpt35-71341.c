//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 1024

struct process_info {
    char name[256];
    pid_t pid;
    pid_t parent_pid;
    long unsigned int rss;
};

typedef struct process_info process_info_t;

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *ent;
    process_info_t processes[1024];
    int count = 0;

    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (atoi(ent->d_name) != 0) {
                char filename[MAX_PATH];
                snprintf(filename, MAX_PATH, "/proc/%s/status", ent->d_name);

                FILE *fp;
                if ((fp = fopen(filename, "r")) != NULL) {

                    char line[256];
                    char *key, *value;
                    while (fgets(line, sizeof(line), fp) != NULL) {
                        key = strtok(line, ":");
                        value = strtok(NULL, ":");
                        if (strcmp(key, "Name") == 0) {
                            strncpy(processes[count].name, value, strlen(value));
                            processes[count].name[strlen(value) - 1] = '\0'; // Removing newline character
                        }
                        else if (strcmp(key, "Pid") == 0) {
                            processes[count].pid = atoi(value);
                        }
                        else if (strcmp(key, "PPid") == 0) {
                            processes[count].parent_pid = atoi(value);
                        }
                        else if (strcmp(key, "VmRSS") == 0) {
                            processes[count].rss = atol(value) * 1024; // Converting to bytes
                        }
                    }

                    fclose(fp);
                    count++;
                }
            }
        }

        closedir(dir);

        // Printing the process table
        printf("   PID     PPID    NAME                   RSS (bytes)\n");
        for (int i = 0; i < count; i++) {
            printf("%6d %6d   %-20s %10lu\n", processes[i].pid, processes[i].parent_pid, processes[i].name, processes[i].rss);
        }
    } else {
        perror("Error: Failed to open dir");
    }

    return 0;
}