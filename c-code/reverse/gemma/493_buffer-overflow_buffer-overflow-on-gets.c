#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  scanf("%[^\n]%*c", str);
  int len = strlen(str);
  int freq[26] = {0};
  for (int i = 0; i < len; i++) {
    char letter = str[i] - 97;
    if (letter >= 0 && letter < 26) {
      freq[letter]++;
    }
  }
  int max_freq = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > max_freq) {
      max_freq = freq[i];
    }
  }
  printf("Most frequent letter: %c, count: %d\n", max_freq, max_freq);
  return 0;
}
