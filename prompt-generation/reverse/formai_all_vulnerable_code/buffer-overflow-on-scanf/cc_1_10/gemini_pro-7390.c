//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 255

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the number of character classes
#define NUM_CHAR_CLASSES 4

// Define the maximum number of characters in a password
#define MAX_PASSWORD_LENGTH 255

// Define the number of players
#define NUM_PLAYERS 4

// Define the player names
char player_names[NUM_PLAYERS][MAX_PASSWORD_LENGTH];

// Define the player passwords
char player_passwords[NUM_PLAYERS][MAX_PASSWORD_LENGTH];

// Define the player scores
int player_scores[NUM_PLAYERS];

// Define the game board
char game_board[NUM_PLAYERS][NUM_CHAR_CLASSES];

// Define the game status
enum game_status {
  GAME_STATUS_IN_PROGRESS,
  GAME_STATUS_PLAYER_1_WINS,
  GAME_STATUS_PLAYER_2_WINS,
  GAME_STATUS_PLAYER_3_WINS,
  GAME_STATUS_PLAYER_4_WINS,
  GAME_STATUS_DRAW
};

// Define the game status messages
char *game_status_messages[] = {
  "Game in progress",
  "Player 1 wins!",
  "Player 2 wins!",
  "Player 3 wins!",
  "Player 4 wins!",
  "Draw"
};

// Initialize the game board
void init_game_board() {
  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < NUM_CHAR_CLASSES; j++) {
      game_board[i][j] = 0;
    }
  }
}

// Check if the password is valid
int is_valid_password(char *password) {
  // Check if the password is the correct length
  if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
    return 0;
  }

  // Check if the password contains at least one character from each character class
  int char_classes[NUM_CHAR_CLASSES] = {0};
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      char_classes[CHAR_CLASS_LOWER] = 1;
    } else if (password[i] >= 'A' && password[i] <= 'Z') {
      char_classes[CHAR_CLASS_UPPER] = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      char_classes[CHAR_CLASS_DIGIT] = 1;
    } else {
      char_classes[CHAR_CLASS_SPECIAL] = 1;
    }
  }

  for (int i = 0; i < NUM_CHAR_CLASSES; i++) {
    if (char_classes[i] == 0) {
      return 0;
    }
  }

  // The password is valid
  return 1;
}

// Get the score for a password
int get_score_for_password(char *password) {
  int score = 0;

  // Add 1 point for each character in the password
  score += strlen(password);

  // Add 1 point for each character class represented in the password
  int char_classes[NUM_CHAR_CLASSES] = {0};
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      char_classes[CHAR_CLASS_LOWER] = 1;
    } else if (password[i] >= 'A' && password[i] <= 'Z') {
      char_classes[CHAR_CLASS_UPPER] = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      char_classes[CHAR_CLASS_DIGIT] = 1;
    } else {
      char_classes[CHAR_CLASS_SPECIAL] = 1;
    }
  }

  for (int i = 0; i < NUM_CHAR_CLASSES; i++) {
    if (char_classes[i] == 1) {
      score++;
    }
  }

  // Return the score
  return score;
}

// Get the player with the highest score
int get_player_with_highest_score() {
  int highest_score = 0;
  int player_with_highest_score = -1;

  for (int i = 0; i < NUM_PLAYERS; i++) {
    if (player_scores[i] > highest_score) {
      highest_score = player_scores[i];
      player_with_highest_score = i;
    }
  }

  return player_with_highest_score;
}

// Play the game
void play_game() {
  // Initialize the game board
  init_game_board();

  // Get the passwords from the players
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("Player %d, enter your password: ", i + 1);
    scanf("%s", player_passwords[i]);
  }

  // Check if the passwords are valid
  for (int i = 0; i < NUM_PLAYERS; i++) {
    if (!is_valid_password(player_passwords[i])) {
      printf("Player %d, your password is invalid. Please enter a new password: ", i + 1);
      scanf("%s", player_passwords[i]);
    }
  }

  // Get the scores for the passwords
  for (int i = 0; i < NUM_PLAYERS; i++) {
    player_scores[i] = get_score_for_password(player_passwords[i]);
  }

  // Get the player with the highest score
  int player_with_highest_score = get_player_with_highest_score();

  // Print the game status
  printf("%s\n", game_status_messages[player_with_highest_score]);
}

int main() {
  // Play the game
  play_game();

  return 0;
}