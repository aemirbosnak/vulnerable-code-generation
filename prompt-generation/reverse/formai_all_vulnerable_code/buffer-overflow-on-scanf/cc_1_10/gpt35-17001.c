//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  FILE *file;
  char name[50], email[50];
  int age;
  
  // Open file for writing
  file = fopen("data.txt", "w");
  
  // Check if file opened successfully
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  
  // Get user input
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your email: ");
  scanf("%s", email);
  printf("Enter your age: ");
  scanf("%d", &age);
  
  // Write data to file
  fprintf(file, "Name: %s\nEmail: %s\nAge: %d", name, email, age);
  
  // Close file
  fclose(file);
  
  // Open file for reading
  file = fopen("data.txt", "r");
  
  // Check if file opened successfully
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  
  // Read data from file and print to console
  char line[100];
  while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
  }
  
  // Close file
  fclose(file);
  
  return 0;
}