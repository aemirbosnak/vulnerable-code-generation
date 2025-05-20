//FormAI DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include<stdio.h>

//Function to create a checkers board
void create_board(char board[][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2==0){
                if(i>=0 && i<3){
                    board[i][j]='R';
                }
                else if(i>=5 && i<8){
                    board[i][j]='B';
                }
                else{
                    board[i][j]=' ';
                }
            }
            else{
                board[i][j]=' ';
            }
        }
    }
}

//Function to display the checkers board
void display_board(char board[][8]){
    printf("\n\tA B C D E F G H\n");
    for(int i=0; i<8; i++){
        printf("%d\t",i+1);
        for(int j=0; j<8; j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

//Function to check if move is valid
int is_valid_move(char board[][8], int start_x, int start_y, int end_x, int end_y, char player){
    //Check whether end coordinates are in range
    if(end_x<0 || end_x>7 || end_y<0 || end_y>7){
        return 0;
    }
    //Check whether the end coordinates are empty
    if(board[end_x][end_y]!=' '){
        return 0;
    }
    //Check whether the player is moving their own piece
    if(player=='R' && board[start_x][start_y]!='R'){
        return 0;
    }
    if(player=='B' && board[start_x][start_y]!='B'){
        return 0;
    }
    //Check whether the move is a diagonal move
    if(abs(end_x-start_x)!=1 || abs(end_y-start_y)!=1){
        return 0;
    }
    return 1;
}

//Function to make a move
void make_move(char board[][8], int start_x, int start_y, int end_x, int end_y){
    //Move the piece to the end coordinates
    board[end_x][end_y] = board[start_x][start_y];
    //Update the start coordinates to be empty
    board[start_x][start_y] = ' ';
}

//Function to play the game
void play_game(){
    char board[8][8];
    int turn_count = 0;
    int game_over = 0;
    int player1_count = 12;
    int player2_count = 12;
    char player1 = 'R';
    char player2 = 'B';
    create_board(board);
    while(!game_over){
        //Display the board
        printf("\n\nTurn %d\n",turn_count+1);
        display_board(board);
        //Get the player's move
        char player;
        int start_x, start_y, end_x, end_y;
        if(turn_count%2==0){
            player = player1;
        }
        else{
            player = player2;
        }
        printf("%c's Move:\n",player);
        printf("Enter starting coordinate (row,column): ");
        scanf("%d,%d",&start_x,&start_y);
        printf("Enter ending coordinate (row,column): ");
        scanf("%d,%d",&end_x,&end_y);
        //Check if move is valid and make the move
        if(is_valid_move(board,start_x-1,start_y-1,end_x-1,end_y-1,player)){
            make_move(board,start_x-1,start_y-1,end_x-1,end_y-1);
            //Check if a piece has been taken
            int diff_x = end_x-start_x;
            int diff_y = end_y-start_y;
            if(abs(diff_x)==2 && abs(diff_y)==2){
                int taken_x = (start_x+end_x)/2;
                int taken_y = (start_y+end_y)/2;
                if(player=='R'){
                    player2_count--;
                }
                else{
                    player1_count--;
                }
                board[taken_x][taken_y] = ' ';
            }
            turn_count++;
        }
        else{
            printf("Invalid move! Please try again.\n");
        }
        //Check if game is over
        if(player1_count==0){
            printf("\nB wins! Congratulations!\n");
            game_over = 1;
        }
        if(player2_count==0){
            printf("\nR wins! Congratulations!\n");
            game_over = 1;
        }
    }
}

//Main function
int main(){
    printf("\nWelcome to Checkers!\n");
    play_game();
    return 0;
}