//FormAI DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Task1()
{
    printf("This is the first task.\n");
}

void Task2()
{
    printf("This is the second task.\n");
}

void Task3()
{
    printf("This is the third task.\n");
}

typedef struct Task
{
    void (*task_func)();
    int task_interval;
    int next_run_time;
} Task;

Task tasks[] = {
    {Task1, 5, 0},
    {Task2, 2, 0},
    {Task3, 10, 0}
};

int main()
{
    int num_tasks = sizeof(tasks) / sizeof(Task);

    while (1)
    {
        for (int i = 0; i < num_tasks; i++)
        {
            if (time(NULL) >= tasks[i].next_run_time)
            {
                tasks[i].task_func();
                tasks[i].next_run_time = time(NULL) + tasks[i].task_interval;
            }
        }
        sleep(1);
    }

    return 0;
}