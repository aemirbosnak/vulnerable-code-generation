//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define bitwise operations
#define AND (1 << 0)
#define OR  (1 << 1)
#define XOR (1 << 2)

// Define input and output files
#define INPUT_FILE  "input.txt"
#define OUTPUT_FILE "output.txt"

// Declare global variables
int num1, num2, result;

// Function to read input from file
void readInput() {
  FILE *fp = fopen(INPUT_FILE, "r");
  if (fp == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }
  fscanf(fp, "%d %d", &num1, &num2);
  fclose(fp);
}

// Function to perform bitwise operations
void performBitwiseOperations() {
  result = num1 & num2;  // AND operation
  printf("AND operation: %d\n", result);
  result = num1 | num2;  // OR operation
  printf("OR operation: %d\n", result);
  result = num1 ^ num2;  // XOR operation
  printf("XOR operation: %d\n", result);
}

// Function to write output to file
void writeOutput() {
  FILE *fp = fopen(OUTPUT_FILE, "w");
  if (fp == NULL) {
    perror("Error opening output file");
    exit(EXIT_FAILURE);
  }
  fprintf(fp, "AND operation: %d\n", result);
  fprintf(fp, "OR operation: %d\n", result);
  fprintf(fp, "XOR operation: %d\n", result);
  fclose(fp);
}

// Main function
int main() {
  readInput();
  performBitwiseOperations();
  writeOutput();
  return 0;
}