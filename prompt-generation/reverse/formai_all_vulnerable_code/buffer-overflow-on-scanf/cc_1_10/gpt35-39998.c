//FormAI DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int id;
    int priority;
    int time_units;
    time_t arrival_time;
    struct task* next;
} Task;

Task* create_task(int id, int priority, int time_units) {
    Task* new_task = (Task*) malloc(sizeof(Task));
    new_task->id = id;
    new_task->priority = priority;
    new_task->time_units = time_units;
    new_task->arrival_time = time(NULL);
    new_task->next = NULL;
    return new_task;
}

void add_task(Task** task_list_ptr, Task* new_task) {
    if (!(*task_list_ptr)) {
        *task_list_ptr = new_task;
        printf("Task with ID %d added.\n", new_task->id);
    } else {
        Task* current_task = *task_list_ptr;
        Task* previous_task = NULL;
        while (current_task && new_task->priority <= current_task->priority) {
            previous_task = current_task;
            current_task = current_task->next;
        }
        if (previous_task) {
            previous_task->next = new_task;
            new_task->next = current_task;
            printf("Task with ID %d added.\n", new_task->id);
        } else {
            new_task->next = *task_list_ptr;
            *task_list_ptr = new_task;
            printf("Task with ID %d added.\n", new_task->id);
        }
    }
}

void remove_task(Task** task_list_ptr, int id) {
    if (!(*task_list_ptr)) {
        printf("Task with ID %d not found.\n", id);
    } else {
        Task* current_task = *task_list_ptr;
        Task* previous_task = NULL;
        while (current_task && id != current_task->id) {
            previous_task = current_task;
            current_task = current_task->next;
        }
        if (!current_task) {
            printf("Task with ID %d not found.\n", id);
        } else {
            if (previous_task) {
                previous_task->next = current_task->next;
                free(current_task);
                printf("Task with ID %d removed.\n", id);
            } else {
                *task_list_ptr = current_task->next;
                free(current_task);
                printf("Task with ID %d removed.\n", id);
            }
        }
    }
}

void print_tasks(Task* task_list) {
    if (!task_list) {
        printf("Task list is empty.\n");
    } else {
        printf("ID\tPriority\tTime Units\tArrival Time\n");
        printf("--\t--------\t----------\t------------\n");
        while (task_list) {
            printf("%d\t%d\t\t%d\t\t%s", task_list->id, task_list->priority, task_list->time_units, ctime(&task_list->arrival_time));
            task_list = task_list->next;
        }
    printf("\n");
    }
}

void run_tasks(Task** task_list_ptr) {
    if (!(*task_list_ptr)) {
        printf("No tasks to run.\n");
    } else {
        int total_time_units = 0;
        Task* current_task = *task_list_ptr;
        while (current_task) {
            total_time_units += current_task->time_units;
            current_task = current_task->next;
        }
        printf("Running all tasks...\n");
        for (int i = 0; i < total_time_units; i++) {
            printf("Time unit: %d\n", i+1);
            current_task = *task_list_ptr;
            while (current_task) {
                if (current_task->time_units > 0) {
                    current_task->time_units--;
                    printf("Task with ID %d is running...\n", current_task->id);
                }
                current_task = current_task->next;
            }
        }
        printf("All tasks have been completed.\n");
        current_task = *task_list_ptr;
        while (current_task) {
            Task* temp_task = current_task;
            current_task = current_task->next;
            free(temp_task);
        }
        *task_list_ptr = NULL;
    }
}

int main() {
    Task* task_list = NULL;
    int option, id, priority, time_units;
    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Add a task\n");
        printf("2. Remove a task\n");
        printf("3. Print all tasks\n");
        printf("4. Run all tasks\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter task ID: ");
                scanf("%d", &id);
                printf("Enter task priority: ");
                scanf("%d", &priority);
                printf("Enter task time units: ");
                scanf("%d", &time_units);
                add_task(&task_list, create_task(id, priority, time_units));
                break;
            case 2:
                printf("Enter task ID: ");
                scanf("%d", &id);
                remove_task(&task_list, id);
                break;
            case 3:
                print_tasks(task_list);
                break;
            case 4:
                run_tasks(&task_list);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}