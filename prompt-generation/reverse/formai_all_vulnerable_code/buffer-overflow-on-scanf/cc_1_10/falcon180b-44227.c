//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spaceAdventure(void);

int main() {
    srand(time(NULL));
    spaceAdventure();
    return 0;
}

void spaceAdventure(void) {
    int choice;
    int health = 100;
    int score = 0;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new planets.\n");
    printf("Your spaceship has landed on an unknown planet.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the planet\n");
    printf("2. Collect resources\n");
    printf("3. Rest\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You start exploring the planet.\n");
            printf("You find a strange cave.\n");
            printf("Do you want to enter the cave? (y/n)\n");
            char answer;
            scanf(" %c", &answer);

            if(answer == 'y' || answer == 'Y') {
                printf("You enter the cave.\n");
                printf("You find a treasure chest!\n");
                printf("You gained 50 points.\n");
                score += 50;
            } else {
                printf("You decide not to enter the cave.\n");
            }
            break;

        case 2:
            printf("You start collecting resources.\n");
            printf("You find some valuable minerals.\n");
            printf("You gained 25 points.\n");
            score += 25;
            break;

        case 3:
            printf("You take a rest.\n");
            printf("Your health increased by 20 points.\n");
            health += 20;
            break;

        case 4:
            printf("You quit the space adventure.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Your current score is: %d\n", score);
    printf("Your current health is: %d\n", health);
}