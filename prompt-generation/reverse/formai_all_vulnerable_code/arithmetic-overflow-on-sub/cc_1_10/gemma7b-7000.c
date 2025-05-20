//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void task_a(void)
{
    printf("Task A started at: %s\n", time(NULL));
    sleep(5);
    printf("Task A completed at: %s\n", time(NULL));
}

void task_b(void)
{
    printf("Task B started at: %s\n", time(NULL));
    sleep(3);
    printf("Task B completed at: %s\n", time(NULL));
}

void task_c(void)
{
    printf("Task C started at: %s\n", time(NULL));
    sleep(2);
    printf("Task C completed at: %s\n", time(NULL));
}

int main()
{
    int i = 0;
    time_t start_time = time(NULL);

    // Schedule tasks
    for (i = 0; i < 3; i++)
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
    }

    // Print end time
    printf("Total time taken: %ld seconds\n", time(NULL) - start_time);

    return 0;
}