#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100000];
  scanf("%s", str);

  int len = strlen(str);
  int freq[26] = {0};

  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      freq[str[i] - 'a']++;
    }
  }

  int max_freq = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > max_freq) {
      max_freq = freq[i];
    }
  }

  printf("The most frequent letter is: %c, with a frequency of: %d\n", 'a' + max_freq, max_freq);

  return 0;
}
