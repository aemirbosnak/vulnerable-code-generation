//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

/* Tic Tac Toe AI */
/* Created By Surprised Bot */

char board[3][3]; // Tic Tac Toe Board
char human = 'X'; // Human Player
char ai = 'O'; // AI Player

int score_board(char player) {
    int r, c, score = 0;
    char opponent;
    if (player == human)
        opponent = ai;
    else
        opponent = human;

    // Check Rows
    for (r = 0; r < 3; ++r) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
            score += 10;
        else if (board[r][0] == opponent && board[r][1] == opponent && board[r][2] == opponent)
            score -= 10;
    }

    // Check Columns
    for (c = 0; c < 3; ++c) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
            score += 10;
        else if (board[0][c] == opponent && board[1][c] == opponent && board[2][c] == opponent)
            score -= 10;
    }

    // Check Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        score += 10;
    else if (board[0][0] == opponent && board[1][1] == opponent && board[2][2] == opponent)
        score -= 10;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        score += 10;
    else if (board[0][2] == opponent && board[1][1] == opponent && board[2][0] == opponent)
        score -= 10;

    return score;
}

int move_possible(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) // Out of Board
        return 0;
    if (board[row][col] == '-') // Empty Space
        return 1;
    return 0; // Non-empty Space
}

int best_move(int* row, int* col) {
    int r, c, best_score = -100, score;
    for (r = 0; r < 3; ++r) {
        for (c = 0; c < 3; ++c) {
            if (move_possible(r, c)) {
                board[r][c] = ai;
                score = score_board(ai);
                board[r][c] = '-'; // Undo Move
                if (score > best_score) {
                    best_score = score;
                    *row = r;
                    *col = c;
                }
            }
        }
    }
}

void print_board() {
    int r, c;
    printf("\n");
    for (r = 0; r < 3; ++r) {
        for (c = 0; c < 3; ++c) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(char player) {
    int r, c;
    char opponent;
    if (player == human)
        opponent = ai;
    else
        opponent = human;

    // Check Rows
    for (r = 0; r < 3; ++r) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
            return 1;
        else if (board[r][0] == opponent && board[r][1] == opponent && board[r][2] == opponent)
            return -1;
    }

    // Check Columns
    for (c = 0; c < 3; ++c) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
            return 1;
        else if (board[0][c] == opponent && board[1][c] == opponent && board[2][c] == opponent)
            return -1;
    }

    // Check Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    else if (board[0][0] == opponent && board[1][1] == opponent && board[2][2] == opponent)
        return -1;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    else if (board[0][2] == opponent && board[1][1] == opponent && board[2][0] == opponent)
        return -1;

    return 0; // No Win
}

int main() {
    // Initialize Board
    int r, c;
    for (r = 0; r < 3; ++r) {
        for (c = 0; c < 3; ++c) {
            board[r][c] = '-';
        }
    }

    int row, col, move_count = 0;
    while (move_count < 9 && check_win(human) == 0) {
        // Human Player Move
        do {
            printf("Enter Row (1-3): ");
            scanf("%d", &row);
            printf("Enter Column (1-3): ");
            scanf("%d", &col);
            row--; col--;
        } while (!move_possible(row, col));
        board[row][col] = human;
        move_count++;
        printf("Human Player Move:\n");
        print_board();

        if (move_count == 9 || check_win(human) != 0) // Game Over
            break;

        // AI Move
        best_move(&row, &col);
        board[row][col] = ai;
        move_count++;
        printf("AI Player Move:\n");
        print_board();
    }

    int result = check_win(human);
    if (result == 1)
        printf("Human Player Wins!\n");
    else if (result == -1)
        printf("AI Player Wins!\n");
    else
        printf("Tie Game!\n");

    return 0;
}