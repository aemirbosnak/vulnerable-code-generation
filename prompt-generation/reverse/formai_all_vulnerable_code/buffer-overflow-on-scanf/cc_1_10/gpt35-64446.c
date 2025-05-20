//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define INTERVAL 10

struct task {
    int id;
    int time_remaining;
};

void add_task(struct task *tasks, int *num_tasks);
void remove_task(struct task *tasks, int *num_tasks, int id);
void print_tasks(struct task *tasks, int num_tasks);
void run_tasks(struct task *tasks, int num_tasks);

int main() {
    srand(time(NULL)); // seed random number generator

    struct task tasks[MAX_TASKS];
    int num_tasks = 0;
    char menu_choice;

    printf("Welcome to the Unique C Task Scheduler!\n");

    do {
        printf("\nMain Menu\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Tasks\n");
        printf("4. Run Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &menu_choice);

        switch(menu_choice) {
            case '1':
                add_task(tasks, &num_tasks);
                break;
            case '2':
                if(num_tasks == 0) {
                    printf("There are no tasks to remove.\n");
                } else {
                    int task_id;
                    printf("Enter task ID to remove: ");
                    scanf("%d", &task_id);
                    remove_task(tasks, &num_tasks, task_id);
                }
                break;
            case '3':
                if(num_tasks == 0) {
                    printf("There are no tasks to view.\n");
                } else {
                    print_tasks(tasks, num_tasks);
                }
                break;
            case '4':
                if(num_tasks == 0) {
                    printf("There are no tasks to run.\n");
                } else {
                    run_tasks(tasks, num_tasks);
                }
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
        }
    } while(menu_choice != '5');

    return 0;
}

void add_task(struct task *tasks, int *num_tasks) {
    if(*num_tasks == MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
    } else {
        int time = rand() % 10 + 1; // generate random time between 1 and 10
        struct task new_task = {.id = (*num_tasks)+1, .time_remaining = time};
        tasks[*num_tasks] = new_task;
        printf("Task %d has been added with a run time of %d.\n", new_task.id, new_task.time_remaining);
        (*num_tasks)++;
    }
}

void remove_task(struct task *tasks, int *num_tasks, int id) {
    int i;
    for(i = 0; i < *num_tasks; i++) {
        if(tasks[i].id == id) {
            // shift all tasks after removed task down one index
            for(int j = i; j < *num_tasks-1; j++) {
                tasks[j] = tasks[j+1];
            }
            (*num_tasks)--;
            printf("Task %d has been removed.\n", id);
            return;
        }
    }
    printf("Task %d not found.\n", id);
}

void print_tasks(struct task *tasks, int num_tasks) {
    printf("Tasks:\n");
    for(int i = 0; i < num_tasks; i++) {
        printf("ID: %d | Time remaining: %d\n", tasks[i].id, tasks[i].time_remaining);
    }
}

void run_tasks(struct task *tasks, int num_tasks) {
    int time_passed = 0;
    int current_index = 0;
    while(num_tasks > 0) {
        if(tasks[current_index].time_remaining <= INTERVAL-time_passed) {
            time_passed += tasks[current_index].time_remaining;
            printf("Task %d has completed.\n", tasks[current_index].id);
            remove_task(tasks, &num_tasks, tasks[current_index].id);
            current_index = 0; // reset to beginning of task list
        } else {
            tasks[current_index].time_remaining -= INTERVAL-time_passed;
            time_passed = INTERVAL;
            printf("Task %d is still running. Time remaining: %d\n", tasks[current_index].id, tasks[current_index].time_remaining);
            current_index++;
        }
        if(current_index == num_tasks) {
            current_index = 0; // reset to beginning of task list
        }
        printf("Interval has ended. Time passed: %d\n", time_passed);
        printf("--------------------\n");
    }
}