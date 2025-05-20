//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str1[50], str2[50], str3[100];

  printf("Enter a string: ");
  scanf("%s", str1);

  printf("Enter another string: ");
  scanf("%s", str2);

  // Concatenating two strings
  strcat(str3, str1);
  strcat(str3, str2);
  printf("Concatenated string: %s\n", str3);

  // Comparing two strings
  if (strcmp(str1, str2) == 0) {
    printf("Strings are equal\n");
  } else {
    printf("Strings are not equal\n");
  }

  // Finding the length of a string
  printf("Length of str1: %ld\n", strlen(str1));
  printf("Length of str2: %ld\n", strlen(str2));
  printf("Length of str3: %ld\n", strlen(str3));

  // Reversing a string
  char rev_str1[50], rev_str2[50];
  int i, j;
  for (i = 0, j = strlen(str1) - 1; i < strlen(str1); i++, j--) {
    rev_str1[i] = str1[j];
  }
  rev_str1[i] = '\0';

  for (i = 0, j = strlen(str2) - 1; i < strlen(str2); i++, j--) {
    rev_str2[i] = str2[j];
  }
  rev_str2[i] = '\0';

  printf("Reversed str1: %s\n", rev_str1);
  printf("Reversed str2: %s\n", rev_str2);

  // Counting vowels in a string
  int vowel_count = 0;
  for (i = 0; i < strlen(str3); i++) {
    if (str3[i] == 'a' || str3[i] == 'e' || str3[i] == 'i' || str3[i] == 'o' || str3[i] == 'u') {
      vowel_count++;
    }
  }
  printf("Number of vowels in str3: %d\n", vowel_count);

  // Changing case of a string
  char lower_str1[50], upper_str2[50];
  for (i = 0; i < strlen(str1); i++) {
    lower_str1[i] = tolower(str1[i]);
  }
  lower_str1[i] = '\0';

  for (i = 0; i < strlen(str2); i++) {
    upper_str2[i] = toupper(str2[i]);
  }
  upper_str2[i] = '\0';

  printf("Lowercase str1: %s\n", lower_str1);
  printf("Uppercase str2: %s\n", upper_str2);

  return 0;
}