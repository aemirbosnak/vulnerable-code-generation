//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char str1[100], str2[100], temp[100];
  int i, j, choice;

  printf("Enter the first string: ");
  scanf("%s", str1);

  printf("Enter the second string: ");
  scanf("%s", str2);

  printf("\nPlease choose one of the following string manipulation options:");
  printf("\n1) Concatenate two strings");
  printf("\n2) Compare two strings");
  printf("\n3) Reverse a string");
  printf("\n4) Convert string to uppercase");
  printf("\n5) Convert string to lowercase\n");

  scanf("%d", &choice);

  switch(choice) {

    case 1: // Concatenate two strings
      strcat(str1, str2);
      printf("The concatenated string is: %s\n", str1);
      break;

    case 2: // Compare two strings
      if(strcmp(str1, str2) == 0)
        printf("The two strings are equal\n");
      else
        printf("The two strings are not equal\n");
      break;

    case 3: // Reverse a string
      j = strlen(str1) - 1;

      for(i = 0; i < j; i++, j--) {
        temp[i] = str1[j];
        temp[j] = str1[i];
      }

      printf("The reversed string is: %s\n", temp);
      break;

    case 4: // Convert string to uppercase
      for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z')
          str1[i] = str1[i] - 32;
      }

      printf("The uppercase string is: %s\n", str1);
      break;

    case 5: // Convert string to lowercase
      for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'A' && str1[i] <= 'Z')
          str1[i] = str1[i] + 32;
      }

      printf("The lowercase string is: %s\n", str1);
      break;

    default:
      printf("Invalid option selected");
  }

  return 0;
}