//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

// Bloom filter size in bits
#define FILTER_SIZE 1000000

// Number of hash functions
#define NUM_HASHES 5

// Hash function
unsigned int hash(const char *str, unsigned int len) {
  unsigned int h = 0;
  for (unsigned int i = 0; i < len; i++) {
    h = (h << 5) + h + str[i];
  }
  return h;
}

// Initialize Bloom filter
void init_filter(unsigned char *filter) {
  memset(filter, 0, FILTER_SIZE / 8);
}

// Add a string to Bloom filter
void add_to_filter(unsigned char *filter, const char *str, unsigned int len) {
  for (unsigned int i = 0; i < NUM_HASHES; i++) {
    unsigned int h = hash(str, len) + i;
    unsigned int index = h % (FILTER_SIZE / 8);
    unsigned int bit = h / (FILTER_SIZE / 8);
    filter[index] |= (1 << bit);
  }
}

// Check if a string is in Bloom filter
int check_in_filter(unsigned char *filter, const char *str, unsigned int len) {
  for (unsigned int i = 0; i < NUM_HASHES; i++) {
    unsigned int h = hash(str, len) + i;
    unsigned int index = h % (FILTER_SIZE / 8);
    unsigned int bit = h / (FILTER_SIZE / 8);
    if ((filter[index] & (1 << bit)) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  // Initialize Bloom filter
  unsigned char filter[FILTER_SIZE / 8];
  init_filter(filter);

  // Add some strings to Bloom filter
  add_to_filter(filter, "spam", 4);
  add_to_filter(filter, "viagra", 6);
  add_to_filter(filter, "casino", 6);

  // Check if some strings are in Bloom filter
  printf("spam in filter: %d\n", check_in_filter(filter, "spam", 4));
  printf("viagra in filter: %d\n", check_in_filter(filter, "viagra", 6));
  printf("casino in filter: %d\n", check_in_filter(filter, "casino", 6));
  printf("legitimate in filter: %d\n", check_in_filter(filter, "legitimate", 10));

  return 0;
}