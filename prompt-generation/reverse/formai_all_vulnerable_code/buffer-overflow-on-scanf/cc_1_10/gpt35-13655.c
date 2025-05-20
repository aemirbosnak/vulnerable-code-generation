//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold user information
struct User {
    int id;
    char name[50];
    int age;
};

int main() {

    printf("Welcome to the Database Simulation Program!\n");

    // Create an array of users
    struct User users[10];
    int num_users = 0;

    // Prompt user for input
    char choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("a. Add a user\n");
        printf("b. View a user\n");
        printf("c. Exit\n");
        printf(">> ");

        // Get user's choice
        scanf(" %c", &choice);
        printf("\n");

        if (choice == 'a') {
            // Add a user

            // Prompt for user input
            printf("Enter the user's name: ");
            scanf("%s", users[num_users].name);
            printf("Enter the user's age: ");
            scanf("%d", &users[num_users].age);

            // Set the user's ID
            users[num_users].id = num_users + 1;

            // Print confirmation message
            printf("\nUser added successfully!\n");
            printf("User ID: %d\n", users[num_users].id);
            printf("Name: %s\n", users[num_users].name);
            printf("Age: %d\n", users[num_users].age);

            // Increment the number of users
            num_users++;

        } else if (choice == 'b') {
            // View a user

            // Prompt for user ID
            int user_id;
            printf("Enter the ID of the user you want to view: ");
            scanf("%d", &user_id);

            // Find the user
            int found = 0;
            for (int i = 0; i < num_users; i++) {
                if (users[i].id == user_id) {
                    printf("\nUser found!\n");
                    printf("User ID: %d\n", users[i].id);
                    printf("Name: %s\n", users[i].name);
                    printf("Age: %d\n", users[i].age);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nUser not found.\n");
            }

        } else if (choice != 'c') {
            // Invalid choice
            printf("Invalid choice. Please try again.");

        }

    } while (choice != 'c');

    printf("Goodbye!\n");

    return 0;
}