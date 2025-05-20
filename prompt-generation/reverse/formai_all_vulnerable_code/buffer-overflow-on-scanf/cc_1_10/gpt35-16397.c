//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  
  // Welcome message
  printf("Welcome to the ultimate spell checking program!\n");
  
  // Get user input
  char input[100];
  printf("Please enter a word for spell checking: ");
  scanf("%s", input);
  
  // Open the dictionary file
  FILE *fp;
  fp = fopen("dictionary.txt", "r");
  
  // Check if the file exists
  if (fp == NULL) {
    printf("Dictionary file not found!\n");
    return -1;
  }
  
  // Check if the word exists in the dictionary
  char line[100];
  int found = 0;
  while (fgets(line, sizeof(line), fp)) {
    
    // Remove the newline character
    line[strcspn(line, "\n")] = 0;
    
    // If the word is found, exit the loop
    if (strcmp(line, input) == 0) {
      found = 1;
      break;
    }
  }
  
  // Close the file
  fclose(fp);
  
  // Print the result
  if (found) {
    printf("Your word is spelled correctly! Congratulations!\n");
  } else {
    printf("Oh no! Your word is spelled incorrectly. Please check your spelling and try again.\n");
  }
  
  return 0;
}