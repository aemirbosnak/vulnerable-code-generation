//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    // Welcome Message
    printf("Welcome to the Energy Adventure Game!\n\n");

    // Game Variables
    int energyLevel = 100;
    char name[20];

    // Get Player's Name
    printf("What is your name? ");
    scanf("%s", name);

    // Introduction Message
    printf("\nHello %s! You are about to embark on an exciting adventure!\n", name);
    printf("Your energy level is currently at %d. You will need to conserve your energy and use it wisely to complete the game.\n", energyLevel);

    // Game Loop
    while (energyLevel > 0) {
        // Get Player's Decision
        char decision[20];
        printf("\nWhat do you want to do? (explore/rest/quit): ");
        scanf("%s", decision);

        // Explore Option
        if (strcmp(decision, "explore") == 0) {
            // Deduct Energy and Display Message
            energyLevel -= 20;
            printf("\nYou have explored the area and used up 20 energy points. Your energy level is now at %d.\n", energyLevel);
            // Check if Player has Enough Energy to Continue
            if (energyLevel <= 0) {
                printf("You have run out of energy and cannot continue. GAME OVER!");
                return 0;
            }
            // Random Event
            int eventChance = rand() % 4;
            if (eventChance == 0) {
                energyLevel -= 30;
                printf("\nYou were attacked by a wild animal and used up 30 energy points. Your energy level is now at %d.\n", energyLevel);
                if (energyLevel <= 0) {
                    printf("You have run out of energy and cannot continue. GAME OVER!");
                    return 0;
                }
            }
            else if (eventChance == 1) {
                energyLevel += 20;
                printf("\nYou found a hidden treasure and gained 20 energy points. Your energy level is now at %d.\n", energyLevel);
            }
            else {
                printf("\nYou did not encounter any events during your exploration.\n");
            }
        }
        // Rest Option
        else if (strcmp(decision, "rest") == 0) {
            // Increase Energy and Display Message
            energyLevel += 40;
            printf("\nYou have rested and gained 40 energy points. Your energy level is now at %d.\n", energyLevel);
        }
        // Quit Option
        else if (strcmp(decision, "quit") == 0) {
            printf("Thanks for playing! Goodbye!");
            return 0;
        }
        // Invalid Decision
        else {
            printf("Invalid decision! Please try again.\n");
        }
    }

    // Game Over
    printf("You have run out of energy and cannot continue. GAME OVER!");
    return 0;
}