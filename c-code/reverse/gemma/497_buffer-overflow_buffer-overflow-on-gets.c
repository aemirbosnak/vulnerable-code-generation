#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
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
  char most_frequent_letter = '\0';

  for (int i = 0; i < 26; i++) {
    if (freq[i] > max_freq) {
      max_freq = freq[i];
      most_frequent_letter = 'a' + i;
    }
  }

  if (most_frequent_letter) {
    printf("The most frequent letter is: %c, with a frequency of: %d\n", most_frequent_letter, max_freq);
  } else {
    printf("No letters found.\n");
  }

  return 0;
}
