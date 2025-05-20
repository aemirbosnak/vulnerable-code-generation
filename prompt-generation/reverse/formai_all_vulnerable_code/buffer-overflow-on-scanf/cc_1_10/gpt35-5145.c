//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer();

int main() {
    // Declare and initialize variables
    char name[50];
    int age;
    char gender;
    int coins = 0;
    int health = 10;
    int is_wizard = 0;
    char choice;

    // Prompt user for name, age, and gender
    printf("Welcome to Adventure Game!\n");
    printf("What is your name? ");
    fgets(name, 50, stdin);
    clear_input_buffer();
    printf("How old are you? ");
    scanf("%d", &age);
    clear_input_buffer();
    printf("What is your gender (M/F)? ");
    scanf("%c", &gender);
    clear_input_buffer();

    // Print user information
    printf("\nWelcome, %s", name);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);

    // Start game loop
    while (1) {
        // Print options for user
        printf("\nChoose an option:\n");
        printf("[1] Explore the forest\n");
        printf("[2] Visit the tavern\n");
        printf("[3] Go to the castle\n");
        printf("[4] Exit game\n");

        // Get user choice
        printf("Enter choice: ");
        scanf("%c", &choice);
        clear_input_buffer();

        // Validate user choice
        if (choice < '1' || choice > '4') {
            printf("\nInvalid choice. Please try again.\n");
            continue;
        }

        // Handle user choice
        switch (choice) {
            case '1':
                printf("\nYou wander into the forest...\n");
                printf("You come across a wizard who offers to give you magical powers for 10 coins.\n");
                printf("Do you accept (Y/N)? ");
                scanf("%c", &choice);
                clear_input_buffer();
                if (choice == 'Y') {
                    if (coins >= 10) {
                        printf("\nThe wizard gives you magical powers!\n");
                        is_wizard = 1;
                        coins -= 10;
                    }
                    else {
                        printf("\nYou don't have enough coins to pay for the magic.\n");
                    }
                }
                else {
                    printf("\nYou decide not to take the wizard's offer.\n");
                }
                break;

            case '2':
                printf("\nYou head to the tavern...\n");
                if (is_wizard) {
                    printf("Your magical powers intimidate the other patrons.\n");
                }
                printf("You spend 5 coins on food and drink.\n");
                coins -= 5;
                health += 5;
                printf("You feel refreshed and ready for adventure!\n");
                break;

            case '3':
                printf("\nYou arrive at the castle gates...\n");
                printf("The guards ask for a toll of 10 coins to enter the castle.\n");
                if (coins >= 10) {
                    printf("You pay the toll and enter the castle.\n");
                    coins -= 10;
                }
                else {
                    printf("You don't have enough coins to pay the toll.\n");
                }
                break;

            case '4':
                printf("\nThanks for playing!\n");
                exit(0);
        }
    }

    return 0;
}

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}