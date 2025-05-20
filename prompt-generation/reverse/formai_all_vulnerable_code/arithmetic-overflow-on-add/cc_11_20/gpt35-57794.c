//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int chances_of_invasion;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the current global situation rating (1-10): ");
    int global_rating;
    scanf("%d", &global_rating);

    if (global_rating < 5) {
        printf("Sorry, but the global rating is too low for an invasion to occur.\n");
        return 0;
    }

    printf("Please enter the current alien activity rating (1-10): ");
    int alien_rating;
    scanf("%d", &alien_rating);

    if (alien_rating < 5) {
        printf("Sorry, but the alien activity rating is too low for an invasion to occur.\n");
        return 0;
    }

    printf("Please enter the current government defense rating (1-10): ");
    int defense_rating;
    scanf("%d", &defense_rating);

    if (defense_rating < 5) {
        printf("Sorry, but the government defense rating is too low for an invasion to occur.\n");
        return 0;
    }

    chances_of_invasion = global_rating * 10 + alien_rating * 10 - defense_rating * 5;
    printf("The chances of an invasion are: %d%%\n", chances_of_invasion);

    if (chances_of_invasion >= 70) {
        printf("Oh no! The chance of an Alien Invasion is HIGH! Be prepared.\n");
    } else if (chances_of_invasion >= 40 && chances_of_invasion < 70) {
        printf("The chance of an Alien Invasion is MODERATE. Stay Alert.\n");
    } else {
        printf("The chance of an Alien Invasion is LOW. But be cautious.\n");
    }

    char decision;
    printf("Do you want to see the detailed report? (Y/N): ");
    scanf(" %c", &decision);

    if (decision == 'Y' || decision == 'y') {
        printf("\n***************************************************\n");
        printf("Global Situation Rating: %d/10\n", global_rating);
        printf("Alien Activity Rating: %d/10\n", alien_rating);
        printf("Government Defense Rating: %d/10\n", defense_rating);
        printf("Chance of Invasion: %d%%\n", chances_of_invasion);

        printf("\nDetailed Report:\n");

        // shape shift into alien language
        int i;
        for (i = 0; i < 50; i++) {
            int language = rand() % 3;
            if (language == 0) {
                printf("Xenon 6UB-43 sends greetings from the A-432 planet.\n");
            } else if (language == 1) {
                printf("Greetings from the Vormax Metropolis!\n");
            } else if (language == 2) {
                printf("Kree Kree from Zogorath Prime.\n");
            }
        }
    }

    return 0;
}