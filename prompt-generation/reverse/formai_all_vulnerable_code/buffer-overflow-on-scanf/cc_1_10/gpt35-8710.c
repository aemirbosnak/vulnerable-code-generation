//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_TASKS 5

typedef struct {
    char* task_name;
    int priority;
    int execution_time;
} task;

void task_execution(task t) {
    printf("Executing task %s for %d seconds with priority %d\n", t.task_name, t.execution_time, t.priority);
    clock_t start_time = clock();
    while((clock() - start_time) < (t.execution_time * CLOCKS_PER_SEC));
}

int main() {
    task task_queue[MAX_TASKS];
    int queue_size = 0;

    printf("Welcome to the Task Scheduler Program\n");
    printf("-------------------------------------\n");

    while(true) {
        printf("Select an option:\n");
        printf("1. Add a task\n");
        printf("2. Remove a task\n");
        printf("3. Execute tasks\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(queue_size == MAX_TASKS) {
                    printf("Task queue is full\n");
                    break;
                }

                task t;
                t.task_name = (char*) malloc(sizeof(char)*20);
                printf("Enter task name:\n");
                scanf("%s", t.task_name);
                printf("Enter task priority (1-10):\n");
                scanf("%d", &t.priority);
                printf("Enter task execution time (in seconds):\n");
                scanf("%d", &t.execution_time);
                
                task_queue[queue_size++] = t;
                break;
            }

            case 2: {
                if(queue_size == 0) {
                    printf("Task queue is empty\n");
                    break;
                }

                printf("Enter task index to remove:\n");
                int idx;
                scanf("%d", &idx);

                if(idx < 0 || idx >= queue_size) {
                    printf("Invalid index\n");
                    break;
                }

                for(int i=idx; i<(queue_size-1); i++)
                    task_queue[i] = task_queue[i+1];

                queue_size--;
                break;
            }

            case 3: {
                if(queue_size == 0) {
                    printf("Task queue is empty\n");
                    break;
                }

                while(queue_size > 0) {
                    int highest_priority_task = 0;
                    for(int i=0; i<queue_size; i++) {
                        if(task_queue[highest_priority_task].priority < task_queue[i].priority)
                            highest_priority_task = i;
                    }
                    task t = task_queue[highest_priority_task];
                    task_execution(t);

                    for(int i=highest_priority_task; i<(queue_size-1); i++)
                        task_queue[i] = task_queue[i+1];

                    queue_size--;
                }
                break;
            }

            case 4: {
                printf("Thank you for using Task Scheduler Program\n");
                exit(0);
            }

            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}