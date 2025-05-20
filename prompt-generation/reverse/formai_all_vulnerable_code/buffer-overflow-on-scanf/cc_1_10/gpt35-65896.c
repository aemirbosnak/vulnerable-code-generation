//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Welcome to Procedural Space Adventure!\n\n");

    // Declaration of variables
    char playerName[20];
    int age, distance;
    float fuel;

    // Player information collection
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Please enter your age: ");
    scanf("%d", &age);

    // Initializing distance and fuel
    distance = 0;
    fuel = 100.0;

    // Introduction to the game
    printf("\n%s, you are the captain of a space vessel!\n", playerName);
    printf("Your mission is to explore the galaxy and search for new planets and life forms.\n");
    printf("Your journey starts with a full fuel tank and your goal is to reach a distance of 500 light years.\n");

    // Main gameplay loop
    while (distance < 500 && fuel > 0) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Travel to the nearest star system.\n");
        printf("2. Explore a nearby planet.\n");
        printf("3. Check fuel levels.\n");
        printf("4. Quit the game.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Implementing game choices
        switch(choice) {
            case 1:
                printf("\nYou travel to the nearest star system, which is 10 light years away.\n");
                distance += 10;
                fuel -= 5.0;
                break;
            case 2:
                printf("\nYou explore a nearby planet.\n");
                printf("However, you encounter hostile alien life forms and are forced to flee back to your ship.\n");
                fuel -= 10.0;
                break;
            case 3:
                printf("\nYour current fuel level is: %.2f\n", fuel);
                break;
            case 4:
                printf("\nThank you for playing Procedural Space Adventure, %s!\n", playerName);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

        // Check remaining fuel
        if (fuel <= 0) {
            printf("You have run out of fuel and are stranded in space. Game over.\n");
            return 0;
        }

        // Display status
        printf("Your current distance from Earth is: %d light years.\n", distance);
        printf("Your current fuel level is: %.2f\n", fuel);
    }

    // Player wins the game
    printf("\nCongratulations, %s! You have successfully completed the mission and reached a distance of 500 light years.\n", playerName);
    return 0;
}