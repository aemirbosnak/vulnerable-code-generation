//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20], answer;
    int health = 100, stamina = 100, gold = 0;
    int potion = 3, food = 2;
    srand(time(0));
    
    printf("Welcome to Real-Life Adventure Game! What's your name?\n");
    scanf("%s", &name);
    printf("Welcome %s, let's begin..\n", name);

    printf("You wake up in a dark room and don't remember how you got here.\n");
    printf("You see two doors - one to your left and one to your right.\n");
    printf("Which door do you choose? (right/left)\n");
    scanf(" %c", &answer);
    if(answer == 'r') {
        printf("You chose the right door and entered a room.\n");
        printf("You see a chest in the room. Do you open it? (y/n)\n");
        scanf(" %c", &answer);
        if(answer == 'y') {
            printf("You found a potion and some gold!\n");
            potion++;
            gold += rand() % 50 + 10;
        } else {
            printf("You missed out on some loot!\n");
        }
        printf("As you were leaving the room, a monster appeared out of nowhere!\n");
        printf("What will you do?\n");
        printf("1. Fight\n");
        printf("2. Flee\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("You engaged in battle with the monster.\n");
            int monster_health = rand() % 50 + 50;
            while(health > 0 && monster_health > 0) {
                printf("Your health: %d, Monster's health: %d\n", health, monster_health);
                printf("What will you do?\n");
                printf("1. Attack\n");
                printf("2. Defend\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    int attack_damage = rand() % 20 + 10;
                    int monster_damage = rand() % 25 + 15;
                    printf("You dealt %d damage to the monster!\n", attack_damage);
                    monster_health -= attack_damage;
                    health -= monster_damage;
                } else {
                    int monster_damage = rand() % 10 + 5;
                    stamina -= 30;
                    printf("You defended the monster's attack, but lost some stamina.\n");
                    printf("Your stamina: %d\n", stamina);
                }
            }
            if(monster_health <= 0) {
                printf("Congratulations! You defeated the monster and gained some gold.\n");
                gold += rand() % 50 + 30;
            } else {
                printf("You were defeated by the monster. Game over!\n");
                exit(0);
            }
        } else {
            printf("You chose to flee from the monster.\n");
            stamina -= 20;
            printf("Your stamina: %d\n", stamina);
            printf("You successfully escaped, but lost some stamina in the process.\n");
        }
    } else {
        printf("You chose the left door and entered a room.\n");
        printf("You see a table with some food on it. Do you eat it? (y/n)\n");
        scanf(" %c", &answer);
        if(answer == 'y') {
            printf("You ate some food and feel energized!\n");
            food--;
            health += rand() % 20 + 10;
            stamina += rand() % 20 + 10;
            if(health > 100) health = 100;
            if(stamina > 100) stamina = 100;
        } else {
            printf("You decided not to eat the food.\n");
        }
        printf("As you were leaving the room, a trader appeared and offered to sell you some items.\n");
        printf("What will you do?\n");
        printf("1. Buy\n");
        printf("2. Decline\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("The trader offered you a potion and some food.\n");
            printf("Potion: 30 gold, Food: 20 gold each\n");
            printf("How many potions do you want to buy? (You currently have %d gold)\n", gold);
            scanf("%d", &choice);
            if(choice * 30 > gold) {
                printf("You don't have enough gold!\n");
            } else {
                printf("You bought %d potions and %d food.\n", choice, choice);
                potion += choice;
                food += choice;
                gold -= choice * 30;
            }
        } else {
            printf("You declined the trader's offer.\n");
        }
    }
    printf("You completed the first part of the game with %d health, %d stamina, and %d gold.\n", health, stamina, gold);
    printf("You have %d potions and %d food left.\n", potion, food);

    return 0;
}