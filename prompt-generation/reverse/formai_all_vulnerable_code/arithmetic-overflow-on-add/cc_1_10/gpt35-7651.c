//FormAI DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*func_ptr)(void);

/* Declaration of Tasks */
void task1(void);
void task2(void);
void task3(void);

/* Array of task function pointers */
func_ptr tasks[] = {task1, task2, task3};

/* Number of tasks */
#define NUM_TASKS (sizeof(tasks) / sizeof(func_ptr))

/* Delay function */
void delay(unsigned int msec)
{
    clock_t goal = msec + clock();
    while (goal > clock())
        ;
}

int main(void)
{
    while (1)
    {
        for (int i = 0; i < NUM_TASKS; i++)
        {
            tasks[i](); /* Execute the task */
            printf("Task %d executed at %ld\n", i+1, time(NULL));
            delay(1000); /* Delay for 1 second */
        }
    }

    return 0;
}

/* Task 1 */
void task1(void)
{
    printf("This is task 1\n");
}

/* Task 2 */
void task2(void)
{
    printf("This is task 2\n");
}

/* Task 3 */
void task3(void)
{
    printf("This is task 3\n");
}