//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

Process processes[MAX_PROCESSES];
int process_count;

void* schedule_process(void* arg) {
    int id = *(int*)arg;

    while (processes[id].remaining_time > 0) {
        if (processes[id].remaining_time > TIME_QUANTUM) {
            printf("Process %d is executing for %d seconds.\n", processes[id].id, TIME_QUANTUM);
            sleep(TIME_QUANTUM);
            processes[id].remaining_time -= TIME_QUANTUM;
        } else {
            printf("Process %d is executing for %d seconds and finishing.\n", processes[id].id, processes[id].remaining_time);
            sleep(processes[id].remaining_time);
            processes[id].remaining_time = 0;
        }
    }
    printf("Process %d has completed execution.\n", processes[id].id);
    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &process_count);
    
    if (process_count > MAX_PROCESSES || process_count <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }
    
    for (int i = 0; i < process_count; i++) {
        processes[i].id = i;
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    pthread_t threads[MAX_PROCESSES];
    int thread_id[MAX_PROCESSES];
    
    for (int i = 0; i < process_count; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, schedule_process, (void*)&thread_id[i]);
    }
    
    for (int i = 0; i < process_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All processes have completed execution.\n");
    return 0;
}