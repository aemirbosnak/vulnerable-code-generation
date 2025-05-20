//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize random seed
    srand(time(NULL));

    //initialize game variables
    int health = 100;
    int ammo = 10;
    int food = 50;
    int water = 50;
    int location = 1;
    int choice;

    //initialize game objects
    int enemy[3] = {25, 50, 75};
    int loot[3] = {10, 20, 30};

    //game loop
    while(1) {
        //display current location
        printf("\nYou are currently at location %d.\n", location);

        //display game status
        printf("Health: %d\n", health);
        printf("Ammo: %d\n", ammo);
        printf("Food: %d\n", food);
        printf("Water: %d\n", water);

        //display options
        printf("\nWhat would you like to do?\n");
        printf("1. Move to a new location.\n");
        printf("2. Search for supplies.\n");
        printf("3. Rest.\n");
        printf("4. Quit.\n");
        printf("> ");
        scanf("%d", &choice);

        //process choice
        switch(choice) {
            case 1:
                //move to new location
                printf("You move to a new location.\n");
                location = rand() % 6 + 1;
                break;
            case 2:
                //search for supplies
                printf("You search for supplies.\n");
                int found = rand() % 2;
                if(found == 1) {
                    printf("You found some ammo!\n");
                    ammo += 5;
                } else if(found == 0) {
                    printf("You didn't find anything.\n");
                }
                break;
            case 3:
                //rest
                printf("You rest.\n");
                health += rand() % 3 + 1;
                food -= 5;
                water -= 5;
                break;
            case 4:
                //quit
                printf("Thanks for playing!\n");
                exit(0);
            default:
                //invalid choice
                printf("Invalid choice.\n");
        }

        //check for game over
        if(health <= 0 || ammo <= 0) {
            printf("\nGame over! You have died.\n");
            exit(0);
        }
    }

    return 0;
}