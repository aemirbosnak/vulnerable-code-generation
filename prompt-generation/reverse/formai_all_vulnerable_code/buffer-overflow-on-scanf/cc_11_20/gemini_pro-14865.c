//GEMINI-pro DATASET v1.0 Category: Pac-Man Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct ghost {
    int x;
    int y;
    enum direction dir;
};

struct pacman {
    int x;
    int y;
    int score;
};

void print_board(char board[HEIGHT][WIDTH], struct pacman *pacman, struct ghost *ghosts, int num_ghosts) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pacman->x == i && pacman->y == j) {
                printf("P");
            } else if (ghosts[0].x == i && ghosts[0].y == j) {
                printf("G");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char board[HEIGHT][WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    struct pacman pacman = {1, 1, 0};
    struct ghost ghosts[1] = {{9, 1, RIGHT}};

    int game_over = 0;

    while (!game_over) {
        // Get input from the user
        char input;
        scanf(" %c", &input);

        // Update the position of Pac-Man
        switch (input) {
            case 'w':
                pacman.x--;
                break;
            case 's':
                pacman.x++;
                break;
            case 'a':
                pacman.y--;
                break;
            case 'd':
                pacman.y++;
                break;
        }

        // Update the position of the ghosts
        for (int i = 0; i < 1; i++) {
            switch (ghosts[i].dir) {
                case UP:
                    ghosts[i].x--;
                    break;
                case DOWN:
                    ghosts[i].x++;
                    break;
                case LEFT:
                    ghosts[i].y--;
                    break;
                case RIGHT:
                    ghosts[i].y++;
                    break;
            }

            // Check if the ghost has hit a wall
            if (ghosts[i].x < 0 || ghosts[i].x >= HEIGHT || ghosts[i].y < 0 || ghosts[i].y >= WIDTH) {
                // Change the direction of the ghost
                ghosts[i].dir = rand() % 4;
            }

            // Check if the ghost has caught Pac-Man
            if (ghosts[i].x == pacman.x && ghosts[i].y == pacman.y) {
                game_over = 1;
            }
        }

        // Check if Pac-Man has eaten all of the dots
        int num_dots = 0;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (board[i][j] == ' ') {
                    num_dots++;
                }
            }
        }

        if (num_dots == 0) {
            game_over = 1;
        }

        // Print the board
        print_board(board, &pacman, ghosts, 1);
    }

    if (game_over) {
        printf("Game over!\n");
    }

    return 0;
}