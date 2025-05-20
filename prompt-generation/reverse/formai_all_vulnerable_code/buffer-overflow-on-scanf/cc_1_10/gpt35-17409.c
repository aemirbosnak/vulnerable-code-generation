//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50

typedef struct Task {
    char name[MAX_NAME_LENGTH];
    int priority;
    int time_required;
    bool done;
} Task;

int get_random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void print_task(Task task) {
    printf("Task name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Time required (in minutes): %d\n", task.time_required);
    if (task.done) {
        printf("Task status: Done\n");
    } else {
        printf("Task status: Not done\n");
    }
}

void run_task(Task *task) {
    printf("Running task %s...\n", task->name);
    //simulate task execution
    int execution_time = get_random_int(task->time_required / 2, task->time_required);
    printf("Task %s took %d minutes to complete.\n", task->name, execution_time);
    task->done = true;
}

int main() {
    //seed the random number generator
    srand(time(NULL));
    
    //initialize task array
    Task task_list[MAX_TASKS] = {
        {"Clean the house", 1, 60, false},
        {"Pay bills", 2, 30, false},
        {"Buy groceries", 3, 45, false},
        {"Work on project", 1, 120, false},
        {"Call mom", 4, 15, false},
        {"Read book", 5, 90, false},
        {"Exercise", 2, 60, false},
        {"Attend meeting", 4, 30, false},
        {"Write report", 3, 90, false},
        {"Take a nap", 5, 30, false}
    };
    
    //calculate total number of tasks
    int num_tasks = sizeof(task_list)/sizeof(Task);
    
    //print initial tasks
    printf("Initial task list:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s\n", i+1, task_list[i].name);
    }
    printf("\n");
    
    //prompt user for time available (in minutes)
    int time_available;
    printf("Enter time available (in minutes): ");
    scanf("%d", &time_available);
    printf("\n");
    
    //initialize variables for tracking time and completed tasks
    int time_elapsed = 0;
    int num_completed_tasks = 0;
    
    //main loop that runs until time is up or all tasks are done
    while (time_elapsed < time_available && num_completed_tasks < num_tasks) {
        //find highest priority task that is not done
        Task *highest_priority_task = NULL;
        for (int i = 0; i < num_tasks; i++) {
            if (!task_list[i].done && (highest_priority_task == NULL || task_list[i].priority < highest_priority_task->priority)) {
                highest_priority_task = &task_list[i];
            }
        }
        
        //if no tasks are available, break out of loop
        if (highest_priority_task == NULL) {
            break;
        }
        
        //run the task and update time and completed tasks
        run_task(highest_priority_task);
        time_elapsed += highest_priority_task->time_required;
        num_completed_tasks++;
        
        //print task details for completed task
        printf("\nTask %d details:\n", num_completed_tasks);
        print_task(*highest_priority_task);
        printf("\n");
    }
    
    //print summary of completed tasks and remaining time
    printf("Summary:\n");
    printf("%d tasks completed in %d minutes.\n", num_completed_tasks, time_elapsed);
    printf("%d tasks remaining.\n", num_tasks - num_completed_tasks);
    printf("Time remaining: %d minutes.\n", time_available - time_elapsed);
    
    return 0;
}