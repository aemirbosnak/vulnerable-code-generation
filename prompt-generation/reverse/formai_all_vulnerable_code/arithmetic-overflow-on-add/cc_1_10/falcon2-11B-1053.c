//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define PACMAN_IMG "pacman.bmp"
#define PELLET_IMG "pellet.bmp"
#define GHOST_IMG "ghost.bmp"
#define KEY_RIGHT 'D'
#define KEY_LEFT 'A'
#define KEY_UP 'W'
#define KEY_DOWN 'S'

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
} position;

typedef struct {
    position pacman;
    position pellets;
    position ghosts;
} game;

void init_game(game* game) {
    srand(time(NULL));
    game->pacman.x = rand() % (SCREEN_WIDTH - 1);
    game->pacman.y = rand() % (SCREEN_HEIGHT - 1);
    game->pellets.x = rand() % (SCREEN_WIDTH - 1);
    game->pellets.y = rand() % (SCREEN_HEIGHT - 1);
    game->ghosts.x = rand() % (SCREEN_WIDTH - 1);
    game->ghosts.y = rand() % (SCREEN_HEIGHT - 1);
}

void move_pacman(game* game) {
    int key = getchar();
    if (key == KEY_RIGHT) {
        game->pacman.dx = 1;
    } else if (key == KEY_LEFT) {
        game->pacman.dx = -1;
    } else if (key == KEY_UP) {
        game->pacman.dy = -1;
    } else if (key == KEY_DOWN) {
        game->pacman.dy = 1;
    }
    game->pacman.x += game->pacman.dx;
    game->pacman.y += game->pacman.dy;
}

void move_pellets(game* game) {
    srand(time(NULL));
    game->pellets.x += 1;
    game->pellets.y += 1;
    if (game->pellets.x >= SCREEN_WIDTH || game->pellets.x < 0) {
        game->pellets.x = rand() % (SCREEN_WIDTH - 1);
        game->pellets.y = rand() % (SCREEN_HEIGHT - 1);
    }
    if (game->pellets.y >= SCREEN_HEIGHT || game->pellets.y < 0) {
        game->pellets.x = rand() % (SCREEN_WIDTH - 1);
        game->pellets.y = rand() % (SCREEN_HEIGHT - 1);
    }
}

void move_ghosts(game* game) {
    srand(time(NULL));
    game->ghosts.x += 1;
    game->ghosts.y += 1;
    if (game->ghosts.x >= SCREEN_WIDTH || game->ghosts.x < 0) {
        game->ghosts.x = rand() % (SCREEN_WIDTH - 1);
        game->ghosts.y = rand() % (SCREEN_HEIGHT - 1);
    }
    if (game->ghosts.y >= SCREEN_HEIGHT || game->ghosts.y < 0) {
        game->ghosts.x = rand() % (SCREEN_WIDTH - 1);
        game->ghosts.y = rand() % (SCREEN_HEIGHT - 1);
    }
}

void draw_game(game* game, int x, int y) {
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            printf(" ");
        }
        printf("\n");
    }
    printf("Pellets: ");
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            if (i == game->pellets.x && j == game->pellets.y) {
                printf("%s", PELLET_IMG);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Pacman: ");
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            if (i == game->pacman.x && j == game->pacman.y) {
                printf("%s", PACMAN_IMG);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Ghosts: ");
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            if (i == game->ghosts.x && j == game->ghosts.y) {
                printf("%s", GHOST_IMG);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    game game_state;
    init_game(&game_state);
    while (1) {
        move_pacman(&game_state);
        move_pellets(&game_state);
        move_ghosts(&game_state);
        draw_game(&game_state, 0, 0);
        printf("Press a key to continue: ");
        getchar();
    }
    return 0;
}