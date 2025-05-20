//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  printf("Welcome to the Text Processor 3000! \n");
  printf("Please enter some text: \n");

  char input[1000];
  fgets(input, 1000, stdin);

  printf("Thank you for your input! Here are some options: \n");
  printf("1. Convert text to uppercase\n");
  printf("2. Convert text to lowercase\n");
  printf("3. Count total characters\n");
  printf("4. Count vowels\n");
  printf("5. Count consonants\n");
  printf("6. Replace all vowels with 'oof'\n");

  int option;
  scanf("%d", &option);

  printf("\n");
  
  switch(option) {
    case 1:
      for(int i=0; i<strlen(input); i++) {
        printf("%c", toupper(input[i]));
      }
      printf("\n");
      break;
    case 2:
      for(int i=0; i<strlen(input); i++) {
        printf("%c", tolower(input[i]));
      }
      printf("\n");
      break;
    case 3:
      printf("Total characters: %d\n", strlen(input)-1);
      break;
    case 4:
      {
        int count=0;
        for(int i=0; i<strlen(input); i++) {
          if(toupper(input[i]) == 'A' || toupper(input[i]) == 'E' || toupper(input[i]) == 'I' || toupper(input[i]) == 'O' || toupper(input[i]) == 'U') {
            count++;
          }
        }
        printf("Number of vowels: %d\n", count);
        break;
      }
    case 5:
      {
        int count=0;
        for(int i=0; i<strlen(input); i++) {
          if(isalpha(input[i]) && toupper(input[i]) != 'A' && toupper(input[i]) != 'E' && toupper(input[i]) != 'I' && toupper(input[i]) != 'O' && toupper(input[i]) != 'U') {
            count++;
          }
        }
        printf("Number of consonants: %d\n", count);
        break;
      }
    case 6:
      for(int i=0; i<strlen(input); i++) {
        if(toupper(input[i]) == 'A' || toupper(input[i]) == 'E' || toupper(input[i]) == 'I' || toupper(input[i]) == 'O' || toupper(input[i]) == 'U') {
          printf("oof");
        } else {
          printf("%c", input[i]);
        }
      }
      printf("\n");
      break;
    default:
      printf("Invalid option selected. Please try again.\n");
      break;
  }

  printf("Thank you for using the Text Processor 3000! Goodbye! \n");

  return 0;
}