//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>

int main() {
  printf("Welcome to my unique C compression program!\n");

  //Get user input
  char input[50];
  printf("Enter the string you would like to compress: ");
  fgets(input, 50, stdin);

  //Initialize variables
  int count = 0;
  char currChar = input[0];
  char compressed[50] = "";
  int compressedIndex = 0;

  //Iterate through string
  for (int i = 0; i < strlen(input); i++) {

    //If current character matches previous character, increment count
    if (input[i] == currChar) {
      count++;
    }

    //If current character is different from previous character, add compressed version to string and reset count
    else {
      sprintf(compressed+compressedIndex, "%c%d", currChar, count);
      compressedIndex += 2;
      currChar = input[i];
      count = 1;
    }
  }

  //Add final compressed version to string
  sprintf(compressed+compressedIndex, "%c%d", currChar, count);
  compressedIndex += 2;

  //Print compressed version of string
  printf("Compressed version: %s\n", compressed);

  //Bonus feature: decompressing the string
  printf("Would you like to decompress the string? (y/n) ");
  char answer;
  scanf("%c", &answer);

  if (answer == 'y') {
    printf("Decompressed version: ");
    int i = 0;
    while (i < strlen(compressed)) {
      currChar = compressed[i];
      i++;
      count = 0;
      while (compressed[i] >= '0' && compressed[i] <= '9') {
        count = count*10 + (compressed[i] - '0');
        i++;
      }
      for (int j = 0; j < count; j++) {
        printf("%c", currChar);
      }
    }
    printf("\n");
  }

  printf("Thank you for using my compression program!\n");

  return 0;
}