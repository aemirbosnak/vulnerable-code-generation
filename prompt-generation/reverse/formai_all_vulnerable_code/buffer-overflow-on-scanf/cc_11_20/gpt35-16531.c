//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//The matrix for our game
char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

//Function to print the matrix
void print_matrix(){
    printf("\n");
    printf("     %c | %c | %c\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("     ---------\n");
    printf("     %c | %c | %c\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("     ---------\n");
    printf("     %c | %c | %c\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

//Function to check if the user has won
int check_win(char ch){
    if (matrix[0][0] == ch && matrix[0][1] == ch && matrix[0][2] == ch)
        return 1;
    else if (matrix[1][0] == ch && matrix[1][1] == ch && matrix[1][2] == ch)
        return 1;
    else if (matrix[2][0] == ch && matrix[2][1] == ch && matrix[2][2] == ch)
        return 1;
    else if (matrix[0][0] == ch && matrix[1][0] == ch && matrix[2][0] == ch)
        return 1;
    else if (matrix[0][1] == ch && matrix[1][1] == ch && matrix[2][1] == ch)
        return 1;
    else if (matrix[0][2] == ch && matrix[1][2] == ch && matrix[2][2] == ch)
        return 1;
    else if (matrix[0][0] == ch && matrix[1][1] == ch && matrix[2][2] == ch)
        return 1;
    else if (matrix[0][2] == ch && matrix[1][1] == ch && matrix[2][0] == ch)
        return 1;
    else
        return 0;
}

//Main function
int main(){
    srand(time(NULL)); //randomize the seed
    
    printf("\nWelcome to Tic Tac Toe Game!\n");
    printf("You are 'X' and the opponent is 'O'.\n");
    printf("To play, enter the number of the cell you want to place your mark in.\n");
    printf("\n");
    
    print_matrix();
    int x, y, p = 1, decision, success; //p is a flag variable that toggles the turn
    
    while(1){
        if (p == 1){
            printf("Enter the cell number you want to place your mark in: ");
            decision = scanf("%d", &x);
            if (decision != 1 || x < 1 || x > 9){
                printf("Invalid input. Please enter a number between 1 and 9.\n");
                fflush(stdin);
                continue;
            }
            success = 0;
            for (int i=0; i<3; i++){
                for (int j=0; j<3; j++){
                    if (matrix[i][j] == x + '0'){
                        matrix[i][j] = 'X';
                        success = 1; //mark placed successfully
                        break;
                    }
                }
            }
            if (success == 0){
                printf("Invalid move. Cell already taken.\n");
                continue;
            }
            p = 0; //Other player's turn
            
            //check if the move has resulted in victory
            if(check_win('X')){
                print_matrix();
                printf("\nCongratulations! You have won the game!\n");
                break;
            }
        }
        else{
            printf("\nComputer's turn:\n");
            int flag = 0;
            while(flag == 0){
                x = rand() % 3;
                y = rand() % 3;
                if (matrix[x][y] != 'X' && matrix[x][y] != 'O'){
                    matrix[x][y] = 'O';
                    flag = 1; //mark placed successfully
                }
            }
            p = 1; //Your turn
            
            print_matrix();
            
            //check if the move has resulted in victory
            if(check_win('O')){
                printf("\nSorry! You have lost the game!\n");
                break;
            }
        }
    }
    return 0;
}