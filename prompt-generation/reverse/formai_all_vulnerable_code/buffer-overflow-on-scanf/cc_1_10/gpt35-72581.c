//FormAI DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
/* 
  A Backup System Story
  By: Chatbot
  
  Once upon a time, in a kingdom far, far away, there lived two young programmers named Romeo and Juliet.
  They worked tirelessly to create a file backup system that would save the kingdom's important files and data.
  
  For the first part of their code, Romeo and Juliet created a function to copy files from one location to another, 
  so that they could be backed up and saved. Here is the code they wrote:
*/

#include <stdio.h>
#include <stdlib.h>

int fileCopy(char *source, char *destination) {
  FILE *sourceFile, *destinationFile;
  char c;

  sourceFile = fopen(source, "r");
  if (sourceFile == NULL) {
    printf("\nError: Cannot open source file");
    return 1;
  }

  destinationFile = fopen(destination, "w");
  if (destinationFile == NULL) {
    printf("\nError: Cannot open destination file");
    fclose(sourceFile);
    return 1;
  }

  while ((c = fgetc(sourceFile)) != EOF) {
    fputc(c, destinationFile);
  }

  printf("\nFile copied successfully");
  fclose(sourceFile);
  fclose(destinationFile);
  return 0;
}

// As they continued working on their backup system, Romeo and Juliet encountered a problem with their file deletion function.
// Sometimes, the function would delete the wrong file or even delete more than one file at a time.

// Juliet: "Oh Romeo, we must fix our delete function! It's causing too many problems with the backup process."

// Romeo: "Fear not my love, I shall fix it right away. Here, let me show you the updated code."

int fileDelete(char *filename) {
  int status;
  status = remove(filename);

  if (status == 0) {
    printf("\n%s deleted successfully\n", filename);
    return 0;
  }
  else {
    printf("\nError: Unable to delete the file\n");
    return 1;
  }
}

// With their new file deletion function, Romeo and Juliet proceeded to finish their backup system.
// They incorporated these functions into a larger program, which prompted the user to select either backup or restore.

int main() {
  int choice;

  printf("\nWelcome to the backup system! Please select an option:\n");
  printf("1. Backup files\n2. Restore files\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("\nPlease enter the source and destination file names: ");
      char source[100], destination[100];
      scanf("%s %s", source, destination);

      int status;
      status = fileCopy(source, destination);

      if (status == 0) {
        printf("\nFile backed up successfully\n");
      }
      break;

    case 2:
      printf("\nPlease enter the file name to restore: ");
      char filename[100];
      scanf("%s", filename);

      status = fileDelete(filename);

      if (status == 0) {
        printf("\nFile restored successfully\n");
      }
      break;

    default:
      printf("\nInvalid choice\n");
      break;
  }

  return 0;
}

// And so, Romeo and Juliet successfully completed their backup system, ensuring that the kingdom's files and data were safe and secure for years to come.