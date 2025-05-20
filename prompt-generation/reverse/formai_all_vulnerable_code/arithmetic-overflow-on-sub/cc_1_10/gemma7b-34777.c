//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Task1()
{
    printf("Task 1 started at: %s\n", time(NULL));
    sleep(5);
    printf("Task 1 completed at: %s\n", time(NULL));
}

void Task2()
{
    printf("Task 2 started at: %s\n", time(NULL));
    sleep(2);
    printf("Task 2 completed at: %s\n", time(NULL));
}

void Task3()
{
    printf("Task 3 started at: %s\n", time(NULL));
    sleep(3);
    printf("Task 3 completed at: %s\n", time(NULL));
}

int main()
{
    int i = 0;
    time_t start_time = time(NULL);

    // Simulate a busy loop to mimic task scheduling
    while (i < 10)
    {
        switch (i)
        {
            case 0:
                Task1();
                break;
            case 1:
                Task2();
                break;
            case 2:
                Task3();
                break;
            default:
                break;
        }

        i++;
    }

    time_t end_time = time(NULL);
    printf("Total time taken: %ld seconds\n", end_time - start_time);

    return 0;
}