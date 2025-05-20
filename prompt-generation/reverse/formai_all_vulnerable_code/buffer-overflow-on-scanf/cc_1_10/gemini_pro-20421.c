//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table size
#define TABLE_SIZE 5

// Define the number of players
#define NUM_PLAYERS 2

// Define the number of dice
#define NUM_DICE 2

// Define the maximum number of turns
#define MAX_TURNS 10

// Define the player types
typedef enum {
  PLAYER_TYPE_HUMAN,
  PLAYER_TYPE_COMPUTER
} player_type_t;

// Define the player struct
typedef struct {
  player_type_t type;
  int score;
} player_t;

// Define the table struct
typedef struct {
  int spaces[TABLE_SIZE];
} table_t;

// Function to initialize the table
void init_table(table_t *table) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    table->spaces[i] = 0;
  }
}

// Function to print the table
void print_table(table_t *table) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d ", table->spaces[i]);
  }
  printf("\n");
}

// Function to get the player's move
int get_move(player_t *player, table_t *table) {
  if (player->type == PLAYER_TYPE_HUMAN) {
    int move;
    printf("Enter your move: ");
    scanf("%d", &move);
    return move;
  } else {
    // Computer player randomly selects a move
    srand(time(NULL));
    return rand() % TABLE_SIZE;
  }
}

// Function to check if the move is valid
int is_valid_move(int move, table_t *table) {
  return move >= 0 && move < TABLE_SIZE && table->spaces[move] == 0;
}

// Function to make a move
void make_move(int move, player_t *player, table_t *table) {
  table->spaces[move] = player->score;
  player->score++;
}

// Function to check if the game is over
int is_game_over(table_t *table) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table->spaces[i] == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to get the winner
player_t *get_winner(player_t *players) {
  if (players[0].score > players[1].score) {
    return &players[0];
  } else if (players[0].score < players[1].score) {
    return &players[1];
  } else {
    return NULL;
  }
}

// Function to play the game
void play_game() {
  // Initialize the table
  table_t table;
  init_table(&table);

  // Initialize the players
  player_t players[NUM_PLAYERS];
  players[0].type = PLAYER_TYPE_HUMAN;
  players[0].score = 0;
  players[1].type = PLAYER_TYPE_COMPUTER;
  players[1].score = 0;

  // Play the game
  int turn = 0;
  while (!is_game_over(&table) && turn < MAX_TURNS) {
    // Get the current player
    player_t *player = &players[turn % NUM_PLAYERS];

    // Get the player's move
    int move = get_move(player, &table);

    // Check if the move is valid
    if (!is_valid_move(move, &table)) {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Make the move
    make_move(move, player, &table);

    // Print the table
    print_table(&table);

    // Increment the turn
    turn++;
  }

  // Get the winner
  player_t *winner = get_winner(players);

  // Print the winner
  if (winner != NULL) {
    printf("The winner is %s!\n", winner->type == PLAYER_TYPE_HUMAN ? "Human" : "Computer");
  } else {
    printf("The game is a draw!\n");
  }
}

// Main function
int main() {
  play_game();
  return 0;
}