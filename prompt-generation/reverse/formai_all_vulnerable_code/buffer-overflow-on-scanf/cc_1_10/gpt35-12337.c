//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5 //number of processes
#define MAX_COUNT 3 // max number of times a process can execute
#define MAX_QUANTUM 5 // max quantum

int waiting_time[N], turnaround_time[N], n, quantum[MAX_COUNT], time_interval[MAX_COUNT], priority[N], burst_time[N], remaining_time[N], process_id[N], completion_time[N];
int temp = 0, total_time = 0, count = 0, completed = 0, current_time = 0, average_waiting_time = 0, average_turnaround_time = 0, choice;

sem_t mutex, service_queue, limit_queue[MAX_COUNT];

pthread_t threads[2];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void initialize() {
    for(int i = 0; i < n; i++) {
        printf("Enter priority(0-9) and burst time for process[%d] : ", i+1);

        scanf("%d%d", &priority[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
        process_id[i] = i+1;
    }
}

void* RR() {
    while(1) {
        sem_wait(&limit_queue[0]);

        if(remaining_time[count] <= quantum[0] && remaining_time[count] > 0) {
            current_time += remaining_time[count];
            remaining_time[count] = 0;

            completion_time[count] = current_time;
            turnaround_time[count] = completion_time[count] - burst_time[count];
            waiting_time[count] = turnaround_time[count] - burst_time[count];

            average_waiting_time += waiting_time[count];
            average_turnaround_time += turnaround_time[count];

            printf("\nProcess[%d] completed at %dms", process_id[count], current_time);
            completed++;

            sem_post(&limit_queue[0]);
        } else if(remaining_time[count] <= 0) {
            completion_time[count] = current_time;
            current_time += 0;
            sem_post(&limit_queue[0]);
        } else {
            current_time += quantum[0];
            remaining_time[count] -= quantum[0];

            printf("\nProcess[%d] current time = %dms", process_id[count], current_time);

            sem_post(&limit_queue[1]);
        }

        if(count == n-1) 
            count = 0;
        else if(process_id[count+1] != 0) 
            count++;
        else 
            count = 0;

        if(completed == n) break;
    }
}

void* SJF() {
    if(choice == 2) sleep(5);

    int min, temp;

    for(int i = 0; i < n; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(burst_time[j] < burst_time[min]) {
                min = j;
            }
        }

        temp = burst_time[i];
        burst_time[i] = burst_time[min];
        burst_time[min] = temp;

        temp = process_id[i];
        process_id[i] = process_id[min];
        process_id[min] = temp;
    }

    printf("\n\nProcess Schedule for SJF Algorithm");
    printf("\n==================================\n");

    for(int i = 0; i < n; i++) {
        printf("Sequence[%d]\tProcess[%d]\n", i+1, process_id[i]);
    }

    printf("\n\nProcess Execution Order for SJF Algorithm");
    printf("\n=======================================\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(process_id[i] == j+1) {
                printf("\nProcess[%d] started at %dms", j+1, total_time);
                waiting_time[j] = total_time;
                total_time += burst_time[i];
                printf("\nProcess[%d] finished at %dms", j+1, total_time);
                turnaround_time[j] = total_time;
            }
        }
    }

    printf("\n\nWaiting Times and Turnaround times for SJF Algorithm");
    printf("\n===================================================\n");

    for(int i = 0; i < n; i++) {
        printf("Process[%d]\tWaiting Time : %dms\tTurnaround Time : %dms\n", process_id[i], waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&service_queue, 0, 0);

    printf("\nEnter the number of processes : ");
    scanf("%d", &n);

    printf("\nEnter your choice of CPU scheduling algorithm (1 for RR and 2 for SJF) : ");
    scanf("%d", &choice);

    initialize();

    if(choice == 1) {
        for(int i = 0; i < MAX_COUNT; i++) {
            quantum[i] = i * MAX_QUANTUM;
        }

        printf("\n\nProcess Schedule for RR Algorithm");
        printf("\n==================================\n");

        for(int i = 0; i < n; i++) {
            printf("Sequence[%d]\tProcess[%d]\n", i+1, process_id[i]);
        }

        printf("\n\nProcess Execution Order for RR Algorithm");
        printf("\n=======================================\n");

        pthread_create(&threads[0], NULL, RR, NULL);

        for(int i = 0; i < n; i++) {
            sem_post(&limit_queue[0]);
        }

        pthread_join(threads[0], NULL);

        average_waiting_time /= n;
        average_turnaround_time /= n;

        printf("\n\nAverage Waiting Time : %dms", average_waiting_time);
        printf("\nAverage Turnaround Time : %dms", average_turnaround_time);
    } else if(choice == 2) {
        pthread_create(&threads[0], NULL, SJF, NULL);

        pthread_join(threads[0], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&service_queue);

    return 0;
}