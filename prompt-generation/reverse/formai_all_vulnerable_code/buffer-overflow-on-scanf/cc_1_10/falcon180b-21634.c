//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process_t;

void *runner(void *param) {
    process_t *p = (process_t *) param;
    int i;

    for (i = 0; i < p->burst_time; i++) {
        printf("Process %d is running\n", p->id);
        sleep(1);
    }

    p->waiting_time = p->burst_time - p->waiting_time;
    p->turnaround_time = p->waiting_time + p->burst_time;

    printf("Process %d has finished. Its turnaround time is %d\n", p->id, p->turnaround_time);

    return NULL;
}

int main() {
    int i, j, n, quantum;
    process_t processes[10];
    pthread_t threads[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times for %d processes:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, runner, &processes[i]);
        sleep(1);
    }

    for (i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}