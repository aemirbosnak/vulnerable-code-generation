//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int money = 0;
    int inventory[10] = {0};
    int num_items = 0;

    srand(time(NULL));

    while (1) {
        system("clear");
        printf("Health: %d\n", health);
        printf("Money: %d\n", money);

        printf("\n");
        for (int i = 0; i < num_items; i++) {
            printf("%d. %s\n", i+1, inventory[i]);
        }

        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        printf("4. Rest\n");
        printf("5. Buy\n");
        printf("6. Sell\n");
        printf("7. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_items > 0 && inventory[0] == 1) {
                    health -= 10;
                    printf("You attacked! You lost 10 health.\n");
                } else {
                    printf("You can't attack without a weapon.\n");
                }
                break;
            case 2:
                if (num_items > 0 && inventory[0] == 2) {
                    printf("You defended!\n");
                } else {
                    printf("You can't defend without a shield.\n");
                }
                break;
            case 3:
                if (num_items > 0 && inventory[0] == 3) {
                    health += 20;
                    printf("You healed! You gained 20 health.\n");
                } else {
                    printf("You can't heal without a potion.\n");
                }
                break;
            case 4:
                printf("You rested and gained 10 health.\n");
                health += 10;
                break;
            case 5:
                if (money >= 50) {
                    inventory[num_items] = 1;
                    num_items++;
                    money -= 50;
                    printf("You bought a sword!\n");
                } else {
                    printf("You don't have enough money.\n");
                }
                break;
            case 6:
                if (num_items > 0 && inventory[0] == 1) {
                    money += 30;
                    inventory[0] = 0;
                    num_items--;
                    printf("You sold your sword! You gained 30 money.\n");
                } else {
                    printf("You don't have anything to sell.\n");
                }
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}