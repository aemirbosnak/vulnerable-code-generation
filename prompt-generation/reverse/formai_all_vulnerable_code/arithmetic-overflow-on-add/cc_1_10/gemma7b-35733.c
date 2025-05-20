//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task
{
    char *name;
    time_t start_time;
    time_t end_time;
    struct Task *next;
} Task;

void add_task(Task **head, char *name, time_t start_time, time_t end_time)
{
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (*head == NULL)
    {
        *head = new_task;
    }
    else
    {
        (*head)->next = new_task;
    }
}

void check_scheduler(Task *head)
{
    time_t now = time(NULL);
    Task *current_task = head;

    while (current_task)
    {
        if (now >= current_task->start_time && now < current_task->end_time)
        {
            printf("%s is running!\n", current_task->name);
        }
        current_task = current_task->next;
    }
}

int main()
{
    Task *scheduler = NULL;

    add_task(&scheduler, "Task 1", time(NULL) + 60, time(NULL) + 90);
    add_task(&scheduler, "Task 2", time(NULL) + 30, time(NULL) + 60);
    add_task(&scheduler, "Task 3", time(NULL) + 10, time(NULL) + 40);

    check_scheduler(scheduler);

    return 0;
}