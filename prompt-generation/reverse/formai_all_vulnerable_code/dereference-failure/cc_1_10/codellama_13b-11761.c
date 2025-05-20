//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct {
  char ch;
  int freq;
} CharFreq;

void print_huffman_code(CharFreq *freqs, int n) {
  if (n == 1) {
    printf("%c: %d\n", freqs[0].ch, freqs[0].freq);
    return;
  }

  CharFreq *left = malloc(sizeof(CharFreq));
  CharFreq *right = malloc(sizeof(CharFreq));

  left->ch = '0';
  right->ch = '1';

  int left_freq = 0;
  int right_freq = 0;

  for (int i = 0; i < n; i++) {
    if (freqs[i].freq <= left_freq) {
      left_freq = freqs[i].freq;
      left->ch = freqs[i].ch;
    }

    if (freqs[i].freq <= right_freq) {
      right_freq = freqs[i].freq;
      right->ch = freqs[i].ch;
    }
  }

  print_huffman_code(left, n);
  print_huffman_code(right, n);

  free(left);
  free(right);
}

int main() {
  CharFreq freqs[MAX_CHARS];
  char ch;
  int n = 0;

  while ((ch = getchar()) != EOF) {
    if (ch == ' ') continue;
    freqs[n].ch = ch;
    freqs[n].freq = 1;
    n++;
  }

  print_huffman_code(freqs, n);

  return 0;
}