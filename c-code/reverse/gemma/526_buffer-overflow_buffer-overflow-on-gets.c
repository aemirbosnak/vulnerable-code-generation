#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];
  int distance;

  gets(str1);
  gets(str2);

  distance = levenshtein(str1, str2);

  printf("The Levenshtein distance between %s and %s is %d.", str1, str2, distance);

  return 0;
}

int levenshtein(char *str1, char *str2) {
  int i, j, distance = 0;
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  for (i = 0; i < len1; i++) {
    for (j = 0; j < len2; j++) {
      if (str1[i] == str2[j]) {
        distance++;
      }
    }
  }

  return distance;
}
