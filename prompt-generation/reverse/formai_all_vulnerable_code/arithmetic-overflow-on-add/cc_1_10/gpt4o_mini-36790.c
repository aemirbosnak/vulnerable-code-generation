//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_DESC_LEN 100

typedef struct Task {
    char description[MAX_DESC_LEN];
    time_t execute_time;
} Task;

typedef struct TaskScheduler {
    Task tasks[MAX_TASKS];
    int count;
} TaskScheduler;

// Function to initialize the task scheduler
void initialize_scheduler(TaskScheduler* scheduler) {
    scheduler->count = 0;
    printf("🎉 Welcome to your joyful Task Scheduler! 🎉\n");
}

// Function to add a task to the scheduler
void add_task(TaskScheduler* scheduler) {
    if (scheduler->count >= MAX_TASKS) {
        printf("😱 Oops! Task limit reached. Can't add more tasks!\n");
        return;
    }

    Task new_task;
    printf("📝 Enter task description: ");
    scanf(" %[^\n]", new_task.description);

    printf("⏰ When would you like to execute this task? (Enter the time in seconds from now): ");
    int delay;
    scanf("%d", &delay);
    new_task.execute_time = time(NULL) + delay;

    scheduler->tasks[scheduler->count++] = new_task;

    printf("🎈 Task '%s' has been scheduled for execution in %d seconds! 🎈\n", 
           new_task.description, delay);
}

// Function to execute the tasks
void execute_tasks(TaskScheduler* scheduler) {
    time_t now;
    for (int i = 0; i < scheduler->count; i++) {
        now = time(NULL);
        if (now >= scheduler->tasks[i].execute_time) {
            printf("🎊 Executing Task: %s 🎊\n", scheduler->tasks[i].description);
            // Shift remaining tasks down
            for (int j = i; j < scheduler->count - 1; j++) {
                scheduler->tasks[j] = scheduler->tasks[j + 1];
            }
            scheduler->count--;
            i--; // Move back to account for the removed task
        }
    }
}

// Function to display all tasks
void display_tasks(TaskScheduler* scheduler) {
    if (scheduler->count == 0) {
        printf("💤 No scheduled tasks! You can add some! 💤\n");
        return;
    }

    printf("\nHere are your scheduled tasks:\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("- Task %d: '%s' scheduled for execution at %s",
               i + 1, scheduler->tasks[i].description,
               ctime(&scheduler->tasks[i].execute_time));
    }
}

int main() {
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);
    
    while (1) {
        printf("\n🌟 Task Scheduler Menu 🌟\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Display Scheduled Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task(&scheduler);
                break;
            case 2:
                execute_tasks(&scheduler);
                break;
            case 3:
                display_tasks(&scheduler);
                break;
            case 4:
                printf("👋 Goodbye! Have a wonderful day! 👋\n");
                exit(0);
            default:
                printf("❗ Invalid choice! Please choose again! ❗\n");
        }

        // Simulating the passage of time
        sleep(1);
    }
    
    return 0;
}