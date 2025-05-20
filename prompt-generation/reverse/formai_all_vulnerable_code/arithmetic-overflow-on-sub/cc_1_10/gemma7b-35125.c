//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <time.h>

void main() {
  time_t t = time(NULL);
  printf("Current time: %ld seconds since the Epoch\n", t);

  // Travel back in time by 1 hour
  t -= 3600;

  printf("Time traveled back: %ld seconds since the Epoch\n", t);

  // Simulate activities from the past
  printf("In the past, you might have been... ");

  // Randomly generate an activity
  int activity = rand() % 3;

  switch (activity) {
    case 0:
      printf("Watching a movie.\n");
      break;
    case 1:
      printf("Reading a book.\n");
      break;
    case 2:
      printf("Playing games.\n");
      break;
  }

  // Travel forward in time by 1 hour
  t += 3600;

  printf("Time traveled forward: %ld seconds since the Epoch\n", t);

  // Simulate activities from the future
  printf("In the future, you might have been... ");

  // Randomly generate an activity
  activity = rand() % 3;

  switch (activity) {
    case 0:
      printf("Working on a project.\n");
      break;
    case 1:
      printf("Traveling the world.\n");
      break;
    case 2:
      printf("Celebrating a birthday.\n");
      break;
  }

  printf("End of time travel.\n");
}