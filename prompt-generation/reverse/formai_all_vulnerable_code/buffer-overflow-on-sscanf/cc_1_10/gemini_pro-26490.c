//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    char name[20];
    int arrival_time;
    int burst_time;
} process;

process processes[MAX_PROCESSES];
int num_processes;

void read_processes() {
    FILE *fp;
    char line[100];

    fp = fopen("processes.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %d %d", processes[num_processes].name, &processes[num_processes].arrival_time, &processes[num_processes].burst_time);
        num_processes++;
    }

    fclose(fp);
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%s %d %d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time);
    }
}

void sort_processes_by_arrival_time() {
    int i, j;
    process temp;

    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void schedule_processes_fcfs() {
    int i;
    int current_time = 0;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }
        current_time += processes[i].burst_time;
        printf("%s %d %d\n", processes[i].name, processes[i].arrival_time, current_time);
    }
}

void schedule_processes_sjf() {
    int i, j;
    int min_index;
    int current_time = 0;

    for (i = 0; i < num_processes - 1; i++) {
        min_index = i;
        for (j = i + 1; j < num_processes; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time < processes[min_index].burst_time) {
                min_index = j;
            }
        }
        process temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;
        current_time += processes[i].burst_time;
        printf("%s %d %d\n", processes[i].name, processes[i].arrival_time, current_time);
    }
}

void schedule_processes_rr() {
    int i, j;
    int quantum = 2;
    int current_time = 0;

    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time > 0) {
                if (processes[j].burst_time > quantum) {
                    current_time += quantum;
                    processes[j].burst_time -= quantum;
                } else {
                    current_time += processes[j].burst_time;
                    processes[j].burst_time = 0;
                    printf("%s %d %d\n", processes[j].name, processes[j].arrival_time, current_time);
                }
            }
        }
    }
}

int main() {
    read_processes();
    print_processes();
    sort_processes_by_arrival_time();
    schedule_processes_fcfs();
    schedule_processes_sjf();
    schedule_processes_rr();
    return 0;
}