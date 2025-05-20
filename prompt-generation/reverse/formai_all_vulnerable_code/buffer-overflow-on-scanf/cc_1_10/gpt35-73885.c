//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice = 0;
    int isHaunted = 0;
    int doorChoice = 0;
    int hasKey = 0;

    printf("Welcome to the Haunted House Simulator!\n");

    // Choose to enter or exit
    printf("Enter the house or exit? (Enter: 1, Exit: 2)\n");
    scanf("%d", &choice);

    if (choice == 2) {
        printf("Goodbye!\n");
        exit(0);
    }

    printf("You have entered the Haunted House...\n");

    // Randomly determine if the house is haunted or not
    srand(time(NULL));
    isHaunted = rand() % 2;

    if (isHaunted == 1) {
        printf("The house is haunted! You must find the key to unlock the door and escape.\n");

        // Determine which door the key is in
        srand(time(NULL));
        doorChoice = rand() % 3 + 1;

        while (hasKey == 0) {
            // Choose a door to open
            printf("Which door will you choose? (1, 2, or 3)\n");
            scanf("%d", &choice);

            if (choice == doorChoice) {
                printf("Congratulations, you found the key! Now escape before it's too late!\n");
                hasKey = 1;
            } else {
                printf("Sorry, that door did not have the key. Choose another door.\n");
            }
        }
    } else {
        printf("The house is not haunted! You can explore freely.\n");
    }

    printf("Thank you for trying out the Haunted House Simulator!\n");

    return 0;
}