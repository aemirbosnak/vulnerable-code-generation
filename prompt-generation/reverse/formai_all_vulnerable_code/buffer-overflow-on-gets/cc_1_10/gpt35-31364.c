//FormAI DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[30], str2[30], temp[30];
  
  //Prompt the user to input two strings
  printf("Enter a string: ");
  gets(str1);
  printf("Enter another string: ");
  gets(str2);

  //Calculate the length of both strings
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  //Print out the length of both strings to the user
  printf("\nThe length of string 1 is %d\n", len1);
  printf("The length of string 2 is %d\n", len2);

  //If the strings are not the same length, swap them
  if(len1 != len2) {
    printf("The strings are not the same length, so we will swap them.\n");
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
  }
  else {
    printf("The strings are already the same length, so we will not swap them.\n");
  }

  //Print out the modified strings to the user
  printf("\nString 1 is now: %s\n", str1);
  printf("String 2 is now: %s\n", str2);

  //Combine the two strings by alternating characters
  char combined[60];
  int i,j,k;
  for(i=0,j=0,k=0; str1[i] != '\0' && str2[j] != '\0'; i++,j++,k+=2) {
    combined[k] = str1[i];
    combined[k+1] = str2[j];
  }
  combined[k] = '\0';

  //Print out the combined string to the user
  printf("\nThe combined string is: %s\n", combined);

  //Find the first occurrence of a letter in the combined string
  char letter;
  printf("\nEnter a letter to search for in the combined string: ");
  scanf(" %c", &letter);
  int pos = -1;
  for(i=0; combined[i] != '\0'; i++) {
    if(combined[i] == letter) {
      pos = i;
      break;
    }
  }
  if(pos == -1) {
    printf("\nThe letter %c was not found in the combined string.\n", letter);
  }
  else {
    printf("\nThe letter %c was found at position %d in the combined string.\n", letter, pos);
  }

  return 0;
}