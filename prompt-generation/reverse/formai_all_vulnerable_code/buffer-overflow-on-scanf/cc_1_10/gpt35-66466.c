//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Definition of the Task structure
typedef struct task
{
    char name[50];
    int priority;
    int time_to_complete;
} Task;

// Definition of the Scheduler structure
typedef struct scheduler
{
    Task* task_list;
    int num_tasks;
} Scheduler;

// Function to generate a random number between min and max
int rand_int(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to add a task to the scheduler
void add_task(Scheduler* scheduler, Task task)
{
    scheduler->task_list = (Task*)realloc(scheduler->task_list, (scheduler->num_tasks + 1) * sizeof(Task));
    scheduler->task_list[scheduler->num_tasks] = task;
    scheduler->num_tasks++;
}

// Function to print all the tasks in the scheduler
void print_tasks(Scheduler scheduler)
{
    printf("Tasks:\n");
    for (int i = 0; i < scheduler.num_tasks; i++)
    {
        printf("%s - Priority: %d - Time to complete: %d\n", scheduler.task_list[i].name, scheduler.task_list[i].priority, scheduler.task_list[i].time_to_complete);
    }
}

// Function to run the scheduler
void run_scheduler(Scheduler scheduler)
{
    printf("Starting Task Scheduler...\n");

    // Loop through all the tasks in priority order
    for (int priority = 1; priority <= 5; priority++)
    {
        for (int i = 0; i < scheduler.num_tasks; i++)
        {
            if (scheduler.task_list[i].priority == priority)
            {
                printf("Starting task %s...\n", scheduler.task_list[i].name);

                // Sleep for the time required to complete the task
                int time_to_sleep = scheduler.task_list[i].time_to_complete;
                printf("Task will take %d seconds to complete...\n", time_to_sleep);
                for (int j = time_to_sleep; j >= 1; j--)
                {
                    printf("%d seconds remaining...\n", j);
                    sleep(1);
                }

                printf("Task %s completed!\n", scheduler.task_list[i].name);
            }
        }
    }

    printf("All tasks have been completed.\n");
}

int main()
{
    time_t t;
    srand((unsigned)time(&t)); // Initialize random number generator

    printf("Welcome to the Post-Apocalyptic Task Scheduler!\n");
    printf("This scheduler will help you manage your tasks in a world ravaged by a global catastrophe.\n");
    printf("Enter the number of tasks to schedule: ");

    int num_tasks;
    scanf("%d", &num_tasks);
    getchar(); // Clear buffer

    Scheduler scheduler;
    scheduler.task_list = NULL;
    scheduler.num_tasks = 0;

    for (int i = 1; i <= num_tasks; i++)
    {
        printf("\nTask %d:\n", i);

        char task_name[50];
        printf("Enter task name: ");
        fgets(task_name, 50, stdin);
        task_name[strcspn(task_name, "\n")] = '\0'; // Remove newline character

        int priority = rand_int(1, 5);
        int time_to_complete = rand_int(10, 20);

        Task task;
        strcpy(task.name, task_name);
        task.priority = priority;
        task.time_to_complete = time_to_complete;

        add_task(&scheduler, task);

        printf("Task %s added to scheduler.\n", task.name);
    }

    print_tasks(scheduler);

    run_scheduler(scheduler);

    return 0;
}