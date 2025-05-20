//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define MAX_PLAYERS 4

int board[BOARD_SIZE][BOARD_SIZE];
int num_players, current_player;

typedef struct {
    int player_num;
    int score;
} player_t;

player_t players[MAX_PLAYERS];

void draw_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board() {
    srand(time(NULL));
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

void initialize_players() {
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    for(int i = 0; i < num_players; i++) {
        players[i].player_num = i+1;
        players[i].score = 0;
    }
    current_player = 0;
}

void get_input() {
    int x, y;
    printf("Player %d - Enter x coordinate: ", players[current_player].player_num);
    scanf("%d", &x);
    printf("Player %d - Enter y coordinate: ", players[current_player].player_num);
    scanf("%d", &y);
    players[current_player].score += board[x][y];
}

void switch_player() {
    current_player = (current_player+1) % num_players;
}

void print_scores() {
    printf("\nScores: \n");
    for(int i = 0; i < num_players; i++) {
        printf("Player %d score: %d\n", players[i].player_num, players[i].score);
    }
}

int check_game_over() {
    int total_score = 0;
    for(int i = 0; i < num_players; i++) {
        total_score += players[i].score;
    }
    if(total_score >= 50) {
        return 1;
    }
    return 0;
}

int main() {
    initialize_board();
    initialize_players();
    while(!check_game_over()) {
        draw_board();
        get_input();
        switch_player();
        print_scores();
    }
    printf("GAME OVER\n");
    print_scores();
    return 0;
}