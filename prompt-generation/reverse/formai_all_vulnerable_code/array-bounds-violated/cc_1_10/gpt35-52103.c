//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define task structure
typedef struct {
    int id;
    int execution_time;
    int period;
    int priority;
    int start_time;
    int deadline;
    int remaining_time;
} Task;

// Define the number of tasks and the hyperperiod
#define NUM_TASKS 4
#define HYPERPERIOD 12

// Define global variables for tasks and the ready queue
Task tasks[NUM_TASKS];
Task readyQueue[NUM_TASKS];

// Function to initialize the tasks with random parameters
void initTasks() {
    srand(time(NULL));

    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].execution_time = rand() % 4 + 1;
        tasks[i].period = rand() % 5 + 1;
        tasks[i].priority = rand() % 3 + 1;
        tasks[i].start_time = rand() % tasks[i].period;
        tasks[i].deadline = tasks[i].start_time + tasks[i].period;
        tasks[i].remaining_time = tasks[i].execution_time;
    }
}

// Function to print the current state of the tasks
void printTasks() {
    printf("ID\tExec\tPeriod\tPriority\tStart\tDeadline\tRem. Time\n");

    for (int i = 0; i < NUM_TASKS; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n", tasks[i].id, tasks[i].execution_time, tasks[i].period, tasks[i].priority, tasks[i].start_time, tasks[i].deadline, tasks[i].remaining_time);
    }
}

// Function to insert a task into the ready queue based on priority
void insertTask(Task task) {
    int i;

    for (i = 0; i < NUM_TASKS; i++) {
        if (readyQueue[i].id == -1 || task.priority > readyQueue[i].priority) {
            break;
        }
    }

    for (int j = NUM_TASKS - 1; j > i; j--) {
        readyQueue[j] = readyQueue[j - 1];
    }

    readyQueue[i] = task;
}

// Function to check if a task is ready to execute based on start time and deadline
int taskReady(Task task, int time) {
    return (time >= task.start_time && time <= task.deadline);
}

// Function to execute a task and update its remaining time and deadline
int executeTask(Task task, int time) {
    if (task.remaining_time > 0) {
        printf("Executing task %d at time %d\n", task.id, time);
        task.remaining_time--;

        if (task.remaining_time == 0) {
            task.deadline += task.period;
            task.remaining_time = task.execution_time;
        }
    }

    return task.remaining_time;
}

// Function to simulate the task scheduler
void runScheduler() {
    int time = 0;

    // Loop through each time slice up to the hyperperiod
    for (int i = 0; i < HYPERPERIOD; i++) {
        printf("Time: %d\n", time);

        // Loop through each task and check if it is ready to execute
        for (int j = 0; j < NUM_TASKS; j++) {
            if (taskReady(tasks[j], time)) {
                insertTask(tasks[j]);
            }
        }

        // Loop through the ready queue and execute each task
        for (int j = 0; j < NUM_TASKS; j++) {
            if (readyQueue[j].id != -1) {
                readyQueue[j].remaining_time = executeTask(readyQueue[j], time);
            }
        }

        // Print the current state of the ready queue
        printf("Ready Queue: ");
        for (int j = 0; j < NUM_TASKS; j++) {
            if (readyQueue[j].id != -1) {
                printf("%d ", readyQueue[j].id);
            }
        }
        printf("\n");

        // Increment the time
        time++;
        printf("\n");
    }
}

// Main function to initialize tasks, print their initial state, and run the task scheduler
int main() {
    // Initialize tasks and ready queue to -1
    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = -1;
        readyQueue[i].id = -1;
    }

    // Initialize tasks and print their initial state
    initTasks();
    printf("Initial Tasks:\n");
    printTasks();

    // Run the task scheduler
    printf("\nRunning Scheduler:\n");
    runScheduler();

    return 0;
}