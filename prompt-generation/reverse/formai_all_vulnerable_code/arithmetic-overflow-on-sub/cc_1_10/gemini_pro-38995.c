//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surprise! Let's type our way to a new high score!

// Constants to define the game parameters
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define TIME_LIMIT 60

// Global variables to track game state
int words_typed = 0;
char words[MAX_WORDS][MAX_WORD_LENGTH];
clock_t start_time;

// Function to generate a random word
void generate_word(char* word) {
  int length = rand() % MAX_WORD_LENGTH + 1;
  for (int i = 0; i < length; i++) {
    word[i] = 'a' + (rand() % 26);
  }
  word[length] = '\0';
}

// Function to start the timer
void start_timer() {
  start_time = clock();
}

// Function to stop the timer and calculate the typing speed
double stop_timer() {
  clock_t end_time = clock();
  double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
  return (double) words_typed / elapsed_time;
}

// Function to check if a word is correct
int check_word(char* word) {
  for (int i = 0; i < words_typed; i++) {
    if (strcmp(word, words[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to print the game instructions
void print_instructions() {
  printf("Type as many words as you can in %d seconds!\n", TIME_LIMIT);
  printf("Press Enter to start.\n");
}

// Function to get a word from the user
void get_word(char* word) {
  scanf("%s", word);
}

// Function to play the game
void play_game() {
  // Print the instructions
  print_instructions();

  // Start the timer
  start_timer();

  // Loop until the time limit is reached
  while (clock() - start_time < TIME_LIMIT * CLOCKS_PER_SEC) {
    // Get a word from the user
    get_word(words[words_typed]);

    // Check if the word is correct
    if (check_word(words[words_typed])) {
      // If the word is correct, increment the word count
      words_typed++;
    }
  }

  // Stop the timer and calculate the typing speed
  double typing_speed = stop_timer();

  // Print the results
  printf("You typed %d words in %d seconds.\n", words_typed, TIME_LIMIT);
  printf("Your typing speed is %.2f words per minute.\n", typing_speed * 60);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}