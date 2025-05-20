//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define L 1
#define U 2
#define D 3

int map[4][4] = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
int player_x = 0, player_y = 0;
int score = 0;

void init_map() {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

void print_map() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void move(int direction) {
    int new_x = player_x, new_y = player_y;
    switch (direction) {
        case R:
            new_x++;
            break;
        case L:
            new_x--;
            break;
        case U:
            new_y--;
            break;
        case D:
            new_y++;
            break;
    }
    if (map[new_x][new_y] == 1) {
        score++;
        map[new_x][new_y] = 0;
        player_x = new_x;
        player_y = new_y;
    }
}

int main() {
    init_map();
    while (1) {
        printf("Score: %d\n", score);
        print_map();
        int choice;
        scanf("%d", &choice);
        move(choice);
        if (score == 16) {
            printf("Congratulations! You won!\n");
            break;
        }
    }
    return 0;
}