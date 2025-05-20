//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct task {
    char name[50];
    int priority;
    int duration;
};

void print_schedule(struct task *schedule, int num_tasks) {
    printf("Task\tPriority\tDuration\n");
    printf("----------------------------\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t\t%d\n", schedule[i].name, schedule[i].priority, schedule[i].duration);
    }
}

void sort_schedule(struct task *schedule, int num_tasks) {
    struct task temp;
    for (int i = 0; i < num_tasks-1; i++) {
        for (int j = i+1; j < num_tasks; j++) {
            if (schedule[i].priority < schedule[j].priority) {
                temp = schedule[i];
                schedule[i] = schedule[j];
                schedule[j] = temp;
            }
        }
    }
}

int main() {
    int num_tasks;
    printf("How many tasks do you have? ");
    scanf("%d", &num_tasks);

    struct task *schedule = malloc(num_tasks * sizeof(struct task));

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task name: ");
        scanf("%s", schedule[i].name);
        printf("Enter task priority: ");
        scanf("%d", &schedule[i].priority);
        printf("Enter task duration: ");
        scanf("%d", &schedule[i].duration);
    }

    printf("\nBefore schedule sorting:\n");
    print_schedule(schedule, num_tasks);

    sort_schedule(schedule, num_tasks);

    printf("\nAfter schedule sorting:\n");
    print_schedule(schedule, num_tasks);

    free(schedule);

    return 0;
}