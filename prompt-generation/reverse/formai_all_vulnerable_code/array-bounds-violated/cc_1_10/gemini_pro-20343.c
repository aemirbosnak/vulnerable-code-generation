//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int value;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].value);
        }
        printf("\n");
    }
}

Position get_random_position() {
    Position position;
    position.x = rand() % BOARD_SIZE;
    position.y = rand() % BOARD_SIZE;
    return position;
}

int get_tile_value(Position position) {
    return board[position.x][position.y].value;
}

void set_tile_value(Position position, int value) {
    board[position.x][position.y].value = value;
}

int get_adjacent_positions(Position position, Position adjacent_positions[]) {
    int count = 0;
    if (position.x > 0) {
        adjacent_positions[count++] = (Position) {position.x - 1, position.y};
    }
    if (position.x < BOARD_SIZE - 1) {
        adjacent_positions[count++] = (Position) {position.x + 1, position.y};
    }
    if (position.y > 0) {
        adjacent_positions[count++] = (Position) {position.x, position.y - 1};
    }
    if (position.y < BOARD_SIZE - 1) {
        adjacent_positions[count++] = (Position) {position.x, position.y + 1};
    }
    return count;
}

int get_adjacent_values(Position position, int adjacent_values[]) {
    int count = 0;
    Position adjacent_positions[4];
    int num_adjacent_positions = get_adjacent_positions(position, adjacent_positions);
    for (int i = 0; i < num_adjacent_positions; i++) {
        adjacent_values[count++] = get_tile_value(adjacent_positions[i]);
    }
    return count;
}

int get_best_move(Position position) {
    int adjacent_values[4];
    int num_adjacent_values = get_adjacent_values(position, adjacent_values);
    int best_move = -1;
    int best_value = -1;
    for (int i = 0; i < num_adjacent_values; i++) {
        if (adjacent_values[i] > best_value) {
            best_value = adjacent_values[i];
            best_move = i;
        }
    }
    return best_move;
}

void make_move(Position position) {
    int best_move = get_best_move(position);
    if (best_move == -1) {
        return;
    }
    Position adjacent_position;
    switch (best_move) {
        case 0:
            adjacent_position = (Position) {position.x - 1, position.y};
            break;
        case 1:
            adjacent_position = (Position) {position.x + 1, position.y};
            break;
        case 2:
            adjacent_position = (Position) {position.x, position.y - 1};
            break;
        case 3:
            adjacent_position = (Position) {position.x, position.y + 1};
            break;
    }
    int adjacent_value = get_tile_value(adjacent_position);
    set_tile_value(position, adjacent_value);
    set_tile_value(adjacent_position, 0);
    make_move(adjacent_position);
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].position = (Position) {i, j};
            board[i][j].value = rand() % 10;
        }
    }
    print_board();
    Position position = get_random_position();
    make_move(position);
    print_board();
    return 0;
}