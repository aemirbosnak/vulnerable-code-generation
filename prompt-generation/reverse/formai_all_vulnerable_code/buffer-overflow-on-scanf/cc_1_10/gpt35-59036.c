//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the maximum length of a task name
#define MAX_NAME_LENGTH 50

// Define the structure of a task
typedef struct Task
{
    char name[MAX_NAME_LENGTH];
    int priority;
    int duration; // in seconds
    time_t scheduled_time;
    bool is_completed;
} Task;

// Define the structure for the task list
typedef struct TaskList
{
    int task_count;
    Task tasks[MAX_TASKS];
} TaskList;

// Function to add a task to the list
void add_task(TaskList *tasks)
{
    if (tasks->task_count >= MAX_TASKS)
    {
        printf("Cannot add more tasks to the list\n");
        return;
    }

    Task new_task;
    printf("Enter the name of the task: ");
    fgets(new_task.name, MAX_NAME_LENGTH, stdin);
    printf("Enter the priority of the task (1-10): ");
    scanf("%d", &new_task.priority);
    printf("Enter the duration of the task in seconds: ");
    scanf("%d", &new_task.duration);
    new_task.is_completed = false;

    // Set the scheduled time to the current time
    new_task.scheduled_time = time(NULL);

    tasks->tasks[tasks->task_count] = new_task;
    tasks->task_count++;
}

// Function to print all the tasks in the list
void print_tasks(TaskList tasks)
{
    if(tasks.task_count == 0)
    {
        printf("No tasks in the list\n");
        return;
    }
    
    printf("Scheduled tasks: \n");
    printf("%-25s %-10s %-10s %-30s\n", "Task Name", "Priority", "Duration", "Scheduled Time");
    for (int i = 0; i < tasks.task_count; i++)
    {
        printf("%-25s %-10d %-10d %-30s", tasks.tasks[i].name, tasks.tasks[i].priority, tasks.tasks[i].duration, ctime(&tasks.tasks[i].scheduled_time));
    }
}

// Function to remove a completed task from the list
void remove_completed(TaskList *tasks)
{
    int completed_count = 0;
    for (int i = 0; i < tasks->task_count; i++)
    {
        if (tasks->tasks[i].is_completed)
        {
            completed_count++;
        }
        else
        {
            tasks->tasks[i - completed_count] = tasks->tasks[i];
        }
    }

    tasks->task_count -= completed_count;
}

// Function to run the task scheduler
void run_scheduler(TaskList *tasks)
{
    while (tasks->task_count > 0)
    {
        // Wait for 1 second
        sleep(1);

        // Update the scheduled time and check for task completion
        for (int i = 0; i < tasks->task_count; i++)
        {
            tasks->tasks[i].scheduled_time += 1;
            if (tasks->tasks[i].scheduled_time + tasks->tasks[i].duration <= time(NULL))
            {
                printf("Task \"%s\" completed\n", tasks->tasks[i].name);
                tasks->tasks[i].is_completed = true;
            }
        }

        // Remove completed tasks
        remove_completed(tasks);
    }

    printf("All tasks completed\n");
}

// Main function to test the task scheduler
int main()
{
    TaskList tasks = {0};

    printf("Welcome to the task scheduler\n");

    while (true)
    {
        printf("\nMenu:\n");
        printf("1 - Add a new task\n");
        printf("2 - Print all scheduled tasks\n");
        printf("3 - Run the task scheduler\n");
        printf("4 - Exit\n");
        printf("Enter your choice (1-4): ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_task(&tasks);
            break;

        case 2:
            print_tasks(tasks);
            break;

        case 3:
            run_scheduler(&tasks);
            break;

        case 4:
            printf("Exiting\n");
            exit(0);
            break;

        default:
            printf("Invalid choice. Try again\n");
        }
    }

    return 0;
}