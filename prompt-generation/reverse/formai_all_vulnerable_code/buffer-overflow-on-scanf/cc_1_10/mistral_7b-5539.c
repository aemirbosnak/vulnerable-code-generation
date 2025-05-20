//MISTRAL-7B DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_HEALTH 100
#define MAX_GOLD 1000
#define MAX_DAMAGE 20
#define MIN_DAMAGE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int gold;
} Character;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
} Dragon;

void print_intro() {
    printf("Welcome, brave knight,\n");
    printf("Thou art in the land of Eldoria,\n");
    printf("Where dragons terrorize the peaceful village.\n");
    printf("Thy quest is to defeat the dragon\n");
    printf("And save the village from its wrath.\n");
}

void create_knight(Character *knight) {
    printf("Enter thy noble name: ");
    scanf("%s", knight->name);
    knight->health = MAX_HEALTH;
    knight->gold = 0;
}

void create_dragon(Dragon *dragon) {
    strcpy(dragon->name, "Dragon of Eldoria");
    dragon->health = 150;
    dragon->damage = rand() % (MAX_DAMAGE - MIN_DAMAGE + 1) + MIN_DAMAGE;
}

int main() {
    srand(time(NULL));
    Character knight;
    Dragon dragon;
    int choice;

    print_intro();
    create_knight(&knight);
    create_dragon(&dragon);

    while (1) {
        printf("\nWhat shall our brave knight do?\n");
        printf("1. Travel to the village and rest.\n");
        printf("2. Attack the dragon directly.\n");
        printf("Enter thy choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Thou art now in the peaceful village.\n");
                knight.health += 10;
                printf("Thy gold: %d\n", knight.gold);
                break;
            case 2:
                if (knight.health >= dragon.damage) {
                    knight.health -= dragon.damage;
                    dragon.health -= MAX_DAMAGE;
                    knight.gold += 50;
                    printf("Thou hast dealt damage to the dragon!\n");
                    printf("Dragon's health: %d\n", dragon.health);
                    if (dragon.health <= 0) {
                        printf("The dragon is slain!\n");
                        printf("Thou art a true hero!\n");
                        break;
                    }
                } else {
                    printf("Thou canst not attack the dragon.\n");
                    knight.health -= 10;
                    printf("Thy health: %d\n", knight.health);
                    break;
                }
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (knight.health <= 0) {
            printf("Thou hast perished in thy quest.\n");
            printf("May thy spirit rest in peace.\n");
            break;
        }
    }

    return 0;
}