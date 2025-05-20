//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define functions and structs for the game
typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    char name[50];
    int health;
    int damage;
    Position position;
} Spaceship;

// function to move the spaceship
void move(Spaceship *ship, int x, int y, int z) {
    ship->position.x += x;
    ship->position.y += y;
    ship->position.z += z;
}

// function to attack the enemy spaceship
void attack(Spaceship *attacker, Spaceship *defender) {
    defender->health -= attacker->damage;
}

int main() {
    // initialize the game world and players
    Spaceship player1 = {"Player 1", 100, 10, {0, 0, 0}};
    Spaceship player2 = {"Player 2", 100, 10, {10, 10, 10}};
    
    // connect to the multiplayer server and start the game loop
    while (1) {
        // get user input and update the game state
        char input[10];
        printf("Enter your command: ");
        scanf("%s", input);
        if (strcmp(input, "move") == 0) {
            int x, y, z;
            printf("Enter your movement vector (x y z): ");
            scanf("%d %d %d", &x, &y, &z);
            move(&player1, x, y, z);
        }
        else if (strcmp(input, "attack") == 0) {
            attack(&player1, &player2);
        }
        else {
            printf("Invalid command.\n");
        }
        
        // print the game state and score
        printf("Player 1: %s, %d health, position (%d,%d,%d)\n", player1.name, player1.health, player1.position.x, player1.position.y, player1.position.z);
        printf("Player 2: %s, %d health, position (%d,%d,%d)\n", player2.name, player2.health, player2.position.x, player2.position.y, player2.position.z);
        if (player2.health <= 0) {
            printf("Game over! Player 1 wins!\n");
            break;
        }
    }
    
    return 0;
}