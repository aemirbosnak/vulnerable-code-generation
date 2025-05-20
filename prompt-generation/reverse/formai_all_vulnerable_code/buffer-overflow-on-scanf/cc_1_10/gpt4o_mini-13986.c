//GPT-4o-mini DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 10

typedef enum { EMPTY, PLAYER1, PLAYER2, PLAYER3, PLAYER4 } Cell;
typedef struct {
    int id;
    int x;
    int y;
    char name[20];
} Player;

void initialize_board(Cell board[BOARD_SIZE][BOARD_SIZE]);
void display_board(Cell board[BOARD_SIZE][BOARD_SIZE]);
void move_player(Player *player, Cell board[BOARD_SIZE][BOARD_SIZE]);
int is_within_bounds(int x, int y);
void check_victory(Player players[], int num_players);

int main() {
    Cell board[BOARD_SIZE][BOARD_SIZE];
    Player players[MAX_PLAYERS];
    int num_players;
    srand(time(NULL));

    printf("Welcome to Future Galactic Conquest!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);
    
    if(num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        players[i].x = rand() % BOARD_SIZE;
        players[i].y = rand() % BOARD_SIZE;
        printf("Enter name for Player %d: ", players[i].id);
        scanf("%s", players[i].name);
    }

    initialize_board(board);
    int turns = 0;
    
    while (1) {
        display_board(board);
        int current_player = turns % num_players;
        printf("\n%s's turn (Player %d)\n", players[current_player].name, players[current_player].id);
        move_player(&players[current_player], board);
        check_victory(players, num_players);
        turns++;
        sleep(1); // Slow down the game loop
    }
    
    return 0;
}

void initialize_board(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void display_board(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nGame Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY: printf(". "); break;
                case PLAYER1: printf("1 "); break;
                case PLAYER2: printf("2 "); break;
                case PLAYER3: printf("3 "); break;
                case PLAYER4: printf("4 "); break;
            }
        }
        printf("\n");
    }
}

void move_player(Player *player, Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int direction;
    char *directions[] = {"UP", "DOWN", "LEFT", "RIGHT"};

    printf("Choose a direction to move (0-3: UP, DOWN, LEFT, RIGHT): ");
    scanf("%d", &direction);

    int new_x = player->x, new_y = player->y;

    switch (direction) {
        case 0: new_x--; break; // Up
        case 1: new_x++; break; // Down
        case 2: new_y--; break; // Left
        case 3: new_y++; break; // Right
        default:
            printf("Invalid direction!\n");
            return;
    }

    if (is_within_bounds(new_x, new_y) && board[new_x][new_y] == EMPTY) {
        board[player->x][player->y] = EMPTY; // Clear current position
        player->x = new_x;
        player->y = new_y;
        board[new_x][new_y] = player->id; // Update new position
    } else {
        printf("Move blocked or out of bounds!\n");
    }
}

int is_within_bounds(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

void check_victory(Player players[], int num_players) {
    // Simple victory check: if a player reaches a certain position (0,0)
    for (int i = 0; i < num_players; i++) {
        if (players[i].x == 0 && players[i].y == 0) {
            printf("\nCongratulations, %s (Player %d) wins!\n", players[i].name, players[i].id);
            exit(0);
        }
    }
}