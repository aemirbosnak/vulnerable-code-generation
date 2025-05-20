//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to compress the input string
char* compress(char* s) {
  int len = strlen(s), index = 0, count = 0;
  char* ans = (char*)calloc(MAX_SIZE, sizeof(char));
  bool repeat = false;

  for (int i = 0; i < len; i++) {
    repeat = false;
    ans[index++] = s[i];
    count++;

    // Count the frequency of current character
    while (i + 1 < len && s[i] == s[i + 1]) {
      count++;
      i++;
      repeat = true;
    }

    // Add the frequency to the compressed string
    if (repeat) {
      char str[10];
      sprintf(str, "%d", count);
      for (int j = 0; str[j] != '\0'; j++, index++) {
        ans[index] = str[j];
      }
      count = 0;
    }
  }

  // If compressed string is longer or same as original string, return the original string
  if (strlen(ans) >= len) {
    free(ans);
    return s;
  }

  return ans;
}

int main() {
  char input[MAX_SIZE];
  printf("Enter the string to compress: ");
  scanf("%[^\n]", input);

  char* ans = compress(input);

  printf("The compressed string is: %s", ans);

  free(ans);
  return 0;
}