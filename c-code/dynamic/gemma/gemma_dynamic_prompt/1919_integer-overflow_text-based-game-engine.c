#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int score = 0;
  int level = 1;

  // Loop until the user wins or loses
  while (score < 100 && score > -1) {
    // Calculate the next level
    int next_level = level * 2 + 5;

    // Overflow the integer
    next_level = next_level * next_level;

    // Update the score and level
    score += next_level;
    level++;
  }

  // Display the final score
  printf("Your final score is: %d", score);

  return 0;
}
