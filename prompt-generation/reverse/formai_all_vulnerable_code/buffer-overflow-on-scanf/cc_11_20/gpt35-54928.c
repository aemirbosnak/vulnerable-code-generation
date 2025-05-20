//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int choice;
  printf("Welcome to the peaceful C String manipulation program!\n");
  printf("Please input a string:\n");
  fgets(input, 100, stdin);
  printf("\nYour inputted string is:\n%s\n", input);

  printf("\nPlease select one of the following operations:\n");
  printf("1. Convert to all uppercase letters.\n");
  printf("2. Convert to all lowercase letters.\n");
  printf("3. Reverse the string.\n");
  printf("4. Remove all whitespace characters.\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1: {
      for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
          input[i] = input[i] - 32;
        }
      }
      printf("\nThe string in all uppercase letters is:\n%s", input);
      break;
    }

    case 2: {
      for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
          input[i] = input[i] + 32;
        }
      }
      printf("\nThe string in all lowercase letters is:\n%s", input);
      break;
    }

    case 3: {
      int length = strlen(input);
      for(int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
      }
      printf("\nThe reversed string is:\n%s", input);
      break;
    }

    case 4: {
      for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
          for(int j = i; input[j] != '\0'; j++) {
            input[j] = input[j + 1];
          }
        i--;
        }
      }
      printf("\nThe string without whitespace characters is:\n%s", input);
      break;
    }

    default: 
      printf("\nInvalid choice! Exiting program.\n");
      break;
  }
  return 0;
}