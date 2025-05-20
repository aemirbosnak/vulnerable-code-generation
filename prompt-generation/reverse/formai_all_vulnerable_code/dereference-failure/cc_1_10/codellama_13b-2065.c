//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom memory management structure
typedef struct {
  void* ptr;
  size_t size;
  int ref_count;
} MemoryBlock;

// Function to allocate a new memory block
MemoryBlock* alloc_mem(size_t size) {
  MemoryBlock* block = malloc(sizeof(MemoryBlock));
  block->ptr = malloc(size);
  block->size = size;
  block->ref_count = 1;
  return block;
}

// Function to free a memory block
void free_mem(MemoryBlock* block) {
  free(block->ptr);
  free(block);
}

// Function to increment the reference count of a memory block
void inc_ref(MemoryBlock* block) {
  block->ref_count++;
}

// Function to decrement the reference count of a memory block
void dec_ref(MemoryBlock* block) {
  block->ref_count--;
  if (block->ref_count == 0) {
    free_mem(block);
  }
}

int main() {
  // Allocate a memory block
  MemoryBlock* block1 = alloc_mem(100);

  // Increment the reference count of the memory block
  inc_ref(block1);

  // Allocate another memory block
  MemoryBlock* block2 = alloc_mem(200);

  // Decrement the reference count of the first memory block
  dec_ref(block1);

  // Free the second memory block
  free_mem(block2);

  return 0;
}