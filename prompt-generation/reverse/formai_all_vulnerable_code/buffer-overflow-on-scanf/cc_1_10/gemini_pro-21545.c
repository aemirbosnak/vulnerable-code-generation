//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_FORTUNES 100

typedef struct {
  char name[32];
  int fortune_index;
} player_t;

typedef struct {
  char fortune[256];
} fortune_t;

// Function to get a random number between min and max
int get_random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to initialize the players
void initialize_players(player_t players[], int num_players) {
  for (int i = 0; i < num_players; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", players[i].name);
    players[i].fortune_index = -1;
  }
}

// Function to initialize the fortunes
void initialize_fortunes(fortune_t fortunes[], int num_fortunes) {
  for (int i = 0; i < num_fortunes; i++) {
    printf("Enter fortune %d: ", i + 1);
    scanf(" %[^\n]%*c", fortunes[i].fortune);
  }
}

// Function to get a random fortune for a player
char *get_random_fortune(fortune_t fortunes[], int num_fortunes) {
  int index = get_random_number(0, num_fortunes - 1);
  return fortunes[index].fortune;
}

// Function to play the game
void play_game(player_t players[], int num_players, fortune_t fortunes[], int num_fortunes) {
  while (1) {
    // Get the player's name
    char name[32];
    printf("Enter your name: ");
    scanf("%s", name);

    // Find the player's index
    int index = -1;
    for (int i = 0; i < num_players; i++) {
      if (strcmp(name, players[i].name) == 0) {
        index = i;
        break;
      }
    }

    // If the player is not found, create a new player
    if (index == -1) {
      printf("Player not found. Creating a new player...\n");
      strcpy(players[num_players].name, name);
      players[num_players].fortune_index = -1;
      num_players++;
    }

    // Get a random fortune for the player
    char *fortune = get_random_fortune(fortunes, num_fortunes);

    // Print the fortune
    printf("Your fortune is: %s\n", fortune);

    // Ask the player if they want to play again
    char answer;
    printf("Do you want to play again? (y/n) ");
    scanf(" %c", &answer);

    // If the player does not want to play again, break out of the loop
    if (answer == 'n') {
      break;
    }
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the players
  player_t players[MAX_PLAYERS];
  int num_players = 0;
  initialize_players(players, MAX_PLAYERS);

  // Initialize the fortunes
  fortune_t fortunes[MAX_FORTUNES];
  int num_fortunes = 0;
  initialize_fortunes(fortunes, MAX_FORTUNES);

  // Play the game
  play_game(players, num_players, fortunes, num_fortunes);

  return 0;
}