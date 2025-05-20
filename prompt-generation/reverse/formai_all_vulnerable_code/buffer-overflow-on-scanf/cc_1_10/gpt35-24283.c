//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function declarations
void initialize_board(char board[][3]);
void display_board(char board[][3]);
int input_valid(int row, int col, char board[][3]);
int check_win(char board[][3], char player);
void player_turn(char board[][3], char player);
void computer_turn(char board[][3], char player);

int main(){
    char board[3][3];
    char player;
    int turn_count = 0;
    srand(time(NULL));      //initialize random number generator

    //initialize the board
    initialize_board(board);

    printf("Welcome to the game of Tic Tac Toe!\n\n");

    //determine who goes first randomly
    if(rand() % 2 == 0){
        printf("You go first!\n");
        player = 'X';
    }
    else{
        printf("The computer goes first.\n");
        player = 'O';
    }

    //play the game until win or tie
    while(turn_count < 9){
        if(player == 'X'){
            player_turn(board, player);
            if(check_win(board, player)){
                printf("Congratulations, you have won!\n");
                display_board(board);
                exit(0);
            }
            player = 'O';
        }
        else{
            printf("Computer's turn...\n");
            computer_turn(board, player);
            if(check_win(board, player)){
                printf("Sorry, the computer has won.\n");
                display_board(board);
                exit(0);
            }
            player = 'X';
        }
        turn_count++;
    }
    printf("It's a tie game!\n");
    display_board(board);

    return 0;
}

//function to initialize the game board with empty spaces
void initialize_board(char board[][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

//function to display the game board
void display_board(char board[][3]){
    printf("\n   0 1 2\n");
    printf("  -------\n");
    for(int i=0; i<3; i++){
        printf("%d| ", i);
        for(int j=0; j<3; j++){
            printf("%c| ", board[i][j]);
        }
        printf("\n  -------\n");
    }
}

//function to validate user input
int input_valid(int row, int col, char board[][3]){
    if(row < 0 || row > 2 || col < 0 || col > 2){
        return 0;
    }
    if(board[row][col] != ' '){
        return 0;
    }
    return 1;
}

//function to check for a win
int check_win(char board[][3], char player){
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == player){
        return 1;
    }
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == player){
        return 1;
    }
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == player){
        return 1;
    }
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == player){
        return 1;
    }
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == player){
        return 1;
    }
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == player){
        return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == player){
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == player){
        return 1;
    }
    return 0;
}

//function for the player's turn
void player_turn(char board[][3], char player){
    int row, col;
    printf("Enter the row and column of your move (0-2): ");
    scanf("%d %d", &row, &col);
    while(!input_valid(row, col, board)){
        printf("Invalid move.\nEnter the row and column of your move (0-2): ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = player;
    display_board(board);
}

//function for the computer's turn
void computer_turn(char board[][3], char player){
    int row, col;
    int i, j;
    int found = 0;

    //check for possible win for computer
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == ' '){
                board[i][j] = player;
                if(check_win(board, player)){
                    row = i;
                    col = j;
                    found = 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    //prevent user win if no possible computer win exists
    if(found == 0){
        player = 'X';
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(board[i][j] == ' '){
                    board[i][j] = player;
                    if(check_win(board, player)){
                        row = i;
                        col = j;
                        found = 1;
                    }
                    board[i][j] = ' ';
                }   
            }
        }
        player = 'O';
    }
    //if no wins can be achieved, choose random empty space
    if(found == 0){
        do{
            row = rand() % 3;
            col = rand() % 3;
        } while(!input_valid(row, col, board));
    }
    board[row][col] = player;
    display_board(board);
}