//FormAI DATASET v1.0 Category: Checkers Game ; Style: futuristic
//Futuristic Checkers Game
#include <stdio.h>

int main(){
  int board[8][8] = {0}; //Initializes an 8x8 checkerboard with all zeros
  int turn = 0; //0 for player 1 and 1 for player 2
  int player1_pieces = 12; //Start with 12 pieces each
  int player2_pieces = 12;
  
  printf("Welcome to Futuristic Checkers Game!\n");
  
  while(player1_pieces > 0 && player2_pieces > 0){ //While both players have pieces
  
    //Print the checkerboard
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
        if(board[i][j] == 0) printf("- ");
        else if(board[i][j] == 1) printf("1 ");
        else printf("2 ");
      }
      printf("\n");
    }
    
    //Get user input for the piece to move and where to move it
    printf("Player %d's turn\n", turn+1);
    int piece_i, piece_j, move_i, move_j;
    printf("Enter the coordinates of the piece to move: ");
    scanf("%d %d", &piece_i, &piece_j);
    printf("Enter the coordinates of where to move the piece: ");
    scanf("%d %d", &move_i, &move_j);
    
    //Check if the move is valid
    if(abs(move_i - piece_i) == abs(move_j - piece_j) && board[move_i][move_j] == 0){ //Diagonal move and the destination is empty
      
      if(turn == 0 && board[piece_i][piece_j] == 1 && move_i > piece_i){ //Player 1 can only move downwards
        board[move_i][move_j] = 1; //Move the piece to the destination
        board[piece_i][piece_j] = 0; //Remove the piece from its original location
      }
      else if(turn == 1 && board[piece_i][piece_j] == 2 && move_i < piece_i){ //Player 2 can only move upwards
        board[move_i][move_j] = 2;
        board[piece_i][piece_j] = 0;
      }
      else{
        printf("Invalid move\n");
        continue; //Restart the loop and ask for input again
      }
      
      //Check if the piece captured another piece
      int captured_piece_i = (move_i + piece_i) / 2; //Calculate the location of the piece that may have been captured
      int captured_piece_j = (move_j + piece_j) / 2;
      if(abs(move_i - piece_i) == 2 && abs(move_j - piece_j) == 2 && board[captured_piece_i][captured_piece_j] != turn+1 && board[captured_piece_i][captured_piece_j] != 0){ //Captured a piece
        if(turn == 0) player2_pieces--; //Reduce player 2's pieces
        else player1_pieces--; //Reduce player 1's pieces
        board[captured_piece_i][captured_piece_j] = 0; //Remove the captured piece from the board
      }
      
      turn = 1 - turn; //Switch turns
    }
    else{
      printf("Invalid move\n");
    }
  }
  
  //The game is over
  if(player1_pieces == 0) printf("Player 2 wins!\n");
  else printf("Player 1 wins!\n");
  
  return 0;
}