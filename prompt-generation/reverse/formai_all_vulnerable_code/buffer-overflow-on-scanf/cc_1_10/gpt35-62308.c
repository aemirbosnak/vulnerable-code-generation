//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
void writeFile();
void readFile();

int main() {
  // Welcome message
  printf("Welcome to File Handling Example Program.\n");

  // Print options
  printf("Choose an option:\n");
  printf("1. Write to file\n");
  printf("2. Read from file\n");

  int choice;
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      writeFile();
      break;
    case 2:
      readFile();
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}

void writeFile() {
  // Open file for writing
  FILE *f = fopen("example.txt", "w");

  // Check if file was opened successfully
  if (f == NULL) {
    printf("Error: File could not be opened.\n");
    return;
  }

  // Get input from user
  printf("Enter text to write to file (max %d characters):\n", MAX_SIZE);
  char input[MAX_SIZE];
  scanf(" %[^\n]", input);

  // Write input to file
  fprintf(f, "%s", input);

  // Close file
  fclose(f);

  printf("File written successfully!\n");
}

void readFile() {
  // Open file for reading
  FILE *f = fopen("example.txt", "r");

  // Check if file was opened successfully
  if (f == NULL) {
    printf("Error: File could not be opened.\n");
    return;
  }

  // Read content of file into buffer
  char buffer[MAX_SIZE];
  fgets(buffer, MAX_SIZE, f);

  // Print content of file
  printf("Content of file:\n%s", buffer);

  // Close file
  fclose(f);
}