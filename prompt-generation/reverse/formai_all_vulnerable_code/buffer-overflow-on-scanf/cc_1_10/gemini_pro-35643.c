//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIN_STR_LEN 100

static bool is_valid_bin_str(const char *bin_str) {
  size_t len = strlen(bin_str);
  if (len == 0 || len > MAX_BIN_STR_LEN) {
    return false;
  }
  for (size_t i = 0; i < len; i++) {
    if (bin_str[i] != '0' && bin_str[i] != '1') {
      return false;
    }
  }
  return true;
}

static uint64_t bin_str_to_uint64(const char *bin_str) {
  size_t len = strlen(bin_str);
  uint64_t result = 0;
  for (size_t i = 0; i < len; i++) {
    result <<= 1;
    if (bin_str[i] == '1') {
      result |= 1;
    }
  }
  return result;
}

static char *uint64_to_bin_str(uint64_t uint64, size_t *len) {
  char *bin_str = malloc(MAX_BIN_STR_LEN + 1);
  if (bin_str == NULL) {
    return NULL;
  }
  *len = 0;
  while (uint64 > 0) {
    bin_str[(*len)++] = (uint64 & 1) + '0';
    uint64 >>= 1;
  }
  bin_str[*len] = '\0';
  return bin_str;
}

int main(void) {
  char bin_str[MAX_BIN_STR_LEN + 1];
  printf("Enter a binary string (max length %d): ", MAX_BIN_STR_LEN);
  scanf("%s", bin_str);

  if (!is_valid_bin_str(bin_str)) {
    printf("Invalid binary string.\n");
    return EXIT_FAILURE;
  }

  uint64_t uint64 = bin_str_to_uint64(bin_str);
  printf("The equivalent unsigned 64-bit integer is: %llu\n", uint64);

  size_t bin_str_len;
  char *new_bin_str = uint64_to_bin_str(uint64, &bin_str_len);
  if (new_bin_str == NULL) {
    printf("Failed to convert unsigned 64-bit integer to binary string.\n");
    return EXIT_FAILURE;
  }

  printf("The converted binary string is: %s\n", new_bin_str);

  free(new_bin_str);

  return EXIT_SUCCESS;
}