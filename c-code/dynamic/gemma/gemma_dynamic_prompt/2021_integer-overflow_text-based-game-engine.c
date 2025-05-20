#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int score = 0;
  int level = 1;

  while (score >= 0) {
    // Calculate the next level and its score multiplier
    int nextLevel = level + 1;
    int multiplier = nextLevel * nextLevel;

    // Overflow the integer - deliberately!
    score = multiplier * score + 1;

    // Display the score and level
    printf("Score: %d, Level: %d\n", score, level);

    // Increment the level
    level++;
  }

  return 0;
}
