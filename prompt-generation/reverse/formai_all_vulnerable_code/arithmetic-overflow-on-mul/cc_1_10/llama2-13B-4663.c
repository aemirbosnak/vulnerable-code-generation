//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MIN_SUPPORT 0.1

// Function to calculate the surprise of a given dataset
int surprise(const char* dataset) {
  int i, j, k;
  int support[26];
  int frequency[26];
  int total_support = 0;
  int total_frequency = 0;

  // Initialize support and frequency arrays
  for (i = 0; i < 26; i++) {
    support[i] = 0;
    frequency[i] = 0;
  }

  // Calculate the support and frequency of each element in the dataset
  for (i = 0; i < strlen(dataset); i++) {
    j = dataset[i] - 'a';
    if (j >= 0 && j < 26) {
      support[j]++;
      frequency[j]++;
    }
  }

  // Calculate the surprise
  for (i = 0; i < 26; i++) {
    total_support += support[i];
  }

  for (i = 0; i < 26; i++) {
    if (frequency[i] > MIN_SUPPORT * total_support) {
      k = i;
      break;
    }
  }

  if (k == 26) {
    // If no element has a surprise value greater than MIN_SUPPORT,
    // return a surprise value of 0
    return 0;
  }

  return (frequency[k] / total_support) * 100;
}

int main() {
  const char* datasets[] = {"the quick brown fox jumps over the lazy dog",
                             "the quick brown fox jumps over the lazy cat",
                             "the quick brown fox jumps over the lazy elephant"};
  int i;

  // Calculate the surprise of each dataset
  for (i = 0; i < sizeof(datasets) / sizeof(datasets[0]); i++) {
    printf("Surprise of %s: %d%%\n", datasets[i], surprise(datasets[i]));
  }

  return 0;
}