//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef enum {
    TASK_NONE,
    TASK_PRINT_HELLO,
    TASK_PRINT_TIME,
    TASK_SHUTDOWN
} TaskType;

typedef struct {
    int id;
    TaskType type;
    time_t scheduled_time;
} Task;

Task tasks[MAX_TASKS];
int next_task_id = 1;

void schedule_task(TaskType type, time_t scheduled_time) {
    if (next_task_id <= MAX_TASKS) {
        tasks[next_task_id - 1].id = next_task_id;
        tasks[next_task_id - 1].type = type;
        tasks[next_task_id - 1].scheduled_time = scheduled_time;
        next_task_id++;
    }
}

void execute_task(Task task) {
    switch (task.type) {
        case TASK_PRINT_HELLO:
            printf("Hello, world!\n");
            break;
        case TASK_PRINT_TIME:;
            time_t current_time = time(NULL);
            printf("Current time: %s", ctime(&current_time));
            break;
        case TASK_SHUTDOWN:
            printf("Shutting down...\n");
            exit(0);
            break;
        default:
            printf("Unknown task type.\n");
    }
}

void run_scheduler() {
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].id != 0 && tasks[i].scheduled_time <= current_time) {
                printf("Executing task %d...\n", tasks[i].id);
                execute_task(tasks[i]);
                tasks[i].id = 0;
            }
        }
        sleep(1);
    }
}

int main() {
    printf("Welcome to the Shape-Shifting Task Scheduler!\n");
    printf("Please enter the task you want to schedule:\n");
    printf("1 - Print 'Hello, world!'\n");
    printf("2 - Print the current time\n");
    printf("3 - Shut down the program\n");

    while (1) {
        int choice;
        time_t scheduled_time;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 3) {
            schedule_task(TASK_SHUTDOWN, time(NULL) + 3);
            break;
        }
        printf("Enter the time (in seconds from now) to schedule the task: ");
        scanf("%ld", &scheduled_time);
        switch (choice) {
            case 1:
                schedule_task(TASK_PRINT_HELLO, time(NULL) + scheduled_time);
                break;
            case 2:
                schedule_task(TASK_PRINT_TIME, time(NULL) + scheduled_time);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    run_scheduler();

    return 0;
}