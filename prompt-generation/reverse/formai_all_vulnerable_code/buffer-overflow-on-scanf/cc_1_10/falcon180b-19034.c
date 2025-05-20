//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int gold = 0;
    int xp = 0;
    int level = 1;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a young adventurer on a quest to find treasure and defeat monsters.\n");
    printf("You start in a small village with nothing but the clothes on your back.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the village\n");
    printf("2. Go to the forest\n");
    printf("3. Visit the blacksmith\n");
    printf("4. Enter the dungeon\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You explore the village and find a hidden stash of gold!\n");
            gold += rand() % 50 + 1;
            printf("You now have %d gold.\n", gold);
            break;
        case 2:
            printf("You enter the forest and encounter a wild boar!\n");
            int boarHealth = rand() % 50 + 1;
            while(health > 0 && boarHealth > 0) {
                printf("The boar attacks you for %d damage!\n", rand() % 10 + 1);
                health -= rand() % 10 + 1;
                printf("You attack the boar for %d damage!\n", rand() % 10 + 1);
                boarHealth -= rand() % 10 + 1;
            }
            if(health <= 0) {
                printf("You have been defeated by the boar.\n");
                return 0;
            } else {
                printf("You have defeated the boar and gained %d XP!\n", rand() % 10 + 1);
                xp += rand() % 10 + 1;
            }
            break;
        case 3:
            printf("You visit the blacksmith and buy a sword for %d gold.\n", rand() % 50 + 1);
            gold -= rand() % 50 + 1;
            printf("You now have %d gold and a sword.\n", gold);
            break;
        case 4:
            printf("You enter the dungeon and find a treasure chest!\n");
            int chestGold = rand() % 100 + 1;
            gold += chestGold;
            printf("You now have %d gold.\n", gold);
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("You have gained %d XP and are now level %d!\n", xp, level);

    return 0;
}