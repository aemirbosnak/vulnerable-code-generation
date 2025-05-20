//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned int calculate_checksum(char* str) {
  int len = strlen(str);
  unsigned int sum = 0;

  // Loop through each character in the string
  for (int i = 0; i < len; i++) {
    // Add the ASCII value of the character to the sum
    sum += (unsigned int)str[i];
  }

  // Return the final checksum
  return sum;
}

int main() {
  // Welcome message
  printf("Welcome to the Checksum Calculator!\n");
  
  int repeat = 1;  // Variable to track if the user wants to calculate another checksum

  while(repeat) {
    // Prompt the user for input
    printf("Please enter a string to calculate the checksum: ");
    char input[100];  // Allocate memory for the user input
    scanf("%s", input);

    // Calculate the checksum of the input
    unsigned int checksum = calculate_checksum(input);

    // Display the results
    printf("The checksum of \"%s\" is: %u\n", input, checksum);

    // Ask the user if they want to calculate another checksum
    printf("Do you want to calculate another checksum? (y/n) ");
    char choice[2];  // Allocate memory for the user choice
    scanf("%s", choice);

    // Check if the user wants to repeat the program
    if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0) {
      repeat = 1;
      printf("-----------------------------\n");  // Add some formatting
    } else {
      repeat = 0;
      printf("Thank you for using the Checksum Calculator!\n");
    }
  }

  // Exit the program
  return 0;
}