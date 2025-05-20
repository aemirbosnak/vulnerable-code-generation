//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 20
#define MAX_VALUES 10
#define MAX_DATA_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int values[MAX_VALUES];
    int num_values;
} Process;

void print_header() {
    printf("%-20s %10s %15s %15s\n", "Process Name", "PID", "Memory Usage", "Total Memory");
}

void print_process(Process p) {
    int total_memory = 0;
    for (int i = 0; i < p.num_values; i++) {
        total_memory += p.values[i];
    }
    printf("%-20s %10d %15d %15d\n", p.name, getpid(), p.values[p.num_values-1], total_memory);
}

int get_mem_usage() {
    int pid = getpid();
    char command[50];
    sprintf(command, "pmap %d | tail -1 | awk '{print $2}'", pid);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error while getting memory usage.\n");
        exit(1);
    }
    char output[MAX_DATA_LENGTH];
    fgets(output, MAX_DATA_LENGTH, fp);
    pclose(fp);
    return atoi(output);
}

int main() {
    int count = 0;
    printf("Press 'q' to quit.\n\n");
    print_header();
    while (1) {
        Process p;
        printf("Enter process name: ");
        fgets(p.name, MAX_NAME_LENGTH, stdin);
        if (p.name[strlen(p.name)-1] == '\n') {
            p.name[strlen(p.name)-1] = '\0';
        }
        if (strcmp(p.name, "q") == 0) {
            break;
        }
        int mem_usage = get_mem_usage();
        p.values[0] = mem_usage;
        p.num_values = 1;
        print_process(p);
        sleep(1);
        count++;
        if (count == 10) {
            printf("Memory usage over time:\n");
            for (int i = 0; i < p.num_values; i++) {
                printf("%d ", p.values[i]);
            }
            printf("\n");
            count = 0;
        }
    }
    return 0;
}