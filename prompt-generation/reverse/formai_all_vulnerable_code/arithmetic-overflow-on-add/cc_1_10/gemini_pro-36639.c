//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num_disks;
    char** towers;
    bool is_illegal_move;
} hanoi_game;

// Initializes the game with the given number of disks. Allocates memory for the towers.
hanoi_game* hanoi_init(int num_disks) {
    hanoi_game* game = malloc(sizeof(hanoi_game));
    game->num_disks = num_disks;
    game->towers = malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++) {
        game->towers[i] = malloc(sizeof(char) * (num_disks + 1));
    }

    // Initialize the towers with the disks.
    for (int i = 0; i < num_disks; i++) {
        game->towers[0][i] = 'A' + i;
        game->towers[1][i] = ' ';
        game->towers[2][i] = ' ';
    }
    game->towers[num_disks][0] = '\0';
    game->towers[num_disks][1] = '\0';
    game->towers[num_disks][2] = '\0';
    game->is_illegal_move = false;

    return game;
}

// Frees the memory allocated for the game.
void hanoi_free(hanoi_game* game) {
    for (int i = 0; i < 3; i++) {
        free(game->towers[i]);
    }
    free(game->towers);
    free(game);
}

// Prints the current state of the game.
void hanoi_print(hanoi_game* game) {
    for (int i = game->num_disks - 1; i >= 0; i--) {
        printf("| %s |", game->towers[0][i] ? game->towers[0][i] : " ");
    }
    printf("\n");
    for (int i = game->num_disks - 1; i >= 0; i--) {
        printf("| %s |", game->towers[1][i] ? game->towers[1][i] : " ");
    }
    printf("\n");
    for (int i = game->num_disks - 1; i >= 0; i--) {
        printf("| %s |", game->towers[2][i] ? game->towers[2][i] : " ");
    }
    printf("\n\n");
}

// Moves the top disk from the given tower to the given destination tower. Returns true if the move is legal, false otherwise.
bool hanoi_move(hanoi_game* game, int from, int to) {
    if (game->towers[from][game->num_disks - 1] == ' ') {
        printf("Error: no disk to move from tower %d.\n", from);
        game->is_illegal_move = true;
        return false;
    }
    if (game->towers[to][game->num_disks - 1] != ' ' &&
        game->towers[from][game->num_disks - 1] > game->towers[to][game->num_disks - 1]) {
        printf("Error: cannot move a larger disk onto a smaller disk.\n");
        game->is_illegal_move = true;
        return false;
    }

    int from_index = game->num_disks - 1;
    while (game->towers[from][from_index] == ' ') {
        from_index--;
    }
    int to_index = game->num_disks - 1;
    while (game->towers[to][to_index] == ' ') {
        to_index--;
    }

    game->towers[to][to_index + 1] = game->towers[from][from_index];
    game->towers[to][to_index + 2] = '\0';
    game->towers[from][from_index] = ' ';

    return true;
}

// Solves the Tower of Hanoi puzzle using a recursive backtracking algorithm.
void hanoi_solve(hanoi_game* game, int n, int from, int to, int via) {
    if (n == 1) {
        hanoi_move(game, from, to);
        return;
    }

    hanoi_solve(game, n - 1, from, via, to);
    if (!game->is_illegal_move) {
        hanoi_move(game, from, to);
    }
    if (!game->is_illegal_move) {
        hanoi_solve(game, n - 1, via, to, from);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    hanoi_game* game = hanoi_init(num_disks);

    printf("Initial state:\n");
    hanoi_print(game);

    hanoi_solve(game, num_disks, 0, 2, 1);

    if (!game->is_illegal_move) {
        printf("Final state:\n");
        hanoi_print(game);
    } else {
        printf("Invalid move detected. The puzzle cannot be solved.\n");
    }

    hanoi_free(game);

    return 0;
}