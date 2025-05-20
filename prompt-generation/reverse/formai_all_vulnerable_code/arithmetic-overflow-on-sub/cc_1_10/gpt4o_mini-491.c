//GPT-4o-mini DATASET v1.0 Category: Space Invaders Game Clone ; Style: retro
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ALIENS 10
#define ALIEN_SYMBOL 'A'
#define PLAYER_SYMBOL '^'
#define BULLET_SYMBOL '|'

typedef struct {
    int x, y;
    int alive;
} Alien;

typedef struct {
    int x, y;
    int active;
} Bullet;

Alien aliens[MAX_ALIENS];
Bullet bullet;
int playerX;

void init_game() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100);

    playerX = COLS / 2;
    bullet.active = 0;

    for (int i = 0; i < MAX_ALIENS; i++) {
        aliens[i].x = 2 + i * 4;
        aliens[i].y = 1;
        aliens[i].alive = 1;
    }
}

void draw_player() {
    mvaddch(LINES - 1, playerX, PLAYER_SYMBOL);
}

void draw_bullet() {
    if (bullet.active) {
        mvaddch(bullet.y, bullet.x, BULLET_SYMBOL);
    }
}

void draw_aliens() {
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].alive) {
            mvaddch(aliens[i].y, aliens[i].x, ALIEN_SYMBOL);
        }
    }
}

void update_bullet() {
    if (bullet.active) {
        mvaddch(bullet.y, bullet.x, ' ');
        bullet.y--;

        if (bullet.y < 0) {
            bullet.active = 0;
        } else {
            for (int i = 0; i < MAX_ALIENS; i++) {
                if (aliens[i].alive && bullet.x == aliens[i].x && bullet.y == aliens[i].y) {
                    aliens[i].alive = 0;
                    bullet.active = 0;
                }
            }
        }
    }
}

void shoot() {
    if (!bullet.active) {
        bullet.x = playerX;
        bullet.y = LINES - 2;
        bullet.active = 1;
    }
}

void move_aliens() {
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].alive) {
            aliens[i].y++;
            if (aliens[i].y >= LINES - 1) {
                mvprintw(LINES / 2, COLS / 2 - 10, "Game Over!");
                refresh();
                usleep(2000000);
                endwin();
                exit(0);
            }
        }
    }
}

int main() {
    init_game();

    while (1) {
        clear();
        draw_bullet();
        draw_player();
        draw_aliens();
        refresh();

        int ch = getch();

        switch (ch) {
            case KEY_LEFT:
                if (playerX > 0) playerX--;
                break;
            case KEY_RIGHT:
                if (playerX < COLS - 1) playerX++;
                break;
            case ' ':
                shoot();
                break;
        }

        update_bullet();
        move_aliens();

        usleep(30000); // Slow down the game loop
    }

    endwin();
    return 0;
}