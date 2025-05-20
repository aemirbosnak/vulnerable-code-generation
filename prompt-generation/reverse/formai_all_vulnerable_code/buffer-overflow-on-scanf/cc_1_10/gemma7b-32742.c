//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int i, j, n, size = 0;

  // Receive the number of messages
  scanf("Enter the number of messages: ", &n);

  // For each message, receive the message and compress it
  for (i = 0; i < n; i++) {
    printf("Enter the message: ");
    scanf("%s", buffer);

    // Calculate the size of the compressed message
    size = compress(buffer, MAX_BUFFER_SIZE);

    // Send the compressed message
    printf("Compressed message: %s\n", buffer);
  }

  return 0;
}

int compress(char *buffer, int size) {
  int i, j, count = 0, compressedSize = 0;
  char compressedBuffer[MAX_BUFFER_SIZE];

  // Iterate over the buffer and count the occurrences of each character
  for (i = 0; i < size; i++) {
    char character = buffer[i];
    count = 0;
    for (j = 0; j < size; j++) {
      if (character == buffer[j]) {
        count++;
      }
    }

    // If the character occurs more than once, add it to the compressed buffer with the count
    if (count > 1) {
      compressedBuffer[compressedSize++] = character;
      compressedBuffer[compressedSize++] = count;
    } else {
      compressedBuffer[compressedSize++] = character;
    }
  }

  // Return the size of the compressed message
  return compressedSize;
}