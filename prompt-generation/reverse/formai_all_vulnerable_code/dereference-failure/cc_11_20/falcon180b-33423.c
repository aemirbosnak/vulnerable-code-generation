//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
  char str[MAX_SIZE];
  char *p;

  // Prompt the user for a string input
  printf("Enter a string: ");
  fgets(str, MAX_SIZE, stdin);

  // Remove any leading or trailing whitespace
  p = str;
  while (isspace(*p)) {
    p++;
  }
  while (p > str && isspace(*(p - 1))) {
    p--;
    *(p - 1) = '\0';
  }

  // Reverse the string
  p = str;
  char temp;
  while (p < str + strlen(str) - 1) {
    temp = *p;
    *p = *(str + strlen(str) - 1 - (p - str));
    *(str + strlen(str) - 1 - (p - str)) = temp;
    p++;
  }

  // Convert all characters to uppercase
  for (p = str; *p; p++) {
    *p = toupper(*p);
  }

  // Count the number of vowels in the string
  int count = 0;
  for (p = str; *p; p++) {
    if (*p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
      count++;
    }
  }

  // Output the modified string and the number of vowels
  printf("Modified string: %s\n", str);
  printf("Number of vowels: %d\n", count);

  return 0;
}