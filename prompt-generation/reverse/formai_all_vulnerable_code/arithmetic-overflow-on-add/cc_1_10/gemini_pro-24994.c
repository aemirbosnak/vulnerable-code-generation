//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
// Lo and behold, a tale of star-crossed lovers,
// Their destinies intertwined in a cruel world.
// A greedy algorithm, our guide through this tragedy,
// Seeking solace in each other's embrace.

#include <stdio.h>

// The Montagues and Capulets, sworn enemies.
int montagues, capulets;

// A forbidden love, destined for heartbreak.
int romeo, juliet;

// The cruel world, where violence reigns supreme.
int fights;

// The greedy algorithm, seeking the least painful path.
int min_pain;

// Initialize the star-crossed lovers and their world.
void prologue() {
  printf("Enter the number of Montagues and Capulets: ");
  scanf("%d %d", &montagues, &capulets);
  printf("Enter Romeo and Juliet's indices: ");
  scanf("%d %d", &romeo, &juliet);
  fights = 0;
  min_pain = montagues + capulets;
}

// The greedy algorithm, seeking to minimize pain.
void greedy() {
  while (montagues > 0 && capulets > 0) {
    if (romeo < juliet) {
      fights++;
      montagues--;
      min_pain--;
    } else {
      fights++;
      capulets--;
      min_pain--;
    }
  }
}

// The tragic end, where love is vanquished by hate.
void epilogue() {
  printf("The lovers' fate: %d fights, %d pain.\n", fights, min_pain);
  printf("Love's labor's lost, a world consumed by strife.\n");
}

int main() {
  prologue();
  greedy();
  epilogue();
  return 0;
}