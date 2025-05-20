//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main()
{
  char str1[50], str2[50], temp[50];
  int i, j;

  printf("Enter string 1: ");
  gets(str1);

  printf("Enter string 2: ");
  gets(str2);

  printf("\nStrings before swapping: \n");
  printf("String 1: %s\n", str1);
  printf("String 2: %s\n", str2);

  // Swapping the strings using temporary variable
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);

  printf("\nStrings after swapping: \n");
  printf("String 1: %s\n", str1);
  printf("String 2: %s\n", str2);

  // Finding the length of a string using strlen function
  printf("\nThe length of string 1 is: %d\n", strlen(str1));
  printf("The length of string 2 is: %d\n", strlen(str2));

  // Concatenating two strings using strcat function
  strcat(str1, str2);
  printf("\nAfter concatenating the strings, string 1 is : %s\n", str1);

  // Reversing a string
  printf("\nReversing string 1: ");
  for(i=strlen(str1)-1;i>=0;i--)
  {
    printf("%c", str1[i]);
  }

  // Counting the number of words in a string
  int count=1;
  printf("\nEnter a sentence: ");
  gets(str1);
  for(i=0;i<strlen(str1);i++)
  {
    if(str1[i]==' ' && str1[i+1]!=' ')
    {
      count++;
    }
  }
  printf("\nThe number of words in the sentence is: %d", count);

  return 0;
}