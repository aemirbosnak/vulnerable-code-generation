//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[30], choice;
    int health = 100, potion = 3, money = 0;

    srand(time(NULL));

    printf("Welcome to the world of Adventure!\n\n");
    printf("Before we start, what's your name? ");
    scanf("%29s", name);
    printf("\nAlright, %s, let's begin our adventure!\n", name);
    printf("You find yourself standing in a dark forest. You can hear the sound of a river in the distance. You see two paths - one to the left and one to the right. Which one do you choose? (L/R): ");
    scanf(" %c", &choice);

    if (choice == 'L') {
        printf("You chose the left path. You walk for a while and come across a merchant selling items. Do you want to buy a health potion for 10 coins? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y') {
            if (money >= 10) {
                money -= 10;
                potion++;
                printf("You bought a health potion. You now have %d health potions.\n", potion);
            } else {
                printf("You don't have enough money. Sorry!\n");
            }
        } else {
            printf("You decide not to buy anything and continue on your journey.\n");
        }

        printf("As you keep walking, you start to feel tired. You stop to take a rest, but suddenly, a monster jumps out of nowhere and attacks you!\n");

        int monster_health = rand() % 50 + 50;

        while (health > 0 && monster_health > 0) {
            printf("\n=====");
            printf("\n| H |  Your Health: %d", health);
            printf("\n| P |  Health Potions: %d", potion);
            printf("\n| M |  Money: %d", money);
            printf("\n=====\n\n");

            printf("What do you want to do? (A/H/P): ");
            scanf(" %c", &choice);

            if (choice == 'A') {
                int damage = rand() % 10 + 1;
                monster_health -= damage;
                printf("You attack the monster and deal %d damage.\n", damage);

                if (monster_health > 0) {
                    damage = rand() % 20 + 1;
                    health -= damage;
                    printf("The monster attacks you back and deals %d damage.\n", damage);
                }
            } else if (choice == 'H') {
                if (potion > 0) {
                    health += 30;
                    potion--;
                    printf("You use a health potion and gain 30 health. You now have %d health potions left.\n", potion);
                } else {
                    printf("You don't have any health potions left.\n");
                }
            } else if (choice == 'P') {
                printf("You can sell a health potion for 5 coins. How many do you want to sell?: ");
                scanf("%d", &choice);

                if (choice <= potion && choice > 0) {
                    potion -= choice;
                    money += choice * 5;
                    printf("You sold %d health potions for %d coins. You now have %d health potions and %d coins.\n", choice, choice * 5, potion, money);
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }

        if (health <= 0) {
            printf("You died.\n");
        } else {
            printf("You defeated the monster and gained 50 coins!\n");
            money += 50;
        }
    } else if (choice == 'R') {
        printf("You chose the right path. You walk for a while and come across a river. Do you want to swim across? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y') {
            printf("You start to swim across the river, but the current is too strong. You die.\n");
        } else {
            printf("You decide not to swim across and continue on your journey.\n");
        }
    } else {
        printf("Invalid choice. Try again.\n");
    }

    printf("\n\nThanks for playing, %s!\n", name);

    return 0;
}