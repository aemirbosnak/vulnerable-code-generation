//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DIMENSION 5
#define MONSTER_COUNT 3

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int isAlive;
} Monster;

void initMonsters(Monster monsters[], int count);
void printHouse(char house[DIMENSION][DIMENSION], Position playerPos);
int movePlayer(Position *playerPos, char direction);
void attackMonster(Monster *monsters, int count, Position playerPos);
void displayResult(int monstersDefeated);

int main() {
    char house[DIMENSION][DIMENSION] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'M', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'm', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    Position playerPos = {0, 0};
    Monster monsters[MONSTER_COUNT];
    int action = 0;
    int monstersDefeated = 0;

    srand(time(NULL));
    initMonsters(monsters, MONSTER_COUNT);

    printf("Welcome to the C Haunted House Simulator!\n");

    while (action != 4) {
        printHouse(house, playerPos);
        printf("Choose your action:\n1. Move\n2. Attack\n3. Check Monsters\n4. Exit\n");
        scanf("%d", &action);

        switch (action) {
            case 1: {
                char direction;
                printf("Enter direction (w/a/s/d): ");
                scanf(" %c", &direction);
                if (movePlayer(&playerPos, direction)) {
                    printf("You moved to (%d, %d).\n", playerPos.x, playerPos.y);
                } else {
                    printf("Invalid move!\n");
                }
                break;
            }
            case 2:
                attackMonster(monsters, MONSTER_COUNT, playerPos);
                monstersDefeated++;
                break;
            case 3:
                printf("Current Monsters:\n");
                for (int i = 0; i < MONSTER_COUNT; i++) {
                    if (monsters[i].isAlive) {
                        printf("Monster %d is at (%d, %d).\n", i + 1, monsters[i].pos.x, monsters[i].pos.y);
                    }
                }
                break;
            case 4:
                printf("Exiting the game!\n");
                break;
            default:
                printf("Invalid action! Please choose again.\n");
                break;
        }
        sleep(1);
    }

    displayResult(monstersDefeated);
    return 0;
}

void initMonsters(Monster monsters[], int count) {
    for (int i = 0; i < count; i++) {
        monsters[i].pos.x = rand() % DIMENSION;
        monsters[i].pos.y = rand() % DIMENSION;
        monsters[i].isAlive = 1;
    }
}

void printHouse(char house[DIMENSION][DIMENSION], Position playerPos) {
    system("clear");
    house[playerPos.x][playerPos.y] = 'P';
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (house[i][j] == ' ') {
                printf(".");
            } else {
                printf("%c", house[i][j]);
            }
        }
        printf("\n");
    }
    house[playerPos.x][playerPos.y] = ' ';
}

int movePlayer(Position *playerPos, char direction) {
    switch (direction) {
        case 'w': 
            if (playerPos->x > 0) playerPos->x--;
            else return 0;
            break;
        case 's':
            if (playerPos->x < DIMENSION - 1) playerPos->x++;
            else return 0;
            break;
        case 'a':
            if (playerPos->y > 0) playerPos->y--;
            else return 0;
            break;
        case 'd':
            if (playerPos->y < DIMENSION - 1) playerPos->y++;
            else return 0;
            break;
        default:
            return 0;
    }
    return 1;
}

void attackMonster(Monster *monsters, int count, Position playerPos) {
    for (int i = 0; i < count; i++) {
        if (monsters[i].isAlive && monsters[i].pos.x == playerPos.x && monsters[i].pos.y == playerPos.y) {
            monsters[i].isAlive = 0;
            printf("You defeated a monster at (%d, %d)!\n", playerPos.x, playerPos.y);
            return;
        }
    }
    printf("No monster to attack here.\n");
}

void displayResult(int monstersDefeated) {
    printf("Game Over! You defeated %d monsters.\n", monstersDefeated);
}