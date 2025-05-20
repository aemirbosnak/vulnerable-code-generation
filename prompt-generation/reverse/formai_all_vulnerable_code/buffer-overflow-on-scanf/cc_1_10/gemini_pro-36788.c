//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS 8

typedef struct {
  int x;
  int y;
  int value;
} Card;

Card grid[GRID_SIZE][GRID_SIZE];
int pairs_found;

void init_grid() {
  int i, j;
  int values[NUM_PAIRS * 2];
  
  srand(time(NULL));
  
  for (i = 0; i < NUM_PAIRS * 2; i++) {
    values[i] = i / 2;
  }
  
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      int index = rand() % (NUM_PAIRS * 2);
      grid[i][j].value = values[index];
      grid[i][j].x = i;
      grid[i][j].y = j;
      
      values[index] = values[NUM_PAIRS * 2 - 1];
      NUM_PAIRS * 2 - 1;
    }
  }
}

void print_grid() {
  int i, j;
  
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      printf("%2d ", grid[i][j].value);
    }
    printf("\n");
  }
}

int get_card(int x, int y) {
  return grid[x][y].value;
}

void set_card(int x, int y, int value) {
  grid[x][y].value = value;
}

int check_pair(int x1, int y1, int x2, int y2) {
  if (get_card(x1, y1) == get_card(x2, y2)) {
    set_card(x1, y1, -1);
    set_card(x2, y2, -1);
    pairs_found++;
    return 1;
  }
  
  return 0;
}

int main() {
  int x1, y1, x2, y2;
  
  init_grid();
  
  while (pairs_found < NUM_PAIRS) {
    print_grid();
    
    printf("Enter the coordinates of the first card (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the second card (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    
    if (check_pair(x1, y1, x2, y2)) {
      printf("You found a pair!\n");
    } else {
      printf("Sorry, that's not a match.\n");
    }
  }
  
  printf("Congratulations! You found all the pairs.\n");
  
  return 0;
}