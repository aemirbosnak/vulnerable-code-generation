#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char* data = NULL;
  int size = 0;

  while (1) {
    // Allocate memory for the data
    data = realloc(data, size + 1);

    // Get the data from the user
    char input[1024];
    printf("Enter data: ");
    scanf("%s", input);

    // Append the data to the memory
    data[size] = input[0];
    size++;

    // Print the data
    printf("Data: %s\n", data);

    // Check if the user wants to continue
    char continue_or_not;
    printf("Continue? (Y/N): ");
    scanf(" %c", &continue_or_not);

    // If the user does not want to continue, break out of the loop
    if (continue_or_not != 'Y') {
      break;
    }
  }

  // Free the memory
  free(data);

  return 0;
}
