//FormAI DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>

// Function to read from a file
void readFromFile(char *filename) {
  FILE *fp;
  char ch;

  // Open file in read mode
  fp = fopen(filename, "r");

  // If file doesn't exist or unable to open
  if (fp == NULL) {
    printf("Unable to open file.\n");
    return;
  }

  // Read contents from the file
  printf("Contents of the file:\n");
  while ((ch = fgetc(fp)) != EOF)
    printf("%c", ch);

  // Close file
  fclose(fp);
}

// Function to write to a file
void writeToFile(char *filename) {
  FILE *fp;
  char data[100];

  // Open file in write mode
  fp = fopen(filename, "w");

  // If file doesn't exist or unable to open
  if (fp == NULL) {
    printf("Unable to open file.\n");
    return;
  }

  // Get input from user
  printf("Enter data to be written to file:\n");
  fgets(data, sizeof(data), stdin);

  // Write to file
  fputs(data, fp);

  // Close file
  fclose(fp);

  printf("Data written to file successfully.\n");
}

int main() {
  char filename[20];
  int choice;

  printf("Enter filename to perform file operations:\n");
  scanf("%s", filename);

  printf("Choose operation to perform:\n");
  printf("1. Read from file.\n");
  printf("2. Write to file.\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      readFromFile(filename);
      break;

    case 2:
      writeToFile(filename);
      break;

    default:
      printf("Invalid choice. Try again.\n");
      break;
  }

  return 0;
}