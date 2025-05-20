//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int treasure = 0;
    int room = 1;

    printf("Welcome to the Brave Adventure!\n");
    printf("You are a brave knight on a quest to find treasure!\n");
    printf("Your health is at %d and you have %d treasure.\n", health, treasure);

    srand(time(NULL));

    while(room <= 5) {
        printf("\nYou are in room %d.\n", room);
        printf("What would you like to do?\n");
        printf("1. Search for treasure.\n");
        printf("2. Rest and regain health.\n");
        printf("3. Move to the next room.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(treasure >= 3) {
                    printf("You have already found enough treasure.\n");
                } else {
                    int random = rand() % 3;
                    if(random == 0) {
                        printf("You found 1 treasure!\n");
                        treasure++;
                    } else if(random == 1) {
                        printf("You found 2 treasure!\n");
                        treasure += 2;
                    } else {
                        printf("You found no treasure this time.\n");
                    }
                }
                break;
            case 2:
                printf("You rest and regain 10 health.\n");
                health += 10;
                if(health > 100) {
                    health = 100;
                }
                break;
            case 3:
                room++;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    if(treasure >= 3) {
        printf("\nCongratulations! You have found enough treasure and completed the quest!\n");
    } else {
        printf("\nSorry, you did not find enough treasure to complete the quest.\n");
    }

    return 0;
}