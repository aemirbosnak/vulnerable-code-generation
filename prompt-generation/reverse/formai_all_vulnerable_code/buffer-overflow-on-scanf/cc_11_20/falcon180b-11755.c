//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int health = 100;
    int ammo = 10;
    int food = 5;
    int water = 5;
    int money = 0;
    int choice;
    int random_encounter = rand() % 10;

    printf("Welcome to the post-apocalyptic world!\n");

    while(health > 0) {

        system("clear");

        printf("Health: %d\n", health);
        printf("Ammo: %d\n", ammo);
        printf("Food: %d\n", food);
        printf("Water: %d\n", water);
        printf("Money: $%d\n", money);

        printf("\n");

        printf("1. Search for supplies\n");
        printf("2. Rest\n");
        printf("3. Trade\n");
        printf("4. Check map\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(random_encounter == 1) {
                    printf("You encounter a group of raiders!\n");
                    printf("Do you want to fight or flee?\n");
                    scanf("%d", &choice);

                    if(choice == 1) {
                        health -= 20;
                        ammo -= 2;

                        if(health <= 0) {
                            printf("You have died.\n");
                            exit(0);
                        }
                    }
                    else {
                        printf("You successfully fled.\n");
                    }
                }
                else if(random_encounter == 2) {
                    printf("You find a cache of supplies!\n");
                    ammo += 5;
                    food += 3;
                    water += 3;
                }
                else {
                    printf("You find nothing.\n");
                }
                break;

            case 2:
                printf("You rest for a while.\n");
                health += 10;
                if(health > 100) {
                    health = 100;
                }
                break;

            case 3:
                printf("You trade with a survivor.\n");
                money += 5;
                break;

            case 4:
                printf("You check your map.\n");
                break;

            case 5:
                printf("You quit the game.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");

        }

        system("sleep 1");

    }

    return 0;

}