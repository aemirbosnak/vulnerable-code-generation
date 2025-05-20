//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int health = 100;
    int fuel = 100;
    int score = 0;
    int planet = 1;
    int aliens = rand() % 10 + 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new planets and meet new alien species.\n");
    printf("Your ship has limited fuel and health, so be careful!\n");
    printf("Let's begin!\n");

    while(health > 0 && fuel > 0) {
        printf("\nYou are currently on planet %d.\n", planet);
        printf("There are %d aliens here.\n", aliens);

        printf("\nWhat would you like to do?\n");
        printf("1. Explore the planet\n");
        printf("2. Meet the aliens\n");
        printf("3. Refuel your ship\n");
        printf("4. Repair your ship\n");
        printf("5. Continue to the next planet\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou explore the planet and find some interesting artifacts.\n");
                printf("You gain 10 points!\n");
                score += 10;
                break;
            case 2:
                printf("\nYou meet the aliens and learn about their culture.\n");
                printf("You gain 20 points!\n");
                score += 20;
                break;
            case 3:
                printf("\nYou refuel your ship.\n");
                fuel = 100;
                break;
            case 4:
                printf("\nYou repair your ship.\n");
                health = 100;
                break;
            case 5:
                planet++;
                aliens = rand() % 10 + 1;
                printf("\nYou travel to the next planet.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    if(health <= 0) {
        printf("\nYour ship has been destroyed! Game over.\n");
    } else if(fuel <= 0) {
        printf("\nYou run out of fuel and are stranded on the last planet you visited.\n");
    } else {
        printf("\nCongratulations! You have completed the Space Adventure!\n");
        printf("You scored %d points.\n", score);
    }

    return 0;
}