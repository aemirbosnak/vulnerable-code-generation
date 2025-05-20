//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct Task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct Task *task) {
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    int i;
    for(i=0; i<task->burst_time; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
}

void schedule_tasks(struct Task *tasks, int num_tasks) {
    int i, j;
    for(i=0; i<num_tasks; i++) {
        printf("Task %s with priority %d arrived\n", tasks[i].name, tasks[i].priority);
    }
    for(i=0; i<num_tasks; i++) {
        for(j=i+1; j<num_tasks; j++) {
            if(tasks[i].priority > tasks[j].priority) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    printf("Tasks scheduled in order of priority:\n");
    for(i=0; i<num_tasks; i++) {
        printf("%s with priority %d\n", tasks[i].name, tasks[i].priority);
    }
}

int main() {
    struct Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    printf("Enter task names and priorities:\n");
    for(int i=0; i<num_tasks; i++) {
        scanf("%s %d", tasks[i].name, &tasks[i].priority);
    }

    printf("Enter burst times for each task:\n");
    for(int i=0; i<num_tasks; i++) {
        scanf("%d", &tasks[i].burst_time);
    }

    schedule_tasks(tasks, num_tasks);

    for(int i=0; i<num_tasks; i++) {
        execute_task(&tasks[i]);
    }

    return 0;
}