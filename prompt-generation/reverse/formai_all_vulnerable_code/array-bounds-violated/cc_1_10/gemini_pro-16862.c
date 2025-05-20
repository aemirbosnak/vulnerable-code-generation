//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
  char name[20];
  int score;
  int time_left;
} player;

typedef struct {
  char word[MAX_WORD_LENGTH];
} word;

char *words[MAX_WORDS];
int num_words;

void load_words() {
  FILE *fp = fopen("words.txt", "r");
  if (fp == NULL) {
    perror("Error opening words.txt");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    line[strlen(line) - 1] = '\0';  // Remove newline character
    words[num_words++] = strdup(line);
  }

  fclose(fp);
}

void free_words() {
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
}

int main() {
  // Load the words from the file
  load_words();

  // Initialize the players
  player players[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    strcpy(players[i].name, "");
    players[i].score = 0;
    players[i].time_left = 60;
  }

  // Initialize the game state
  int current_player = 0;
  int round = 1;
  char current_word[MAX_WORD_LENGTH];

  // Main game loop
  while (1) {
    // Get the current word
    strcpy(current_word, words[rand() % num_words]);

    // Display the current word to the players
    printf("Round %d: %s\n", round, current_word);

    // Get the players' guesses
    for (int i = 0; i < MAX_PLAYERS; i++) {
      printf("%s, enter your guess: ", players[i].name);
      scanf("%s", players[i].name);

      // Check if the player's guess is correct
      if (strcmp(players[i].name, current_word) == 0) {
        players[i].score++;
        printf("%s guessed correctly!\n", players[i].name);
      } else {
        printf("%s guessed incorrectly.\n", players[i].name);
      }
    }

    // Update the game state
    current_player++;
    if (current_player == MAX_PLAYERS) {
      current_player = 0;
      round++;
    }

    // Check if any players have run out of time
    for (int i = 0; i < MAX_PLAYERS; i++) {
      if (players[i].time_left == 0) {
        printf("%s has run out of time!\n", players[i].name);
        players[i].score = 0;
      }
    }

    // Check if the game is over
    if (round == 10) {
      break;
    }
  }

  // Display the final scores
  printf("Final scores:\n");
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("%s: %d\n", players[i].name, players[i].score);
  }

  // Free the words
  free_words();

  return 0;
}