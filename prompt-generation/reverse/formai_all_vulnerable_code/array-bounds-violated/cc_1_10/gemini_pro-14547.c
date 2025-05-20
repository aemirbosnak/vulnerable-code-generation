//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_NUMS 75

// Bingo card
int bingo[BINGO_SIZE][BINGO_SIZE];

// Drawn numbers
int drawn[BINGO_NUMS];

// Create a new bingo card
void create_bingo_card() {
  int i, j, num;
  
  // Clear the bingo card
  for (i = 0; i < BINGO_SIZE; i++) {
    for (j = 0; j < BINGO_SIZE; j++) {
      bingo[i][j] = 0;
    }
  }
  
  // Draw numbers for the bingo card
  for (i = 0; i < BINGO_SIZE; i++) {
    for (j = 0; j < BINGO_SIZE; j++) {
      do {
        num = rand() % BINGO_NUMS + 1;
      } while (bingo[i][j] != 0 && drawn[num] != 0);
      
      bingo[i][j] = num;
      drawn[num] = 1;
    }
  }
}

// Print the bingo card
void print_bingo_card() {
  int i, j;
  
  printf("Your bingo card:\n");
  for (i = 0; i < BINGO_SIZE; i++) {
    for (j = 0; j < BINGO_SIZE; j++) {
      printf("%2d ", bingo[i][j]);
    }
    printf("\n");
  }
}

// Draw a number
int draw_number() {
  int num;
  
  do {
    num = rand() % BINGO_NUMS + 1;
  } while (drawn[num] != 0);
  
  drawn[num] = 1;
  
  return num;
}

// Check if a number is on the bingo card
int check_number(int num) {
  int i, j;
  
  for (i = 0; i < BINGO_SIZE; i++) {
    for (j = 0; j < BINGO_SIZE; j++) {
      if (bingo[i][j] == num) {
        return 1;
      }
    }
  }
  
  return 0;
}

// Check if the bingo card has a winning combination
int check_bingo() {
  int i, j, k, l;
  
  // Check rows
  for (i = 0; i < BINGO_SIZE; i++) {
    for (j = 0; j < BINGO_SIZE; j++) {
      if (bingo[i][j] == 0) {
        break;
      }
    }
    if (j == BINGO_SIZE) {
      return 1;
    }
  }
  
  // Check columns
  for (i = 0; i < BINGO_SIZE; i++) {
    for (j = 0; j < BINGO_SIZE; j++) {
      if (bingo[j][i] == 0) {
        break;
      }
    }
    if (j == BINGO_SIZE) {
      return 1;
    }
  }
  
  // Check diagonals
  for (i = 0; i < BINGO_SIZE; i++) {
    if (bingo[i][i] == 0) {
      break;
    }
  }
  if (i == BINGO_SIZE) {
    return 1;
  }
  
  for (i = 0, j = BINGO_SIZE - 1; i < BINGO_SIZE; i++, j--) {
    if (bingo[i][j] == 0) {
      break;
    }
  }
  if (i == BINGO_SIZE) {
    return 1;
  }
  
  return 0;
}

int main() {
  int num, drawn_num;
  
  // Initialize the random number generator
  srand(time(NULL));
  
  // Create a new bingo card
  create_bingo_card();
  
  // Print the bingo card
  print_bingo_card();
  
  // Start the game
  printf("Let's play bingo!\n");
  while (!check_bingo()) {
    // Draw a number
    drawn_num = draw_number();
    
    // Check if the number is on the bingo card
    if (check_number(drawn_num)) {
      printf("Your number is: %d\n", drawn_num);
    } else {
      printf("No match!\n");
    }
  }
  
  // Game over
  printf("Congratulations! You won!\n");
  
  return 0;
}