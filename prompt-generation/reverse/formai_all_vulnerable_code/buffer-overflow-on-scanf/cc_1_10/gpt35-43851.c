//FormAI DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

/* Task struct holding information about each task */
typedef struct task {
    int interval;
    char command[100];
    int execution_time;
} Task;

/* Array of tasks */
Task tasks[10];
int num_tasks = 0;

/* Function to handle SIGUSR1 signal */
void signal_handler(int signal) {
    int i;
    time_t now;

    /* Get current time */
    now = time(NULL);

    /* Loop through tasks and execute if necessary */
    for (i = 0; i < num_tasks; i++) {
        if ((now - tasks[i].execution_time) >= tasks[i].interval) {
            printf("Executing task: %s\n", tasks[i].command);
            system(tasks[i].command);
            tasks[i].execution_time = now;
        }
    }
}

int main() {
    int i;
    char command[100];
    int interval;
    time_t now;

    /* Add tasks */
    strcpy(tasks[0].command, "ls");
    tasks[0].interval = 10;
    tasks[0].execution_time = time(NULL);

    strcpy(tasks[1].command, "date");
    tasks[1].interval = 5;
    tasks[1].execution_time = time(NULL);

    num_tasks = 2;

    /* Register signal handler */
    signal(SIGUSR1, signal_handler);

    /* Loop forever */
    while (1) {
        printf("Enter command to add to task scheduler: ");
        scanf("%s", command);
        printf("Enter interval in seconds: ");
        scanf("%d", &interval);

        /* Add task */
        strcpy(tasks[num_tasks].command, command);
        tasks[num_tasks].interval = interval;
        tasks[num_tasks].execution_time = time(NULL);

        num_tasks++;

        /* Trigger signal to execute tasks */
        kill(getpid(), SIGUSR1);
    }

    return 0;
}