//Falcon2-11B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char board[3][3];
} Game;

void print_board(Game game) {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", game.board[0][0], game.board[0][1], game.board[0][2]);
    printf("   |   |   \n");
    printf("-------------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", game.board[1][0], game.board[1][1], game.board[1][2]);
    printf("   |   |   \n");
    printf("-------------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", game.board[2][0], game.board[2][1], game.board[2][2]);
    printf("   |   |   \n");
}

void play_game(Game *game) {
    printf("Welcome to tic-tac-toe!\n");
    printf("To play, press the corresponding letter of the cell you want to mark.\n");
    printf("To quit, press 'q'.\n");

    int player_1, player_2;
    srand(time(NULL));

    while (1) {
        print_board(*game);
        printf("Player 1, choose your move: ");
        scanf(" %c", &player_1);

        if (player_1 == 'q') {
            break;
        }

        if (game->board[player_1 - 'a'][0]!= '.') {
            printf("That cell is already taken. Choose again.\n");
            continue;
        }

        game->board[player_1 - 'a'][0] = 'X';

        if (game->board[player_1 - 'a'][1]!= '.') {
            printf("That cell is already taken. Choose again.\n");
            continue;
        }

        game->board[player_1 - 'a'][1] = 'X';

        if (game->board[player_1 - 'a'][2]!= '.') {
            printf("That cell is already taken. Choose again.\n");
            continue;
        }

        game->board[player_1 - 'a'][2] = 'X';

        if (game->board[0][0]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[1][0]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[2][0]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[0][1]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[1][1]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[2][1]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[0][2]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[1][2]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        if (game->board[2][2]!= '.') {
            printf("Player 2 has already won.\n");
            break;
        }

        srand(time(NULL));

        while (1) {
            printf("Player 2, choose your move: ");
            scanf(" %c", &player_2);

            if (player_2 == 'q') {
                break;
            }

            if (game->board[player_2 - 'a'][0]!= '.') {
                printf("That cell is already taken. Choose again.\n");
                continue;
            }

            game->board[player_2 - 'a'][0] = 'O';

            if (game->board[player_2 - 'a'][1]!= '.') {
                printf("That cell is already taken. Choose again.\n");
                continue;
            }

            game->board[player_2 - 'a'][1] = 'O';

            if (game->board[player_2 - 'a'][2]!= '.') {
                printf("That cell is already taken. Choose again.\n");
                continue;
            }

            game->board[player_2 - 'a'][2] = 'O';

            if (game->board[0][0]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[1][0]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[2][0]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[0][1]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[1][1]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[2][1]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[0][2]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[1][2]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }

            if (game->board[2][2]!= '.') {
                printf("Player 1 has already won.\n");
                break;
            }
        }

        if (game->board[0][0] == 'X' && game->board[0][1] == 'X' && game->board[0][2] == 'X') {
            printf("Player 1 has won!\n");
            break;
        }

        if (game->board[1][0] == 'X' && game->board[1][1] == 'X' && game->board[1][2] == 'X') {
            printf("Player 1 has won!\n");
            break;
        }

        if (game->board[2][0] == 'X' && game->board[2][1] == 'X' && game->board[2][2] == 'X') {
            printf("Player 1 has won!\n");
            break;
        }

        if (game->board[0][0] == 'O' && game->board[0][1] == 'O' && game->board[0][2] == 'O') {
            printf("Player 2 has won!\n");
            break;
        }

        if (game->board[1][0] == 'O' && game->board[1][1] == 'O' && game->board[1][2] == 'O') {
            printf("Player 2 has won!\n");
            break;
        }

        if (game->board[2][0] == 'O' && game->board[2][1] == 'O' && game->board[2][2] == 'O') {
            printf("Player 2 has won!\n");
            break;
        }
    }
}

int main() {
    Game game;
    game.board[0][0] = '.';
    game.board[0][1] = '.';
    game.board[0][2] = '.';
    game.board[1][0] = '.';
    game.board[1][1] = '.';
    game.board[1][2] = '.';
    game.board[2][0] = '.';
    game.board[2][1] = '.';
    game.board[2][2] = '.';

    printf("Welcome to tic-tac-toe!\n");
    printf("To play, press the corresponding letter of the cell you want to mark.\n");
    printf("To quit, press 'q'.\n");

    play_game(&game);

    return 0;
}