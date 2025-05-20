//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>

char current_board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
char bot = 'O';

void draw_board() {
    printf("\n");
    printf(" %c | %c | %c \n", current_board[0], current_board[1], current_board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", current_board[3], current_board[4], current_board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", current_board[6], current_board[7], current_board[8]);
    printf("\n");
}

int check_win() {

    if (current_board[0] == current_board[1] && current_board[1] == current_board[2])
        return 1;

    else if (current_board[3] == current_board[4] && current_board[4] == current_board[5])
        return 1;

    else if (current_board[6] == current_board[7] && current_board[7] == current_board[8])
        return 1;

    else if (current_board[0] == current_board[3] && current_board[3] == current_board[6])
        return 1;

    else if (current_board[1] == current_board[4] && current_board[4] == current_board[7])
        return 1;

    else if (current_board[2] == current_board[5] && current_board[5] == current_board[8])
        return 1;

    else if (current_board[0] == current_board[4] && current_board[4] == current_board[8])
        return 1;

    else if (current_board[2] == current_board[4] && current_board[4] == current_board[6])
        return 1;

    else if (current_board[0] != '1' && current_board[1] != '2' && current_board[2] != '3' && current_board[3] != '4'
             && current_board[4] != '5' && current_board[5] != '6' && current_board[6] != '7'
             && current_board[7] != '8' && current_board[8] != '9')
        return 0;

    else
        return -1;
}

void player_turn() {
    int choice;
    printf("It's your turn, where do you want to place your mark: ");
    scanf("%d", &choice);
    if (current_board[choice - 1] == 'X' || current_board[choice - 1] == 'O') {
        printf("That spot is already taken, please choose another spot...\n");
        player_turn();
    } else {
        current_board[choice - 1] = player;
    }
}

void bot_turn() {
    int i, j, best_score = -1000, score;
    int move[2];

    // AI to make its turn
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (current_board[3 * i + j] != 'X' && current_board[3 * i + j] != 'O') {
                current_board[3 * i + j] = bot;
                score = minimax(0, 0);
                current_board[3 * i + j] = (3 * i + j) + '1';
                if (score > best_score) {
                    best_score = score;
                    move[0] = i;
                    move[1] = j;
                }
            }
        }
    }

    // bot makes move after calculation
    current_board[3 * move[0] + move[1]] = bot;
}

int minimax(int depth, int isMax) {
    int score = check_win();

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (score == 0)
        return 0;

    int i, j;
    int best_score;

    if (isMax) {
        best_score = -1000;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (current_board[3 * i + j] != 'X' && current_board[3 * i + j] != 'O') {
                    current_board[3 * i + j] = bot;
                    score = minimax(depth + 1, !isMax);
                    current_board[3 * i + j] = (3 * i + j) + '1';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
    } else {
        best_score = 1000;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (current_board[3 * i + j] != 'X' && current_board[3 * i + j] != 'O') {
                    current_board[3 * i + j] = player;
                    score = minimax(depth + 1, !isMax);
                    current_board[3 * i + j] = (3 * i + j) + '1';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
    }

    return best_score;
}

int main() {
    int turn;

    printf("Let's play Tic Tac Toe\n");

    while (check_win() == -1) {
        draw_board();

        turn = (player == 'X') ? 1 : 0;

        if (turn) {
            player_turn();
            if (check_win() == 1) {
                draw_board();
                printf("Congratulations, you won!\n");
                return 0;
            }
        } else {
            bot_turn();
            if (check_win() == 1) {
                draw_board();
                printf("Oops, you lost! Better luck next time.\n");
                return 0;
            }
        }
    }

    if (check_win() == 0) {
        draw_board();
        printf("It's a tie!\n");
    }

    return 0;
}