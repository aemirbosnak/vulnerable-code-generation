//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: imaginative
// Welcome to the enchanted realm of Matrixia, where numbers dance and transformations unfold.

#include <stdio.h>
#include <stdlib.h>

// Declare our magical matrices, each a portal to a realm of numbers.
int matrixA[10][10], matrixB[10][10], matrixC[10][10];

// Set the dimensions of our magical portals.
int rows, columns;

// Summon the user, the master of these realms, to define our matrices.
void summonUserMatrices() {
  printf("Oh, wise and powerful user, enter the dimensions of your matrices.\n");
  printf("Rows: ");
  scanf("%d", &rows);
  printf("Columns: ");
  scanf("%d", &columns);

  // Fill matrixA with numbers that shimmer like stars.
  printf("Fill the first matrix, matrixA, with your cosmic numbers:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      scanf("%d", &matrixA[i][j]);
    }
  }

  // Fill matrixB with numbers that dance like fireflies.
  printf("Now, summon the second matrix, matrixB, with its enchanting numbers:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      scanf("%d", &matrixB[i][j]);
    }
  }
}

// Perform matrix addition, a union of two realms.
void addMatrices() {
  printf("\nBehold, the mystical sum of matrixA and matrixB:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }
}

// Perform matrix subtraction, a battle of two realms.
void subtractMatrices() {
  printf("\nWitness the epic battle of matrixA and matrixB:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }
}

// Perform matrix multiplication, a dance of numbers.
void multiplyMatrices() {
  printf("\nNow, watch the enchanting dance of matrixA and matrixB:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrixC[i][j] = 0;
      for (int k = 0; k < columns; k++) {
        matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
      }
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }
}

// The main portal, where the user enters Matrixia.
int main() {
  printf("Greetings, traveler! Welcome to the mystical realm of Matrixia.\n");

  summonUserMatrices();

  addMatrices();
  subtractMatrices();
  multiplyMatrices();

  return 0;
}