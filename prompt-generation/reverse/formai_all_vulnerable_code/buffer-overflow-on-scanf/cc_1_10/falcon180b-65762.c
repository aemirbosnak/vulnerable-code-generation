//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int random = rand() % 3;
    int score = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark and mysterious forest.\n");
    printf("Choose your path wisely, for danger lurks around every corner.\n");

    if (random == 0) {
        printf("\nYou see a narrow path leading deeper into the forest.\n");
        printf("Do you:\n");
        printf("1. Take the path.\n");
        printf("2. Turn back.\n");
    } else if (random == 1) {
        printf("\nYou come across a fork in the road.\n");
        printf("Do you:\n");
        printf("1. Go left.\n");
        printf("2. Go right.\n");
    } else {
        printf("\nYou stumble upon a small clearing.\n");
        printf("Do you:\n");
        printf("1. Investigate the clearing.\n");
        printf("2. Continue through the forest.\n");
    }

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nYou take the narrow path and continue deeper into the forest.\n");
            score++;
            break;
        case 2:
            printf("\nYou turn back and retrace your steps.\n");
            break;
        case 3:
            printf("\nYou go left at the fork in the road.\n");
            score++;
            break;
        case 4:
            printf("\nYou go right at the fork in the road.\n");
            score++;
            break;
        case 5:
            printf("\nYou investigate the clearing and find a treasure chest!\n");
            score += 2;
            break;
        case 6:
            printf("\nYou continue through the forest, but find nothing of interest.\n");
            break;
        default:
            printf("\nInvalid choice. Game over.\n");
            return 0;
    }

    if (score == 5) {
        printf("\nCongratulations! You have completed the game with a score of %d.\n", score);
    } else {
        printf("\nThanks for playing! Your final score is %d.\n", score);
    }

    return 0;
}