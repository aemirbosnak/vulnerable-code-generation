//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a peace sign (☮️)
void print_peace_sign(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("☮️");
    }
    printf("\n");
  }
}

// Function to print a heart (❤️)
void print_heart(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("❤️");
    }
    printf("\n");
  }
}

// Function to print a smiley face (😊)
void print_smiley(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("😊");
    }
    printf("\n");
  }
}

// Function to print a rainbow (🌈)
void print_rainbow(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("🌈");
    }
    printf("\n");
  }
}

int main() {
  int size;
  printf("Enter the size of the symbol: ");
  scanf("%d", &size);

  // Call the function to print the peace sign
  print_peace_sign(size);

  // Call the function to print the heart
  print_heart(size);

  // Call the function to print the smiley face
  print_smiley(size);

  // Call the function to print the rainbow
  print_rainbow(size);

  return 0;
}