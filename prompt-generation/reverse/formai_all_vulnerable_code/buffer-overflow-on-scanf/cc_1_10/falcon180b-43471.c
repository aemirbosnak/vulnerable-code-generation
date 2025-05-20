//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void print_menu();
void play_game();

int main() {
    srand(time(NULL)); // Seed the random number generator

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                play_game();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }

    } while (choice!= 2);

    return 0;
}

// Print the main menu
void print_menu() {
    printf("\n");
    printf("Sherlock Holmes' Space Adventure\n");
    printf("-------------------------------\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("\n");
}

// The game loop
void play_game() {
    int health = 100;
    int score = 0;
    int choice;

    while (health > 0 && score < 10) {
        printf("\n");
        printf("You are in a space station.\n");
        printf("You have %d health points and %d score points.\n", health, score);
        printf("What do you want to do?\n");
        printf("1. Attack an alien\n");
        printf("2. Defend yourself\n");
        printf("3. Search for clues\n");
        printf("4. Rest\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You attack an alien!\n");
                health -= 10;
                score += 1;
                break;
            case 2:
                printf("You defend yourself!\n");
                health -= 5;
                break;
            case 3:
                printf("You search for clues!\n");
                score += 2;
                break;
            case 4:
                printf("You rest for a while.\n");
                health += 10;
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    if (score >= 10) {
        printf("\n");
        printf("Congratulations! You have won the game with %d score points!\n", score);
    } else {
        printf("\n");
        printf("Game Over! You have %d score points.\n", score);
    }
}