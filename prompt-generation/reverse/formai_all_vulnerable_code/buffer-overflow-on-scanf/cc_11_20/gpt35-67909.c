//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 10
#define MAX_DAYS 7

int main() {
    // array to store user data
    int users[MAX_USERS][MAX_DAYS];
    int user_count = 0;

    // loop runs until user decides to exit
    while (true) {
        // menu to get user input
        printf("\nC Fitness Tracker");
        printf("\n1. Add user data");
        printf("\n2. Show user data");
        printf("\n3. Exit program");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // Add user data
            case 1: {
                // check if there is space for new user
                if (user_count >= MAX_USERS) {
                    printf("\nMaximum number of users reached");
                    break;
                }

                // get user data
                printf("\nEnter data for user %d:\n", user_count + 1);
                for (int i = 0; i < MAX_DAYS; i++) {
                    printf("Day %d: ", i + 1);
                    int data;
                    scanf("%d", &data);
                    users[user_count][i] = data;
                }

                // increment user count
                user_count++;

                printf("\nUser data added successfully");
                break;
            }

            // Show user data
            case 2: {
                // check if there are any users
                if (user_count == 0) {
                    printf("\nNo user data available");
                    break;
                }

                // get user number
                int user_num;
                printf("\nEnter user number (1 to %d): ", user_count);
                scanf("%d", &user_num);

                // check if user number is valid
                if (user_num < 1 || user_num > user_count) {
                    printf("\nInvalid user number");
                    break;
                }

                // display user data
                printf("\nUser %d data:\n", user_num);
                for (int i = 0; i < MAX_DAYS; i++) {
                    printf("Day %d: %d\n", i + 1, users[user_num - 1][i]);
                }

                break;
            }

            // Exit program
            case 3: {
                printf("\nExiting program\n");
                exit(0);
            }

            // Invalid choice
            default: {
                printf("\nInvalid choice");
                break;
            }
        }
    }

    return 0;
}