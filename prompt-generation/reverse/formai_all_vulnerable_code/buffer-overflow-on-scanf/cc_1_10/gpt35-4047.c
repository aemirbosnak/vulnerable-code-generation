//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct for player
struct player {
    char name[20];
    int health;
    int damage;
    int potionCount;
};

// Define struct for enemy
struct enemy {
    char name[20];
    int health;
    int damage;
};

// Function to generate random number between min and max (inclusive)
int randNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate fight between player and enemy
int runFight(struct player *p, struct enemy *e) {
    int turn = 1;
    while (p->health > 0 && e->health > 0) {
        if (turn % 2 == 1) {
            // Player's turn
            printf("%s attacks %s with a damage of %d.\n", p->name, e->name, p->damage);
            e->health -= p->damage;
        } else {
            // Enemy's turn
            printf("%s attacks %s with a damage of %d.\n", e->name, p->name, e->damage);
            p->health -= e->damage;
        }
        turn++;
    }
    if (p->health > 0) {
        printf("%s wins!\n", p->name);
        return 1;
    } else {
        printf("%s wins!\n", e->name);
        return 0;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize player and enemy
    struct player player1;
    struct enemy enemy1;
    
    // Initialize player's attributes
    printf("Hello! What is your name?\n");
    scanf("%s", player1.name);
    player1.health = 100;
    player1.damage = 10;
    player1.potionCount = 3;
    
    // Initialize enemy's attributes with random values
    strcpy(enemy1.name, "Evil Monster");
    enemy1.health = randNumber(50, 100);
    enemy1.damage = randNumber(5, 15);
    
    // Introduce player to game
    printf("Welcome %s! Prepare to embark on an adventure!\n", player1.name);
    printf("You find yourself in a dark forest with a path leading to your left and right.\n");
    
    // Ask player for input
    char choice[10];
    printf("Which direction do you choose? (left/right)\n");
    scanf("%s", choice);
    
    if (strcmp(choice, "left") == 0) {
        // Player encounters enemy
        printf("As you walk down the left path, you encounter a fierce %s!\n", enemy1.name);
        
        // Simulate fight between player and enemy
        if (runFight(&player1, &enemy1) == 1) {
            printf("You defeated the %s!\n", enemy1.name);
        } else {
            printf("Game over! Try again next time!\n");
            return 0;
        }
        
        // Give player potion as reward
        printf("Congratulations! You found a potion!\n");
        player1.potionCount++;
    } else if (strcmp(choice, "right") == 0) {
        // Player finds treasure
        printf("As you walk down the right path, you find a treasure chest!\n");
        printf("Inside the treasure chest, you find a powerful sword!\n");
        player1.damage += 10;
    } else {
        printf("Invalid input! Try again next time!\n");
        return 0;
    }
    
    // Ask player if they want to continue
    printf("Do you want to continue? (yes/no)\n");
    scanf("%s", choice);
    
    if (strcmp(choice, "yes") == 0) {
        // Player encounters final boss
        printf("As you continue on your journey, you find yourself face-to-face with the final boss!\n");
        
        // Initialize final boss attributes with random values
        struct enemy finalBoss;
        strcpy(finalBoss.name, "Dark Lord");
        finalBoss.health = randNumber(100, 200);
        finalBoss.damage = randNumber(10, 20);
        
        // Simulate fight between player and final boss
        if (runFight(&player1, &finalBoss) == 1) {
            printf("Congratulations! You have defeated the final boss and won the game!\n");
        } else {
            printf("Game over! Try again next time!\n");
        }
    } else {
        printf("Thanks for playing! See you next time!\n");
    }
    
    return 0;
}