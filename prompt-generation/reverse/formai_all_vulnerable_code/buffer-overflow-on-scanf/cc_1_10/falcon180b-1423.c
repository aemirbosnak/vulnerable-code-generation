//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    void (*func)(void *);
    void *arg;
};

void *execute_task(void *task) {
    struct task *t = (struct task *) task;
    printf("Executing task: %s with priority %d\n", t->name, t->priority);
    t->func(t->arg);
    return NULL;
}

int main() {
    pthread_t thread_id[MAX_TASKS];
    struct task tasks[MAX_TASKS];

    int choice, i = 0;

    do {
        printf("\n\nTask Scheduler Menu\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Display tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(i >= MAX_TASKS) {
                    printf("Maximum number of tasks reached\n");
                } else {
                    printf("Enter task name: ");
                    scanf("%s", tasks[i].name);
                    printf("Enter task priority: ");
                    scanf("%d", &tasks[i].priority);
                    printf("Enter task function: ");
                    scanf("%p", &tasks[i].func);
                    printf("Enter task argument: ");
                    scanf("%p", &tasks[i].arg);
                    pthread_create(&thread_id[i], NULL, execute_task, (void *) &tasks[i]);
                    i++;
                }
                break;

            case 2:
                if(i == 0) {
                    printf("No tasks to remove\n");
                } else {
                    printf("Enter task index to remove: ");
                    scanf("%d", &choice);
                    if(choice >= 0 && choice < i) {
                        pthread_cancel(thread_id[choice]);
                        i--;
                    } else {
                        printf("Invalid task index\n");
                    }
                }
                break;

            case 3:
                printf("Task Name\tPriority\tFunction\tArgument\n");
                for(int j=0; j<i; j++) {
                    printf("%s\t%d\t%p\t%p\n", tasks[j].name, tasks[j].priority, tasks[j].func, tasks[j].arg);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while(1);

    return 0;
}