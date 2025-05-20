//FormAI DATASET v1.0 Category: File Backup System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to C File Backup System!\n");

  // Prompt user for input file name
  printf("Please enter the name of the file you want to backup: ");
  char file_name[100];
  scanf("%s", file_name);

  // Open input file
  FILE* input_file = fopen(file_name, "r");

  // Check if the input file exists
  if (input_file == NULL) {
    printf("Error: file '%s' not found.\n", file_name);
    return 1;
  }

  // Create backup file name
  char backup_name[100];
  strcpy(backup_name, file_name);
  strcat(backup_name, ".bak");

  // Open output file
  FILE* output_file = fopen(backup_name, "w");

  // Check if the output file was created
  if (output_file == NULL) {
    printf("Error: could not create backup file '%s'.\n", backup_name);
    return 1;
  }

  // Copy contents of input file to output file
  int character;
  while ((character = fgetc(input_file)) != EOF) {
    fputc(character, output_file);
  }

  // Close input and output files
  fclose(input_file);
  fclose(output_file);

  // Success message
  printf("File '%s' has been successfully backed up to '%s'.\n", file_name, backup_name);

  return 0;
}