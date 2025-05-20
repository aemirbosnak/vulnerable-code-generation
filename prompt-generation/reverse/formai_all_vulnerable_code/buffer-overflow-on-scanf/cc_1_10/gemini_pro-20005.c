//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the input buffer
#define MAX_INPUT_SIZE 1024

// Define the size of the checksum
#define CHECKSUM_SIZE 4

// Declare the input buffer
char input_buffer[MAX_INPUT_SIZE];

// Declare the checksum buffer
char checksum_buffer[CHECKSUM_SIZE];

// Calculate the checksum of the input buffer
void calculate_checksum(char *input_buffer, char *checksum_buffer) {
  // Initialize the checksum to zero
  int checksum = 0;

  // Iterate over the input buffer
  for (int i = 0; i < MAX_INPUT_SIZE; i++) {
    // Add the current character to the checksum
    checksum += input_buffer[i];
  }

  // Convert the checksum to a string
  sprintf(checksum_buffer, "%04x", checksum);
}

// Print the checksum to the console
void print_checksum(char *checksum_buffer) {
  // Print the checksum
  printf("Checksum: %s\n", checksum_buffer);
}

// Main function
int main() {
  // Get the input from the user
  printf("Enter the input: ");
  scanf("%s", input_buffer);

  // Calculate the checksum of the input
  calculate_checksum(input_buffer, checksum_buffer);

  // Print the checksum to the console
  print_checksum(checksum_buffer);

  return 0;
}