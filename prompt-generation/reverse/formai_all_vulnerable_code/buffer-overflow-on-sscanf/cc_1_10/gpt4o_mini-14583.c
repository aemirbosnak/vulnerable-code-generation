//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int interval; // in seconds
    time_t next_run;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    strncpy(task_list[task_count].name, name, TASK_NAME_LENGTH);
    task_list[task_count].interval = interval;
    task_list[task_count].next_run = time(NULL) + interval;
    task_count++;
    printf("Task '%s' added with an interval of %d seconds.\n", name, interval);
}

void list_tasks() {
    if (task_count == 0) {
        printf("No scheduled tasks.\n");
        return;
    }
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf(" - %s (Next run: %s)\n", task_list[i].name, ctime(&task_list[i].next_run));
    }
}

void execute_task(const char* task_name) {
    printf("Executing task: %s\n", task_name);
}

void check_and_execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (current_time >= task_list[i].next_run) {
            execute_task(task_list[i].name);
            task_list[i].next_run = current_time + task_list[i].interval; // Resetting the next run time
        }
    }
}

void sigalrm_handler(int signo) {
    check_and_execute_tasks();
}

void setup_signal_handling() {
    struct sigaction sa;
    sa.sa_handler = sigalrm_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
}

int main() {
    setup_signal_handling();
    
    // Setup a periodic alarm every second
    ualarm(1000000, 1000000); // 1 second

    char command[100];
    char task_name[TASK_NAME_LENGTH];
    int interval;

    printf("Welcome to the Task Scheduler!\n");
    printf("Commands:\n");
    printf("1. add <task_name> <interval_in_seconds>\n");
    printf("2. list\n");
    printf("3. exit\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        
        if (sscanf(command, "add %s %d", task_name, &interval) == 2) {
            add_task(task_name, interval);
        } else if (strcmp(command, "list\n") == 0) {
            list_tasks();
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting the Task Scheduler. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}