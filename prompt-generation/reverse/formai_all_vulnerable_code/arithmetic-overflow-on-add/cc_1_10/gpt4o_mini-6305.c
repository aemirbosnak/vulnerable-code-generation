//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 32
#define TASK_EXECUTE_INTERVAL 2

typedef struct {
    char name[TASK_NAME_LEN];
    time_t next_run;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int interval);
void execute_task(Task *task);
void signal_handler(int sig);
void display_tasks();
void cleanup();

int main() {
    signal(SIGINT, signal_handler);
    
    printf("😱 Welcome to the C Task Scheduler! 😱\n");
    printf("------------------------------------------------\n");
    
    // Adding sample tasks
    add_task("Task 1", TASK_EXECUTE_INTERVAL);
    add_task("Task 2", TASK_EXECUTE_INTERVAL);
    add_task("Task 3", TASK_EXECUTE_INTERVAL);
    
    while (1) {
        time_t current_time = time(NULL);
        printf("\nCurrent time: %s", ctime(&current_time));
        printf("Upcoming tasks:\n");
        display_tasks();
        
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].next_run) {
                execute_task(&task_list[i]);
                task_list[i].next_run = current_time + TASK_EXECUTE_INTERVAL;
            }
        }
        
        sleep(1);
    }
    
    cleanup();
    
    return 0;
}

void add_task(const char *name, int interval) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, TASK_NAME_LEN);
        task_list[task_count].next_run = time(NULL) + interval;
        task_count++;
        printf("✅ Task \"%s\" added! Next run at %s", name, ctime(&task_list[task_count - 1].next_run));
    } else {
        printf("❌ Cannot add task \"%s\": Maximum tasks limit reached!\n", name);
    }
}

void execute_task(Task *task) {
    printf("🚀 Executing \"%s\" at %s", task->name, ctime(&task->next_run));
    // Simulate task execution delay
    sleep(1);
    printf("✅ Task \"%s\" executed successfully!\n", task->name); 
}

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\n⚠️  Interrupt signal received! Cleaning up...\n");
        cleanup();
        exit(0);
    }
}

void display_tasks() {
    if (task_count == 0) {
        printf("😱 No tasks to display!\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("- %s (Next Run: %s)", task_list[i].name, ctime(&task_list[i].next_run));
    }
}

void cleanup() {
    printf("🧹 Cleaning up resources...\n");
    // Perform any cleanup needed
    printf("✅ Cleanup completed! Exiting...\n");
}