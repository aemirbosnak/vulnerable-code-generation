//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
  char str1[MAX_LEN], str2[MAX_LEN];
  int i, j, len1, len2;

  printf("Enter string 1: ");
  fgets(str1, sizeof(str1), stdin);

  printf("Enter string 2: ");
  fgets(str2, sizeof(str2), stdin);

  // Remove new line characters from the input string
  len1 = strlen(str1);
  if (str1[len1-1] == '\n')
    str1[len1-1] = '\0';
  
  len2 = strlen(str2);
  if (str2[len2-1] == '\n')
    str2[len2-1] = '\0';

  // Concatenate the two strings
  for (i = 0; str1[i] != '\0'; i++);

  for (j = 0; str2[j] != '\0'; j++)
    str1[i++] = str2[j];

  str1[i] = '\0';
  
  printf("Concatenated string: %s\n", str1);

  // Reverse the concatenated string
  int l = strlen(str1);
  char temp;
  
  for (i = 0, j = l-1; i < j; i++, j--) {
    temp = str1[i];
    str1[i] = str1[j];
    str1[j] = temp;
  }

  printf("Reversed string: %s\n", str1);

  // Count the number of vowels in the reversed string
  int count = 0;
  for (i = 0; str1[i] != '\0'; i++) {
    if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u')
      count++;
  }

  printf("Number of vowels in the reversed string: %d\n", count);
  
  return 0;
}