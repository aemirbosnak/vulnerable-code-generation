//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int treasure = 0;

    srand(time(NULL));

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer in search of treasure.\n");
    printf("Guide me through this adventure.\n");

    while(1) {
        system("clear");
        printf("You are in a dark, damp cave.\n");
        printf("There are three paths in front of you:\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go straight\n");
        printf("What do you choose? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You go left and find a treasure chest!\n");
                printf("Do you open it? (y/n) ");
                char open;
                scanf(" %c", &open);
                if(open == 'y') {
                    treasure += rand() % 10 + 1;
                    printf("You found %d gold coins!\n", treasure);
                }
                else {
                    printf("You leave the chest alone.\n");
                }
                break;
            case 2:
                printf("You go right and encounter a giant spider!\n");
                printf("Do you fight it or run away? (f/r) ");
                char fightrun;
                scanf(" %c", &fightrun);
                if(fightrun == 'f') {
                    int damage = rand() % 10 + 1;
                    health -= damage;
                    if(health <= 0) {
                        printf("The spider defeated you.\n");
                        return 0;
                    }
                    else {
                        printf("You defeated the spider but lost %d health.\n", damage);
                    }
                }
                else {
                    printf("You ran away from the spider.\n");
                }
                break;
            case 3:
                printf("You go straight and find a healing potion!\n");
                printf("Do you drink it? (y/n) ");
                char drink;
                scanf(" %c", &drink);
                if(drink == 'y') {
                    int heal = rand() % 10 + 1;
                    health += heal;
                    printf("You gained %d health!\n", heal);
                }
                else {
                    printf("You leave the potion behind.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}