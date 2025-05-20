//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int attack = 10;
    int defense = 5;
    int money = 0;
    int shapeShift = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nWelcome to the world of shape shifters, %s!\n", name);
    printf("You have %d health, %d attack, %d defense, and %d money.\n", health, attack, defense, money);

    while (1) {
        system("clear");
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        printf("4. Shape Shift\n");
        printf("5. Check Stats\n");
        printf("6. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou attack with %d damage!\n", attack);
                break;
            case 2:
                printf("\nYou defend with %d defense!\n", defense);
                break;
            case 3:
                printf("\nYou heal yourself for %d health!\n", health);
                break;
            case 4:
                if (shapeShift == 0) {
                    printf("\nYou shape shift into a wolf!\n");
                    attack += 5;
                    defense -= 2;
                } else if (shapeShift == 1) {
                    printf("\nYou shape shift into a bear!\n");
                    attack += 10;
                    defense += 5;
                } else {
                    printf("\nYou can't shape shift anymore.\n");
                }
                shapeShift++;
                break;
            case 5:
                printf("\nYour current stats:\n");
                printf("Health: %d\n", health);
                printf("Attack: %d\n", attack);
                printf("Defense: %d\n", defense);
                printf("Money: %d\n", money);
                break;
            case 6:
                printf("\nThanks for playing, %s!\n", name);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}