//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100], str2[100], result[200];

  //Taking user input for string 1 and string 2
  printf("Enter the first string: ");
  scanf("%s", str1);
  printf("Enter the second string: ");
  scanf("%s", str2);

  //Concatenating the two strings
  strcat(result, str1);
  strcat(result, str2);

  printf("The concatenated string is: %s\n", result);

  //Checking if the two strings are equal
  if (strcmp(str1, str2) == 0)
    printf("The two strings are equal.\n");
  else
    printf("The two strings are not equal.\n");

  //Finding the length of the string
  int length = strlen(str1);
  printf("The length of the string is: %d\n", length);

  //Reversing the string
  char reversed[length];
  int i, j=0;
  for(i=length-1; i>=0; i--){
    reversed[j++] = str1[i];
  }
  reversed[j] = '\0';

  printf("The reversed string is: %s\n", reversed);

  //Finding the first occurrence of a character in the string
  char c;
  int index = 0;
  printf("Enter a character to find its index in the string: ");
  scanf(" %c", &c);
  char *ptr = strchr(str1, c);
  index = ptr - str1;
  if (ptr != NULL)
    printf("The index of the character '%c' in the string is: %d\n", c, index);
  else
    printf("The character '%c' is not found in the string.\n", c);

  return 0;
}