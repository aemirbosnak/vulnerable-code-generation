//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void welcome_screen(){
    printf("Welcome to Tic Tac Toe: Post-Apocalyptic Edition\n");
    printf("You are the last surviving human against the AI robots\n\n");
}

void draw_board(char board[]){
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

char check_winner(char board[]){
    if(board[0] == board[1] && board[1] == board[2])
        return board[0];
    else if(board[3] == board[4] && board[4] == board[5])
        return board[3];
    else if(board[6] == board[7] && board[7] == board[8])
        return board[6];
    else if(board[0] == board[3] && board[3] == board[6])
        return board[0];
    else if(board[1] == board[4] && board[4] == board[7])
        return board[1];
    else if(board[2] == board[5] && board[5] == board[8])
        return board[2];
    else if(board[0] == board[4] && board[4] == board[8])
        return board[0];
    else if(board[2] == board[4] && board[4] == board[6])
        return board[2];
    else
        return 'T'; 
}

int minimax(char board[], char player, int depth){
    char opponent = (player == 'X') ? 'O' : 'X';
    int score = 0;
    char winner = check_winner(board);
    if(winner == player)
        return 10;
    else if(winner == opponent)
        return -10;
    else if(winner == 'T')
        return 0;
    if(depth == 0){
        return score;
    }
    if(player == 'X'){
        int best_score = -1000;
        for(int i=0; i<9; i++){
            if(board[i] == '-'){
                board[i] = player;
                score = minimax(board, opponent, depth - 1);
                if(score > best_score)
                    best_score = score;
                board[i] = '-';
            }
        }
        return best_score;
    }
    else{
        int best_score = 1000;
        for(int i=0; i<9; i++){
            if(board[i] == '-'){
                board[i] = player;
                score = minimax(board, opponent, depth - 1);
                if(score < best_score)
                    best_score = score;
                board[i] = '-';
            }
        }
        return best_score;
    }
}

int cpu_move(char board[]){
    char opponent = 'X';
    int best_score = -1000;
    int best_move = -1;
    for(int i=0; i<9; i++){
        if(board[i] == '-'){
            board[i] = 'O';
            int score = minimax(board, opponent, 10);
            board[i] = '-';
            if(score > best_score){
                best_score = score;
                best_move = i;
            }
        }
    }
    return best_move;
}

int player_move(char board[]){
    int move;
    printf("Enter your move (0-8): ");
    scanf("%d", &move);
    if(board[move] != '-')
        return -1;
    else
        return move;
}

int main(){
    srand(time(NULL));
    char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    welcome_screen();
    int player = rand() % 2;
    int move;
    draw_board(board);
    while(1){
        if(player == 0){
            move = player_move(board);
            if(move == -1){
                printf("Invalid move, try again.\n");
                continue;
            }
            board[move] = 'X';
            player = 1;
        }
        else{
            printf("CPU's turn\n");
            move = cpu_move(board);
            board[move] = 'O';
            player = 0;
        }
        draw_board(board);
        char winner = check_winner(board);
        if(winner == 'X'){
            printf("You have won!\n");
            break;
        }
        else if(winner == 'O'){
            printf("CPU wins!\n");
            break;
        }
        else if(winner == 'T'){
            printf("It's a tie!\n");
            break;
        }
    }
    return 0;
}