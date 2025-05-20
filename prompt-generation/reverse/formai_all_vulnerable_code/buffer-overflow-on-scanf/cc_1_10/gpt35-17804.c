//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

typedef enum { FLOOR, WALL } tile;

tile map[MAP_SIZE][MAP_SIZE];
int player_x, player_y;

void generate_map();
void print_map();
void move_player(int dx, int dy);

int main() {
    srand(time(NULL));
    
    generate_map();
    print_map();
    
    while (1) {
        char input;
        printf("Enter a direction (w,a,s,d): ");
        scanf(" %c", &input);
        
        int dx = 0, dy = 0;
        switch (input) {
            case 'w': dy = -1; break;
            case 'a': dx = -1; break;
            case 's': dy = 1; break;
            case 'd': dx = 1; break;
            default: continue;
        }
        
        move_player(dx, dy);
        print_map();
    }
    
    return 0;
}

void generate_map() {
    // Generate random map
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            if (rand() % 100 < 40) {
                map[x][y] = WALL;
            } else {
                map[x][y] = FLOOR;
            }
        }
    }
    
    // Place player
    player_x = rand() % MAP_SIZE;
    player_y = rand() % MAP_SIZE;
    map[player_x][player_y] = FLOOR;
}

void print_map() {
    // Clear screen
    system("clear");
    
    // Print map
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (x == player_x && y == player_y) {
                printf("@");
            } else if (map[x][y] == FLOOR) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void move_player(int dx, int dy) {
    int new_x = player_x + dx;
    int new_y = player_y + dy;
    
    if (new_x < 0 || new_x >= MAP_SIZE || new_y < 0 || new_y >= MAP_SIZE) {
        return;
    }
    
    if (map[new_x][new_y] == WALL) {
        return;
    }
    
    player_x = new_x;
    player_y = new_y;
}