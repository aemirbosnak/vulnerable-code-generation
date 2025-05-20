//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>

// Function to check the board for a winning condition
int checkWin(char board[]) {
  if (board[0] == board[1] && board[0] == board[2]) {
    return 1;
  } else if (board[3] == board[4] && board[3] == board[5]) {
    return 1;
  } else if (board[6] == board[7] && board[6] == board[8]) {
    return 1;
  } else if (board[0] == board[3] && board[0] == board[6]) {
    return 1;
  } else if (board[1] == board[4] && board[1] == board[7]) {
    return 1;
  } else if (board[2] == board[5] && board[2] == board[8]) {
    return 1;
  } else if (board[0] == board[4] && board[0] == board[8]) {
    return 1;
  } else if (board[2] == board[4] && board[2] == board[6]) {
    return 1;
  } else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
             board[3] != '4' && board[4] != '5' && board[5] != '6' &&
             board[6] != '7' && board[7] != '8' && board[8] != '9') {
    return 0;
  } else {
    return -1;
  }
}

// Function to display the board
void displayBoard(char board[]) {
  printf("\n");
  printf(" %c | %c | %c \n", board[0], board[1], board[2]);
  printf("------------\n");
  printf(" %c | %c | %c \n", board[3], board[4], board[5]);
  printf("------------\n");
  printf(" %c | %c | %c \n", board[6], board[7], board[8]);
  printf("\n");
}

// Function to get the input from the player and update the board accordingly
void getPlayerInput(char board[], char playerChar) {
  int input;
  printf("%c's turn. Choose a spot: ", playerChar);
  scanf("%d", &input);
  if (input >= 1 && input <= 9 && board[input - 1] != 'X' &&
      board[input - 1] != 'O') {
    board[input - 1] = playerChar;
  } else {
    printf("Invalid input. Choose a spot between 1 and 9 that hasn't been taken.\n");
    getPlayerInput(board, playerChar);
  }
}

// Function to get the input from the AI and update the board accordingly
void getAIInput(char board[], char aiChar) {
  for (int i = 0; i < 9; i++) {
    if (board[i] != 'X' && board[i] != 'O') {
      // Check if the AI can win
      board[i] = aiChar;
      if (checkWin(board) == 1) {
        return;
      }
      board[i] = ' ';
    }
  }

  for (int i = 0; i < 9; i++) {
    if (board[i] != 'X' && board[i] != 'O') {
      // Check if the player can win and block it
      board[i] = 'X';
      if (checkWin(board) == 1) {
        board[i] = aiChar;
        return;
      }
      board[i] = ' ';
    }
  }

  // Choose a random spot
  int index;
  do {
    index = rand() % 9;
  } while (board[index] == 'X' || board[index] == 'O');

  board[index] = aiChar;
}

int main() {
  char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char playerChar = 'X';
  char aiChar = 'O';
  int currentPlayer = 0;
  int gameState = -1;

  printf("Welcome to Tic Tac Toe!\n");
  printf("You will be playing as X and the AI will be playing as O.\n\n");
  displayBoard(board);

  // Loop until the game is over
  while (gameState == -1) {
    if (currentPlayer == 0) {
      getPlayerInput(board, playerChar);
    } else {
      getAIInput(board, aiChar);
      printf("The AI chose its spot.\n");
    }

    // Display the updated board
    displayBoard(board);

    // Check for a winning condition
    gameState = checkWin(board);

    if (gameState == 1) {
      if (currentPlayer == 0) {
        printf("Congratulations! You won!\n");
      } else {
        printf("The AI wins!\n");
      }
    } else if (gameState == 0) {
      printf("It's a tie!\n");
    }

    // Switch players
    currentPlayer = (currentPlayer + 1) % 2;
  }

  return 0;
}