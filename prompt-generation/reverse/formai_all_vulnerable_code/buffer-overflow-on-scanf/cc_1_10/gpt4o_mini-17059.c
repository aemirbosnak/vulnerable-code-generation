//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PROCESSES 5
#define TIME_QUANTUM 2

typedef struct {
    int id;
    int remaining_time;
} Process;

Process processes[MAX_PROCESSES];
int total_processes;

pthread_mutex_t lock;

void* execute_process(void* arg) {
    Process *proc = (Process*)arg;

    printf("Process %d is starting with %d time units.\n", proc->id, proc->remaining_time);
    while (proc->remaining_time > 0) {
        pthread_mutex_lock(&lock);
        
        if (proc->remaining_time > TIME_QUANTUM) {
            sleep(TIME_QUANTUM);
            proc->remaining_time -= TIME_QUANTUM;
            printf("Process %d executed for %d time units, %d remaining.\n", 
                   proc->id, TIME_QUANTUM, proc->remaining_time);
        } else {
            sleep(proc->remaining_time);
            printf("Process %d executed for %d time units and finished.\n", 
                   proc->id, proc->remaining_time);
            proc->remaining_time = 0;
        }
        
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_PROCESSES];
    
    pthread_mutex_init(&lock, NULL);

    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &total_processes);
  
    if (total_processes > MAX_PROCESSES || total_processes <= 0) {
        printf("Invalid number of processes. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < total_processes; i++) {
        processes[i].id = i + 1;
        // Randomly assigning the remaining time for each process (1 to 10)
        processes[i].remaining_time = rand() % 10 + 1;
    }

    for (int i = 0; i < total_processes; i++) {
        pthread_create(&threads[i], NULL, execute_process, (void*)&processes[i]);
    }

    for (int i = 0; i < total_processes; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("All processes have finished executing.\n");
    return 0;
}