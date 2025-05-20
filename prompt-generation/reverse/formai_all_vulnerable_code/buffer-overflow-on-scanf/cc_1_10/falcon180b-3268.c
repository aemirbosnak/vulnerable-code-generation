//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    char name[20];

    // Welcome message
    printf("Welcome to the Space Adventure!");
    printf("\n");

    // Get player name
    printf("What is your name? ");
    scanf("%s", name);

    // Game loop
    while (1) {
        // Display menu
        printf("\n");
        printf("%s, you are currently in the middle of space. What would you like to do?\n", name);
        printf("1. Explore\n");
        printf("2. Attack alien ship\n");
        printf("3. Return to Earth\n");
        printf("4. Quit\n");
        printf("\n");

        // Get player choice
        scanf("%d", &choice);

        // Perform action based on choice
        switch (choice) {
            case 1:
                // Explore
                printf("%s explores space and discovers a new planet.\n", name);
                score += 10;
                break;
            case 2:
                // Attack alien ship
                printf("%s encounters an alien ship and engages in a fierce battle.\n", name);
                int attack_result = rand() % 2;
                if (attack_result == 0) {
                    printf("%s successfully defeats the alien ship and gains valuable resources.\n", name);
                    score += 20;
                } else {
                    printf("%s is defeated by the alien ship and loses some resources.\n", name);
                    score -= 5;
                }
                break;
            case 3:
                // Return to Earth
                printf("%s returns to Earth and is hailed as a hero.\n", name);
                printf("%s's final score is %d.\n", name, score);
                exit(0);
            case 4:
                // Quit
                printf("%s decides to quit the game.\n", name);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Delay for 1 second
        clock_t start_time = clock();
        while (clock() < start_time + CLOCKS_PER_SEC);
    }

    return 0;
}