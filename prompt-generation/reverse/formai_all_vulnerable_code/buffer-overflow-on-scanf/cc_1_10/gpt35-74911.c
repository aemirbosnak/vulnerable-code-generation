//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Player {
    char name[20];
    int health;
    int gold;
} player;

struct Enemy {
    char name[20];
    int health;
} enemy;

void gameOver() {
    printf("\n\n**********************************\n");
    printf("        GAME OVER\n");
    printf("**********************************\n");
    exit(0);
}

void win() {
    printf("\n\n**********************************\n");
    printf("        %s is defeated!\n", enemy.name);
    printf("        You have earned %d gold.\n", enemy.health);
    printf("**********************************\n");
    player.gold += enemy.health;
}

void battle() {
    printf("\n\n**********************************\n");
    printf("        YOU ARE ATTACKED BY %s!\n", enemy.name);
    printf("**********************************\n");

    while (player.health > 0 && enemy.health > 0) {
        int player_damage = rand() % 10 + 1;
        int enemy_damage = rand() % 5 + 1;

        printf("\n%s attacks! You lose %d health points.\n", enemy.name, enemy_damage);
        player.health -= enemy_damage;
        printf("You attack back! %s loses %d health points.\n", enemy.name, player_damage);
        enemy.health -= player_damage;

        printf("You have %d health points left.\n", player.health);
        printf("%s has %d health points left.\n", enemy.name, enemy.health);
    }

    if (player.health <= 0) {
        printf("\n\n**********************************\n");
        printf("        YOU ARE DEAD!\n");
        printf("**********************************\n");
        gameOver();
    }

    win();
}

void explore() {
    int x = rand() % 3 + 1;

    switch(x) {
        case 1:
            strcpy(enemy.name, "Troll");
            enemy.health = 10;
            break;
        case 2:
            strcpy(enemy.name, "Goblin");
            enemy.health = 8;
            break;
        case 3:
            strcpy(enemy.name, "Dragon");
            enemy.health = 15;
            break;
    }

    battle();
}

void shop() {
    printf("\n\n**********************************\n");
    printf("        WELCOME TO THE SHOP!\n");
    printf("        YOU HAVE %d GOLD.\n", player.gold);
    printf("**********************************\n");

    int choice;

    do {
        printf("\nWhat would you like to buy?\n");
        printf("1. Potion (+5 health) - 5 gold\n");
        printf("2. Sword (+3 attack) - 10 gold\n");
        printf("3. Leave Shop\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (player.gold >= 5) {
                    player.health += 5;
                    player.gold -= 5;
                    printf("\nYou bought a potion! Your health is now %d.\n", player.health);
                } else {
                    printf("\nYou cannot afford that!\n");
                }
                break;
            case 2:
                if (player.gold >= 10) {
                    player.gold -= 10;
                    printf("\nYou bought a sword! Your attack is now stronger.\n");
                } else {
                    printf("\nYou cannot afford that!\n");
                }
                break;
            case 3:
                printf("\nYou left the shop.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 3);

}

int main() {
    srand(time(NULL));

    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = 25;
    player.gold = 0;

    printf("\n\n\t   ~~~~~ WELCOME %s ~~~~~\n", player.name);
    printf("\n\n**********************************\n");
    printf("        Instructions:\n");
    printf("        Explore to fight enemies and earn gold.\n");
    printf("        Use gold to buy potions and swords.\n");
    printf("        You lose if you die in battle.\n");
    printf("**********************************\n");

    int choice;

    do{
        printf("\n\nWhat would you like to do?\n");
        printf("1. Explore\n");
        printf("2. Shop\n");
        printf("3. Quit Game\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                explore();
                break;
            case 2:
                shop();
                break;
            case 3:
                printf("\n\nThanks for playing, %s!\n", player.name);
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}