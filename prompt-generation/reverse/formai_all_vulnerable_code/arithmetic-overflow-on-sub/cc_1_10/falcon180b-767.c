//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITIES 10

typedef struct task {
    int id;
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

typedef struct task_queue {
    Task tasks[MAX_TASKS];
    int size;
} TaskQueue;

int compare_priority(const void *a, const void *b) {
    Task *task_a = (Task *) a;
    Task *task_b = (Task *) b;
    return task_a->priority - task_b->priority;
}

void add_task(TaskQueue *queue) {
    int i = 0;
    while (i < MAX_TASKS && queue->size == MAX_TASKS) {
        i++;
    }
    if (i < MAX_TASKS) {
        printf("Enter task name: ");
        scanf("%s", queue->tasks[i].name);
        printf("Enter task priority: ");
        scanf("%d", &queue->tasks[i].priority);
        queue->size++;
    } else {
        printf("Task queue is full!\n");
    }
}

void remove_task(TaskQueue *queue, int id) {
    int i = 0;
    while (i < MAX_TASKS && queue->tasks[i].id!= id) {
        i++;
    }
    if (i < MAX_TASKS) {
        queue->size--;
        printf("Task %d removed!\n", id);
    } else {
        printf("Task not found!\n");
    }
}

void display_tasks(TaskQueue *queue) {
    printf("Task ID\t\tTask Name\tPriority\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        if (queue->tasks[i].id!= 0) {
            printf("%d\t\t%s\t\t%d\n", queue->tasks[i].id, queue->tasks[i].name, queue->tasks[i].priority);
        }
    }
}

void sort_tasks(TaskQueue *queue) {
    qsort(queue->tasks, queue->size, sizeof(Task), compare_priority);
}

void schedule_tasks(TaskQueue *queue) {
    time_t current_time = time(NULL);
    for (int i = 0; i < queue->size; i++) {
        if (queue->tasks[i].start_time == current_time) {
            printf("Task %s started at %s.\n", queue->tasks[i].name, ctime(&current_time));
            queue->tasks[i].end_time = current_time + queue->tasks[i].priority;
        } else if (queue->tasks[i].start_time + queue->tasks[i].priority == current_time) {
            printf("Task %s ended at %s.\n", queue->tasks[i].name, ctime(&current_time));
            queue->tasks[i].id = 0;
        }
    }
}

int main() {
    TaskQueue queue;
    queue.size = 0;
    srand(time(NULL));
    for (int i = 0; i < MAX_TASKS; i++) {
        queue.tasks[i].id = 0;
    }
    printf("Welcome to the Task Scheduler!\n");
    while (1) {
        printf("1. Add task\n2. Remove task\n3. Display tasks\n4. Schedule tasks\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_task(&queue);
                break;
            case 2:
                printf("Enter task ID to remove: ");
                int id;
                scanf("%d", &id);
                remove_task(&queue, id);
                break;
            case 3:
                display_tasks(&queue);
                break;
            case 4:
                sort_tasks(&queue);
                schedule_tasks(&queue);
                break;
            case 5:
                printf("Thank you for using the Task Scheduler!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}