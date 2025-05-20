//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Maze dimensions
#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// Maze data
int maze[MAZE_WIDTH][MAZE_HEIGHT] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Player positions
int player_x[2];
int player_y[2];

// Player scores
int player_scores[2];

// Mutex to protect shared data
pthread_mutex_t mutex;

// Thread function for each player
void *player_thread(void *arg) {
  int player_id = (int)arg;

  // Initialize player position
  player_x[player_id] = 1;
  player_y[player_id] = 1;

  // Main game loop
  while (1) {
    // Get player input
    char input;
    scanf(" %c", &input);

    // Update player position based on input
    switch (input) {
      case 'w':
        if (maze[player_x[player_id]][player_y[player_id] - 1] == 0) {
          player_y[player_id]--;
        }
        break;
      case 's':
        if (maze[player_x[player_id]][player_y[player_id] + 1] == 0) {
          player_y[player_id]++;
        }
        break;
      case 'a':
        if (maze[player_x[player_id] - 1][player_y[player_id]] == 0) {
          player_x[player_id]--;
        }
        break;
      case 'd':
        if (maze[player_x[player_id] + 1][player_y[player_id]] == 0) {
          player_x[player_id]++;
        }
        break;
    }

    // Check if the player has reached the exit
    if (player_x[player_id] == MAZE_WIDTH - 2 && player_y[player_id] == MAZE_HEIGHT - 2) {
      // Lock the mutex to protect shared data
      pthread_mutex_lock(&mutex);

      // Increment the player's score
      player_scores[player_id]++;

      // Unlock the mutex
      pthread_mutex_unlock(&mutex);

      printf("Player %d wins!\n", player_id + 1);
      return NULL;
    }

    // Print the maze with the players' positions
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAZE_HEIGHT; i++) {
      for (int j = 0; j < MAZE_WIDTH; j++) {
        if (player_x[0] == j && player_y[0] == i) {
          printf("1");
        } else if (player_x[1] == j && player_y[1] == i) {
          printf("2");
        } else if (maze[j][i] == 1) {
          printf("#");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
    printf("Player 1 score: %d\n", player_scores[0]);
    printf("Player 2 score: %d\n", player_scores[1]);
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

int main() {
  // Initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // Create the player threads
  pthread_t player_threads[2];
  pthread_create(&player_threads[0], NULL, player_thread, (void *)0);
  pthread_create(&player_threads[1], NULL, player_thread, (void *)1);

  // Wait for the player threads to finish
  pthread_join(player_threads[0], NULL);
  pthread_join(player_threads[1], NULL);

  // Destroy the mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}