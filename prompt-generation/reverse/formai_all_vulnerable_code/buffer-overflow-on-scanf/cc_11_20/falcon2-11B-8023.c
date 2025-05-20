//Falcon2-11B DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int choice, armor, weapon;
    char player[50], enemy[50];

    printf("Welcome to the medieval battle!\n");
    printf("You are a brave knight fighting against the evil dragon.\n\n");
    printf("What is your name, brave warrior? ");
    scanf("%s", player);

    printf("Your enemy is the mighty dragon, %s.\n", enemy);

    while (1) {
        printf("\nDo you want to:\n");
        printf("1. Attack the dragon\n");
        printf("2. Wear armor\n");
        printf("3. Equip a weapon\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You attack the dragon!\n");
                if (rand() % 10 < 5) {
                    printf("You successfully hit the dragon!\n");
                    printf("The dragon has taken %d damage.\n", rand() % 20 + 1);
                } else {
                    printf("You missed the dragon!\n");
                }
                break;
            case 2:
                printf("What armor would you like to wear?\n");
                printf("1. Helmet\n");
                printf("2. Chestplate\n");
                printf("3. Leggings\n");
                printf("4. Boots\n");
                printf("5. Quit\n");

                printf("Enter your choice: ");
                scanf("%d", &armor);

                switch (armor) {
                    case 1:
                        printf("You put on a helmet!\n");
                        break;
                    case 2:
                        printf("You put on a chestplate!\n");
                        break;
                    case 3:
                        printf("You put on leggings!\n");
                        break;
                    case 4:
                        printf("You put on boots!\n");
                        break;
                    case 5:
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 3:
                printf("What weapon would you like to equip?\n");
                printf("1. Sword\n");
                printf("2. Axe\n");
                printf("3. Bow and arrow\n");
                printf("4. Quit\n");

                printf("Enter your choice: ");
                scanf("%d", &weapon);

                switch (weapon) {
                    case 1:
                        printf("You pick up a sword!\n");
                        break;
                    case 2:
                        printf("You pick up an axe!\n");
                        break;
                    case 3:
                        printf("You pick up a bow and arrow!\n");
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 4:
                printf("You quit the game.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\nContinue? (y/n): ");
        char input[50];
        scanf("%s", input);
        if (input[0] == 'n') {
            printf("Thanks for playing!\n");
            exit(0);
        }
    }
}