//FormAI DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 
Medieval System Administration Program
Developed by the Knights of Camelot
*/

void welcome_message() {
    printf("\n=======================\n");
    printf("Welcome to the Castle's System\n");
    printf("=======================\n");
}

void display_options() {
    printf("Choose an option:\n");
    printf("1. View system information\n");
    printf("2. Manage users\n");
    printf("3. Manage files and directories\n");
    printf("4. Exit\n");
}

int main() {
    char name[50];
    int choice;

    srand(time(NULL)); // Initialize random seed
    
    welcome_message();

    printf("What is your name, sir knight? ");
    scanf("%s", name);

    printf("\nGreetings, Sir %s!\n", name);

    do {
        display_options();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n--- System Information ---\n");
                // Todo: Display system information
                break;
            case 2:
                printf("\n--- User Management ---\n");
                // Todo: Manage users
                break;
            case 3:
                printf("\n--- File and Directory Management ---\n");
                // Todo: Manage files and directories
                break;
            case 4:
                printf("\nFarewell, Sir %s!\n", name);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Add some medieval flavor to the response
        int rand_num = rand() % 3;
        if (rand_num == 0) {
            printf("Very well, Sir %s.\n", name);
        } else if (rand_num == 1) {
            printf("As you command, Sir %s.\n", name);
        } else {
            printf("Yes, Sir %s. Right away.\n", name);
        }

    } while (choice != 4);

    return 0;
}