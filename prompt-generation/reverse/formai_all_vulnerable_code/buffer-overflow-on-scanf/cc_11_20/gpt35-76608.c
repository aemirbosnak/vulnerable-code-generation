//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int health = 100, attack = 5, defense = 3, gold = 0;
    int monsterType, monsterHealth, monsterAttack, monsterDefense, monsterGold;
    int choice, chance;
    srand(time(0));
    
    printf("Welcome to the Statistical Adventure Game!\n");
    printf("Your stats: Health: %d, Attack: %d, Defense: %d, Gold: %d\n\n", health, attack, defense, gold);
    
    while (health > 0) {
        monsterType = rand() % 3 + 1;
        
        switch (monsterType) {
            case 1:
                monsterHealth = 50;
                monsterAttack = 10;
                monsterDefense = 2;
                monsterGold = rand() % 10 + 1;
                printf("You encounter a Goblin with %d health and %d attack!\n", monsterHealth, monsterAttack);
                break;
            case 2:
                monsterHealth = 70;
                monsterAttack = 15;
                monsterDefense = 5;
                monsterGold = rand() % 20 + 1;
                printf("You encounter an Orc with %d health and %d attack!\n", monsterHealth, monsterAttack);
                break;
            case 3:
                monsterHealth = 100;
                monsterAttack = 20;
                monsterDefense = 10;
                monsterGold = rand() % 30 + 1;
                printf("You encounter a Dragon with %d health and %d attack!\n", monsterHealth, monsterAttack);
                break;
        }
        
        while (monsterHealth > 0 && health > 0) {
            printf("What do you want to do?\n");
            printf("1. Attack\n");
            printf("2. Defend\n");
            printf("3. Run\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            
            switch (choice) {
                case 1:
                    chance = rand() % 10 + 1;
                    if (chance > monsterDefense) {
                        monsterHealth -= attack;
                        printf("You hit the monster for %d damage!\n", attack);
                    } else {
                        printf("The monster blocks your attack!\n");
                    }
                    chance = rand() % 10 + 1;
                    if (chance > defense) {
                        health -= monsterAttack;
                        printf("The monster hits you for %d damage!\n", monsterAttack);
                    } else {
                        printf("You successfully defend against the monster's attack!\n");
                    }
                    break;
                case 2:
                    defense += 2;
                    printf("You defend yourself and increase your defense by 2!\n");
                    chance = rand() % 10 + 1;
                    if (chance > defense) {
                        health -= monsterAttack / 2;
                        printf("The monster hits you for %d damage!\n", monsterAttack / 2);
                    } else {
                        printf("You successfully defend against the monster's attack!\n");
                    }
                    break;
                case 3:
                    chance = rand() % 10 + 1;
                    if (chance > 5) {
                        printf("You successfully run away!\n");
                        monsterHealth = 0;
                    } else {
                        printf("You try to run away but the monster catches you!\n");
                        chance = rand() % 10 + 1;
                        if (chance > defense) {
                            health -= monsterAttack;
                            printf("The monster hits you for %d damage!\n", monsterAttack);
                        } else {
                            printf("You successfully defend against the monster's attack!\n");
                        }
                    }
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
            
            if (monsterHealth <= 0) {
                printf("You defeated the monster and earned %d gold!\n", monsterGold);
                gold += monsterGold;
            } else if (health <= 0) {
                printf("You died!\n");
            }
        }
        
        printf("\nYour stats: Health: %d, Attack: %d, Defense: %d, Gold: %d\n\n", health, attack, defense, gold);
    }
    
    printf("Game over!\n");
    
    return 0;
}