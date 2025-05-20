//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_NODES 1000

typedef struct {
  int freq;
  char ch;
} node_t;

typedef struct {
  node_t *nodes;
  int count;
} huffman_tree_t;

huffman_tree_t *create_huffman_tree(int *freqs) {
  huffman_tree_t *tree = malloc(sizeof(huffman_tree_t));
  tree->nodes = malloc(MAX_NODES * sizeof(node_t));
  tree->count = 0;

  for (int i = 0; i < MAX_CHARS; i++) {
    node_t node = {
      .freq = freqs[i],
      .ch = (char)i
    };
    tree->nodes[i] = node;
    tree->count++;
  }

  return tree;
}

void build_huffman_tree(huffman_tree_t *tree) {
  while (tree->count > 1) {
    node_t *node1 = NULL;
    node_t *node2 = NULL;
    int min_freq = MAX_CHARS;

    for (int i = 0; i < tree->count; i++) {
      if (tree->nodes[i].freq < min_freq) {
        min_freq = tree->nodes[i].freq;
        node1 = &tree->nodes[i];
      }
    }

    for (int i = 0; i < tree->count; i++) {
      if (tree->nodes[i].freq < min_freq && &tree->nodes[i] != node1) {
        min_freq = tree->nodes[i].freq;
        node2 = &tree->nodes[i];
      }
    }

    node_t node = {
      .freq = node1->freq + node2->freq,
      .ch = '\0'
    };
    tree->nodes[tree->count] = node;
    tree->count++;

    node1->freq = 0;
    node2->freq = 0;
  }
}

void print_huffman_tree(huffman_tree_t *tree) {
  for (int i = 0; i < tree->count; i++) {
    printf("%c: %d\n", tree->nodes[i].ch, tree->nodes[i].freq);
  }
}

int main(void) {
  int freqs[MAX_CHARS] = {0};

  freqs['a'] = 5;
  freqs['b'] = 3;
  freqs['c'] = 2;
  freqs['d'] = 1;

  huffman_tree_t *tree = create_huffman_tree(freqs);
  build_huffman_tree(tree);
  print_huffman_tree(tree);

  return 0;
}