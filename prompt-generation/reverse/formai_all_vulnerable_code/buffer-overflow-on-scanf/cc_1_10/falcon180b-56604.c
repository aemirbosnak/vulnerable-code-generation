//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int money = 100;
    int weapon = 1;
    int enemyhealth = 50;
    int enemyattack = rand() % 10 + 1;
    int planet = 1;
    int fuel = 100;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer with %d health points and %d money.\n", health, money);
    printf("You have a weapon with an attack power of %d.\n", weapon);
    printf("You are currently on Planet %d with %d units of fuel.\n\n", planet, fuel);

    while(health > 0) {
        system("clear");
        printf("What would you like to do?\n");
        printf("1. Attack the enemy\n");
        printf("2. Heal yourself\n");
        printf("3. Buy a weapon\n");
        printf("4. Buy fuel\n");
        printf("5. Travel to another planet\n");
        printf("6. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enemyhealth -= weapon;
                if(enemyhealth <= 0) {
                    printf("You have defeated the enemy!\n");
                    health += 10;
                    money += 50;
                } else {
                    printf("You attacked the enemy and dealt %d damage.\n", weapon);
                    enemyattack = rand() % 10 + 1;
                    health -= enemyattack;
                }
                break;
            case 2:
                printf("You healed yourself and gained 10 health points.\n");
                health += 10;
                break;
            case 3:
                printf("You bought a new weapon with an attack power of %d.\n", weapon + 1);
                weapon++;
                break;
            case 4:
                printf("You bought 10 units of fuel.\n");
                fuel += 10;
                break;
            case 5:
                planet++;
                printf("You traveled to Planet %d.\n", planet);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}