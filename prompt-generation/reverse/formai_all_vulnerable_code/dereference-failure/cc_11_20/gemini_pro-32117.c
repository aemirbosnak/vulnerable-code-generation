//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

typedef struct node {
  char *word;
  int count;
  struct node *next;
} node_t;

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  node_t *head = NULL;
  int total_words = 0;
  char buffer[BUFSIZ];
  while (fgets(buffer, BUFSIZ, f)) {
    char *p = buffer;
    while (*p) {
      while (!isalpha(*p)) {
        p++;
      }
      if (*p) {
        char *start = p;
        while (isalpha(*p)) {
          p++;
        }
        int len = p - start;
        char *word = malloc(len + 1);
        strncpy(word, start, len);
        word[len] = '\0';

        node_t *node = head;
        while (node != NULL) {
          if (strcmp(node->word, word) == 0) {
            node->count++;
            break;
          }
          node = node->next;
        }

        if (node == NULL) {
          node_t *new_node = malloc(sizeof(node_t));
          new_node->word = word;
          new_node->count = 1;
          new_node->next = NULL;
          if (head == NULL) {
            head = new_node;
          } else {
            node_t *last = head;
            while (last->next != NULL) {
              last = last->next;
            }
            last->next = new_node;
          }
        }

        total_words++;
      }
    }
  }

  fclose(f);

  node_t *node = head;
  while (node != NULL) {
    printf("%s: %d\n", node->word, node->count);
    node = node->next;
  }

  printf("Total words: %d\n", total_words);

  return EXIT_SUCCESS;
}