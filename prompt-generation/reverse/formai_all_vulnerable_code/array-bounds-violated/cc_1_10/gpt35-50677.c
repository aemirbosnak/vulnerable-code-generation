//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define ALIENS 15

int score = 0;

char grid[ROWS][COLS];
char player[4] = {' ', '^', ' ', '|'};

typedef struct Alien {
    int x;
    int y;
    int alive;
} Alien;

Alien aliens[ALIENS];

void init_game() {
    // initialize grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }

    // initialize player
    int player_x = COLS / 2;
    int player_y = ROWS - 1;
    grid[player_y][player_x] = player[1];
    grid[player_y][player_x - 1] = player[0];
    grid[player_y][player_x + 1] = player[2];
    grid[player_y - 1][player_x] = player[3];

    // initialize aliens
    int count = 0;
    for(int i = 0; i < ROWS - 2; i++) {
        for(int j = 0; j < COLS; j+=2) {
            aliens[count].x = j;
            aliens[count].y = i;
            aliens[count].alive = 1;
            count++;
        }
    }
}

void draw() {
    system("clear");
    printf("Score: %d\n", score);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_player(int dir) {
    // move player left
    if(dir == -1) {
        // check if player is at left edge of screen
        if(grid[ROWS - 1][1] != ' ') {
            return;
        }

        // erase current player position
        int player_x = 0;
        int player_y = ROWS - 1;
        grid[player_y][player_x] = ' ';
        grid[player_y][player_x + 1] = ' ';
        grid[player_y][player_x + 2] = ' ';
        grid[player_y - 1][player_x + 1] = ' ';

        // update player position
        player_x++;
        grid[player_y][player_x] = player[1];
        grid[player_y][player_x - 1] = player[0];
        grid[player_y][player_x + 1] = player[2];
        grid[player_y - 1][player_x] = player[3];
    }
    // move player right
    else if(dir == 1) {
        // check if player is at right edge of screen
        if(grid[ROWS - 1][COLS - 2] != ' ') {
            return;
        }
        
        // erase current player position
        int player_x = 0;
        int player_y = ROWS - 1;
        for(int i = 0; i < COLS; i++) {
            if(grid[player_y][i] == player[1]) {
                player_x = i;
                break;
            }
        }

        grid[player_y][player_x] = ' ';
        grid[player_y][player_x - 1] = ' ';
        grid[player_y][player_x + 1] = ' ';
        grid[player_y - 1][player_x] = ' ';

        // update player position
        player_x++;
        grid[player_y][player_x] = player[1];
        grid[player_y][player_x - 1] = player[0];
        grid[player_y][player_x + 1] = player[2];
        grid[player_y - 1][player_x] = player[3];
    }
}

void update_aliens() {
    for(int i = 0; i < ALIENS; i++) {
        if(aliens[i].alive) {
            // erase current position
            grid[aliens[i].y][aliens[i].x] = ' ';
            
            // move one step down
            aliens[i].y++;
            
            // check if alien hit player
            if(grid[aliens[i].y][aliens[i].x] == player[1] ||
               grid[aliens[i].y][aliens[i].x - 1] == player[0] ||
               grid[aliens[i].y][aliens[i].x + 1] == player[2] ||
               grid[aliens[i].y - 1][aliens[i].x] == player[3]) {
                printf("Game over!\n");
                exit(0);
            }

            // check if alien hit bottom of screen
            if(aliens[i].y == ROWS - 1) {
                printf("Game over!\n");
                exit(0);
            }

            // draw new position
            grid[aliens[i].y][aliens[i].x] = 'X';
        }
    }
}

void fire_bullet() {
    // check if bullet already exists
    if(grid[ROWS - 2][1] != ' ') {
        return;
    }

    // find player position
    int player_x = 0;
    int player_y = ROWS - 1;
    for(int i = 0; i < COLS; i++) {
        if(grid[player_y][i] == player[1]) {
            player_x = i;
            break;
        }
    }

    // draw bullet
    grid[ROWS - 2][player_x] = '-';

    // check if bullet hit an alien
    for(int i = 0; i < ALIENS; i++) {
        if(aliens[i].alive &&
           aliens[i].x == player_x &&
           aliens[i].y == ROWS - 2) {
            aliens[i].alive = 0;
            score += 10;
            return;
        }
    }
}

int main() {
    srand(time(0));
    init_game();
    draw();

    char c = ' ';
    while(c != 'q') {
        c = getchar();
        switch(c) {
            case 'a':
                update_player(-1);
                break;
            case 'd':
                update_player(1);
                break;
            case ' ':
                fire_bullet();
                break;
        }
        update_aliens();
        draw();
    }
    
    return 0;
}