//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

// Task structure definition
struct task {
    int id;
    char name[20];
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to compare two tasks based on their arrival time
int compare(const void *a, const void *b) {
    struct task task1 = *((struct task *)a);
    struct task task2 = *((struct task *)b);

    if (task1.arrival_time < task2.arrival_time)
        return -1;
    else if (task1.arrival_time > task2.arrival_time)
        return 1;
    else
        return 0;
}

// Function to execute a task
void execute_task(struct task task, int quantum) {
    int i;

    for (i = 0; i < task.burst_time; i += quantum) {
        printf("Task %d is executing...\n", task.id);
        fflush(stdout);
        sleep(quantum);
    }
}

// Function to implement Round Robin scheduling algorithm
void round_robin(struct task tasks[], int n, int quantum) {
    int i, j, count = 0;
    struct task *temp;

    qsort(tasks, n, sizeof(struct task), compare);

    for (i = 0; i < n; i++) {
        temp = &tasks[i];

        if (temp->arrival_time <= count) {
            execute_task(*temp, quantum);
            count += temp->burst_time;
        } else {
            break;
        }
    }

    for (j = i + 1; j < n; j++) {
        temp = &tasks[j];

        if (temp->arrival_time <= count) {
            execute_task(*temp, quantum);
            count += temp->burst_time;
        }
    }
}

int main() {
    int i, n;
    struct task tasks[MAX];

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    printf("Enter task details:\n");

    for (i = 0; i < n; i++) {
        printf("Task %d:\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &tasks[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &tasks[i].burst_time);
        printf("Enter task name (max 20 characters): ");
        scanf("%s", tasks[i].name);
    }

    round_robin(tasks, n, 2);

    return 0;
}