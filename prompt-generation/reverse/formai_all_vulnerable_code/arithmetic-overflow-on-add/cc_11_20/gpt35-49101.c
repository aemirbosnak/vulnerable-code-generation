//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Surprise! You just stumbled upon a unique C Task Scheduler example program!\n");
    printf("This program is going to keep track of your daily tasks and make sure you get them done.\n");
    printf("Let's get started!\n\n");

    // Get the current time
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    // Set up the tasks
    int task1Time = 900;   // 9:00am
    int task2Time = 1200;  // 12:00pm
    int task3Time = 1500;  // 3:00pm

    // Loop through the day and check for tasks
    char task1Done = 0;
    char task2Done = 0;
    char task3Done = 0;

    while (1) {
        // Get the current time
        time_t currentTime;
        struct tm *localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        
        // Check if it's time for task 1
        if (localTime->tm_hour * 100 + localTime->tm_min >= task1Time && !task1Done) {
            printf("It's time to do Task 1!\n");
            // TODO: Add code to actually do Task 1 here
            task1Done = 1;
        }
        
        // Check if it's time for task 2
        if (localTime->tm_hour * 100 + localTime->tm_min >= task2Time && !task2Done) {
            printf("It's time to do Task 2!\n");
            // TODO: Add code to actually do Task 2 here
            task2Done = 1;
        }

        // Check if it's time for task 3
        if (localTime->tm_hour * 100 + localTime->tm_min >= task3Time && !task3Done) {
            printf("It's time to do Task 3!\n");
            // TODO: Add code to actually do Task 3 here
            task3Done = 1;
        }
        
        // Break out of the loop if all tasks are done
        if (task1Done && task2Done && task3Done) {
            printf("Congratulations! You have completed all your tasks for the day!\n");
            break;
        }
    }

    printf("Thank you for using the C Task Scheduler. Have a productive day!\n");

    return 0;
}