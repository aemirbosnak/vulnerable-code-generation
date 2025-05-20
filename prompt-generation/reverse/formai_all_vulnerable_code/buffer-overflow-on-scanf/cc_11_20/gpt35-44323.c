//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define MAX_DELAY 3

int main() {
    int i = 0;
    int attempts = 0;

    srand(time(NULL));

    while (1) {
        printf("Please enter your password: ");

        char input[20];
        scanf("%s", input);

        // Simulate random delay to prevent brute force attacks
        int delay = rand() % MAX_DELAY;
        for (int j = 0; j < delay; j++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");

        if (strcmp(input, "password123") == 0) {
            printf("Welcome to the system!\n");
            break;
        }

        printf("Incorrect password. ");
        attempts++;

        if (attempts >= MAX_ATTEMPTS) {
            printf("Too many attempts. Exiting program.\n");
            exit(0);
        }

        printf("You have %d attempts remaining.\n", MAX_ATTEMPTS - attempts);
    }

    // Intrusion detection system - monitoring user activity
    printf("\nWelcome to the Intrusion Detection System!\n");
    while (1) {
        printf("Please enter a command: ");

        char command[20];
        scanf("%s", command);

        // Simulate random delay to prevent brute force attacks
        int delay = rand() % MAX_DELAY;
        for (int j = 0; j < delay; j++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");

        if (strcmp(command, "shutdown") == 0) {
            printf("Are you sure you want to shutdown? (y/n)");

            char answer;
            scanf(" %c", &answer);

            if (answer == 'y') {
                printf("Shutting down the system...\n");
                exit(0);
            } else {
                printf("Command aborted.\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Are you sure you want to delete? (y/n)");

            char answer;
            scanf(" %c", &answer);

            if (answer == 'y') {
                printf("Deleting files...\n");
            } else {
                printf("Command aborted.\n");
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}