//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int health = 100;
    int gold = 0;
    int key = 0;

    printf("\nWelcome to the Quest!\n\n");

    while (1) {
        printf("You are in a forest.\n");
        printf("You have %d health and %d gold.\n\n", health, gold);

        printf("What do you want to do?\n");
        printf("1. Go deeper into the forest\n");
        printf("2. Search for food\n");
        printf("3. Rest and regain health\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou come across a haunted mansion.\n");
                printf("Do you want to enter?\n");
                printf("1. Yes\n");
                printf("2. No\n");

                scanf("%d", &choice);

                if (choice == 1) {
                    if (key) {
                        printf("\nYou use the key to enter the mansion.\n");
                        printf("Inside, you find a chest filled with gold!\n");
                        gold += 50;
                    } else {
                        printf("\nYou try to enter the mansion, but it's locked.\n");
                        printf("You need a key to enter.\n");
                    }
                } else {
                    printf("\nYou ignore the haunted mansion and keep going deeper into the forest.\n");
                    printf("You come across a group of bandits who attack you.\n");

                    health -= 20;

                    if (health <= 0) {
                        printf("\nYou have died.\n");
                        exit(0);
                    }
                }

                break;

            case 2:
                printf("\nYou search for food and find some berries.\n");
                printf("You eat the berries and regain some health.\n");

                health += 10;

                break;

            case 3:
                printf("\nYou rest and regain some health.\n");

                health += 20;

                break;

            default:
                printf("\nInvalid choice.\n");
                continue;
        }

        if (health <= 0) {
            printf("\nYou have died.\n");
            exit(0);
        }

        printf("You continue on your adventure.\n\n");

        if (!key && gold >= 50) {
            printf("You come across a merchant who is selling a key.\n");
            printf("Do you want to buy it for 50 gold?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            scanf("%d", &choice);

            if (choice == 1) {
                printf("\nYou buy the key and continue on your adventure.\n");

                key = 1;
                gold -= 50;
            } else {
                printf("\nYou ignore the key and continue on your adventure.\n");
            }
        }
    }

    return 0;
}