//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <ctype.h>

int main() {
  printf("Welcome to Text Converter\n");
  printf("Enter a string: ");

  char input[100];
  fgets(input, sizeof(input), stdin);

  printf("\nSelect an operation:\n");
  printf("1. Convert to UPPERCASE\n");
  printf("2. Convert to lowercase\n");
  printf("3. capitalize each word\n");

  int option;
  scanf("%d", &option);

  switch (option) {
    case 1:
      for (int i = 0; input[i] != '\0'; i++) {
        input[i] = toupper(input[i]);
      }
      printf("\nAfter converting to UPPERCASE: %s", input);
      break;

    case 2:
      for (int i = 0; input[i] != '\0'; i++) {
        input[i] = tolower(input[i]);
      }
      printf("\nAfter converting to lowercase: %s", input);
      break;

    case 3:
      for (int i = 0; input[i] != '\0'; i++) {
        if (i == 0 || input[i - 1] == ' ') {
          input[i] = toupper(input[i]);
        } else {
          input[i] = tolower(input[i]);
        }
      }
      printf("\nAfter capitalizing each word: %s", input);
      break;

    default:
      printf("\nInvalid option entered!");
  }

  return 0;
}