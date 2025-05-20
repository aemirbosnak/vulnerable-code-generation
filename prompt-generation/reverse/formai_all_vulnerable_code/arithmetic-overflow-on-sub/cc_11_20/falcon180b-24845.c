//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int health = 100;
    int gold = 50;
    int xp = 0;
    int level = 1;
    int enemyHealth = 50;
    int enemyAttack = 10;
    int playerAttack = 5;
    int attackRoll;
    int defenseRoll;
    int damage;
    char name[20];

    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you wake up in a dark dungeon with no memory of how you got there.\n", name);
    printf("You have %d health, %d gold, and %d experience points.\n", health, gold, xp);

    while(1) {
        system("clear");
        printf("\n%s, you are in a dark dungeon.\n", name);
        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Check Stats\n4. Save Game\n5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou decide to attack.\n");
                attackRoll = rand() % 20 + 1;
                printf("You roll a %d for your attack.\n", attackRoll);
                damage = playerAttack + attackRoll - defenseRoll;
                if(damage > 0) {
                    printf("You hit the enemy and deal %d damage!\n", damage);
                    enemyHealth -= damage;
                    if(enemyHealth <= 0) {
                        printf("\nYou have defeated the enemy!\n");
                        gold += 10;
                        xp += 5;
                    }
                } else {
                    printf("You miss the enemy.\n");
                }
                break;
            case 2:
                printf("\nYou decide to defend.\n");
                defenseRoll = rand() % 20 + 1;
                printf("You roll a %d for your defense.\n", defenseRoll);
                if(defenseRoll > enemyAttack) {
                    printf("You successfully defend against the enemy's attack!\n");
                } else {
                    printf("The enemy hits you and deals %d damage!\n", enemyAttack);
                    health -= enemyAttack;
                    if(health <= 0) {
                        printf("\nYou have been defeated by the enemy.\n");
                        return 0;
                    }
                }
                break;
            case 3:
                printf("\nYour stats:\n");
                printf("Health: %d\nGold: %d\nExperience: %d\nLevel: %d\n", health, gold, xp, level);
                break;
            case 4:
                printf("\nGame saved.\n");
                break;
            case 5:
                printf("\nThank you for playing, %s.\n", name);
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}