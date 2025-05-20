//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int num) {
  int a = 0, b = 1, c;
  printf("Fibonacci sequence up to %d terms:\n", num);
  printf("0 ");
  for(int i = 1; i < num; i++) {
    c = a + b;
    a = b;
    b = c;
    printf("%d ", c);
  }
}

// Function to visualize Fibonacci sequence
void visualizeFibonacci(int num) {
  system("clear"); // Clear console
  int a = 0, b = 1, c;
  printf("Fibonacci sequence up to %d terms:\n", num);
  printf("0 ");
  for(int i = 1; i < num; i++) {
    c = a + b;
    a = b;
    b = c;
    printf("%d ", c);
  }
}

// Main function
int main() {
  int choice, num;
  do {
    printf("\nEnter 1 to generate Fibonacci sequence\nEnter 2 to visualize Fibonacci sequence\nEnter 3 to exit\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter the number of terms: ");
        scanf("%d", &num);
        generateFibonacci(num);
        break;
      case 2:
        printf("Enter the number of terms: ");
        scanf("%d", &num);
        visualizeFibonacci(num);
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice! Please enter again.\n");
    }
  } while(choice!= 3);
  return 0;
}