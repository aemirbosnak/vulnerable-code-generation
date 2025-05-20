//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SYMBOLS 256

typedef struct node {
  unsigned char symbol;
  int freq;
  struct node *left, *right;
} node_t;

void count_chars(FILE *input_file, int **freq) {
  int c;
  while ((c = fgetc(input_file)) != EOF) {
    (*freq)[c]++;
  }
}

node_t *new_node(unsigned char symbol, int freq) {
  node_t *new = malloc(sizeof(node_t));
  new->symbol = symbol;
  new->freq = freq;
  new->left = new->right = NULL;
  return new;
}

int cmp_nodes(const void *a, const void *b) {
  node_t **node_a = (node_t **) a;
  node_t **node_b = (node_t **) b;
  return (*node_a)->freq - (*node_b)->freq;
}

node_t *build_huffman_tree(int *freq) {
  node_t **trees = malloc(sizeof(node_t *) * NUM_SYMBOLS);
  node_t **tree_ptr = trees;

  for (int i = 0; i < NUM_SYMBOLS; i++) {
    if (freq[i]) {
      *tree_ptr++ = new_node(i, freq[i]);
    }
  }

  qsort(trees, tree_ptr - trees, sizeof(node_t *), cmp_nodes);

  while (tree_ptr - trees > 1) {
    node_t *a = *trees++;
    node_t *b = *trees++;
    node_t *parent = new_node(0, a->freq + b->freq);
    parent->left = a;
    parent->right = b;

    node_t **new_loc = trees;
    while ((*new_loc) && (*new_loc)->freq < parent->freq) {
      new_loc++;
    }

    memmove(new_loc + 1, new_loc, (trees + NUM_SYMBOLS - new_loc - 1) * sizeof(node_t *));
    *new_loc = parent;
  }

  return *trees;
}

void write_char(unsigned char c, FILE *output_file) {
  static unsigned char write_buffer;
  static int bits_in_buffer = 0;

  for (int i = 0; i < 8; i++) {
    write_buffer = (write_buffer << 1) | ((c >> i) & 1);
    if (++bits_in_buffer == 8) {
      fputc(write_buffer, output_file);
      write_buffer = 0;
      bits_in_buffer = 0;
    }
  }
}

void dump_bits(node_t *root, unsigned char bits, int bit_count, FILE *output_file) {
  if (root->left || root->right) {
    if (bits & (1 << (bit_count - 1))) {
      dump_bits(root->right, bits, bit_count - 1, output_file);
    } else {
      dump_bits(root->left, bits, bit_count - 1, output_file);
    }
  } else {
    write_char(root->symbol, output_file);
  }
}

void write_output(node_t *root, FILE *input_file, FILE *output_file) {
  int c;
  unsigned char buffer = 0;
  int bit_count = 0;
  while ((c = fgetc(input_file)) != EOF) {
    node_t *leaf = root;
    while (leaf->left || leaf->right) {
      if (c & (1 << (7 - bit_count))) {
        leaf = leaf->right;
      } else {
        leaf = leaf->left;
      }
      if (++bit_count == 8) {
        dump_bits(root, buffer, 8, output_file);
        buffer = 0;
        bit_count = 0;
      }
    }

    buffer = (buffer << 1) | (leaf->symbol & 1);
    if (++bit_count == 8) {
      dump_bits(root, buffer, 8, output_file);
      buffer = 0;
      bit_count = 0;
    }
  }

  if (bit_count) {
    while (bit_count < 8) {
      buffer <<= 1;
      bit_count++;
    }
    dump_bits(root, buffer, bit_count, output_file);
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input_file = fopen(argv[1], "rb");
  if (!input_file) {
    perror("Unable to open input file");
    return EXIT_FAILURE;
  }

  int *freq = calloc(NUM_SYMBOLS, sizeof(int));
  count_chars(input_file, &freq);
  fclose(input_file);

  node_t *root = build_huffman_tree(freq);
  free(freq);

  FILE *output_file = fopen(argv[2], "wb");
  if (!output_file) {
    perror("Unable to open output file");
    return EXIT_FAILURE;
  }

  fwrite(&root, sizeof(node_t **), 1, output_file);
  write_output(root, input_file, output_file);

  fclose(output_file);

  return EXIT_SUCCESS;
}