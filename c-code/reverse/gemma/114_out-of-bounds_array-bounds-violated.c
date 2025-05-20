#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(1024);

  // Receive data from the user
  printf("Enter the data: ");
  scanf("%s", buffer);

  // Check if the user-supplied input exceeds the buffer size
  if (strlen(buffer) > 1024) {
    printf("Error: Input too large.\n");
  } else {
    // Print the received data
    printf("Data received: %s\n", buffer);
  }

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}
