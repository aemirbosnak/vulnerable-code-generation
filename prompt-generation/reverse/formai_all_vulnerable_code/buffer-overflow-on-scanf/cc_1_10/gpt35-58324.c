//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3]; // Create a 3x3 Tic Tac Toe board
int empty_spaces = 9; // Each board begins with 9 empty spaces

void print_board(){
    printf("-------------\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("| %c ", board[i][j]); // Print each symbol in the board
        }
        printf("|\n");
        printf("-------------\n");
    }
}

int check_win(char symbol){
    // Check for horizontal win
    for(int i=0;i<3;i++){
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol){
            return 1;
        }
    }
    
    // Check for vertical win
    for(int j=0;j<3;j++){
        if(board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol){
            return 1;
        }
    }

    // Check for diagonal win
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
        return 1;
    }else if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol){
        return 1;
    }

    return 0;
}

void player_turn(){
    int row, col;
    printf("Enter row(0-2) and column(0-2) coordinates to place 'X': ");
    scanf("%d%d", &row, &col);

    if(row<0 || row>2 || col<0 || col>2){
        printf("Invalid input. Please enter valid row and colunm values.\n");
        player_turn();
    }else if(board[row][col] != ' '){
        printf("That space is already taken. Please choose another one.\n");
        player_turn();
    }else{
        board[row][col] = 'X';
        empty_spaces--;
    }
}

void ai_turn(){
    printf("AI is thinking...\n");
    int row, col;   
    srand(time(NULL)); // Seed with current time

    while(empty_spaces>0){
        row = rand() % 3; // Generate a random row number
        col = rand() % 3; // Generate a random column number

        if(board[row][col] == ' '){ // If the space is empty
            board[row][col] = 'O';
            empty_spaces--;
            break;
        }
    }
}

int main(){
    // Initialize the board
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");

    // Game loop
    while(empty_spaces>0){
        print_board(); // Print the current board
        player_turn(); // Player's turn
        if(check_win('X')){ // Check if the player wins
            print_board();
            printf("Congratulations! You won!\n");
            return 0;
        }
        ai_turn(); // AI's turn
        if(check_win('O')){ // Check if the AI wins
            print_board();
            printf("AI wins! Better luck next time.\n");
            return 0;
        }
    }

    print_board();
    printf("It's a tie!\n");

    return 0;
}