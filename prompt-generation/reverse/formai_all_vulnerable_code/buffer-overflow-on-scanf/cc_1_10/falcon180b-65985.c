//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void intro();
void game();
void outro();

int main() {
    intro();
    game();
    outro();
    return 0;
}

void intro() {
    printf("Welcome to the Retro Space Adventure!\n");
    printf("You are a brave space explorer on a mission to discover new planets.\n");
    printf("Your journey will be filled with dangers and challenges.\n");
    printf("Are you ready? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice!= 'y') {
        printf("Aborting mission.\n");
        exit(0);
    }
}

void game() {
    int health = 100;
    int score = 0;
    int planet = 1;
    char choice;

    while (health > 0) {
        printf("\nPlanet %d:\n", planet);
        printf("A) Explore\n");
        printf("B) Skip\n");
        scanf("%c", &choice);

        switch (choice) {
        case 'A':
            printf("You explore the planet and find valuable resources.\n");
            printf("Your score increases by 10 points.\n");
            score += 10;
            break;
        case 'B':
            printf("You decide to skip this planet.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

        planet++;

        if (planet == 5) {
            printf("\nYou have reached the end of your journey.\n");
            printf("Your final score is %d.\n", score);
            return;
        }

        printf("\nYour health status:\n");
        printf("Health: %d\n", health);
        printf("Score: %d\n", score);
    }

    printf("\nGame over. Your final score is %d.\n", score);
}

void outro() {
    printf("Thank you for playing Retro Space Adventure.\n");
}