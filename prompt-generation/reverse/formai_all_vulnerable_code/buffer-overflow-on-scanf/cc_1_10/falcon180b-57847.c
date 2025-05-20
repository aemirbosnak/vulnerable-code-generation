//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int x;
    int y;
    int score;
    char name[20];
} Player;

void init_map(int map[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

int get_neighbors(int map[MAX_ROWS][MAX_COLS], int x, int y) {
    int count = 0;
    if (x > 0 && map[x-1][y] == 0) {
        count++;
    }
    if (y > 0 && map[x][y-1] == 0) {
        count++;
    }
    if (x < MAX_ROWS - 1 && map[x+1][y] == 0) {
        count++;
    }
    if (y < MAX_COLS - 1 && map[x][y+1] == 0) {
        count++;
    }
    return count;
}

void print_map(int map[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (map[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void *player_thread(void *data) {
    Player *player = data;
    int map[MAX_ROWS][MAX_COLS];

    srand(time(NULL) + player->score);
    init_map(map);

    int x = 0;
    int y = 0;
    int score = 0;

    while (x < MAX_ROWS && y < MAX_COLS) {
        int neighbors = get_neighbors(map, x, y);
        if (neighbors == 0) {
            x++;
        } else if (neighbors == 1) {
            y++;
        } else {
            printf("Player %s reached the end with score %d\n", player->name, score);
            pthread_exit(0);
        }
        score++;
    }
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    Player players[MAX_PLAYERS];

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_create(&threads[i], NULL, player_thread, &players[i]);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}