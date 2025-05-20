#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

typedef struct MemBlock {
  struct MemBlock* next;
  void* data;
  int size;
} MemBlock;

MemBlock* mem_alloc(int size) {
  MemBlock* block = NULL;
  if (size <= 0) {
    return NULL;
  }

  block = malloc(sizeof(MemBlock) + size);
  if (block == NULL) {
    return NULL;
  }

  block->size = size;
  block->data = (void*) ((char*) block + sizeof(MemBlock));
  block->next = NULL;

  return block;
}

void mem_free(MemBlock* block) {
  if (block) {
    free(block);
  }
}

int main() {
  MemBlock* block1 = mem_alloc(10);
  MemBlock* block2 = mem_alloc(20);
  mem_free(block1);
  block1 = mem_alloc(15);

  mem_free(block2);
  block2 = mem_alloc(30);

  mem_free(block1);
  mem_free(block2);

  return 0;
}
