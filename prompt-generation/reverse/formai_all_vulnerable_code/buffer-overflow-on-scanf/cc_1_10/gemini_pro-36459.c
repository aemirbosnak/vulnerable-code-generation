//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS (GRID_SIZE * GRID_SIZE) / 2
#define FLIP_COST 1
#define MATCH_REWARD 10

typedef struct {
  int id;
  char symbol;
  int revealed;
} card;

card grid[GRID_SIZE][GRID_SIZE];
int pairs_remaining;
int score;

void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j].revealed) {
        printf(" %c ", grid[i][j].symbol);
      } else {
        printf(" # ");
      }
    }
    printf("\n");
  }
}

void reveal_card(int x, int y) {
  if (!grid[x][y].revealed) {
    grid[x][y].revealed = 1;
    score -= FLIP_COST;
  }
}

int check_for_match(int x1, int y1, int x2, int y2) {
  if (grid[x1][y1].id == grid[x2][y2].id) {
    score += MATCH_REWARD;
    return 1;
  } else {
    return 0;
  }
}

void play_game() {
  int x1, y1, x2, y2;
  pairs_remaining = NUM_PAIRS;
  score = 0;

  while (pairs_remaining > 0) {
    printf("Score: %d\n", score);
    print_grid();
    printf("Enter the coordinates of two cards to flip (e.g. \"1 2 3 4\"): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 < 0 || x1 >= GRID_SIZE || y1 < 0 || y1 >= GRID_SIZE ||
        x2 < 0 || x2 >= GRID_SIZE || y2 < 0 || y2 >= GRID_SIZE) {
      printf("Invalid coordinates. Please enter again.\n");
    } else {
      reveal_card(x1, y1);
      reveal_card(x2, y2);
      int match = check_for_match(x1, y1, x2, y2);
      if (match) {
        pairs_remaining--;
      } else {
        printf("No match. Try again.\n");
      }
    }
  }

  printf("Congratulations! You found all the pairs.\n");
  printf("Your final score is: %d\n", score);
}

int main() {
  srand(time(NULL));

  // Initialize the grid with pairs of cards
  int id = 1;
  for (int i = 0; i < GRID_SIZE / 2; i++) {
    for (int j = 0; j < 2; j++) {
      grid[i][j].id = id;
      grid[i][j].symbol = 'A' + i;
      grid[i][j].revealed = 0;
    }
    id++;
  }

  // Shuffle the cards
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      int rand_i = rand() % GRID_SIZE;
      int rand_j = rand() % GRID_SIZE;
      card temp = grid[i][j];
      grid[i][j] = grid[rand_i][rand_j];
      grid[rand_i][rand_j] = temp;
    }
  }

  play_game();

  return 0;
}