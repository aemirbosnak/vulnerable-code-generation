//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum length of a word
#define MAX_WORD_LENGTH 256

// Define the number of rounds to play
#define NUM_ROUNDS 10

// Define the thread structure
typedef struct {
  int id;
  char *name;
  int score;
} player_t;

// Define the game state structure
typedef struct {
  int round;
  int current_player;
  char *target_word;
} game_state_t;

// Define the mutex
pthread_mutex_t mutex;

// Define the condition variable
pthread_cond_t cond;

// Initialize the game state
game_state_t game_state = {
  .round = 1,
  .current_player = 0,
  .target_word = NULL,
};

// Initialize the players
player_t players[MAX_PLAYERS] = {
  {
    .id = 0,
    .name = "Player 1",
    .score = 0,
  },
  {
    .id = 1,
    .name = "Player 2",
    .score = 0,
  },
  {
    .id = 2,
    .name = "Player 3",
    .score = 0,
  },
  {
    .id = 3,
    .name = "Player 4",
    .score = 0,
  },
};

// Define the thread function
void *thread_func(void *arg) {
  // Get the player ID
  int id = *(int *)arg;

  // Get the player's name
  char *name = players[id].name;

  // Loop until the game is over
  while (game_state.round <= NUM_ROUNDS) {
    // Acquire the mutex
    pthread_mutex_lock(&mutex);

    // Wait until it is the player's turn
    while (game_state.current_player != id) {
      pthread_cond_wait(&cond, &mutex);
    }

    // Get the target word
    char *target_word = game_state.target_word;

    // Print the target word
    printf("Player %s, your target word is: %s\n", name, target_word);

    // Get the player's input
    char input[MAX_WORD_LENGTH];
    scanf("%s", input);

    // Check if the player's input matches the target word
    int correct = strcmp(input, target_word) == 0;

    // Increment the player's score if they got the correct answer
    if (correct) {
      players[id].score++;
    }

    // Print the player's score
    printf("Player %s, your score is: %d\n", name, players[id].score);

    // Increment the current player
    game_state.current_player++;

    // If all players have had a turn, reset the current player and increment the round
    if (game_state.current_player == MAX_PLAYERS) {
      game_state.current_player = 0;
      game_state.round++;
    }

    // Signal to the other threads that it is their turn
    pthread_cond_broadcast(&cond);

    // Release the mutex
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

int main() {
  // Initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // Initialize the condition variable
  pthread_cond_init(&cond, NULL);

  // Generate the target words
  char *target_words[] = {
    "apple",
    "banana",
    "cherry",
    "dog",
    "cat",
    "fish",
    "bird",
    "tree",
    "house",
    "car",
  };

  // Create the threads
  pthread_t threads[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    pthread_create(&threads[i], NULL, thread_func, &i);
  }

  // Wait for the threads to finish
  for (int i = 0; i < MAX_PLAYERS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex and condition variable
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  // Print the final scores
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("Player %s, your final score is: %d\n", players[i].name, players[i].score);
  }

  return 0;
}