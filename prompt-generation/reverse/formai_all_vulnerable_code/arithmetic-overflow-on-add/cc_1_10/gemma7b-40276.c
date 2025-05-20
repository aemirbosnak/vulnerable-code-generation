//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextBlock {
  char **buffer;
  int size;
  int capacity;
} TextBlock;

void TextBlock_init(TextBlock *block, int capacity) {
  block->buffer = NULL;
  block->size = 0;
  block->capacity = capacity;

  block->buffer = malloc(capacity * MAX_BUFFER_SIZE);
  if (block->buffer == NULL) {
    perror("Memory allocation error");
    exit(1);
  }
}

void TextBlock_add_line(TextBlock *block, char *line) {
  int new_size = block->size + 1;
  block->buffer = realloc(block->buffer, new_size * MAX_BUFFER_SIZE);

  block->buffer[block->size++] = line;
}

void TextBlock_print(TextBlock *block) {
  for (int i = 0; i < block->size; i++) {
    printf("%s\n", block->buffer[i]);
  }
}

int main() {
  TextBlock *block = NULL;
  TextBlock_init(block, 10);

  TextBlock_add_line(block, "This is the first line.");
  TextBlock_add_line(block, "This is the second line.");
  TextBlock_add_line(block, "This is the third line.");

  TextBlock_print(block);

  free(block->buffer);
  free(block);

  return 0;
}