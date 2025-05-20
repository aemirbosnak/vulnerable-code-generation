//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>

#define TOTAL_MEMORY (1024 * 1024)
#define FREQUENCY 1000

typedef struct {
    int pid;
    char name[16];
    int usage;
} process;

int main() {
    FILE *fp;
    char line[1024], *token;
    process *processes = malloc(sizeof(process) * TOTAL_MEMORY);
    int count = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        if (token!= NULL) {
            if (strcmp(token, "cpu") == 0) {
                token = strtok(NULL, " ");
                while (token!= NULL) {
                    processes[count].pid = count;
                    strncpy(processes[count].name, token, sizeof(processes[count].name));
                    processes[count++].usage = 0;
                    token = strtok(NULL, " ");
                }
            }
        }
    }

    fclose(fp);

    while (1) {
        for (int i = 0; i < count; i++) {
            sprintf(line, "/proc/%d/stat", processes[i].pid);
            fp = fopen(line, "r");
            if (fp == NULL) {
                printf("Error: Could not open /proc/%d/stat\n", processes[i].pid);
                exit(1);
            }

            token = fgets(line, sizeof(line), fp);
            fclose(fp);

            int usage = 0;
            token = strtok(line, " ");
            while (token!= NULL) {
                if (strcmp(token, "utime") == 0 || strcmp(token, "stime") == 0) {
                    usage += atoi(token);
                }
                token = strtok(NULL, " ");
            }

            processes[i].usage = usage;
        }

        printf("\n");
        for (int i = 0; i < count; i++) {
            printf("%-15s %10d\n", processes[i].name, processes[i].usage);
        }

        usleep(FREQUENCY);
    }

    free(processes);
    return 0;
}