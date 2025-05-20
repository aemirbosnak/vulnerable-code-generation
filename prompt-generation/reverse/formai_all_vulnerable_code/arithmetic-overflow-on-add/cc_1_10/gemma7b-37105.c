//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task
{
    char name[20];
    int priority;
    time_t scheduled_time;
} Task;

Task tasks[MAX_TASKS];

void schedule_task(char *name, int priority, time_t scheduled_time)
{
    for (int i = 0; i < MAX_TASKS; i++)
    {
        if (tasks[i].name == NULL)
        {
            strcpy(tasks[i].name, name);
            tasks[i].priority = priority;
            tasks[i].scheduled_time = scheduled_time;
            return;
        }
    }

    printf("Error: No more tasks can be scheduled.\n");
}

void print_tasks()
{
    for (int i = 0; i < MAX_TASKS; i++)
    {
        if (tasks[i].name)
        {
            printf("Name: %s, Priority: %d, Scheduled Time: %ld\n", tasks[i].name, tasks[i].priority, tasks[i].scheduled_time);
        }
    }
}

int main()
{
    schedule_task("Task 1", 1, time(NULL) + 60);
    schedule_task("Task 2", 2, time(NULL) + 30);
    schedule_task("Task 3", 3, time(NULL) + 15);

    print_tasks();

    return 0;
}