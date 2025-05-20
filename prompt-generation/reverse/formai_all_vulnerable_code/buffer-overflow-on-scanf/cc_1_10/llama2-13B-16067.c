//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to print a pattern of asterisks
void print_pattern(int num_rows, int num_cols) {
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if (i % 2 == 0 && j % 2 == 0) {
        printf(" * ");
      } else if (i % 2 == 0 && j % 2 == 1) {
        printf("* ");
      } else if (i % 2 == 1 && j % 2 == 0) {
        printf("* ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }
}

// Function to print a centered message
void print_message(char *message, int num_rows, int num_cols) {
  int message_len = strlen(message);
  int padding = (num_cols - message_len) / 2;

  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if (j < padding) {
        printf(" ");
      } else if (j >= padding && j < padding + message_len) {
        printf("%c", message[j - padding]);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  int num_rows, num_cols;

  printf("Enter the number of rows: ");
  scanf("%d", &num_rows);
  printf("Enter the number of columns: ");
  scanf("%d", &num_cols);

  // Print a pattern of asterisks
  print_pattern(num_rows, num_cols);

  // Print a centered message
  char message[] = "Hello, World!";
  print_message(message, num_rows, num_cols);

  return 0;
}