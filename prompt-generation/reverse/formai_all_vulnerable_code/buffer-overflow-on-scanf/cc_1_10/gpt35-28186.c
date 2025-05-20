//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
void sanitize(char input[]) {
  int i = 0;
  char sanitized[100];
  
  // Loop through the input string
  while (input[i]) {
    char currentChar = input[i];
    
    // Only accept letters and numbers
    if ((currentChar >= 'A' && currentChar <= 'Z') ||
        (currentChar >= 'a' && currentChar <= 'z') ||
        (currentChar >= '0' && currentChar <= '9')) {
      sanitized[i] = currentChar;
    }
    // Replace all other characters with '?'
    else {
      sanitized[i] = '?';
    }
    i++;
  }
  
  // Terminate the sanitized string with a null character
  sanitized[i] = '\0';
  
  // Print the sanitized string
  printf("Sanitized input: %s\n", sanitized);
}

int main() {
  
  printf("Welcome to the User Input Sanitizer Puzzle Program!\n");
  printf("Your task is to enter a string of characters, and the program will sanitize your input to only accept letters and numbers.\n");
  printf("Are you ready to begin?\n");
  printf("Enter 'Y' for Yes or 'N' for No: ");
  
  char response[10];
  scanf("%s", response);
  
  // Check if the user is ready to begin
  if (strcmp(response, "Y") == 0 || strcmp(response, "y") == 0) {
    printf("Great! Please enter your input:\n");
    
    char input[100];
    scanf("%s", input);
    
    printf("You entered: %s\n", input);
    printf("Sanitizing input...\n");
    
    // Call the sanitize function to sanitize the user input
    sanitize(input);
  }
  else if (strcmp(response, "N") == 0 || strcmp(response, "n") == 0) {
    printf("Okay, no worries. Maybe next time!\n");
  }
  else {
    printf("Invalid input. Please try again.\n");
  }
  
  return 0;
}