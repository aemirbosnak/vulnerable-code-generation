//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shapeShift(int shape) {
    switch(shape) {
        case 1:
            printf("You have shape shifted into a bird!\n");
            break;
        case 2:
            printf("You have shape shifted into a fish!\n");
            break;
        case 3:
            printf("You have shape shifted into a tree!\n");
            break;
        default:
            printf("Invalid shape shifting choice.\n");
            break;
    }
}

int main() {
    srand(time(0));
    int choice;
    int shape;
    int health = 100;

    printf("Welcome to the Shape Shifting Space Adventure!\n");

    while(health > 0) {
        printf("You are on a planet with strange creatures.\n");
        printf("Do you want to shape shift? (y/n): ");
        scanf("%c", &choice);

        if(choice == 'y' || choice == 'Y') {
            printf("What shape do you want to shift into?\n1. Bird\n2. Fish\n3. Tree\n");
            scanf("%d", &shape);
            shapeShift(shape);
        } else {
            printf("You decide not to shape shift.\n");
        }

        printf("A creature approaches you.\n");
        int creatureType = rand() % 3;

        switch(creatureType) {
            case 0:
                printf("It's a giant bird!\n");
                break;
            case 1:
                printf("It's a school of fish!\n");
                break;
            case 2:
                printf("It's a walking tree!\n");
                break;
        }

        if(health <= 50) {
            printf("You are injured and cannot fight.\n");
        } else {
            printf("Do you want to fight the creature? (y/n): ");
            scanf("%c", &choice);

            if(choice == 'y' || choice == 'Y') {
                int attack = rand() % 101;
                int defense = rand() % 101;

                if(attack > defense) {
                    printf("You successfully defeated the creature!\n");
                } else {
                    printf("The creature defeated you.\n");
                    health -= 50;
                }
            } else {
                printf("You decide to run away.\n");
            }
        }
    }

    printf("Game over. Your health is at 0.\n");

    return 0;
}