//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100], str2[100];
  int len1, len2, i, j, cost = 0;

  printf("Welcome to the Levenshtein Distance Calculator! \n");
  printf("Please enter your first word or phrase: ");
  scanf("%s", str1);
  printf("Please enter your second word or phrase: ");
  scanf("%s", str2);

  len1 = strlen(str1);
  len2 = strlen(str2);

  int distTable[len1 + 1][len2 + 1];

  for (i = 0; i <= len1; i++) {
    for (j = 0; j <= len2; j++) {
      if (i == 0) {
        distTable[i][j] = j;
      }
      else if (j == 0) {
        distTable[i][j] = i;
      }
      else if (str1[i - 1] == str2[j - 1]) {
        distTable[i][j] = distTable[i - 1][j - 1];
      }
      else {
        distTable[i][j] = 1 + minimum(distTable[i][j - 1], distTable[i - 1][j], distTable[i - 1][j - 1]);
      }
    }
  }

  cost = distTable[len1][len2];

  printf("\nThe Levenshtein Distance between the two words or phrases is: %d\n", cost);

  printf("Congratulations! You have successfully calculated the Levenshtein Distance between two strings!\n");

  return 0;
}

int minimum(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  }
  else if (b <= a && b <= c) {
    return b;
  }
  else {
    return c;
  }
}