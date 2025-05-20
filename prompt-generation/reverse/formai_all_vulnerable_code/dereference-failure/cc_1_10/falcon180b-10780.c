//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LEN 1024

typedef struct {
    char name[MAX_LINE_LEN];
    int pid;
    float cpu_usage;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void read_processes() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (i >= MAX_PROCESSES) {
            printf("Error: too many processes\n");
            exit(1);
        }

        token = strtok(line, " ");
        strcpy(processes[i].name, token);
        processes[i].pid = atoi(token);

        token = strtok(NULL, " ");
        processes[i].cpu_usage = atof(token);

        i++;
    }

    fclose(fp);
}

void display_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%s (%d) - %.2f%%\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
    }
}

int main() {
    read_processes();
    display_processes();

    return 0;
}