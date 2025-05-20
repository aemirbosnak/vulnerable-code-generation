//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN_WIDTH 80
#define WIN_HEIGHT 25

typedef struct {
    int x;
    int y;
} POINT;

typedef struct {
    POINT pos;
    char dir;
} PLAYER;

PLAYER player;

void init_player(void);
void move_player(char dir);
void draw_player(void);
void draw_window(void);
void update_window(void);

int main(void) {
    init_player();
    while (1) {
        update_window();
        draw_window();
    }
    return 0;
}

void init_player(void) {
    player.pos.x = WIN_WIDTH / 2;
    player.pos.y = WIN_HEIGHT / 2;
    player.dir = 'N';
}

void move_player(char dir) {
    switch (dir) {
        case 'N':
            player.pos.y -= 1;
            break;
        case 'S':
            player.pos.y += 1;
            break;
        case 'E':
            player.pos.x += 1;
            break;
        case 'W':
            player.pos.x -= 1;
            break;
    }
}

void draw_player(void) {
    printf("Player at (%d, %d) facing %c\n", player.pos.x, player.pos.y, player.dir);
}

void draw_window(void) {
    printf("Window size: %d x %d\n", WIN_WIDTH, WIN_HEIGHT);
}

void update_window(void) {
    char dir_input;
    printf("Enter direction (N/S/E/W): ");
    scanf(" %c", &dir_input);
    move_player(dir_input);
}