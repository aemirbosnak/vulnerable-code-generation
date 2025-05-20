//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

void compress(const char *in, char *out) {
  int i, j = 0, k = 0;
  int len = strlen(in);
  char c, d;
  int count;

  for (i = 0; i < len; i++) {
    c = in[i];
    count = 1;
    while (i + 1 < len && in[i + 1] == c) {
      count++;
      i++;
    }

    if (count > 1) {
      out[j++] = c;
      out[j++] = count + '0';
    } else {
      out[j++] = c;
    }
  }
  out[j] = '\0';
}

void decompress(const char *in, char *out) {
  int i, j = 0, k = 0;
  int len = strlen(in);
  char c, d;
  int count;

  for (i = 0; i < len; i++) {
    c = in[i];
    if (i + 1 < len && in[i + 1] >= '0' && in[i + 1] <= '9') {
      count = in[i + 1] - '0';
      i++;
      while (count-- > 0) {
        out[j++] = c;
      }
    } else {
      out[j++] = c;
    }
  }
  out[j] = '\0';
}

int main() {
  char in[MAX_BUF], out[MAX_BUF];

  printf("Enter a string to compress: ");
  gets(in);

  printf("Compressed: ");
  compress(in, out);
  puts(out);

  printf("Decompressed: ");
  decompress(out, in);
  puts(in);

  return 0;
}