//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#define MaxN 3
char board[MaxN][MaxN];
int x, y;
int play_number_move=0;

void start_board(){
    //initialize the board with empty values
    for (int x = 0; x < MaxN; x++) {
        for (int y = 0; y < MaxN; y++) {
            board[x][y] = ' ';
        }
    }
}

void print_board(){
    printf("\n***********\n\n");
    for(int x=0; x<MaxN; x++){
        printf(" %c | %c | %c ", board[x][0], board[x][1], board[x][2]);
        if(x!=2) printf("\n---|---|---\n");
    }
    printf("\n***********\n\n");
}

int check_position(int x, int y){
    if(board[x][y] == ' '){
        return 1;
    } else {
        return 0;
    }
}

int check_rows(){
    for(int row=0; row<MaxN; row++){
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' '){
            return 1;
        }
    }
    return 0;
}

int check_columns(){
    for(int column=0; column<MaxN; column++){
        if(board[0][column] == board[1][column] && board[1][column] == board[2][column] && board[0][column] != ' '){
            return 1;
        }
    }
    return 0;
}

int check_diagonals(){
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
        return 1;
    }
    return 0;
}

int check_winner(){
    if(check_rows() || check_columns() || check_diagonals()){
        return 1;
    } else {
        return 0;
    }
}

void mark_position(int x, int y, char mark){
    board[x][y] = mark;
    play_number_move++;
}

void play_game(){
    printf("Game Start!!!\n");
    printf("Player 1 is O , Player 2 is X\n\n");
    int player = 1, i, choice;
    char mark;

    do {
        print_board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number between 1 and 9:  ", player);
        scanf("%d", &choice);

        if(choice == 1 && check_position(0,0)) x = 0, y = 0;
        else if(choice == 2 && check_position(0,1)) x = 0, y = 1;
        else if(choice == 3 && check_position(0,2)) x = 0, y = 2;
        else if(choice == 4 && check_position(1,0)) x = 1, y = 0;
        else if(choice == 5 && check_position(1,1)) x = 1, y = 1;
        else if(choice == 6 && check_position(1,2)) x = 1, y = 2;
        else if(choice == 7 && check_position(2,0)) x = 2, y = 0;
        else if(choice == 8 && check_position(2,1)) x = 2, y = 1;
        else if(choice == 9 && check_position(2,2)) x = 2, y = 2;
        else{
            printf("Invalid move!");
            player--;
        }

        mark = (player == 1) ? 'O' : 'X';
        mark_position(x, y, mark);

    } while (!check_winner() && play_number_move!=9);

    print_board();

    if (check_winner()){
        printf("Player %d Wins!\n\n", player);
    }else{
        printf("Draw!\n\n");
    }
}

int main(){
    start_board();
    play_game();
    return 0;
}