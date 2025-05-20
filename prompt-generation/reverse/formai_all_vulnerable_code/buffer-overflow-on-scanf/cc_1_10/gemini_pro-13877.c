//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_UNIT_TYPES 5

// Unit types
typedef enum {
  INCHES,
  FEET,
  YARDS,
  MILES,
  KILOMETERS
} unit_type;

// Player struct
typedef struct {
  char name[MAX_NAME_LENGTH];
  int score;
  unit_type unit;
} player;

// Unit conversion table
double conversion_table[MAX_UNIT_TYPES][MAX_UNIT_TYPES] = {
  {1.0, 12.0, 36.0, 1760.0, 160934.0},
  {1.0 / 12.0, 1.0, 3.0, 144.0, 12000.0},
  {1.0 / 36.0, 1.0 / 3.0, 1.0, 48.0, 4000.0},
  {1.0 / 1760.0, 1.0 / 144.0, 1.0 / 48.0, 1.0, 823.0},
  {1.0 / 160934.0, 1.0 / 12000.0, 1.0 / 4000.0, 1.0 / 823.0, 1.0}
};

// Function to convert from one unit to another
double convert(double value, unit_type from, unit_type to) {
  return value * conversion_table[from][to];
}

// Function to get the unit type from a string
unit_type get_unit_type(char *unit_string) {
  if (strcmp(unit_string, "inches") == 0) {
    return INCHES;
  } else if (strcmp(unit_string, "feet") == 0) {
    return FEET;
  } else if (strcmp(unit_string, "yards") == 0) {
    return YARDS;
  } else if (strcmp(unit_string, "miles") == 0) {
    return MILES;
  } else if (strcmp(unit_string, "kilometers") == 0) {
    return KILOMETERS;
  } else {
    return -1;
  }
}

// Function to get the player's guess
double get_guess(player *player) {
  double guess;
  printf("%s, enter your guess: ", player->name);
  scanf("%lf", &guess);
  return guess;
}

// Function to check if the guess is correct
int check_guess(double guess, double answer) {
  double tolerance = 0.01;
  return fabs(guess - answer) < tolerance;
}

// Function to update the player's score
void update_score(player *player, int correct) {
  if (correct) {
    player->score++;
  }
}

// Function to print the game results
void print_results(player *players, int num_players) {
  printf("Game results:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s: %d points\n", players[i].name, players[i].score);
  }
}

// Main game function
void game() {
  // Initialize the players
  player players[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", players[i].name);
    players[i].score = 0;

    // Get the player's unit type
    char unit_string[MAX_NAME_LENGTH];
    printf("Enter %s's unit of measurement (inches, feet, yards, miles, kilometers): ", players[i].name);
    scanf("%s", unit_string);
    players[i].unit = get_unit_type(unit_string);
  }

  // Generate a random conversion problem
  unit_type from = rand() % MAX_UNIT_TYPES;
  unit_type to = rand() % MAX_UNIT_TYPES;
  double value = rand() % 100;
  double answer = convert(value, from, to);

  // Get the players' guesses
  double guesses[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    guesses[i] = get_guess(&players[i]);
  }

  // Check the players' guesses
  int correct[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    correct[i] = check_guess(guesses[i], answer);
  }

  // Update the players' scores
  for (int i = 0; i < MAX_PLAYERS; i++) {
    update_score(&players[i], correct[i]);
  }

  // Print the game results
  print_results(players, MAX_PLAYERS);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  game();

  return 0;
}