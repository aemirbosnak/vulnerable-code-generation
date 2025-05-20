//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[20];
    int time;
} Task;

void prepareIngredients() {
    printf("Preparing ingredients...\n");
    sleep(3);
    printf("Done!\n");
}

void cookDish() {
    printf("Cooking dish...\n");
    sleep(5);
    printf("Done!\n");
}

void serveCustomer() {
    printf("Serving customer...\n");
    sleep(2);
    printf("Done!\n");
}

void cleanUp() {
    printf("Cleaning up...\n");
    sleep(4);
    printf("Done!\n");
}

void taskScheduler(Task taskList[], int n) {
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);
    int currentHour = currentTime->tm_hour;
    int currentMin = currentTime->tm_min;

    printf("Current time: %02d:%02d\n", currentHour, currentMin);

    for (int i = 0; i < n; i++) {
        int taskHour = currentHour;
        int taskMin = currentMin + taskList[i].time;

        if (taskMin >= 60) {
            taskHour++;
            taskMin = taskMin % 60;
        }

        printf("Task %d: %s at %02d:%02d\n", taskList[i].id, taskList[i].name, taskHour, taskMin);
        sleep(1);
    }
}

int main() {
    Task taskList[4];

    taskList[0].id = 1;
    strcpy(taskList[0].name, "Prepare ingredients");
    taskList[0].time = 5;

    taskList[1].id = 2;
    strcpy(taskList[1].name, "Cook dish");
    taskList[1].time = 10;

    taskList[2].id = 3;
    strcpy(taskList[2].name, "Serve customer");
    taskList[2].time = 2;

    taskList[3].id = 4;
    strcpy(taskList[3].name, "Clean up");
    taskList[3].time = 7;

    printf("Welcome to the restaurant!\n");

    taskScheduler(taskList, 4);

    printf("Let's get to work!\n");

    prepareIngredients();
    cookDish();
    serveCustomer();
    cleanUp();

    printf("Great job, team!\n");

    return 0;
}