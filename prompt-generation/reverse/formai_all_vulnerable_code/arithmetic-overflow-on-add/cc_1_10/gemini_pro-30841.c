//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time jumps
#define MAX_JUMPS 10

// Define the maximum time interval for each jump
#define MAX_INTERVAL 1000

// Define the initial time
time_t initial_time;

// Define the current time
time_t current_time;

// Define the array of time jumps
time_t time_jumps[MAX_JUMPS];

// Initialize the time jumps array
void init_time_jumps() {
  for (int i = 0; i < MAX_JUMPS; i++) {
    time_jumps[i] = 0;
  }
}

// Generate a random time jump
time_t generate_time_jump() {
  return (rand() % MAX_INTERVAL) - (MAX_INTERVAL / 2);
}

// Apply a time jump to the current time
void apply_time_jump(time_t time_jump) {
  current_time += time_jump;
}

// Print the current time
void print_time() {
  printf("Current time: %s", ctime(&current_time));
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the initial time
  initial_time = time(NULL);

  // Initialize the current time
  current_time = initial_time;

  // Initialize the time jumps array
  init_time_jumps();

  // Generate a random number of time jumps
  int num_jumps = rand() % MAX_JUMPS;

  // Apply the time jumps
  for (int i = 0; i < num_jumps; i++) {
    time_jumps[i] = generate_time_jump();
    apply_time_jump(time_jumps[i]);
  }

  // Print the current time
  print_time();

  return 0;
}