//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time
    int choice;
    int health = 100;
    int score = 0;

    // game loop
    while (health > 0 && score < 10) {
        int event = rand() % 3; // generate random event (0-2)

        switch (event) {
            case 0:
                printf("You encounter a group of friendly aliens.\n");
                printf("They offer to give you a power-up.\n");
                printf("Press 1 to accept, or 0 to decline.\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    health += 10;
                    score++;
                    printf("You gained 10 health points and 1 score point!\n");
                } else {
                    printf("You declined the offer.\n");
                }
                break;
            case 1:
                printf("You stumble upon a dangerous asteroid field.\n");
                printf("Try to navigate through it without getting hit.\n");
                for (int i = 0; i < 5; i++) {
                    int asteroid = rand() % 2; // generate random asteroid (0 or 1)
                    if (asteroid == 1) {
                        health -= 10;
                        printf("You got hit by an asteroid!\n");
                    }
                }
                break;
            case 2:
                printf("You find a hidden treasure on a deserted planet.\n");
                printf("Press 1 to take the treasure, or 0 to leave it.\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    health += 20;
                    score += 2;
                    printf("You gained 20 health points and 2 score points!\n");
                } else {
                    printf("You left the treasure behind.\n");
                }
                break;
        }

        printf("Your current health is %d and your score is %d.\n\n", health, score);
    }

    if (health <= 0) {
        printf("Game over. You ran out of health.\n");
    } else if (score >= 10) {
        printf("Congratulations! You won the game!\n");
    } else {
        printf("Game over. You didn't get enough score points.\n");
    }

    return 0;
}