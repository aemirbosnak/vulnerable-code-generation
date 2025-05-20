//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100], str2[100], temp[100];
  int len1, len2, i, j;

  printf("Enter the first string: ");
  scanf("%s", str1);

  printf("Enter the second string: ");
  scanf("%s", str2);

  len1 = strlen(str1);
  len2 = strlen(str2);

  // swap the strings if the second string is longer
  if (len2 > len1) {
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
  }

  printf("After swapping, the first string is: %s\n", str1);
  printf("And the second string is: %s\n", str2);

  // concatenate the two strings
  strcat(str1, str2);

  printf("After concatenation, the first string is: %s\n", str1);
  
  // convert the first letter of each word to uppercase
  for (i = 0; i < strlen(str1); i++) {
    if (i == 0 || str1[i-1] == ' ') {
      if (str1[i] >= 'a' && str1[i] <= 'z') {
        str1[i] = str1[i] - 32;
      }
    }
  }

  printf("After converting the first letter of each word to uppercase, the string is: %s\n", str1);

  // count the number of vowels in the string
  int vowelCount = 0;
  for (i = 0; i < strlen(str1); i++) {
    char ch = str1[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      vowelCount++;
    }
  }

  printf("The number of vowels in the string is: %d\n", vowelCount);

  // replace all the spaces with hyphens
  for (i = 0; i < strlen(str1); i++) {
    if (str1[i] == ' ') {
      str1[i] = '-';
    }
  }

  printf("After replacing all the spaces with hyphens, the string is: %s\n", str1);

  return 0;
}