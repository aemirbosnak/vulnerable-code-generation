//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 1024
#define NUM_TASKS 5

typedef struct {
    char name[32];
    int difficulty;
    int completed;
} task_t;

task_t tasks[NUM_TASKS] = {
    {"Fix memory leak in driver", 7, 0},
    {"Add support for new device", 5, 0},
    {"Optimize CPU scheduler", 9, 0},
    {"Add support for new file system", 8, 0},
    {"Fix race condition in network stack", 6, 0}
};

void print_tasks() {
    int i;
    printf("\nCurrent tasks:\n");
    for (i = 0; i < NUM_TASKS; i++) {
        if (!tasks[i].completed) {
            printf("%d. %s (difficulty: %d)\n", i + 1, tasks[i].name, tasks[i].difficulty);
        }
    }
}

void complete_task(int task_num) {
    if (task_num < 1 || task_num > NUM_TASKS || tasks[task_num - 1].completed) {
        printf("\nInvalid task number or task already completed.\n");
        return;
    }

    tasks[task_num - 1].completed = 1;
    printf("\nTask %s completed.\n", tasks[task_num - 1].name);
}

int main() {
    int i, rand_num;
    char command[MAX_LINE];
    srand(time(NULL));

    printf("\nWelcome, Linus! You are a kernel developer.\n");
    print_tasks();

    while (1) {
        printf("\n%s> ", "kernel");
        fgets(command, MAX_LINE, stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "quit") == 0) {
            printf("\nGoodbye!\n");
            return 0;
        } else if (strcmp(command, "tasks") == 0) {
            print_tasks();
        } else if (sscanf(command, "complete %d", &i) == 1) {
            complete_task(i);
            print_tasks();
        } else {
            printf("\nInvalid command.\n");
        }

        if (tasks[rand() % NUM_TASKS].completed) {
            rand_num = rand() % NUM_TASKS;
            while (tasks[rand_num].completed) {
                rand_num = rand() % NUM_TASKS;
            }
            printf("\nSudden bug report! A new task has appeared: %s\n", tasks[rand_num].name);
            tasks[rand_num].completed = 0;
        }
    }

    return 0;
}