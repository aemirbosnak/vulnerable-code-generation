//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct task {
    int id;         // Unique ID for each task
    int priority;   // Priority of the task (1-10)
    int time;       // Time needed to complete the task (in seconds)
    int status;     // Status of the task (0: incomplete, 1: complete)
    char name[100]; // Name of the task (max length: 100)
};

int current_task = -1;   // Index of currently running task
struct task tasks[100];  // Array to hold all tasks
int num_tasks = 0;       // Number of tasks currently in the array

// Adds a new task to the array
void add_task() {
    printf("Enter task name: ");
    scanf("%s", tasks[num_tasks].name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[num_tasks].priority);
    printf("Enter task time (in seconds): ");
    scanf("%d", &tasks[num_tasks].time);
    tasks[num_tasks].status = 0;
    tasks[num_tasks].id = num_tasks;
    num_tasks++;
}

// Runs the next task according to priority and time
// Returns the index of the task that was run, or -1 if no tasks are available
int run_task() {
    int max_priority = -1;
    int max_priority_idx = -1;
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].status == 0 && tasks[i].priority > max_priority) {
            max_priority = tasks[i].priority;
            max_priority_idx = i;
        }
    }
    if (max_priority_idx == -1) {
        return -1;
    }
    printf("\nRunning task %d: %s\n", tasks[max_priority_idx].id, tasks[max_priority_idx].name);
    tasks[max_priority_idx].status = 1;
    current_task = max_priority_idx;
    sleep(tasks[max_priority_idx].time);
    printf("Task %d: %s completed in %d seconds\n", tasks[max_priority_idx].id, tasks[max_priority_idx].name, tasks[max_priority_idx].time);
    current_task = -1;
    return max_priority_idx;
}

// Prints the status of all tasks
void print_tasks() {
    printf("--------------------------------------------------------\n");
    printf(" ID | Priority |    Time    |   Status   |    Name      \n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%3d | %8d | %10d | %10s | %s\n", tasks[i].id, tasks[i].priority, tasks[i].time, tasks[i].status == 0 ? "Incomplete" : "Complete", tasks[i].name);
    }
    printf("--------------------------------------------------------\n");
}

int main() {
    int choice = 0;
    while(choice != 4) {
        printf("\nScheduler Menu\n");
        printf("1. Add a new task\n");
        printf("2. Run the next task\n");
        printf("3. View all tasks\n");
        printf("4. Quit\n");

        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                if (run_task() == -1) {
                    printf("No tasks available!\n");
                }
                break;
            case 3:
                print_tasks();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}