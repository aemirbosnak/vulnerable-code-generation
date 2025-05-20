//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Game constants
#define BOARD_SIZE 10
#define NUM_PLAYERS 2
#define MAX_NAME_LENGTH 20

// Game state
typedef struct {
  char board[BOARD_SIZE][BOARD_SIZE];
  int player_turn;
  int winner;
} game_state;

// Player data
typedef struct {
  char name[MAX_NAME_LENGTH];
  char symbol;
  int wins;
  int losses;
} player;

// Function prototypes
void init_game(game_state *state);
void print_board(game_state *state);
int check_winner(game_state *state);
void take_turn(game_state *state, player *player);
void switch_turn(game_state *state);
void game_loop(game_state *state, player *players);

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the game state and players
  game_state state;
  player players[NUM_PLAYERS];

  // Initialize the game
  init_game(&state);

  // Prompt the players for their names
  printf("Enter the name of player 1: ");
  scanf("%s", players[0].name);
  players[0].symbol = 'X';

  printf("Enter the name of player 2: ");
  scanf("%s", players[1].name);
  players[1].symbol = 'O';

  // Start the game loop
  game_loop(&state, players);

  return 0;
}

// Initialize the game state
void init_game(game_state *state) {
  // Clear the board
  memset(state->board, ' ', sizeof(state->board));

  // Set the player turn to player 1
  state->player_turn = 0;

  // Set the winner to none
  state->winner = -1;
}

// Print the game board
void print_board(game_state *state) {
  // Print the column numbers
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i);
  }
  printf("\n");

  // Print the board rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", state->board[i][j]);
    }
    printf("\n");
  }
}

// Check if there is a winner
int check_winner(game_state *state) {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (state->board[i][0] != ' ' && state->board[i][0] == state->board[i][1] && state->board[i][1] == state->board[i][2]) {
      return state->board[i][0] == 'X' ? 0 : 1;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (state->board[0][i] != ' ' && state->board[0][i] == state->board[1][i] && state->board[1][i] == state->board[2][i]) {
      return state->board[0][i] == 'X' ? 0 : 1;
    }
  }

  // Check for diagonal wins
  if (state->board[0][0] != ' ' && state->board[0][0] == state->board[1][1] && state->board[1][1] == state->board[2][2]) {
    return state->board[0][0] == 'X' ? 0 : 1;
  }
  if (state->board[0][2] != ' ' && state->board[0][2] == state->board[1][1] && state->board[1][1] == state->board[2][0]) {
    return state->board[0][2] == 'X' ? 0 : 1;
  }

  // No winner yet
  return -1;
}

// Take a turn for a player
void take_turn(game_state *state, player *player) {
  int x, y;

  // Prompt the player for their move
  printf("%s, it's your turn. Enter the coordinates of your move (x, y): ", player->name);
  scanf("%d %d", &x, &y);

  // Check if the move is valid
  while (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || state->board[x][y] != ' ') {
    printf("Invalid move. Enter the coordinates of your move (x, y): ");
    scanf("%d %d", &x, &y);
  }

  // Place the player's symbol on the board
  state->board[x][y] = player->symbol;
}

// Switch the player turn
void switch_turn(game_state *state) {
  state->player_turn = (state->player_turn + 1) % NUM_PLAYERS;
}

// Game loop
void game_loop(game_state *state, player *players) {
  // Loop until there is a winner
  while (state->winner == -1) {
    // Print the game board
    print_board(state);

    // Take a turn for the current player
    take_turn(state, &players[state->player_turn]);

    // Check if there is a winner
    state->winner = check_winner(state);

    // Switch the player turn
    switch_turn(state);
  }

  // Print the winner
  printf("The winner is %s!\n", players[state->winner].name);
}