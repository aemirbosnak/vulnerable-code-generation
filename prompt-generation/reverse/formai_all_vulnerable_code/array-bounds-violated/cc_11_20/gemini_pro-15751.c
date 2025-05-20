//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function is a labyrinth of code, enigmatic and full of twists.
int main(int argc, char *argv[]) {
  // A cryptic message awaits the curious explorer.
  char *enigma = "Follow the path, uncover the truth, and thou shalt find the key.";

  // A map, or perhaps a decoy, is revealed.
  int grid[5][5] = {
    {1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1}
  };

  // A riddle, a test of wit.
  int key = -1;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (grid[i][j] == 1) {
        key++;
      }
    }
  }

  // The path is treacherous, a maze of logic.
  char path[key + 1];
  int x = 0, y = 0, steps = 0;
  while (steps < key) {
    if (grid[x][y] == 1 && path[steps] == '\0') {
      path[steps] = 'R';
      y++;
      steps++;
    } else if (grid[x][y] == 1 && path[steps - 1] != 'L') {
      path[steps] = 'D';
      x++;
      steps++;
    } else if (grid[x][y] == 0 && path[steps - 1] == 'R') {
      path[steps] = 'L';
      y--;
      steps++;
    } else if (grid[x][y] == 0 && path[steps - 1] == 'D') {
      path[steps] = 'U';
      x--;
      steps++;
    }
  }

  // The key, a symbol of knowledge unlocked.
  printf("The key: '%s'\n", path);

  // A final twist, an enigmatic farewell.
  printf("May the mysteries of code forever intrigue thee.\n");
  return EXIT_SUCCESS;
}