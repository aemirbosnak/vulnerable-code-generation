//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define P 1
#define S 2

int main() {
    int choice;
    int points = 0;
    int lives = 3;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    srand(time(NULL));

    printf("\nWelcome to the Adventure Game, %s!\n\n", name);
    printf("You are in a mysterious forest. What would you like to do?\n");
    printf("1. Explore the forest\n2. Gather resources\n3. Build a shelter\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if((rand() % 2) == 0) {
                printf("\nYou found a hidden path leading to a magical waterfall!\n");
                points += 10;
            } else {
                printf("\nYou got lost in the forest.\n");
                points -= 5;
            }
            break;
        case 2:
            if((rand() % 3) == 0) {
                printf("\nYou found some berries and mushrooms!\n");
                points += 5;
            } else {
                printf("\nYou couldn't find any resources.\n");
            }
            break;
        case 3:
            if((rand() % 2) == 0) {
                printf("\nYou built a sturdy shelter using branches and leaves!\n");
                points += 15;
            } else {
                printf("\nYour shelter collapsed.\n");
                points -= 10;
            }
            break;
        default:
            printf("\nInvalid choice.\n");
    }

    if(points >= 50) {
        printf("\nCongratulations! You have survived the adventure and earned %d points!\n", points);
    } else {
        printf("\nGame Over! You only earned %d points.\n", points);
    }

    return 0;
}