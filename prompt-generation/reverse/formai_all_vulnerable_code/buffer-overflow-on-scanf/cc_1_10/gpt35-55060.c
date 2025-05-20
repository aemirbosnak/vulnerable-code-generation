//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if the user wants to continue with the program
int askUser() {
    char reply;
    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &reply);
    if (reply == 'y' || reply == 'Y') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int choice; // variable for user input
    srand(time(NULL)); // seed for random number generator

    printf("Welcome to the Automated Fortune Teller!\n\n");

    do {
        printf("Please choose a number between 1-4:\n");
        printf("1. Love Life\n2. Career Path\n3. Financial Success\n4. Health\n");

        scanf("%d", &choice);
        printf("\n");

        // switch statement to determine fortune based on user's choice
        switch(choice) {
            case 1:
                printf("You will meet someone special soon!\n");
                break;
            case 2:
                printf("You will have great success in your chosen career!\n");
                break;
            case 3:
                printf("Financial success is on the horizon!\n");
                break;
            case 4:
                printf("You will have good health for a long time!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }

    } while (askUser()); // continue asking user for input until they say no

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}