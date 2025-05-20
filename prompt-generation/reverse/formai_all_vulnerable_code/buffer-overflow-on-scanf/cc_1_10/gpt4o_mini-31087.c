//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_ENEMIES 5

typedef struct {
    char name[20];
    int attack;
    int defense;
} Character;

typedef struct {
    char name[20];
    int power;
} Item;

void initializeCharacter(Character *hero) {
    printf("Enter the name of thy brave hero: ");
    scanf("%s", hero->name);
    hero->attack = 10;
    hero->defense = 5;
}

void initializeItems(Item items[]) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        snprintf(items[i].name, sizeof(items[i].name), "Item%d", i + 1);
        items[i].power = rand() % 10 + 1; // Random power between 1 and 10
    }
}

void displayItems(Item items[]) {
    printf("List of mystical items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s (Power: %d)\n", i + 1, items[i].name, items[i].power);
    }
}

int main() {
    srand(time(NULL));
    
    Character hero;
    initializeCharacter(&hero);
    
    Item items[MAX_ITEMS];
    initializeItems(items);
    
    int action = 0, item_choice, enemy_power;

    while (action != 3) {
        printf("\nBrave %s, choose an action:\n", hero.name);
        printf("1. View items\n");
        printf("2. Encounter an enemy\n");
        printf("3. Flee to safety\n");
        printf("Select thine action: ");
        scanf("%d", &action);
        
        switch (action) {
            case 1:
                displayItems(items);
                break;
            case 2:
                // Simulate an enemy encounter
                enemy_power = rand() % 20 + 1; // Random enemy power between 1 and 20
                printf("Thy foe approaches, with a might of %d!\n", enemy_power);
                
                if (enemy_power <= hero.attack + hero.defense) {
                    printf("Thou hast vanquished the enemy!\n");
                } else {
                    printf("Alas! The enemy hath defeated thee! Thy strength is insufficient.\n");
                }
                break;
            case 3:
                printf("Thou hast fled to safety. A wise choice!\n");
                break;
            default:
                printf("Choose a most noble action!\n");
        }
    }
    
    printf("Farewell, %s! Until our paths cross again!\n", hero.name);
    return 0;
}