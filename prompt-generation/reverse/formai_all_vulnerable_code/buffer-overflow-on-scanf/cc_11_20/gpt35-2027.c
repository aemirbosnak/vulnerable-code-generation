//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include<stdio.h>

int main() {
  // Inquisitive style program to handle file in C

  // Step 1: Ask the user for the name of the file they want to create or open
  char filename[100];
  printf("What is the name of the file you want to create or open?\n");
  scanf("%s", filename);

  // Step 2: Check if the file exists
  FILE *fileptr;
  fileptr = fopen(filename, "r"); // Try to open file in read mode
  if(fileptr == NULL) { // If fileptr is NULL, file does not exist
    printf("The file does not exist. Do you want to create it? (Y/N)\n");
    char response;
    scanf(" %c", &response);
    if(response == 'Y' || response == 'y') { // If user wants to create the file
      fileptr = fopen(filename, "w"); // Create file in write mode
      if(fileptr == NULL) { // Check if file creation was successful
        printf("There was an error creating the file.\n");
        return 1;
      } else {
        printf("File created successfully!\n");
      }
    } else { // If user does not want to create the file
      printf("Exiting program.\n");
      return 0;
    }
  } else { // If file already exists
    printf("File exists. Do you want to read or write to it? (R/W)\n");
    char response;
    scanf(" %c", &response);
    if(response == 'R' || response == 'r') { // If user wants to read the file
      char ch = fgetc(fileptr); // Get first character from file
      while(ch != EOF) { // Print characters until end-of-file
        printf("%c", ch);
        ch = fgetc(fileptr);
      }
      fclose(fileptr);
    } else if(response == 'W' || response == 'w') { // If user wants to write to the file
      fileptr = fopen(filename, "a"); // Open file in append mode
      if(fileptr == NULL) { // Check if file opening was successful
        printf("There was an error opening the file.\n");
        return 1;
      } else {
        printf("Enter the data you want to write to the file:\n");
        char data[1000];
        scanf(" %[^\n]s", data); // Read data from user input
        fprintf(fileptr, "%s", data); // Write data to file
        fclose(fileptr);
        printf("Data written successfully!\n");
      }
    } else { // If user enters an invalid response
      printf("Invalid option.\n");
      return 1;
    }
  }

  return 0;
}