//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //Initialize Tic Tac Toe board
char player_marker, ai_marker; //Variables to store player and AI markers

void display_board() {
    printf("\nTic Tac Toe Board:\n\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c \n\n", board[6], board[7], board[8]);
}

int check_win(char marker) {
    if ((board[0] == marker && board[1] == marker && board[2] == marker) ||
        (board[3] == marker && board[4] == marker && board[5] == marker) ||
        (board[6] == marker && board[7] == marker && board[8] == marker) ||
        (board[0] == marker && board[3] == marker && board[6] == marker) ||
        (board[1] == marker && board[4] == marker && board[7] == marker) ||
        (board[2] == marker && board[5] == marker && board[8] == marker) ||
        (board[0] == marker && board[4] == marker && board[8] == marker) ||
        (board[2] == marker && board[4] == marker && board[6] == marker))
        return 1; //Player has won
    else
        return 0; //Player has not won yet
}

int is_valid_move(int move) {
    if (board[move] == 'X' || board[move] == 'O')
        return 0; //Invalid move
    else
        return 1; //Valid move
}

int minimax(char marker, int depth) {
    int best_score;
    
    if (check_win(ai_marker)) //AI has won
        return 10 - depth;
    else if (check_win(player_marker)) //Player has won
        return depth - 10;
    else if (depth == 0) //Reached maximum depth
        return 0;
        
    if (marker == ai_marker) { //Maximizing player
        best_score = -100; //Initialize to very low score
        for (int i = 0; i < 9; i++) {
            if (is_valid_move(i)) {
                board[i] = ai_marker; //Make move
                int score = minimax(player_marker, depth - 1); //Find score for next move
                board[i] = i + '1'; //Undo move
                if (score > best_score)
                    best_score = score;
            }
        }
        return best_score;
    } else { //Minimizing player
        best_score = 100; //Initialize to very high score
        for (int i = 0; i < 9; i++) {
            if (is_valid_move(i)) {
                board[i] = player_marker; //Make move
                int score = minimax(ai_marker, depth - 1); //Find score for next move
                board[i] = i + '1'; //Undo move
                if (score < best_score)
                    best_score = score;
            }
        }
        return best_score;
    }
}

int get_best_move() {
    int best_move;
    int best_score = -100; //Initialize to very low score
    
    for (int i = 0; i < 9; i++) {
        if (is_valid_move(i)) {
            board[i] = ai_marker; //Make move
            int score = minimax(player_marker, 4); //Find score for next move
            board[i] = i + '1'; //Undo move
            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }
    return best_move;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Choose your marker (X/O): ");
    scanf("%c", &player_marker);
    if (player_marker == 'X') ai_marker = 'O';
    else ai_marker = 'X';
    
    int turn = 0; //Variable to keep track of turns
    
    while (turn < 9) {
        if (turn % 2 == 0) { //Player's turn
            int move;
            display_board();
            printf("Your turn. Enter move (1-9): ");
            scanf("%d", &move);
            move--; //Adjust for 0-indexed array
            if (!is_valid_move(move)) {
                printf("Invalid move. Try again.\n");
                continue; //Go to next iteration of while loop
            }
            board[move] = player_marker;
            if (check_win(player_marker)) {
                printf("Congratulations! You won!\n");
                display_board();
                return 0;
            }
        } else { //AI's turn
            int ai_move = get_best_move();
            board[ai_move] = ai_marker;
            printf("AI's turn. AI chose move %d.\n", ai_move + 1);
            if (check_win(ai_marker)) {
                printf("Better luck next time. AI won.\n");
                display_board();
                return 0;
            }
        }
        turn++;
    }
    printf("It's a tie!\n");
    display_board();
    return 0;
}