//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void fiboSeq (int terms) {
  int a = 0, b = 1, c, i;
  printf("%d %d ", a, b);

  for (i = 3; i <= terms; i++) {
    c = a + b;
    printf("%d ", c);
    a = b;
    b = c;
  }
}

void fiboVisual(int terms) {
  int a = 0, b = 1, c, i, j, k, d;
  
  for (i = 1; i <= terms; i++) {
    d = 0;
    c = a + b;
    a = b;
    b = c;
    for (j = 0; j < terms - i; j++) {
      printf(" ");
    }
    for (k = 0; k < i; k++) {
      printf("%d ", c - d);
      d = c - d;
      c = d + c;
    }
    printf("\n");
  }
}

int main() {
  int terms, choice;
  printf("Welcome to the Fibonacci Sequence Visualizer!\n");
  printf("Choose from the following:\n");
  printf("Option 1: Display the Fibonacci Sequence from 0 to n terms\n");
  printf("Option 2: Display the Fibonacci Sequence in a visual form\n");
  printf("Enter choice: ");
  scanf("%d", &choice);
  printf("Enter the number of terms you want to display: ");
  scanf("%d", &terms);
  
  switch(choice) {
    case 1:
      fiboSeq(terms);
      break;
    case 2:
      fiboVisual(terms);
      break;
    default:
      printf("Invalid choice. Please try again.");
      break;
  }
  
  return 0;
}