//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int arrival_time;
    int service_time;
    int waiting_time;
    int finish_time;
} Process;

int compare(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;

    if (p1->arrival_time > p2->arrival_time)
        return 1;
    else if (p1->arrival_time < p2->arrival_time)
        return -1;
    else
        return 0;
}

void print_queue(Process queue[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", queue[i].id);
    }
    printf("\n");
}

int main() {
    int num_processes, i;
    Process queue[100];

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    srand(time(NULL));
    int max_arrival_time = 50;
    int min_arrival_time = 1;

    for (i = 0; i < num_processes; i++) {
        queue[i].id = i + 1;
        queue[i].arrival_time = rand() % (max_arrival_time - min_arrival_time + 1) + min_arrival_time;
        queue[i].service_time = rand() % 10 + 1;
    }

    qsort(queue, num_processes, sizeof(Process), compare);

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        if (current_time >= queue[0].arrival_time) {
            if (queue[0].service_time <= current_time - queue[0].arrival_time) {
                current_time += queue[0].service_time;
                queue[0].finish_time = current_time;
                completed_processes++;
            } else {
                current_time = queue[0].arrival_time + queue[0].service_time;
                queue[0].waiting_time = current_time - queue[0].arrival_time;
            }
        } else {
            break;
        }

        print_queue(queue, num_processes);
    }

    printf("Average waiting time: %d\n", (int)((float)completed_processes / num_processes * 100));

    return 0;
}