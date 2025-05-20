//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int health = 100;
    int score = 0;
    int level = 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a brave astronaut on a mission to explore the universe.\n");
    printf("Your goal is to collect as many stars as possible and avoid obstacles.\n");
    printf("Are you ready to begin? (y/n) ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        while (health > 0) {
            int obstacle = rand() % 2;
            int star = rand() % 3;

            if (obstacle == 0) {
                printf("You encounter an asteroid field!\n");
                health -= 20;
            } else if (star == 0) {
                printf("You collect a star!\n");
                score += 10;
            } else if (star == 1) {
                printf("You collect a rare star!\n");
                score += 25;
            } else if (star == 2) {
                printf("You collect a legendary star!\n");
                score += 50;
            }

            if (health <= 0) {
                printf("Game Over! You scored %d points.\n", score);
                break;
            }

            if (level == 1 && score >= 50) {
                printf("Congratulations! You have completed level 1.\n");
                level++;
            } else if (level == 2 && score >= 100) {
                printf("Congratulations! You have completed level 2.\n");
                level++;
            } else if (level == 3 && score >= 150) {
                printf("Congratulations! You have completed the game.\n");
            }
        }
    } else {
        printf("Thank you for playing!\n");
    }

    return 0;
}