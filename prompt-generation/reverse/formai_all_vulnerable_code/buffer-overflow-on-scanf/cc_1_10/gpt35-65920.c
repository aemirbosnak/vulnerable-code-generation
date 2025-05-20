//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100;
int money = 100;

void intro();
void mainMenu();
void forest();
void fight();
void shop();

int main() {
    srand(time(NULL));
    intro();
    mainMenu();
    return 0;
}

void intro() {
    printf("Welcome to Adventure Game!\n\n");
    printf("You are a brave adventurer on a quest to defeat the evil dragon and save the kingdom.\n");
    printf("You start out with 100 health and 100 gold.\n\n");
}

void mainMenu() {
    printf("MAIN MENU\n");
    printf("1. Go to the forest\n");
    printf("2. Go to the shop\n");
    printf("3. Check Stats\n");
    printf("4. Quit game\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            forest();
            break;
        case 2:
            shop();
            break;
        case 3:
            printf("Health: %d\n", health);
            printf("Gold: %d\n", money);
            mainMenu();
            break;
        case 4:
            printf("Thanks for playing!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            mainMenu();
            break;
    }
}

void forest() {
    printf("\nYou enter the forest and encounter a goblin!\n");
    printf("1. Fight\n");
    printf("2. Run\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fight();
            break;
        case 2:
            printf("You run away from the goblin. Coward!\n");
            mainMenu();
            break;
        default:
            printf("Invalid choice.\n");
            forest();
            break;
    }
}

void fight() {
    int goblinHealth = 50 + rand() % 50;
    printf("\nYou fight the goblin!\n");
    while (goblinHealth > 0) {
        printf("Your health: %d\n", health);
        printf("Goblin's health: %d\n", goblinHealth);
        printf("1. Attack\n");
        printf("2. Run\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                goblinHealth -= 25 + rand() % 25;
                health -= 10 + rand() % 10;
                if (health <= 0) {
                    printf("You died. Game over.\n");
                    exit(0);
                }
                printf("You attack the goblin and deal %d damage.\n", 25 + rand() % 25);
                break;
            case 2:
                printf("You run away from the goblin. Coward!\n");
                mainMenu();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    printf("You defeated the goblin! You gain 50 gold.\n");
    money += 50;
    mainMenu();
}

void shop() {
    printf("\nWelcome to the shop!\n");
    printf("1. Purchase a health potion for 25 gold\n");
    printf("2. Purchase a sword for 50 gold\n");
    printf("3. Leave the shop\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (money >= 25) {
                printf("You purchased a health potion!\n");
                money -= 25;
                health += 25 + rand() % 25;
                if (health > 100) {
                    health = 100;
                }
            }
            else {
                printf("You do not have enough gold.\n");
            }
            shop();
            break;
        case 2:
            if (money >= 50) {
                printf("You purchased a sword!\n");
                money -= 50;
            }
            else {
                printf("You do not have enough gold.\n");
            }
            shop();
            break;
        case 3:
            printf("You leave the shop.\n");
            mainMenu();
            break;
        default:
            printf("Invalid choice.\n");
            shop();
            break;
    }
}