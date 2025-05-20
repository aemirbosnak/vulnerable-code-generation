//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int ai_move(int board[3][3], int ai_marker, int player_marker);
int check_win(int board[3][3], int marker);
void print_board(int board[3][3]);
void init_board(int board[3][3]);
int get_player_move(int board[3][3], int player_marker);
int minimax(int board[3][3], int depth, int maximizing_player, int ai_marker, int player_marker);

int main(){
    int board[3][3];
    int player_marker, ai_marker;
    char choice;
    printf("Welcome to Tic Tac Toe. Do you want to play X or O? ");
    scanf(" %c", &choice);
    if(choice == 'X' || choice == 'x'){
        player_marker = 1;
        ai_marker = 2;
    }
    else{
        player_marker = 2;
        ai_marker = 1;
    }
    init_board(board);
    printf("Let's begin! \n");
    print_board(board);
    while(1){
        get_player_move(board, player_marker);
        print_board(board);
        if(check_win(board, player_marker) == 1){
            printf("Congratulations! You have won.\n");
            return 0;
        }
        if(check_win(board, player_marker) == -1){
            printf("It's a tie!\n");
            return 0;
        }
        printf("It's my turn now.\n");
        ai_move(board, ai_marker, player_marker);
        print_board(board);
        if(check_win(board, ai_marker) == 1){
            printf("I win! Better luck next time.\n");
            return 0;
        }
        if(check_win(board, ai_marker) == -1){
            printf("It's a tie!\n");
            return 0;
        }
    
    }
}

void init_board(int board[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j] = 0;
        }
    }
}

void print_board(int board[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("|");
            if(board[i][j] == 0){
                printf(" ");
            }else if(board[i][j] == 1){
                printf("X");
            }else{
                printf("O");
            }
        }
        printf("|\n");
    }
}

int get_player_move(int board[3][3], int player_marker){
    int row, col;
    printf("Enter row and column, separated by a space: ");
    scanf("%d %d", &row, &col);
    row--;
    col--;
    if(board[row][col] == 0){
        board[row][col] = player_marker;
        return 1;
    }else{
        printf("You cannot make this move. Please try again.\n");
        return get_player_move(board, player_marker);
    }
}

int check_win(int board[3][3], int marker){
    int i;
    for(i=0; i<3; i++){
        if(board[i][0] == marker && board[i][1] == marker && board[i][2] == marker){
            return 1;
        }
        if(board[0][i] == marker && board[1][i] == marker && board[2][i] == marker){
            return 1;
        }
    }
    if(board[0][0] == marker && board[1][1] == marker && board[2][2] == marker){
        return 1;
    }
    if(board[0][2] == marker && board[1][1] == marker && board[2][0] == marker){
        return 1;
    }
    int count = 0;
    for(i=0; i<3; i++){
        int j;
        for(j=0; j<3; j++){
            if(board[i][j] != 0){
                count++;
            }
        }
    }
    if(count == 9){
        return -1;
    }
    return 0;
}

int ai_move(int board[3][3], int ai_marker, int player_marker){
    int i, j;
    int best_score = -1000000;
    int best_move_i, best_move_j;
    
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == 0){
                board[i][j] = ai_marker;
                int score = minimax(board, 0, 0, ai_marker, player_marker);
                board[i][j] = 0;
                if(score > best_score){
                    best_score = score;
                    best_move_i = i;
                    best_move_j = j;
                }
            }
        }
    }
    board[best_move_i][best_move_j] = ai_marker;
    return 1;
}

int minimax(int board[3][3], int depth, int maximizing_player, int ai_marker, int player_marker){
    int result = check_win(board, ai_marker);
    if(result == -1 || result == 1){
        return result;
    }
    if(maximizing_player){
        int max_score = -1000000;
        int i, j;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(board[i][j] == 0){
                    board[i][j] = ai_marker;
                    int score = minimax(board, depth+1, 0, ai_marker, player_marker);
                    board[i][j] = 0;
                    if(score > max_score){
                        max_score = score;
                    }
                }
            }
        }
        return max_score;
    }else{
        int min_score = 1000000;
        int i, j;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(board[i][j] == 0){
                    board[i][j] = player_marker;
                    int score = minimax(board, depth+1, 1, ai_marker, player_marker);
                    board[i][j] = 0;
                    if(score < min_score){
                        min_score = score;
                    }
                }
            }
        }
        return min_score;
    }
}