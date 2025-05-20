//FormAI DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

// Declare function pointers for tasks
void task1(void);
void task2(void);
void task3(void);

int main()
{
    // Declare array of function pointers for tasks
    void (*tasks[3])(void) = {task1, task2, task3};
    
    int i, num_tasks, delay;
    
    // Get number of tasks and delay time from user
    printf("How many tasks do you want to schedule? ");
    scanf("%d", &num_tasks);
    
    printf("Enter the delay time (in seconds) between tasks: ");
    scanf("%d", &delay);
    
    // Schedule the tasks
    for(i=0; i<num_tasks; i++)
    {
        // Call the task
        (*tasks[i])();
        
        // Wait for specified delay time
        sleep(delay);
    }
    
    return 0;
}

// Task 1 prints a message to the console
void task1()
{
    printf("Task 1 running...\n");
}

// Task 2 prompts the user to enter a number and prints the square of the number
void task2()
{
    int num;
    printf("Task 2 running...\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The square of the number is %d.\n", num*num);
}

// Task 3 generates a random number and prints it to the console
void task3()
{
    int num = rand() % 100;
    printf("Task 3 running...\n");
    printf("The random number is %d.\n", num);
}