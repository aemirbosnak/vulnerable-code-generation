//FormAI DATASET v1.0 Category: Task Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define struct for task 
typedef struct {
    int id; // unique ID for each task
    int priority; // priority of the task
    int runtime; // time required to complete the task
} task;

int main() {
    int num_tasks; // number of tasks to be scheduled
    int total_runtime = 0; // total runtime of all tasks
    srand(time(0)); // set seed for random number generator
    
    // Get input for number of tasks
    printf("How many tasks do you want to schedule? ");
    scanf("%d", &num_tasks);
    
    // Create array of tasks with random runtime and priority
    task tasks[num_tasks];
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i+1;
        tasks[i].priority = rand() % 5 + 1; // priority ranges from 1 to 5
        tasks[i].runtime = rand() % 10 + 1; // runtime ranges from 1 to 10
        total_runtime += tasks[i].runtime; // add runtime to total
    }
    
    // Calculate time slices for each priority level
    int time_slices[5];
    for (int i = 0; i < 5; i++) {
        time_slices[i] = (total_runtime * (i+1)) / 15; // total time slices = 15 (arbitrary)
    }
    
    // Initialize variables for scheduling
    int current_time = 0;
    int next_priority = 0;
    int time_slice_count[5] = {0};
    
    // Loop through each time slice until all tasks are complete
    while (current_time < total_runtime) {
        // Find task with highest priority that has not finished
        int chosen_task = -1;
        for (int i = next_priority; i < 5; i++) {
            for (int j = 0; j < num_tasks; j++) {
                if (tasks[j].priority == i+1 && tasks[j].runtime > 0) {
                    chosen_task = j;
                    next_priority = i;
                    break;
                }
            }
            if (chosen_task != -1) {
                break;
            }
        }
        // If no task is found with priority > next_priority, reset to lowest priority
        if (chosen_task == -1) {
            for (int k = 0; k < num_tasks; k++) {
                if (tasks[k].priority == 1 && tasks[k].runtime > 0) {
                    chosen_task = k;
                    next_priority = 0;
                    break;
                }
            }
        }
        // Update time slices and task runtime
        if (time_slice_count[tasks[chosen_task].priority-1] < time_slices[tasks[chosen_task].priority-1]) {
            tasks[chosen_task].runtime--;
            time_slice_count[tasks[chosen_task].priority-1]++;
        } else {
            // Time slice for priority level has been reached, move to next priority
            next_priority = tasks[chosen_task].priority;
            time_slice_count[tasks[chosen_task].priority-1] = 0;
        }
        // Update current time
        current_time++;
        // Print status update for each second of execution
        printf("Second %d: Task %d (Priority %d, Runtime %d)\n", current_time, tasks[chosen_task].id, tasks[chosen_task].priority, tasks[chosen_task].runtime);
    }
    // Print final status update
    printf("All tasks complete!\n");
    return 0;
}