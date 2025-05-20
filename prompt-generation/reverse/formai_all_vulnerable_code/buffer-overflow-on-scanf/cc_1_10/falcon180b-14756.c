//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void space_adventure();

int main() {
    srand(time(NULL));
    space_adventure();
    return 0;
}

void space_adventure() {
    int choice;
    char name[20];
    int health = 100;
    int score = 0;

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you are a space explorer on a mission to discover new planets and civilizations.\n", name);
    printf("You have %d health points and 0 score points.\n", health);

    while(health > 0) {
        system("clear");
        printf("\nYou are currently in sector %d of the galaxy.\n", rand() % 10 + 1);
        printf("What would you like to do?\n");
        printf("1. Explore the planet\n");
        printf("2. Engage in space battle\n");
        printf("3. Trade with alien species\n");
        printf("4. Rest and recover health\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou have landed on an unknown planet.\n");
                system("sleep 1");
                printf("\nThe planet is teeming with life and resources.\n");
                printf("You have gained 10 score points and +10 health points.\n");
                score += 10;
                health += 10;
                break;
            case 2:
                printf("\nYou have engaged in a space battle with an enemy ship.\n");
                system("sleep 1");
                printf("\nThe battle was intense, but you emerged victorious!\n");
                printf("You have gained 20 score points and +20 health points.\n");
                score += 20;
                health += 20;
                break;
            case 3:
                printf("\nYou have encountered an alien species willing to trade.\n");
                system("sleep 1");
                printf("\nThe trade was successful and you have gained 30 score points and +30 health points.\n");
                score += 30;
                health += 30;
                break;
            case 4:
                printf("\nYou have taken some time to rest and recover your health.\n");
                system("sleep 1");
                printf("\nYou feel much better now.\n");
                break;
            case 5:
                printf("\n%s, your space adventure has come to an end.\n", name);
                printf("You scored %d points and had %d health points remaining.\n", score, health);
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    printf("\n%s, your space adventure has ended.\n", name);
}