//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

int main() 
{ 
    // Initialize the game
    printf("Welcome to the Cryptic Maze Game!\n");
    printf("You are trapped in a maze with multiple rooms filled with obstacles and enemies.\n");
    printf("Your objective is to find the way out of the maze and reach the end point.\n");
    printf("Do you want to start the game? (y/n): ");
    char start;
    scanf("%c", &start);
    if (start == 'n') {
        printf("Game Over. Bye!\n");
        return 0;
    }
    else if (start != 'y') {
        printf("Invalid input. Exiting the game.\n");
        return 0;
    }
    
    // Initialize variables
    srand(time(NULL)); 
    int playerHealth = 100;
    int playerAttack = 20;
    
    // Initialize the maze structure
    enum Rooms {
        EMPTY,
        OBSTACLE,
        ENEMY,
        TREASURE,
        ENDPOINT
    };
    int maze[10][10];
    int startX = rand() % 10;
    int startY = rand() % 10;
    maze[startX][startY] = EMPTY;
    int endX, endY;
    do {
        endX = rand() % 10;
        endY = rand() % 10;
    } while (endX == startX && endY == startY);
    maze[endX][endY] = ENDPOINT;
    int numObstacles = 10 + rand() % 10;
    for (int i = 0; i < numObstacles; i++) {
        int obsX, obsY;
        do {
            obsX = rand() % 10;
            obsY = rand() % 10;
        } while (maze[obsX][obsY] != 0 && (obsX != startX || obsY != startY) && (obsX != endX || obsY != endY));
        maze[obsX][obsY] = OBSTACLE;
    }
    int numEnemies = 5 + rand() % 5;
    for (int i = 0; i < numEnemies; i++) {
        int enemyX, enemyY;
        do {
            enemyX = rand() % 10;
            enemyY = rand() % 10;
        } while (maze[enemyX][enemyY] != 0 && (enemyX != startX || enemyY != startY) && (enemyX != endX || enemyY != endY));
        maze[enemyX][enemyY] = ENEMY;
    }
    int numTreasures = 5 + rand() % 5;
    for (int i = 0; i < numTreasures; i++) {
        int treasureX, treasureY;
        do {
            treasureX = rand() % 10;
            treasureY = rand() % 10;
        } while (maze[treasureX][treasureY] != 0 && (treasureX != startX || treasureY != startY) && (treasureX != endX || treasureY != endY));
        maze[treasureX][treasureY] = TREASURE;
    }
    
    // Initialize player position
    int playerX = startX;
    int playerY = startY;
    
    // Start the game loop
    while (maze[playerX][playerY] != ENDPOINT) {
        // Show the maze state
        printf("Current Health: %d\n", playerHealth);
        printf("Current Attack: %d\n", playerAttack);
        printf("\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == playerX && j == playerY) {
                    printf(" P ");
                }
                else {
                    switch (maze[i][j]) {
                        case EMPTY:
                            printf(" . ");
                            break;
                        case OBSTACLE:
                            printf(" X ");
                            break;
                        case ENEMY:
                            printf(" E ");
                            break;
                        case TREASURE:
                            printf(" $ ");
                            break;
                        case ENDPOINT:
                            printf(" F ");
                            break;
                    }
                }
            }
            printf("\n");
        }
        
        // Take user input and move the player
        printf("Enter 'w' for up, 'a' for left, 's' for down, 'd' for right, or 'q' to quit: ");
        char input;
        scanf(" %c", &input);
        int moveX = 0;
        int moveY = 0;
        switch (input) {
            case 'w':
                moveX = -1;
                break;
            case 'a':
                moveY = -1;
                break;
            case 's':
                moveX = 1;
                break;
            case 'd':
                moveY = 1;
                break;
            case 'q':
                printf("Game Over. Bye!\n");
                return 0;
            default:
                printf("Invalid input.\n");
                continue;
        }
        int newX = playerX + moveX;
        int newY = playerY + moveY;
        if (newX < 0 || newX >= 10 || newY < 0 || newY >= 10) {
            printf("Cannot move out of bounds.\n");
            continue;
        }
        if (maze[newX][newY] == OBSTACLE) {
            printf("Cannot move through obstacle.\n");
            continue;
        }
        if (maze[newX][newY] == ENEMY) {
            playerHealth -= rand() % 20;
            printf("Encountered an enemy! Current Health: %d\n", playerHealth);
            if (playerHealth <= 0) {
                printf("Game Over. Player died.\n");
                return 0;
            }
            int enemyHealth = 50 + rand() % 50;
            int enemyAttack = 10 + rand() % 20;
            while (playerHealth > 0 && enemyHealth > 0) {
                printf("Player attacks enemy for %d damage.\n", playerAttack);
                enemyHealth -= playerAttack;
                printf("Enemy health: %d\n", enemyHealth);
                if (enemyHealth <= 0) {
                    printf("Enemy defeated!\n");
                    break;
                }
                printf("Enemy attacks player for %d damage.\n", enemyAttack);
                playerHealth -= enemyAttack;
                printf("Player health: %d\n", playerHealth);
                if (playerHealth <= 0) {
                    printf("Game Over. Player died.\n");
                    return 0;
                }
            }
            maze[newX][newY] = EMPTY;
        }
        if (maze[newX][newY] == TREASURE) {
            int treasureAmount = 50 + rand() % 50;
            printf("You found a treasure chest with %d gold coins!\n", treasureAmount);
            playerAttack += treasureAmount / 10;
            playerHealth += treasureAmount / 5;
            printf("Current Attack: %d\n", playerAttack);
            printf("Current Health: %d\n", playerHealth);
            maze[newX][newY] = EMPTY;
        }
        playerX = newX;
        playerY = newY;
    }
    
    // Player reached the endpoint, game over and victory!
    printf("Congratulations! You've reached the endpoint and finished the game!\n"); 
    return 0; 
}