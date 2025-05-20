//FormAI DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declare our random function
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main(void) {
    // Seed our random function with the current time
    srand(time(NULL));

    // Define our variables
    char sysadmin_name[50];
    int sysadmin_age;
    char sysadmin_task[100];

    // Prompt the user to enter their name
    printf("Greetings, my dear user! What is your name?\n");
    scanf("%s", sysadmin_name);

    // Generate a random age for the sysadmin
    sysadmin_age = random_number(25, 70);

    // Confirm their age
    printf("Ah, %s, I see you are %d years old.\n", sysadmin_name, sysadmin_age);

    // Prompt the user for their task
    printf("What task have you been assigned to perform today, %s?\n", sysadmin_name);
    scanf("%s", sysadmin_task);

    // Tell the user that Sherlock Holmes is on the case
    printf("Fear not, %s! Sherlock Holmes is on the case!\n\n", sysadmin_name);

    // Simulate Sherlock Holmes examining the user's system
    printf("Sherlock Holmes examined %s's system:\n", sysadmin_name);
    printf("-----------------------------------------------\n");

    // Simulate finding some system logs
    printf("Found system logs...\n");

    // Simulate searching through system logs
    printf("Searching through system logs...\n");

    // Simulate finding the root cause of a system error
    printf("Found root cause of system error: %s\n", sysadmin_task);

    // Simulate fixing the system issue
    printf("Fixing system issue...\n");

    // Simulate confirming that the task is complete
    printf("Task complete, %s!\n", sysadmin_name);

    // Exit the program
    return 0;
}