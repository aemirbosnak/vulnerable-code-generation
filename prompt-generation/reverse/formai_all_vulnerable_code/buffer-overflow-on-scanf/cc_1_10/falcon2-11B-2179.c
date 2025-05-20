//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

struct task_data {
    char name[50];
    int priority;
    int duration;
};

struct task_data tasks[10];
int num_tasks = 0;

void display_tasks(void) {
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: %d\n", tasks[i].name, tasks[i].priority);
    }
}

int main(void) {
    srand(time(NULL));

    printf("Enter task name: ");
    fflush(stdin);
    scanf("%s", tasks[num_tasks].name);
    tasks[num_tasks].priority = rand() % 10 + 1;
    tasks[num_tasks].duration = rand() % 10 + 1;

    for (int i = num_tasks; i < 10; i++) {
        printf("Enter task name: ");
        fflush(stdin);
        scanf("%s", tasks[i].name);
        tasks[i].priority = rand() % 10 + 1;
        tasks[i].duration = rand() % 10 + 1;
    }

    printf("Enter task name: ");
    fflush(stdin);
    scanf("%s", tasks[num_tasks].name);
    tasks[num_tasks].priority = rand() % 10 + 1;
    tasks[num_tasks].duration = rand() % 10 + 1;

    printf("Enter task name: ");
    fflush(stdin);
    scanf("%s", tasks[num_tasks].name);
    tasks[num_tasks].priority = rand() % 10 + 1;
    tasks[num_tasks].duration = rand() % 10 + 1;

    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: %s, Priority: %d, Duration: %d\n", i + 1, tasks[i].name, tasks[i].priority, tasks[i].duration);
    }

    display_tasks();

    return 0;
}