//FormAI DATASET v1.0 Category: System boot optimizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diskReadTime;
    int maxTaskTime = 20;

    // Get disk read time from user input
    printf("Enter disk read time in milliseconds: ");
    scanf("%d", &diskReadTime);

    // Randomly generate task times to simulate boot process
    srand(time(NULL));
    int task1 = rand() % maxTaskTime + 1;
    int task2 = rand() % maxTaskTime + 1;
    int task3 = rand() % maxTaskTime + 1;

    // Sort tasks in descending order of time required
    int tasks[3] = {task1, task2, task3};
    int temp;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (tasks[i] < tasks[j]) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Determine optimal order of task execution
    int firstTask, secondTask, thirdTask;
    if (tasks[0] > diskReadTime) {
        firstTask = tasks[0];
        secondTask = tasks[1];
        thirdTask = tasks[2];
    } else if (tasks[1] > diskReadTime) {
        firstTask = diskReadTime;
        secondTask = tasks[0];
        thirdTask = tasks[1] > tasks[2] ? tasks[1] : tasks[2];
    } else {
        firstTask = diskReadTime;
        secondTask = tasks[1] > diskReadTime ? tasks[1] : diskReadTime;
        thirdTask = tasks[1] > diskReadTime ? diskReadTime : tasks[1];
    }

    // Simulate task execution and measure total time taken
    int totalTime = 0;
    printf("Optimal order of task execution: %dms -> %dms -> %dms\n", firstTask, secondTask, thirdTask);
    totalTime += firstTask;
    printf("Task 1 completed in %dms\n", firstTask);
    totalTime += secondTask;
    printf("Task 2 completed in %dms\n", secondTask);
    totalTime += thirdTask;
    printf("Task 3 completed in %dms\n", thirdTask);
    printf("Total time taken: %dms\n", totalTime);

    return 0;
}