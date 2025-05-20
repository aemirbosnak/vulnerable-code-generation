//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 40   // Width of the screen
#define HEIGHT 20  // Height of the screen
#define MAX_ENEMIES 5 // Maximum number of enemies
#define ENEMY_SPEED 1 // Speed of the enemies
#define BULLET_SPEED 2 // Speed of the bullet
#define PLAYER_SPEED 1 // Speed of the player

// Function to sleep for a specified number of milliseconds
void sleep(unsigned int ms) {
    clock_t goal = ms + clock();
    while (goal > clock());
}

// Function to move the cursor to a specified position on the screen
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
}

// Structure to represent an entity on the screen (player, enemy, bullet)
typedef struct {
    int x, y;     // Position of the entity
    int width, height; // Size of the entity
    int dx, dy;   // Velocity of the entity
    char symbol;  // ASCII character to represent the entity on the screen
} entity;

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initialize the player entity
    entity player = { WIDTH / 2, HEIGHT - 2, 5, 1, 0, 0, '#' };

    // Initialize the enemy entities
    entity enemies[MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].x = rand() % WIDTH;
        enemies[i].y = rand() % HEIGHT;
        enemies[i].width = 3;
        enemies[i].height = 1;
        enemies[i].dx = ENEMY_SPEED;
        enemies[i].dy = 0;
        enemies[i].symbol = 'X';
    }

    // Initialize the bullet entity
    entity bullet = { 0, 0, 1, 1, 0, -BULLET_SPEED, '|' };

    int score = 0; // Keep track of the player's score
    int playing = 1; // Flag to indicate if the player is still playing

    while (playing) {
        // Clear the screen
        system("clear");

        // Move the player
        int c = getchar(); // Read a character from the keyboard
        if (c == 'a') {
            player.dx = -PLAYER_SPEED;
        } else if (c == 'd') {
            player.dx = PLAYER_SPEED;
        } else {
            player.dx = 0;
        }
        player.x += player.dx;

        // Keep the player within the bounds of the screen
        if (player.x < 0) {
            player.x = 0;
        } else if (player.x + player.width > WIDTH) {
            player.x = WIDTH - player.width;
        }

        // Move the enemies
        for (int i = 0; i < MAX_ENEMIES; i++) {
            enemies[i].x += enemies[i].dx;
            enemies[i].y += enemies[i].dy;

            // Reverse the direction of the enemy when it hits the edge of the screen
            if (enemies[i].x < 0 || enemies[i].x + enemies[i].width >= WIDTH) {
                enemies[i].dx = -enemies[i].dx;
            }

            // Check if the enemy has hit the player
            if (enemies[i].y == player.y && enemies[i].x <= player.x + player.width && enemies[i].x + enemies[i].width >= player.x) {
                playing = 0;
                break;
            }
        }

        // Move the bullet
        bullet.x += bullet.dx;
        bullet.y += bullet.dy;

        // Check if the bullet has hit any enemies
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (bullet.y == enemies[i].y && bullet.x >= enemies[i].x && bullet.x <= enemies[i].x + enemies[i].width) {
                enemies[i].y = -1;
                score++;
            }
        }

        // Draw the entities on the screen
        gotoxy(player.x, player.y);
        printf("%c", player.symbol);

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].y >= 0) {
                gotoxy(enemies[i].x, enemies[i].y);
                printf("%c", enemies[i].symbol);
            }
        }

        if (bullet.y >= 0) {
            gotoxy(bullet.x, bullet.y);
            printf("%c", bullet.symbol);
        }

        // Print the score on the screen
        gotoxy(WIDTH / 2, 0);
        printf("Score: %d", score);

        // Sleep for a short period of time to make the game playable
        sleep(100);

        // Reset the bullet if it has gone off the screen
        if (bullet.y < 0) {
            bullet.x = player.x + player.width / 2;
            bullet.y = player.y - 1;
        }
    }

    // Print the game over message
    gotoxy(WIDTH / 2 - 4, HEIGHT / 2);
    printf("Game Over");

    return 0;
}