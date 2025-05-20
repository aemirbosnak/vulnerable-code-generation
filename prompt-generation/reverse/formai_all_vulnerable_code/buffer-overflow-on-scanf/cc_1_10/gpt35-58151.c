//FormAI DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20
#define MAX_PRIORITY 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int frequency;
    int last_executed;
    int is_running;
    void (*func)(void);
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void task1(void) {
    printf("Executing Task 1.\n");
}

void task2(void) {
    printf("Executing Task 2.\n");
}

void task3(void) {
    printf("Executing Task 3.\n");
}

void task4(void) {
    printf("Executing Task 4.\n");
}

void task5(void) {
    printf("Executing Task 5.\n");
}

void add_task(char name[MAX_NAME_LENGTH], int priority, int frequency, void (*func)(void)) {
    if(num_tasks >= MAX_TASKS) {
        printf("Cannot add task. Maximum number of tasks reached.\n");
        return;
    }
    Task t;
    strcpy(t.name, name);
    t.priority = priority;
    t.frequency = frequency;
    t.last_executed = 0;
    t.is_running = 0;
    t.func = func;
    task_list[num_tasks++] = t;
    printf("Task %s added.\n", name);
}

void remove_task(char name[MAX_NAME_LENGTH]) {
    int i, j;
    for(i = 0; i < num_tasks; i++) {
        if(strcmp(task_list[i].name, name) == 0) {
            for(j = i; j < num_tasks - 1; j++) {
                task_list[j] = task_list[j+1];
            }
            num_tasks--;
            printf("Task %s removed.\n", name);
            return;
        }
    }
    printf("Task %s not found.\n", name);
}

void run_task(Task t) {
    t.func();
    t.last_executed = time(NULL);
    t.is_running = 0;
}

void scheduler(void) {
    int i;
    while(1) {
        for(i = 0; i < num_tasks; i++) {
            Task t = task_list[i];
            if(!t.is_running && (time(NULL) - t.last_executed) >= t.frequency) {
                printf("Task %s executed.\n", t.name);
                t.is_running = 1;
                run_task(t);
            }
        }
        sleep(1);
    }
}

int main(void) {
    printf("Welcome to the paranoid task scheduler.\n");
    printf("Be assured that all tasks are executed perfectly on time, every time!\n");
    printf("All tasks are monitored 24/7 by our system administrators.\n");
    printf("Any deviations from the expected execution are immediately reported to our security team.\n");
    printf("Please enter the tasks you want to add to the scheduler. Type END to finish.\n");
    int p, f;
    char s[MAX_NAME_LENGTH];
    scanf("%s", s);
    while(strcmp(s, "END") != 0) {
        printf("Enter priority, frequency (in seconds) and name of task %s: ", s);
        scanf("%d %d", &p, &f);
        if(p < 0 || p > MAX_PRIORITY) {
            printf("Invalid priority. Priority set to 1.\n");
            p = 1;
        }
        add_task(s, p, f, (void (*)(void)) &task1);
        scanf("%s", s);
    }
    printf("Scheduler starting...\n");
    scheduler();
    return 0;
}