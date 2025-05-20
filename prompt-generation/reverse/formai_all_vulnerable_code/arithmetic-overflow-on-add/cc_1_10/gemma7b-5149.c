//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* scheduler_insert(Task* head, char* name, time_t start, time_t end)
{
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->start_time = start;
    new_task->end_time = end;
    new_task->next = NULL;

    if (head == NULL)
    {
        head = new_task;
    }
    else
    {
        Task* tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new_task;
    }

    return head;
}

void scheduler_print(Task* head)
{
    while (head)
    {
        printf("%s, start: %d, end: %d\n", head->name, head->start_time, head->end_time);
        head = head->next;
    }
}

int main()
{
    time_t now = time(NULL);
    Task* head = NULL;

    // Insert tasks into the scheduler
    scheduler_insert(head, "Scavenge for food", now + 3600, now + 4320);
    scheduler_insert(head, "Repair weapons", now + 4320, now + 5040);
    scheduler_insert(head, "Fortify shelter", now + 5040, now + 5760);

    // Print the scheduled tasks
    scheduler_print(head);

    return 0;
}