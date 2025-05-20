//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_BOARD_SIZE 10

typedef struct {
  char name[20];
  int score;
  char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
} player_t;

void print_board(player_t *player) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      printf("%c", player->board[i][j]);
    }
    printf("\n");
  }
}

int check_winner(player_t *player) {
  // Check rows
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    if (player->board[i][0] != ' ' && player->board[i][0] == player->board[i][1] && player->board[i][1] == player->board[i][2]) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    if (player->board[0][i] != ' ' && player->board[0][i] == player->board[1][i] && player->board[1][i] == player->board[2][i]) {
      return 1;
    }
  }

  // Check diagonals
  if (player->board[0][0] != ' ' && player->board[0][0] == player->board[1][1] && player->board[1][1] == player->board[2][2]) {
    return 1;
  }
  if (player->board[0][2] != ' ' && player->board[0][2] == player->board[1][1] && player->board[1][1] == player->board[2][0]) {
    return 1;
  }

  return 0;
}

int main() {
  player_t players[MAX_PLAYERS];
  int num_players;

  // Get the number of players
  printf("How many players? (1-4): ");
  scanf("%d", &num_players);

  // Get the player names
  for (int i = 0; i < num_players; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", players[i].name);
  }

  // Initialize the game board
  for (int i = 0; i < num_players; i++) {
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      for (int k = 0; k < MAX_BOARD_SIZE; k++) {
        players[i].board[j][k] = ' ';
      }
    }
  }

  // Game loop
  int current_player = 0;
  while (1) {
    // Print the game board
    for (int i = 0; i < num_players; i++) {
      printf("Player %s's board:\n", players[i].name);
      print_board(&players[i]);
      printf("\n");
    }

    // Get the current player's move
    int row, col;
    printf("Player %s's turn: ", players[current_player].name);
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);

    // Place the player's symbol on the board
    players[current_player].board[row - 1][col - 1] = players[current_player].name[0];

    // Check if the player has won
    if (check_winner(&players[current_player])) {
      printf("Player %s wins!\n", players[current_player].name);
      break;
    }

    // Switch to the next player
    current_player = (current_player + 1) % num_players;
  }

  return 0;
}