//FormAI DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define TASK_COUNT 10

struct task {
    int id;
    int priority;
    int interval;
    time_t last_executed;
    void (*function)();
};

struct task g_tasks[TASK_COUNT];

void task1()
{
    printf("Task 1: Executed\n");
}

void task2()
{
    printf("Task 2: Executed\n");
}

void task3()
{
    printf("Task 3: Executed\n");
}

void task4()
{
    printf("Task 4: Executed\n");
}

void task5()
{
    printf("Task 5: Executed\n");
}

void init_tasks()
{
    g_tasks[0] = (struct task){ .id = 1, .priority = 1, .interval = 2, .last_executed = 0, .function = task1 };
    g_tasks[1] = (struct task){ .id = 2, .priority = 2, .interval = 5, .last_executed = 0, .function = task2 };
    g_tasks[2] = (struct task){ .id = 3, .priority = 3, .interval = 1, .last_executed = 0, .function = task3 };
    g_tasks[3] = (struct task){ .id = 4, .priority = 4, .interval = 4, .last_executed = 0, .function = task4 };
    g_tasks[4] = (struct task){ .id = 5, .priority = 5, .interval = 3, .last_executed = 0, .function = task5 };
}

int select_task_index()
{
    int i;
    int selected = -1;

    for (i = 0; i < TASK_COUNT; i++) {
        if ((time(NULL) - g_tasks[i].last_executed) >= g_tasks[i].interval) {
            if (selected == -1 || g_tasks[i].priority < g_tasks[selected].priority) {
                selected = i;
            }
        }
    }

    return selected;
}

void execute_task(int index)
{
    if (index >= 0 && index < TASK_COUNT) {
        g_tasks[index].function();
        g_tasks[index].last_executed = time(NULL);
    }
}

int main()
{
    init_tasks();

    int i;
    for (i = 0; i < 20; i++) {
        int selected_task = select_task_index();
        execute_task(selected_task);
        sleep(1);
    }

    return 0;
}