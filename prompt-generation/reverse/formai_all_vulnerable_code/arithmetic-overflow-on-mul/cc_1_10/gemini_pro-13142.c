//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// These are not true time travel functions, but they simulate the idea.
void goToPast(int years) {
  time_t now = time(NULL);
  now -= years * 31556926;  // Convert years to seconds.
  char *dt = ctime(&now);
  printf("You traveled to the past: %s", dt);
}

void goToFuture(int years) {
  time_t now = time(NULL);
  now += years * 31556926;  // Convert years to seconds.
  char *dt = ctime(&now);
  printf("You traveled to the future: %s", dt);
}

// This function is used to check the user's paranoia level.
int checkParanoiaLevel() {
  int level = 0;
  printf("How paranoid are you? (0-10): ");
  scanf("%d", &level);
  return level;
}

int main() {
  // Set the paranoia level.
  int paranoiaLevel = checkParanoiaLevel();

  // Seed the random number generator with the paranoia level.
  srand(paranoiaLevel);

  // Generate a random year to travel to.
  int year = rand() % 10000;

  // Choose whether to travel to the past or the future.
  int direction = rand() % 2;

  // Perform the time travel.
  if (direction == 0) {
    goToPast(year);
  } else {
    goToFuture(year);
  }

  // Display a warning about the dangers of time travel.
  printf("Warning: Time travel is dangerous and can have unexpected consequences.\n");

  return 0;
}