//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct GameData {
  int score;
  char board[MAX_BUFFER_SIZE];
  int turn;
  char player_symbol;
} GameData;

void drawBoard(GameData *data) {
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 5; c++) {
      printf("%c ", data->board[r * 5 + c]);
    }
    printf("\n");
  }
}

void makeMove(GameData *data) {
  char move;

  printf("Enter your move (e.g. e2): ");
  scanf("%c", &move);

  switch (move) {
    case 'a':
      data->board[0] = data->player_symbol;
      break;
    case 'b':
      data->board[1] = data->player_symbol;
      break;
    case 'c':
      data->board[2] = data->player_symbol;
      break;
    case 'd':
      data->board[3] = data->player_symbol;
      break;
    case 'e':
      data->board[4] = data->player_symbol;
      break;
    default:
      printf("Invalid move.\n");
  }
}

int main() {
  int game_number = 1;
  while (game_number) {
    // Initialize game data
    GameData data;
    data.score = 0;
    data.board[0] = ' ';
    data.board[1] = ' ';
    data.board[2] = ' ';
    data.board[3] = ' ';
    data.board[4] = ' ';
    data.turn = 0;
    data.player_symbol = 'X';

    // Draw the board
    drawBoard(&data);

    // Make the move
    makeMove(&data);

    // Draw the board again
    drawBoard(&data);

    // Check if the game is over
    if (data.score == 5) {
      printf("Game over! You won!");
      break;
    } else if (data.score == 6) {
      printf("Game over! You lost.");
      break;
    } else if (data.board[0] == data.board[1] && data.board[0] == data.board[2] && data.board[0] == data.player_symbol) {
      printf("Game over! You won!");
      break;
    } else if (data.board[3] == data.board[4] && data.board[3] == data.board[2] && data.board[3] == data.player_symbol) {
      printf("Game over! You won!");
      break;
    } else if (data.board[0] == data.board[4] && data.board[0] == data.board[2] && data.board[0] == data.player_symbol) {
      printf("Game over! You won!");
      break;
    } else if (data.board[1] == data.board[3] && data.board[1] == data.board[2] && data.board[1] == data.player_symbol) {
      printf("Game over! You won!");
      break;
    }

    // Increment the game number
    game_number++;
  }

  return 0;
}