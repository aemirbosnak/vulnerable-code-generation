//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_INTERVAL 5 // in seconds

typedef struct task {
    int id;
    int interval;
    int next_time;
    void (*callback)();
} task;

task tasks[MAX_TASKS];
int task_count = 0;

pthread_mutex_t lock;


// Define your unique tasks here 
void task1_callback()
{
    printf("Task 1: Hello, World!\n");
}

void task2_callback()
{
    printf("Task 2: This is a task that executes every 3 seconds.\n");
}


// Function to add tasks to the scheduler
void add_task(int interval, void (*callback)())
{
    pthread_mutex_lock(&lock);

    // Check if maximum task limit has been reached
    if (task_count >= MAX_TASKS) {
        printf("Cannot add task. Maximum limit reached.\n");
        return;
    }

    // Add task to the task list
    task new_task;
    new_task.id = task_count;
    new_task.interval = interval;
    new_task.next_time = time(NULL) + interval;
    new_task.callback = callback;
    tasks[task_count] = new_task;

    printf("Task %d added.\n", task_count);

    task_count++;

    pthread_mutex_unlock(&lock);
}

// Function to remove tasks from the scheduler
void remove_task(int id)
{
    pthread_mutex_lock(&lock);

    // Find the task with given id
    int i;
    for (i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            // Shift all tasks present after this task one position back
            for (int j = i; j < task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            task_count--;
            printf("Task %d removed.\n", id);
            break;
        }
    }

    // Task with given id not found
    if (i == task_count) {
        printf("Task %d not found.\n", id);
    }

    pthread_mutex_unlock(&lock);
}

// Function to execute all tasks that have a timer that has reached or passed
void execute_tasks()
{
    pthread_mutex_lock(&lock);

    int current_time = time(NULL);

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].next_time <= current_time) {
            tasks[i].callback();
            tasks[i].next_time += tasks[i].interval;
        }
    }

    pthread_mutex_unlock(&lock);
}

// Thread function for the scheduler
void *scheduler_thread(void *args)
{
    while (1) {
        execute_tasks();
        sleep(1);
    }
}

int main()
{
    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    // Add example tasks
    add_task(3, task1_callback);
    add_task(5, task2_callback);

    // Start scheduler thread
    pthread_t scheduler_tid;
    pthread_create(&scheduler_tid, NULL, scheduler_thread, NULL);

    // Wait for user input to remove tasks
    int id;
    while (1) {
        printf("Enter task id to be removed (or -1 to exit): ");
        scanf("%d", &id);
        
        if (id == -1) {
            break;
        }

        remove_task(id);
    }

    // Stop scheduler thread
    pthread_cancel(scheduler_tid);

    // Destroy lock
    pthread_mutex_destroy(&lock);

    return 0;
}