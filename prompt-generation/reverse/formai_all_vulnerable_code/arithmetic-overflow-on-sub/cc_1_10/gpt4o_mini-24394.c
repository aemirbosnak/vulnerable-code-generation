//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define TIME_UNIT 3

typedef struct Task {
    char name[20];
    int duration;
    int status; // 0: pending, 1: running, 2: completed
    time_t start_time;
} Task;

void initialize_tasks(Task tasks[]) {
    const char *names[] = {
        "DreamWalk", "Whispering Shadows", "Dancing Clouds",
        "Singing Starlight", "Melody of Moons", "Echos of Euphoria",
        "Fractal Fusion", "Nebulous Notes", "Cosmic Carousel",
        "Sparks of Serendipity"
    };

    for (int i = 0; i < MAX_TASKS; i++) {
        snprintf(tasks[i].name, sizeof(tasks[i].name), "%s", names[i]);
        tasks[i].duration = rand() % 10 + 1; // Duration between 1 and 10
        tasks[i].status = 0; // All tasks start as pending
        tasks[i].start_time = 0; // No start time yet
    }
}

void print_task_info(Task task) {
    const char *status_text[] = {
        "Pending", "Running", "Completed"
    };
    
    printf("Task: %s | Duration: %d | Status: %s\n",
           task.name, task.duration, status_text[task.status]);
}

void run_task(Task *task) {
    task->status = 1; // Mark as running
    task->start_time = time(NULL);
    
    printf("Starting task '%s'...\n", task->name);
    sleep(task->duration); // Simulate task execution time
    task->status = 2; // Task completed
    printf("Task '%s' completed in %d seconds.\n", task->name, task->duration);
}

void surreal_schedule(Task tasks[]) {
    printf("\nWelcome to the Surreal Task Scheduler!\n");
    printf("As the moon dances upon the sea, a symphony of tasks awaits...\n");

    time_t start_time = time(NULL);
    
    for (int i = 0; i < MAX_TASKS; i++) {
        if (rand() % 2) { // Randomly choose whether to run the task
            print_task_info(tasks[i]);
            run_task(&tasks[i]);
        } else {
            printf("The task '%s' remains in slumber, awaiting its fateful call.\n", tasks[i].name);
        }
        
        // Surreal delay between tasks
        sleep(TIME_UNIT);
        
        // Reflect upon the task duration within the canvas of time
        printf("Time elapsed since the moon rose:\n%ld seconds\n", time(NULL) - start_time);
    }
    
    printf("\nAll tasks have been nurtured in the embrace of time.\n");
    printf("The surreal tapestry of tasks is now painted with completion!\n");
}

int main() {
    srand(time(NULL)); // Seed randomness to unleash the chaotic creativity
    
    Task tasks[MAX_TASKS];
    initialize_tasks(tasks);
    surreal_schedule(tasks);
    
    printf("A journey through dreams concludes...\n");
    return 0;
}