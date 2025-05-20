//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generate_card(int card[5][5]);
void print_card(int card[5][5]);
int check_line(int card[5][5], int line);
int check_diagonal(int card[5][5]);
int check_win(int card[5][5]);
int main() {
  srand(time(NULL));
  int card[5][5];
  generate_card(card);
  print_card(card);
  int player_choice;
  int win = 0;
  while (!win) {
    printf("Enter your choice (1-%d): ", 25);
    scanf("%d", &player_choice);
    if (player_choice >= 1 && player_choice <= 25) {
      if (card[player_choice / 5][player_choice % 5] == 0) {
        card[player_choice / 5][player_choice % 5] = 1;
        win = check_win(card);
      } else {
        printf("Invalid move. Try again.\n");
      }
    } else {
      printf("Invalid choice. Try again.\n");
    }
  }
  if (win) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Sorry, you lost.\n");
  }
  return 0;
}

void generate_card(int card[5][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      card[i][j] = rand() % 2;
    }
  }
}

void print_card(int card[5][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (card[i][j] == 0) {
        printf("_ ");
      } else {
        printf("%d ", card[i][j]);
      }
    }
    printf("\n");
  }
}

int check_line(int card[5][5], int line) {
  for (int i = 0; i < 5; i++) {
    if (card[i][line] == 0) {
      return 0;
    }
  }
  return 1;
}

int check_diagonal(int card[5][5]) {
  return (check_line(card, 0) || check_line(card, 4));
}

int check_win(int card[5][5]) {
  for (int i = 0; i < 5; i++) {
    if (check_line(card, i)) {
      return 1;
    }
  }
  if (check_diagonal(card)) {
    return 1;
  }
  return 0;
}