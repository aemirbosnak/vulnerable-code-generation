//GPT-4o-mini DATASET v1.0 Category: Space Invaders Game Clone ; Style: Linus Torvalds
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define ENEMY_CHAR 'M'
#define PLAYER_CHAR 'A'
#define BULLET_CHAR '|'
#define MAX_BULLETS 5

typedef struct {
    int x;
    int y;
    int active;
} Bullet;

typedef struct {
    int x;
    int y;
} Enemy;

void initializeEnemies(Enemy enemies[], int count) {
    for (int i = 0; i < count; i++) {
        enemies[i].x = rand() % (COLS - 2) + 1;
        enemies[i].y = (rand() % 5) + 1; // Top rows for enemies
    }
}

void drawEnemy(Enemy enemy) {
    mvaddch(enemy.y, enemy.x, ENEMY_CHAR);
}

void drawPlayer(int playerX, int playerY) {
    mvaddch(playerY, playerX, PLAYER_CHAR);
}

void drawBullet(Bullet bullet) {
    if (bullet.active) {
        mvaddch(bullet.y, bullet.x, BULLET_CHAR);
    }
}

void updateBullet(Bullet *bullet) {
    if (bullet->active) {
        bullet->y--;
        if (bullet->y < 0) {
            bullet->active = 0; // Mark bullet as inactive
        }
    }
}

int main() {
    int playerX, playerY;
    Enemy enemies[MAX_ENEMIES];
    Bullet bullets[MAX_BULLETS];
    int ch;
    int enemyCount = 5; // Define how many enemies
    int score = 0;

    srand(time(NULL));
    initscr(); // Start curses mode
    noecho(); // Don't echo pressed keys
    cbreak(); // Disable line buffering
    timeout(100); // Non-blocking input
    curs_set(0); // Hide the cursor

    playerX = COLS / 2;
    playerY = LINES - 1;

    initializeEnemies(enemies, enemyCount);

    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = 0; // Initialize bullets as inactive
    }

    while (1) {
        clear(); // Clear the screen

        // Draw enemies
        for (int i = 0; i < enemyCount; i++) {
            drawEnemy(enemies[i]);
        }

        // Draw player
        drawPlayer(playerX, playerY);

        // Draw bullets
        for (int i = 0; i < MAX_BULLETS; i++) {
            drawBullet(bullets[i]);
        }

        // Print score
        mvprintw(0, 0, "Score: %d", score);

        // Get user input
        ch = getch(); // Non-blocking
        switch (ch) {
            case 'a': // Move left
                if (playerX > 0) playerX--;
                break;
            case 'd': // Move right
                if (playerX < COLS - 1) playerX++;
                break;
            case ' ': // Shoot
                for (int i = 0; i < MAX_BULLETS; i++) {
                    if (!bullets[i].active) {
                        bullets[i].x = playerX;
                        bullets[i].y = playerY - 1;
                        bullets[i].active = 1;
                        break;
                    }
                }
                break;
            case 'q': // Quit
                endwin();
                return 0;
            default:
                break;
        }

        // Update bullets
        for (int i = 0; i < MAX_BULLETS; i++) {
            updateBullet(&bullets[i]);
        }

        // Check for bullet collisions with enemies
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (bullets[i].active) {
                for (int j = 0; j < enemyCount; j++) {
                    if (bullets[i].y == enemies[j].y && bullets[i].x == enemies[j].x) {
                        bullets[i].active = 0; // Deactivate bullet
                        enemies[j].x = rand() % (COLS - 2) + 1; // Respawn enemy
                        enemies[j].y = (rand() % 5) + 1;
                        score += 10; // Increase score
                    }
                }
            }
        }

        refresh(); // Refresh screen
        usleep(100000); // Delay to control game speed
    }

    endwin(); // End curses mode
    return 0;
}