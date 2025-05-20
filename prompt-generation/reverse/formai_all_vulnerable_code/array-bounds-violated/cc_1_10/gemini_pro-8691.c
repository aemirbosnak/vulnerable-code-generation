//GEMINI-pro DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 5

// Define the number of players
#define NUM_PLAYERS 2

// Define the player types
typedef enum {
  PLAYER_HUMAN,
  PLAYER_COMPUTER
} player_type;

// Define the game state
typedef enum {
  GAME_STATE_PLAYING,
  GAME_STATE_OVER
} game_state;

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player data
struct player {
  player_type type;
  char symbol;
};

// Define the game data
struct game {
  game_state state;
  struct player players[NUM_PLAYERS];
  int current_player;
};

// Function to initialize the game
void game_init(struct game *game) {
  // Set the game state to playing
  game->state = GAME_STATE_PLAYING;

  // Set the current player to player 1
  game->current_player = 0;

  // Initialize the players
  game->players[0].type = PLAYER_HUMAN;
  game->players[0].symbol = 'X';
  game->players[1].type = PLAYER_COMPUTER;
  game->players[1].symbol = 'O';

  // Clear the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void game_print(struct game *game) {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the next move from a player
int game_get_next_move(struct game *game, struct player *player) {
  int row, col;

  if (player->type == PLAYER_HUMAN) {
    // Get the move from the user
    printf("Player %d, enter your move (row, col): ", game->current_player + 1);
    scanf("%d %d", &row, &col);
  } else {
    // Get the move from the computer
    // Here we are using a simple random move generator
    srand(time(NULL));
    row = rand() % BOARD_SIZE;
    col = rand() % BOARD_SIZE;
  }

  return row * BOARD_SIZE + col;
}

// Function to make a move on the game board
void game_make_move(struct game *game, int move) {
  int row, col;

  // Get the row and column from the move
  row = move / BOARD_SIZE;
  col = move % BOARD_SIZE;

  // Place the player's symbol on the board
  board[row][col] = game->players[game->current_player].symbol;
}

// Function to check if the game is over
int game_is_over(struct game *game) {
  // Check for a win in any of the rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return 1;
    }
  }

  // Check for a win in any of the columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return 1;
    }
  }

  // Check for a win in either diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 1;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 1;
  }

  // Check for a tie
  int tie = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        tie = 0;
        break;
      }
    }
  }
  if (tie) {
    return 2;
  }

  return 0;
}

// Function to play the game
void game_play(struct game *game) {
  int move;

  while (game->state == GAME_STATE_PLAYING) {
    // Get the next move from the current player
    move = game_get_next_move(game, &game->players[game->current_player]);

    // Make the move on the game board
    game_make_move(game, move);

    // Print the game board
    game_print(game);

    // Check if the game is over
    int result = game_is_over(game);
    if (result == 1) {
      // A player has won
      printf("Player %d wins!\n", game->current_player + 1);
      game->state = GAME_STATE_OVER;
    } else if (result == 2) {
      // The game is a tie
      printf("Tie game!\n");
      game->state = GAME_STATE_OVER;
    } else {
      // The game is still playing
      // Switch to the other player
      game->current_player = (game->current_player + 1) % NUM_PLAYERS;
    }
  }
}

// Main function
int main() {
  // Initialize the game
  struct game game;
  game_init(&game);

  // Play the game
  game_play(&game);

  return 0;
}