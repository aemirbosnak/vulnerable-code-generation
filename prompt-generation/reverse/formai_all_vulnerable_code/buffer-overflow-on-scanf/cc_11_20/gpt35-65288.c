//FormAI DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
  char str1[20], str2[20];
  int len1, len2;

  printf("Enter first string: ");
  scanf("%s", str1);

  printf("Enter second string: ");
  scanf("%s", str2);

  // Calculate lengths of the strings
  len1 = strlen(str1);
  len2 = strlen(str2);

  // Concatenate the strings
  strcat(str1, str2);

  // Reverse the concatenated string
  int i, j;
  char temp;
  for(i = 0, j = len1+len2-1; i < j; i++, j--) {
    temp = str1[i];
    str1[i] = str1[j];
    str1[j] = temp;
  }

  // Convert all uppercase alphabets to lowercase and vice versa
  for(i = 0; str1[i]; i++) {
    if(str1[i] >= 'A' && str1[i] <= 'Z') {
      str1[i] += ('a' - 'A');
    } else if(str1[i] >= 'a' && str1[i] <= 'z') {
      str1[i] -= ('a' - 'A');
    }
  }

  // Count the number of vowels in the string
  int count = 0;
  for(i = 0; str1[i]; i++) {
    switch(str1[i]) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        count++;
    }
  }

  // Print the modified string along with the number of vowels
  printf("\nModified string: %s", str1);
  printf("\nNumber of vowels: %d\n", count);

  return 0;
}