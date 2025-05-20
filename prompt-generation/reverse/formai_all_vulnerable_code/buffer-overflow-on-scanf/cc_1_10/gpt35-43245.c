//FormAI DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4
#define MAX_LENGTH 15

char table[NUM_ROWS][NUM_COLS][MAX_LENGTH];
int player_turn = 1;

void initialize_table() {
  int i, j;

  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      strcpy(table[i][j], "      ");
    }
  }
}

void print_table() {
  int i, j;

  printf("\n\n\n");

  for (i = 0; i < NUM_ROWS; i++) {
    printf("   |");
    for (j = 0; j < NUM_COLS; j++) {
      printf(" %s |", table[i][j]);
    }
    printf("\n");
  }

  printf("\n\n\n");
}

int is_valid_input(int row, int col) {
  if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
    return 1;
  }
  return 0;
}

int is_empty_cell(int row, int col) {
  if (strcmp(table[row][col], "      ") == 0) {
    return 1;
  }
  return 0;
}

void place_marker(int row, int col, char marker[]) {
  strcpy(table[row][col], marker);
}

void get_input(int *row, int *col) {
  printf("Player %d's turn. Enter coordinates (row col): ", player_turn);
  scanf("%d %d", row, col);
}

int check_winner(char marker[]) {
  int i, j;
  
  for (i = 0; i < NUM_ROWS; i++) {
    if (strcmp(table[i][0], marker) == 0 && strcmp(table[i][1], marker) == 0 && strcmp(table[i][2], marker) == 0 && strcmp(table[i][3], marker) == 0) {
      return 1;
    }
  }
  
  for (j = 0; j < NUM_COLS; j++) {
    if (strcmp(table[0][j], marker) == 0 && strcmp(table[1][j], marker) == 0 && strcmp(table[2][j], marker) == 0 && strcmp(table[3][j], marker) == 0) {
      return 1;
    }
  }
  
  if (strcmp(table[0][0], marker) == 0 && strcmp(table[1][1], marker) == 0 && strcmp(table[2][2], marker) == 0 && strcmp(table[3][3], marker) == 0) {
    return 1;
  }
  
  if (strcmp(table[0][3], marker) == 0 && strcmp(table[1][2], marker) == 0 && strcmp(table[2][1], marker) == 0 && strcmp(table[3][0], marker) == 0) {
    return 1;
  }
  
  return 0;
}

int main() {
  srand(time(NULL));
  int row, col, i, j;
  char player1_marker[MAX_LENGTH], player2_marker[MAX_LENGTH];
  
  printf("Welcome to CyberTicTacToe! The ultimate table game in cyberpunk style!\n");

  printf("\n\nPlayer 1, choose your marker (one word only): ");
  scanf("%s", player1_marker);

  printf("\n\nPlayer 2, choose your marker (one word only): ");
  scanf("%s", player2_marker);

  initialize_table();

  while (1) {
    print_table();

    if (player_turn == 1) {
      get_input(&row, &col);
      while (!is_valid_input(row, col) || !is_empty_cell(row, col)) {
        printf("Invalid input or cell already taken. Please try again.\n");
        get_input(&row, &col);
      }
      place_marker(row, col, player1_marker);
      
      if (check_winner(player1_marker)) {
        print_table();
        printf("Player 1 wins the game!\n");
        break;
      }
      
      player_turn = 2;
    } else {
      row = rand() % NUM_ROWS;
      col = rand() % NUM_COLS;
      while (!is_empty_cell(row, col)) {
        row = rand() % NUM_ROWS;
        col = rand() % NUM_COLS;
      }
      place_marker(row, col, player2_marker);
      
      if (check_winner(player2_marker)) {
        print_table();
        printf("Player 2 wins the game!\n");
        break;
      }
      
      player_turn = 1;
    }
  }

  return 0;
}