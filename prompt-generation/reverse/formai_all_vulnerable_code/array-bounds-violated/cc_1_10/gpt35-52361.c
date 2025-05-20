//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];
  
  printf("Enter a string: ");
  fgets(str1, 100, stdin);
  
  printf("Enter another string: ");
  fgets(str2, 100, stdin);
  
  int len1 = strlen(str1);
  // Removing the newline character at the end of str1
  if (str1[len1-1] == '\n') {
    str1[len1-1] = '\0';
  }
  
  int len2 = strlen(str2);
  // Removing the newline character at the end of str2
  if (str2[len2-1] == '\n') {
    str2[len2-1] = '\0';
  }
  
  // Concatenating str1 and str2
  strcat(str1, str2);
  
  printf("\nConcatenated string: %s\n", str1);
  
  // Reversing the concatenated string
  char temp;
  int i = 0;
  int j = strlen(str1) - 1;
  while (i < j) {
    temp = str1[i];
    str1[i] = str1[j];
    str1[j] = temp;
    i++;
    j--;
  }
  
  printf("\nReversed string: %s\n", str1);
  
  // Finding the length of the reversed string
  int len_reversed = strlen(str1);
  
  printf("\nLength of reversed string: %d\n", len_reversed);
  
  // Converting the reversed string to uppercase
  for (int k = 0; k < len_reversed; k++) {
    if (str1[k] >= 'a' && str1[k] <= 'z') {
      str1[k] -= 32;
    }
  }
  
  printf("\nUppercase string: %s\n", str1);
  
  return 0;
}