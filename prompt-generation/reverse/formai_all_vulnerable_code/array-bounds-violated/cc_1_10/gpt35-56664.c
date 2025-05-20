//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time range
#define MIN_TIME 1
#define MAX_TIME 10

// Define the number of tasks to schedule
#define NUM_TASKS 5

// Define the maximum number of knights available
#define MAX_KNIGHTS 3

// Define the task names
#define TASK_NAME_1 "Defend Castle"
#define TASK_NAME_2 "Gather Resources"
#define TASK_NAME_3 "Train Recruits"
#define TASK_NAME_4 "Patrol the Realm"
#define TASK_NAME_5 "Deliver Message"

// Define the task priorities
#define TASK_PRIORITY_1 5
#define TASK_PRIORITY_2 3
#define TASK_PRIORITY_3 2
#define TASK_PRIORITY_4 4
#define TASK_PRIORITY_5 1

// Define the knight names
#define KNIGHT_NAME_1 "Sir Lancelot"
#define KNIGHT_NAME_2 "Sir Galahad"
#define KNIGHT_NAME_3 "Sir Gawain"

// Define the task struct
typedef struct task {
    char name[20];
    int priority;
    int time_required;
    int is_completed;
} Task;

// Define the knight struct
typedef struct knight {
    char name[20];
    int is_available;
    int task_on_hand;
} Knight;

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare an array of tasks
    Task tasks[NUM_TASKS] = {
        {TASK_NAME_1, TASK_PRIORITY_1, generate_random_number(MIN_TIME, MAX_TIME), 0},
        {TASK_NAME_2, TASK_PRIORITY_2, generate_random_number(MIN_TIME, MAX_TIME), 0},
        {TASK_NAME_3, TASK_PRIORITY_3, generate_random_number(MIN_TIME, MAX_TIME), 0},
        {TASK_NAME_4, TASK_PRIORITY_4, generate_random_number(MIN_TIME, MAX_TIME), 0},
        {TASK_NAME_5, TASK_PRIORITY_5, generate_random_number(MIN_TIME, MAX_TIME), 0}
    };

    // Declare an array of knights
    Knight knights[MAX_KNIGHTS] = {
        {KNIGHT_NAME_1, 1, -1},
        {KNIGHT_NAME_2, 1, -1},
        {KNIGHT_NAME_3, 1, -1}
    };

    // Schedule the tasks
    int num_completed_tasks = 0;

    while (num_completed_tasks < NUM_TASKS) {
        // Find the task with the highest priority that has not been completed
        int highest_priority = -1;
        int task_index = -1;

        for (int i = 0; i < NUM_TASKS; i++) {
            if (tasks[i].is_completed == 0 && tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                task_index = i;
            }
        }

        // Assign the task to an available knight
        int knight_index = -1;

        for (int i = 0; i < MAX_KNIGHTS; i++) {
            if (knights[i].is_available == 1) {
                knights[i].is_available = 0;
                knights[i].task_on_hand = task_index;
                knight_index = i;
                break;
            }
        }

        // Perform the task
        printf("%s is performing the task '%s' for %d hours\n", knights[knight_index].name, tasks[task_index].name, tasks[task_index].time_required);

        // Decrement the time required for the task
        tasks[task_index].time_required--;

        // Check if the task is completed
        if (tasks[task_index].time_required == 0) {
            tasks[task_index].is_completed = 1;
            num_completed_tasks++;
            knights[knight_index].is_available = 1;
            knights[knight_index].task_on_hand = -1;
            printf("%s has completed the task '%s'\n", knights[knight_index].name, tasks[task_index].name);
        }
    }

    printf("All tasks have been completed!\n");

    return 0;
}