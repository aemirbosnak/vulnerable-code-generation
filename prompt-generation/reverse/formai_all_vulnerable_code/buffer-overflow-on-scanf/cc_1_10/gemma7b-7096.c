//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
  char buffer[MAX_BUFFER_SIZE];
  char compressed_buffer[MAX_BUFFER_SIZE];
  int i, j, k, l, n, original_size, compressed_size;
  int repeat_count = 0;

  printf("Enter the original text: ");
  scanf("%s", buffer);

  original_size = strlen(buffer);
  compressed_size = 0;

  // Iterate over the original text to find repeated characters
  for (i = 0; i < original_size - 1; i++)
  {
    for (j = i + 1; j < original_size && buffer[i] == buffer[j]; j++)
    {
      repeat_count++;
    }

    // If the character is repeated, compress it
    if (repeat_count > 0)
    {
      sprintf(compressed_buffer + compressed_size, "%c(%d)", buffer[i], repeat_count);
      compressed_size += strlen(compressed_buffer + compressed_size) + 1;
    }
    else
    {
      compressed_buffer[compressed_size++] = buffer[i];
    }

    repeat_count = 0;
  }

  // Print the compressed text
  printf("Compressed text: ");
  for (k = 0; k < compressed_size; k++)
  {
    printf("%c ", compressed_buffer[k]);
  }

  printf("\n");

  return 0;
}