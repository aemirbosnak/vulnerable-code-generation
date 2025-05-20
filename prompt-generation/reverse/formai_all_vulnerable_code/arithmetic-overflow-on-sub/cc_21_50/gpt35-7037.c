//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

//function to print the tic-tac-toe board
void print_board(char board[]){
    printf("\n");
    printf("\t  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("\t--------------\n");
    printf("\t  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("\t--------------\n");
    printf("\t  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("\n");
}

//function to check if any player won the game
int check_winner(char board[]){
    
    //checking all the possible win scenarios
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X') return 1;
    if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') return 1;
    if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') return 1;
    if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') return 1;
    if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return 1;
    if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') return 1;
    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') return 1;
    if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') return 1;
    
    if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O') return -1;
    if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') return -1;
    if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') return -1;
    if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') return -1;
    if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') return -1;
    if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') return -1;
    if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') return -1;
    if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O') return -1;
    
    return 0;
}

//function to take input from the player
int player_input(char board[]){
    int choice;
    printf("Enter your choice (1-9): ");
    scanf("%d", &choice);
    choice--;
    if(board[choice] == 'X' || board[choice] == 'O') {
        printf("Already taken. Please try again.\n");
        player_input(board);
    }
    else{
        board[choice] = 'X';
        return choice;
    }
}

//function to get AI's move
int get_AImove(char board[]){
    int check = 0;
    int move;
    
    //checking all the possible win scenarios for AI
    if(board[0] == 'O' && board[1] == 'O' && board[2] == ' ') move = 2;
    else if(board[3] == 'O' && board[4] == 'O' && board[5] == ' ') move = 5;
    else if(board[6] == 'O' && board[7] == 'O' && board[8] == ' ') move = 8;
    else if(board[0] == 'O' && board[3] == 'O' && board[6] == ' ') move = 6;
    else if(board[1] == 'O' && board[4] == 'O' && board[7] == ' ') move = 7;
    else if(board[2] == 'O' && board[5] == 'O' && board[8] == ' ') move = 8;
    else if(board[0] == 'O' && board[4] == 'O' && board[8] == ' ') move = 8;
    else if(board[2] == 'O' && board[4] == 'O' && board[6] == ' ') move = 6;
    
    //checking all the possible block scenarios for AI
    else if(board[0] == 'X' && board[1] == 'X' && board[2] == ' ') move = 2;
    else if(board[3] == 'X' && board[4] == 'X' && board[5] == ' ') move = 5;
    else if(board[6] == 'X' && board[7] == 'X' && board[8] == ' ') move = 8;
    else if(board[0] == 'X' && board[3] == 'X' && board[6] == ' ') move = 6;
    else if(board[1] == 'X' && board[4] == 'X' && board[7] == ' ') move = 7;
    else if(board[2] == 'X' && board[5] == 'X' && board[8] == ' ') move = 8;
    else if(board[0] == 'X' && board[4] == 'X' && board[8] == ' ') move = 8;
    else if(board[2] == 'X' && board[4] == 'X' && board[6] == ' ') move = 6;
    
    //getting a random move if no such scenario exists
    else{
        while(check == 0){
            move = rand() % 9;
            if(board[move] == ' ') check = 1;
        }
    }
    
    board[move] = 'O';
    return move;
}

//main program
int main(){
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int winner = 0;
    int turn = 0;
    int choice;
    
    printf("Welcome to Tic-Tac-Toe!\n");
    print_board(board);
    
    while(winner == 0 && turn < 9){
        if(turn % 2 == 0){
            choice = player_input(board);
        }
        else{
            choice = get_AImove(board);
            printf("AI has chosen %d\n", choice+1);
        }
        print_board(board);
        winner = check_winner(board);
        turn++;
    }
    
    if(winner == 1){
        printf("Congratulations!\nYou have won the game!");
    }
    else if(winner == -1){
        printf("Sorry!\nThe AI has won the game.");
    }
    else{
        printf("It's a tie!");
    }
    
    return 0;
}