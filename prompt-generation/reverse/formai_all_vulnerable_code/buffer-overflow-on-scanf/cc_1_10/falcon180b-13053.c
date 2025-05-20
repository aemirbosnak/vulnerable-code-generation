//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game();
void outro();

int main() {
    srand(time(NULL));
    intro();
    game();
    outro();
    return 0;
}

void intro() {
    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer traveling through the galaxy.\n");
    printf("Your mission is to collect as many stars as possible.\n");
    printf("But be careful, there are dangers lurking in the darkness.\n");
    printf("Good luck!\n\n");
}

void game() {
    int choice;
    int stars = 0;
    int health = 100;

    while (health > 0) {
        printf("You have %d health points left.\n", health);
        printf("What would you like to do?\n");
        printf("1. Collect stars\n2. Rest\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stars++;
                if (stars % 10 == 0) {
                    printf("You collected 10 stars! Your health increased by 10!\n");
                    health += 10;
                } else {
                    printf("You collected 1 star.\n");
                }
                break;
            case 2:
                printf("You rested and regained 10 health points.\n");
                health += 10;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    if (stars >= 50) {
        printf("Congratulations! You collected 50 stars and completed the mission!\n");
    } else {
        printf("Game over. You collected %d stars.\n", stars);
    }
}

void outro() {
    printf("Thanks for playing!\n");
}