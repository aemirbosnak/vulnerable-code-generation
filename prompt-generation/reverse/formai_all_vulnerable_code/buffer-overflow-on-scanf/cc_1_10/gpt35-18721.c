//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3];
int move_count = 0;
int computer_wins = 0;
int player_wins = 0;

void initialize_board(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      board[i][j] = '-';
    }
  }
}

void display_board(){
  printf("-------------\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
    printf("-------------\n");
  }
}

void player_move(char player){
  int row, col;
  printf("Enter the row and column of your move: ");
  scanf("%d %d", &row, &col);
  while(1){
    if(row<0 || row>2 || col<0 || col>2){
      printf("Invalid move. Enter again: ");
      scanf("%d %d", &row, &col);
      continue;
    }
    if(board[row][col] == '-'){
      board[row][col] = player;
      move_count++;
      break;
    }
    else{
      printf("Invalid move. Enter again: ");
      scanf("%d %d", &row, &col);
      continue;
    }
  }
}

void computer_move(char computer){
  int row, col;
  while(1){
    srand(time(NULL));
    row = rand() % 3;
    col = rand() % 3;
    if(board[row][col] == '-'){
      board[row][col] = computer;
      move_count++;
      break;
    }
    else{
      continue;
    }
  }
}

int check_win(char player){
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return 1;
  }
  else if(board[1][0] == player && board[1][1] == player && board[1][2] == player){
    return 1;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player){
    return 1;
  }
  else if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
    return 1;
  }
  else if(board[0][1] == player && board[1][1] == player && board[2][1] == player){
    return 1;
  }
  else if(board[0][2] == player && board[1][2] == player && board[2][2] == player){
    return 1;
  }
  else if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return 1;
  }
  else if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  char player, computer;
  printf("Enter which player you want to be (X/O): ");
  scanf(" %c", &player);
  while(1){
    if(player == 'X' || player == 'O'){
      break;
    }
    else{
      printf("Invalid choice. Enter again: ");
      scanf(" %c", &player);
      continue;
    }
  }
  if(player == 'X'){
    computer = 'O';
  }
  else{
    computer = 'X';
  }

  initialize_board();
  display_board();

  while(move_count < 9){
    player_move(player);
    display_board();
    if(check_win(player)){
      printf("Congratulations! You won!\n");
      player_wins++;
      printf("Player wins: %d, Computer wins: %d\n\n", player_wins, computer_wins);
      printf("New game started.\n");
      move_count = 0;
      initialize_board();
      display_board();
      continue;
    }
    if(move_count == 9){
      printf("It's a tie!\n");
      printf("Player wins: %d, Computer wins: %d\n\n", player_wins, computer_wins);
      printf("New game started.\n");
      move_count = 0;
      initialize_board();
      display_board();
      continue;
    }
    printf("Computer has made a move.\n");
    computer_move(computer);
    display_board();
    if(check_win(computer)){
      printf("Sorry, you lost. Better luck next time!\n");
      computer_wins++;
      printf("Player wins: %d, Computer wins: %d\n\n", player_wins, computer_wins);
      printf("New game started.\n");
      move_count = 0;
      initialize_board();
      display_board();
      continue;
    }
  }

  return 0;
}