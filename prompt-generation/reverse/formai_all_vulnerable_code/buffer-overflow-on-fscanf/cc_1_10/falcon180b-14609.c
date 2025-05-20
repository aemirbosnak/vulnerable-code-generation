//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int memory_usage;
} Process;

int get_process_info(int pid, char *name, int *memory_usage) {
    FILE *fp;
    char path[64];
    sprintf(path, "/proc/%d/statm", pid);
    fp = fopen(path, "r");
    if (!fp) {
        return -1;
    }
    fscanf(fp, "%*d %*d %*d %*d %*d %d", memory_usage);
    fclose(fp);
    sprintf(path, "/proc/%d/comm", pid);
    fp = fopen(path, "r");
    if (!fp) {
        return -1;
    }
    fscanf(fp, "%s", name);
    fclose(fp);
    return 0;
}

int main() {
    int i, j, num_processes = 0;
    Process processes[MAX_PROCESSES];
    time_t start_time, end_time;
    double elapsed_time;
    char c;

    printf("Starting RAM usage monitor...\n");
    fflush(stdout);

    start_time = time(NULL);

    while (1) {
        num_processes = 0;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (get_process_info(i, processes[i].name, &processes[i].memory_usage) == 0) {
                num_processes++;
            } else {
                memset(&processes[i], 0, sizeof(Process));
            }
        }

        printf("\nRAM usage for %d processes:\n", num_processes);
        for (i = 0; i < num_processes; i++) {
            printf("%-16s %8d kB\n", processes[i].name, processes[i].memory_usage);
        }

        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);

        if (elapsed_time >= 5.0) {
            break;
        }

        printf("\nPress any key to refresh...\n");
        fflush(stdout);
        while ((c = getchar())!= '\n' && c!= EOF) {
            ;
        }
        fflush(stdin);
    }

    printf("\nExiting RAM usage monitor...\n");
    fflush(stdout);

    return 0;
}