//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board
char ai = 'O'; // AI player symbol
char human = 'X'; // Human player symbol

// AI Move
void aiMove() {
  int row, col;

  // Get the current time for random move
  srand(time(NULL));

  // Generate random row and column
  row = rand() % 3;
  col = rand() % 3;

  // Check if the random position is empty
  while(board[row][col] != ' ') {
    row = rand() % 3;
    col = rand() % 3;
  }

  board[row][col] = ai;
}

// Draw Board
void drawBoard() {

  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Check if game is over
int gameOver() {
  int i, j;
  int flag = 0;

  // Check if any row is identical
  for(i = 0; i < 3; i++) {
    if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && board[i][0] != ' ') {
      flag = 1;
      break;
    }
  }

  // Check if any column is identical
  for(i = 0; i < 3; i++) {
    if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) && board[0][i] != ' ') {
      flag = 1;
      break;
    }
  }

  // Check if either diagonal is identical
  if(((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0])) && board[1][1] != ' ') {
    flag = 1;
  }

  // Check if game is tied
  int emptySpaces = 0;
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      if (board[i][j] == ' '){
        emptySpaces++;
      }
    }
  }

  if (emptySpaces == 0 && flag == 0){
    flag = -1; // Tie game
  }

  return flag;
}

// Human Move
void humanMove() {
  int row, col;
  printf("Enter row number (0-2): ");
  scanf("%d", &row);
  printf("Enter column number (0-2): ");
  scanf("%d", &col);

  // Check if position is empty
  while(board[row][col] != ' ') {
    printf("Position already occupied. Enter a different position.\n");
    printf("Enter row number (0-2): ");
    scanf("%d", &row);
    printf("Enter column number (0-2): ");
    scanf("%d", &col);
  }

  board[row][col] = human;
}

int main() {
  int winner = 0; // 0 - game not over, 1 - AI wins, 2 - human wins, -1 - tie game

  // Initialize board
  int i, j;
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }

  // Draw empty board
  drawBoard();

  // Play game
  while(winner == 0){
    // AI turn
    aiMove();
    drawBoard();
    winner = gameOver();
    if (winner != 0){
      break;
    }

    // Human turn
    humanMove();
    drawBoard();
    winner = gameOver();
  }

  // Check winner
  switch(winner) {
    case 1:
      printf("AI Wins!\n");
      break;
    case 2:
      printf("Human Wins!\n");
      break;
    case -1:
      printf("Tie Game!\n");
      break;
  }

  return 0;
}