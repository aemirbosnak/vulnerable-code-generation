//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define MAX_WORD_LENGTH 10

typedef struct {
  char name[MAX_WORD_LENGTH];
  int score;
} Player;

typedef struct {
  char word[MAX_WORD_LENGTH];
  int points;
} Word;

void print_game_header() {
  printf("Welcome to the Table Game!\n");
  printf("---------------------------\n");
  printf("You will be given a set of words, and you must come up with a word that starts with the last letter of the previous word.\n");
  printf("The player with the highest score at the end of the game wins.\n");
  printf("Let's begin!\n");
}

void print_table(Player players[], int num_players) {
  printf("  Name   |  Score\n");
  printf("---------|----------\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s | %d\n", players[i].name, players[i].score);
  }
}

void print_words(Word words[], int num_words) {
  printf("Here are the words for this round:\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s\n", words[i].word);
  }
}

void play_game(Player players[], int num_players, Word words[], int num_words) {
  int current_player = 0;
  int current_word = 0;
  int round = 1;
  int points = 0;

  while (round <= MAX_ROUNDS) {
    print_table(players, num_players);
    printf("Round %d\n", round);
    print_words(words, num_words);

    points = 0;
    for (int i = 0; i < num_players; i++) {
      printf("Player %s, enter your word: ", players[i].name);
      char word[MAX_WORD_LENGTH];
      scanf("%s", word);

      if (strcmp(word, words[current_word].word) == 0) {
        points += words[current_word].points;
        players[i].score += points;
      }
    }

    current_player = (current_player + 1) % num_players;
    current_word = (current_word + 1) % num_words;
    round++;
  }
}

int main() {
  srand(time(NULL));

  Player players[MAX_PLAYERS] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"David", 0}
  };

  Word words[MAX_ROUNDS] = {
    {"apple", 10},
    {"banana", 20},
    {"orange", 30},
    {"grape", 40},
    {"strawberry", 50},
    {"peach", 60},
    {"watermelon", 70},
    {"pineapple", 80},
    {"kiwi", 90},
    {"mango", 100}
  };

  print_game_header();
  play_game(players, MAX_PLAYERS, words, MAX_ROUNDS);
  printf("\nGame Over!\n");
  print_table(players, MAX_PLAYERS);

  return 0;
}