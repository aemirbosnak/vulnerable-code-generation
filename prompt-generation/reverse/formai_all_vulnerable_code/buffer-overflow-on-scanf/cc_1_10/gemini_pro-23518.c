//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output strings.
#define MAX_SIZE 1024

// Create a function to compress the input string.
char* compress(char* input) {
  // Allocate memory for the output string.
  char* output = malloc(MAX_SIZE);
  
  // Initialize the output string.
  int output_index = 0;
  
  // Iterate over the input string.
  int input_index = 0;
  while (input[input_index] != '\0') {
    // Get the current character from the input string.
    char character = input[input_index];
    
    // Count the number of consecutive occurrences of the current character.
    int count = 0;
    while (input[input_index] == character) {
      count++;
      input_index++;
    }
    
    // Add the current character and the count of its consecutive occurrences to the output string.
    output[output_index++] = character;
    output[output_index++] = count + '0';
  }
  
  // Null-terminate the output string.
  output[output_index] = '\0';
  
  // Return the output string.
  return output;
}

// Create a function to decompress the input string.
char* decompress(char* input) {
  // Allocate memory for the output string.
  char* output = malloc(MAX_SIZE);
  
  // Initialize the output string.
  int output_index = 0;
  
  // Iterate over the input string.
  int input_index = 0;
  while (input[input_index] != '\0') {
    // Get the current character from the input string.
    char character = input[input_index++];
    
    // Get the count of the current character's consecutive occurrences.
    int count = input[input_index++] - '0';
    
    // Add the current character to the output string count times.
    for (int i = 0; i < count; i++) {
      output[output_index++] = character;
    }
  }
  
  // Null-terminate the output string.
  output[output_index] = '\0';
  
  // Return the output string.
  return output;
}

// Get the input string from the user.
char* get_input() {
  // Allocate memory for the input string.
  char* input = malloc(MAX_SIZE);
  
  // Prompt the user to enter the input string.
  printf("Enter the input string: ");
  
  // Read the input string from the user.
  scanf("%[^\n]%*c", input);
  
  // Return the input string.
  return input;
}

// Print the output string to the console.
void print_output(char* output) {
  // Print the output string to the console.
  printf("The output string is: %s\n", output);
}

// Get the user's choice of compression or decompression.
int get_choice() {
  // Prompt the user to enter their choice.
  printf("Enter 1 to compress, 2 to decompress: ");
  
  // Read the user's choice from the console.
  int choice;
  scanf("%d", &choice);
  
  // Return the user's choice.
  return choice;
}

// Main function.
int main() {
  // Get the input string from the user.
  char* input = get_input();
  
  // Get the user's choice of compression or decompression.
  int choice = get_choice();
  
  // Compress or decompress the input string based on the user's choice.
  char* output;
  if (choice == 1) {
    output = compress(input);
  } else if (choice == 2) {
    output = decompress(input);
  } else {
    printf("Invalid choice.\n");
    return 1;
  }
  
  // Print the output string to the console.
  print_output(output);
  
  // Free the memory allocated for the input and output strings.
  free(input);
  free(output);
  
  // Return 0 to indicate successful execution.
  return 0;
}