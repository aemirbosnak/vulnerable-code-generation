//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void wait() {
    printf("\nPress any key to continue...\n");
    getchar(); 
}

int main() {
    char name[20];
    int health = 100;
    int attack = 10;
    int potion = 3;
    int choice;
    int monsterHealth = 0;
    int monsterAttack = 0;
    int gold = 0;
    int hasSword = 0;
    int hasShield = 0;
    int gameover = 0;
    
    printf("Hello, what is your name?\n");
    scanf("%s", name);
    printf("Welcome %s to the Text-Based Adventure Game.\n", name);
    printf("You were on a journey to find treasure but got lost and stumbled upon an unknown land.\n");
    printf("You were greeted by the resident town folk who told you about the monsters lurking around the town.\n");
    printf("As you entered the town, you encountered a strange man in a cloak that offered you a sword and shield for gold.\n");
    
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Go out of town to fight a monster\n");
        printf("2. Buy equipment\n");
        printf("3. Check gold and inventory\n");
        printf("4. Quit game\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                monsterHealth = rand() % 100 + 1;  
                monsterAttack = rand() % 10 + 1;
                printf("\nYou have encountered a monster!\n");
                
                while(health > 0 && monsterHealth > 0) {
                    printf("\nYour HP: %d | Monster's HP: %d\n", health, monsterHealth);
                    printf("What do you want to do?\n");
                    printf("1. Attack\n");
                    printf("2. Use Health Potion\n");
                    scanf("%d", &choice);
                    
                    switch(choice) {
                        case 1:
                            monsterHealth -= attack;
                            printf("\nYou dealt %d damage to the monster!\n", attack);
                            health -= monsterAttack;
                            printf("The monster dealt %d damage to you!\n", monsterAttack);
                            break;
                        case 2:
                            if(potion > 0) {
                                health += 20;
                                potion--;
                                printf("\nYou gained 20 hp!\n");
                                printf("You now have %d health potions left.\n", potion);
                                health -= monsterAttack;
                                printf("The monster dealt %d damage to you!\n", monsterAttack);
                            } else {
                                printf("\nYou have no health potions left!\n");
                            }
                            break;
                        default:
                            printf("\nInvalid choice! Please choose 1 or 2.\n");
                            break;
                    }
                    
                    if(health <= 0) {
                        printf("\nYou died!\n");
                        gameover = 1;
                        break;
                    } else if(monsterHealth <= 0) {
                        int monsterGold = rand() % 20 + 1;
                        gold += monsterGold;
                        printf("\nYou defeated the monster and gained %d gold!\n", monsterGold);
                        break;
                    }
                }
                break;
            
            case 2:
                printf("\nYou currently have %d gold.\n", gold);
                printf("What do you want to buy?\n");
                printf("1. Sword (50 gold)\n");
                printf("2. Shield (30 gold)\n");
                scanf("%d", &choice);
                
                switch(choice) {
                    case 1:
                        if(gold < 50) {
                            printf("\nYou do not have enough gold!\n");
                        } else {
                            gold -= 50;
                            attack += 10;
                            hasSword = 1;
                            printf("\nYou have purchased a sword!\n");
                        }
                        break;
                    case 2:
                        if(gold < 30) {
                            printf("\nYou do not have enough gold!\n");
                        } else {
                            gold -= 30;
                            hasShield = 1;
                            printf("\nYou have purchased a shield!\n");
                        }
                        break;
                    default:
                        printf("\nInvalid choice! Please choose 1 or 2.\n");
                        break;
                }
                break;
            
            case 3:
                printf("\nName: %s\n", name);
                printf("Health: %d\n", health);
                printf("Attack: %d\n", attack);
                printf("Gold: %d\n", gold);
                printf("Number of Health Potions: %d\n", potion);
                if(hasSword) {
                    printf("You have a sword.\n");
                }
                if(hasShield) {
                    printf("You have a shield.\n");
                }
                break;
            
            case 4:
                printf("\nThanks for playing!\n");
                gameover = 1;
                break;
            
            default:
                printf("\nInvalid choice! Please choose 1, 2, 3 or 4.\n");
                break;
        }
        
        wait();
        system("clear");
    } while(!gameover);
    
    return 0;
}