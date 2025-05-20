//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>

int main() {
  printf("Hello there! I am grateful to present to you this unique pattern printing program!\n");
  printf("This program will print a diamond shape pattern using the characters 'C' and 'U'.\n");
  printf("Please enter the size of the pattern you wish to create (must be a positive odd number): ");
  
  int size, i, j, spaces, chars;
  scanf("%d", &size);
  
  printf("Excellent choice! Creating a diamond pattern of size %d...\n", size);
  
  if (size % 2 == 0) {
    printf("Oops! Size must be an odd number. Please try again with an odd number.\n");
    return 0;
  }
  
  spaces = size / 2;
  chars = 1;
  
  // Upper half of diamond
  for (i = 0; i < size / 2 + 1; i++) {
    for (j = 0; j < spaces; j++) {
      printf(" ");
    }
    
    for (j = 0; j < chars; j++) {
      if (j == 0 || j == chars - 1) {
        printf("C");
      } else {
        printf("U");
      }
    }
    
    printf("\n");
    spaces--;
    chars += 2;
  }
  
  spaces = 1;
  chars = size - 2;
  
  // Lower half of diamond
  for (i = 0; i < size / 2; i++) {
    for (j = 0; j < spaces; j++) {
      printf(" ");
    }
    
    for (j = 0; j < chars; j++) {
      if (j == 0 || j == chars - 1) {
        printf("C");
      } else {
        printf("U");
      }
    }
    
    printf("\n");
    spaces++;
    chars -= 2;
  }
  
  printf("There you have it! The beautiful diamond pattern made of C's and U's.\n");
  printf("Thank you for using this program, have a wonderful day! :)\n");

  return 0;
}