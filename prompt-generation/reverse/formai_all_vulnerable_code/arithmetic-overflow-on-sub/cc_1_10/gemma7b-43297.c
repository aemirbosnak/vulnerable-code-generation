//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task_a()
{
    printf("Task A is running...\n");
    sleep(2);
    printf("Task A has finished.\n");
}

void task_b()
{
    printf("Task B is running...\n");
    sleep(2);
    printf("Task B has finished.\n");
}

void task_c()
{
    printf("Task C is running...\n");
    sleep(2);
    printf("Task C has finished.\n");
}

int main()
{
    int i = 0;
    time_t start_time = time(NULL);
    while (i < 3)
    {
        switch (i)
        {
            case 0:
                task_a();
                break;
            case 1:
                task_b();
                break;
            case 2:
                task_c();
                break;
        }
        i++;
        time_t end_time = time(NULL);
        printf("Time taken for task %d: %ld seconds\n", i, end_time - start_time);
        start_time = end_time;
    }

    return 0;
}