//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

int main() {
  int length;
  printf("Enter the length of the pattern: ");
  scanf("%d", &length);

  // Print the first half of the pattern
  for(int i=0; i<length/2; i++) {
    // Print leading spaces
    for(int j=0; j<i; j++) {
      printf(" ");
    }

    // Print stars
    for(int k=0; k<(length - 2*i); k++) {
      printf("*");
    }

    // Print trailing spaces
    for(int j=0; j<i; j++) {
      printf(" ");
    }

    printf("\n");
  }

  // Print the middle line of the pattern
  for(int i=0; i<length/2; i++) {
    printf(" ");
  }
  printf("*\n");

  // Print the second half of the pattern
  for(int i=length/2; i>0; i--) {
    // Print leading spaces
    for(int j=0; j<i-1; j++) {
      printf(" ");
    }

    // Print stars
    for(int k=0; k<(length - 2*(i-1)); k++) {
      printf("*");
    }

    // Print trailing spaces
    for(int j=0; j<i-1; j++) {
      printf(" ");
    }

    printf("\n");
  }

  return 0;
}