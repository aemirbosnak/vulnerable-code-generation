//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define ROOM_SIZE 5
#define PLAYER_SYMBOL 'P'
#define EMPTY_SYMBOL '.'
#define MONSTER_SYMBOL 'M'

typedef enum { HUMAN, WOLF, DRAGON } Shape;

typedef struct {
    int x, y;
    Shape shape;
} Player;

typedef struct {
    int x, y;
    int health;
} Monster;

char dungeon[ROOM_SIZE][ROOM_SIZE];
Player player;
Monster monster;

void initializeDungeon();
void placeMonster();
void displayDungeon();
void playerMove(int dx, int dy);
void transformPlayer(Shape shape);
void generateRoom();
Shape getRandomShape();

int main() {
    srand(time(NULL));
    initializeDungeon();
    placeMonster();
    
    char command;
    while (1) {
        displayDungeon();
        printf("Enter command (w/a/s/d to move, t to transform, q to quit): ");
        scanf(" %c", &command);
        
        if (command == 'q') break;
        else if (command == 't') {
            transformPlayer(getRandomShape());
        } else if (command == 'w') playerMove(-1, 0);
        else if (command == 's') playerMove(1, 0);
        else if (command == 'a') playerMove(0, -1);
        else if (command == 'd') playerMove(0, 1);
        
        // Add any additional game logic here
    }
    
    return 0;
}

void initializeDungeon() {
    memset(dungeon, EMPTY_SYMBOL, sizeof(dungeon));
    player.x = ROOM_SIZE / 2;
    player.y = ROOM_SIZE / 2;
    player.shape = HUMAN;
    dungeon[player.x][player.y] = PLAYER_SYMBOL;
}

void placeMonster() {
    monster.x = rand() % ROOM_SIZE;
    monster.y = rand() % ROOM_SIZE;
    monster.health = 10; // Simple monster health
    if (monster.x == player.x && monster.y == player.y) {
        monster.x = (monster.x + 1) % ROOM_SIZE;
        monster.y = (monster.y + 1) % ROOM_SIZE; // Ensure monster is not at player position
    }
    dungeon[monster.x][monster.y] = MONSTER_SYMBOL;
}

void displayDungeon() {
    system("clear"); // Replace with system("cls") for Windows
    for (int i = 0; i < ROOM_SIZE; i++) {
        for (int j = 0; j < ROOM_SIZE; j++) {
            putchar(dungeon[i][j]);
        }
        putchar('\n');
    }
}

void playerMove(int dx, int dy) {
    // Calculate new position
    int newX = player.x + dx;
    int newY = player.y + dy;
    
    // Check boundaries
    if (newX >= 0 && newX < ROOM_SIZE && newY >= 0 && newY < ROOM_SIZE) {
        dungeon[player.x][player.y] = EMPTY_SYMBOL; // Clear old position
        player.x = newX;
        player.y = newY;
        dungeon[player.x][player.y] = PLAYER_SYMBOL; // Update new position
    }
}

void transformPlayer(Shape shape) {
    player.shape = shape;
    // You can implement different abilities based on the shape
    switch (shape) {
        case HUMAN: 
            printf("You transformed into a Human!\n");
            break;
        case WOLF: 
            printf("You transformed into a Wolf! Speed increases!\n");
            break;
        case DRAGON: 
            printf("You transformed into a Dragon! Powerful attack!\n");
            break;
    }
}

Shape getRandomShape() {
    return rand() % 3;
}