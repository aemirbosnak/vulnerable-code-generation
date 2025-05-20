//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #define MAX_CHARS 256

  typedef struct {
    int weight;
    char ch;
  } HuffmanNode;

  HuffmanNode* buildHuffmanTree(int freq[], int size) {
    HuffmanNode* nodes = malloc(size * sizeof(HuffmanNode));
    for (int i = 0; i < size; i++) {
      nodes[i].weight = freq[i];
      nodes[i].ch = (char)i;
    }
    for (int i = 0; i < size - 1; i++) {
      int min1 = 0;
      int min2 = 0;
      for (int j = 1; j < size; j++) {
        if (nodes[j].weight < nodes[min1].weight) {
          min1 = j;
        }
      }
      for (int j = min1 + 1; j < size; j++) {
        if (nodes[j].weight < nodes[min2].weight) {
          min2 = j;
        }
      }
      HuffmanNode* node = malloc(sizeof(HuffmanNode));
      node->weight = nodes[min1].weight + nodes[min2].weight;
      node->ch = (char)(min1 * 256 + min2);
      nodes[min1].weight = -1;
      nodes[min2].weight = -1;
      nodes[size + i] = *node;
    }
    return nodes;
  }

  void encode(HuffmanNode* tree, char* str, char* encoded) {
    int i = 0;
    while (str[i] != '\0') {
      int j = 0;
      while (tree[j].ch != '\0') {
        if (tree[j].ch == str[i]) {
          encoded[i] = tree[j].ch;
          break;
        }
        j++;
      }
      i++;
    }
    encoded[i] = '\0';
  }

  void decode(HuffmanNode* tree, char* encoded, char* decoded) {
    int i = 0;
    while (encoded[i] != '\0') {
      int j = 0;
      while (tree[j].ch != '\0') {
        if (tree[j].ch == encoded[i]) {
          decoded[i] = tree[j].ch;
          break;
        }
        j++;
      }
      i++;
    }
    decoded[i] = '\0';
  }

  int main() {
    int freq[MAX_CHARS] = {0};
    char str[1024] = "this is an example for huffman coding";
    char encoded[1024] = {0};
    char decoded[1024] = {0};

    // build huffman tree
    HuffmanNode* tree = buildHuffmanTree(freq, MAX_CHARS);

    // encode the string
    encode(tree, str, encoded);

    // decode the encoded string
    decode(tree, encoded, decoded);

    printf("Encoded string: %s\n", encoded);
    printf("Decoded string: %s\n", decoded);

    return 0;
  }