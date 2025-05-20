//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>

#define MAX_TASKS 10
#define NAME_LEN 32
#define TASK_INTERVAL 2   // Time in seconds between each task execution

typedef struct {
    char name[NAME_LEN];
    time_t next_run_time;
    void (*task_func)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t lock;

void nano_rain_task() {
    printf("Task: Nano Rain Routine - Simulating nano rain cleanup in the mega city...\n");
}

void neon_lights_task() {
    printf("Task: Neon Lights Sync - Syncing neon lights for optimal energy consumption...\n");
}

void data_heist_task() {
    printf("Task: Data Heist - Initiating digital incursion into corporate archives...\n");
}

void augment_human_task() {
    printf("Task: Augment Human Levels - Enhancing human performance augmentations...\n");
}

void schedule_task(char *name, void (*task_func)(void), int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Cannot schedule more tasks. Max limit reached!\n");
        return;
    }
    strcpy(task_list[task_count].name, name);
    task_list[task_count].task_func = task_func;
    task_list[task_count].next_run_time = time(NULL) + interval;
    task_count++;
}

void execute_task(Task *task) {
    task->task_func();
    task->next_run_time = time(NULL) + TASK_INTERVAL;  // Reset next run time
}

void *task_scheduler(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        time_t current_time = time(NULL);
        
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].next_run_time) {
                execute_task(&task_list[i]);
            }
        }
        pthread_mutex_unlock(&lock);
        sleep(1); // Scheduler runs every second
    }
    return NULL;
}

void initialize_scheduler() {
    pthread_mutex_init(&lock, NULL);
    schedule_task("Nano Rain Cleanup", nano_rain_task, TASK_INTERVAL);
    schedule_task("Neon Lights Sync", neon_lights_task, TASK_INTERVAL * 2);
    schedule_task("Corporate Data Heist", data_heist_task, TASK_INTERVAL * 3);
    schedule_task("Human Augmentation", augment_human_task, TASK_INTERVAL * 4);
}

void cleanup_scheduler() {
    pthread_mutex_destroy(&lock);
}

int main() {
    printf("Initializing Cyberpunk Task Scheduler...\n");
    initialize_scheduler();

    pthread_t scheduler_thread;
    if (pthread_create(&scheduler_thread, NULL, task_scheduler, NULL) != 0) {
        perror("Failed to create scheduler thread");
        exit(EXIT_FAILURE);
    }

    printf("Scheduler is running. Press Ctrl+C to stop.\n");
    
    // Wait for user to interrupt
    while(1) {
        pause();
    }

    // Cleanup
    cleanup_scheduler();
    return 0;
}