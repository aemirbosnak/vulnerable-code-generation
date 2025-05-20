//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_TASKS 5 // Define number of tasks

int task_counter = 0; // Initialize task counter

typedef struct task {
    char name[30];
    int priority;
    int duration;
} Task;

Task task_list[NUM_TASKS]; // Initialize task list

void add_task() {
    printf("\nEnter task name: ");
    scanf("%s", task_list[task_counter].name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &task_list[task_counter].priority);
    printf("Enter task duration in minutes: ");
    scanf("%d", &task_list[task_counter].duration);
    task_counter++;
}

void remove_task() {
    int task_index;
    printf("\nEnter the index of the task you want to remove: ");
    scanf("%d", &task_index);
    if(task_index >= 0 && task_index < task_counter) {
        for(int i=task_index; i<task_counter-1; i++) {
            task_list[i] = task_list[i+1];
        }
        task_counter--;
    }
    else {
        printf("Invalid index!");
    }
}

void display_tasks() {
    printf("\nTask List:\n");
    for(int i=0; i<task_counter; i++) {
        printf("%d. %s (Priority: %d, Duration: %d minutes)\n", i, task_list[i].name, task_list[i].priority, task_list[i].duration);
    }
}

void execute_task(Task t) {
    time_t start_time = time(NULL);
    printf("Starting task %s...\n", t.name);
    while(difftime(time(NULL), start_time) < t.duration) {
        // Do nothing (simulate task execution)
    }
    printf("Task %s completed!\n", t.name);
}

void schedule_tasks() {
    int executed_tasks = 0;
    while(executed_tasks < task_counter) {
        int next_task_index = -1;
        int max_priority = -1;
        for(int i=0; i<task_counter; i++) {
            if(task_list[i].priority > max_priority) {
                max_priority = task_list[i].priority;
                next_task_index = i;
            }
        }
        if(next_task_index != -1) {
            execute_task(task_list[next_task_index]);
            executed_tasks++;
            for(int i=next_task_index; i<task_counter-1; i++) {
                task_list[i] = task_list[i+1];
            }
            task_counter--;
        }
        else {
            printf("\nNo tasks left to execute!\n");
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nTask Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Schedule Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(NUM_TASKS == task_counter) {
                    printf("\nTask list full!\n");
                }
                else {
                    add_task();
                }
                break;
            case 2:
                if(task_counter == 0) {
                    printf("\nTask list is empty!\n");
                }
                else {
                    remove_task();
                }
                break;
            case 3:
                if(task_counter == 0) {
                    printf("\nTask list is empty!\n");
                }
                else {
                    display_tasks();
                }
                break;
            case 4:
                if(task_counter == 0) {
                    printf("\nTask list is empty!\n");
                }
                else {
                    schedule_tasks();
                }
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}