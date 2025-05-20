//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **Surprise!** We'll be backing up files like pros!

// Define some fancy macros to make our lives easier
#define YES 1
#define NO 0
#define MAX_PATH 256
#define MAX_FILES 100

// **Woah!** An array to store our precious file paths
char filePaths[MAX_FILES][MAX_PATH];

// **Holy smokes!** Let's create a log file for our backup adventures
FILE *logFile;

// **Ta-da!** Our main function - where the magic happens
int main() {
  // **Step 1: Initializing our backup wonderland**
  printf("Yo! We're ready to back things up like rockstars.\n");
  logFile = fopen("backup_log.txt", "w");
  if (logFile == NULL) {
    printf("Oh no! Couldn't create backup log. We're doomed!\n");
    return EXIT_FAILURE;
  }

  // **Step 2: Collecting our file paths - let's get specific!**
  int fileCount = 0;
  printf("Time to gather the files we wanna protect. Go wild!\n");
  while (YES) {
    char filePath[MAX_PATH];
    printf("Input a file path (or type 'quit' to finish): ");
    scanf("%s", filePath);

    if (strcmp(filePath, "quit") == 0) {
      break;
    }

    strcpy(filePaths[fileCount++], filePath);
  }

  // **Step 3: Playing backup maestro - time to make copies!**
  printf("**Abracadabra!** Time to make backup copies!\n");
  for (int i = 0; i < fileCount; i++) {
    char backupPath[MAX_PATH];
    sprintf(backupPath, "backup_%s", filePaths[i]);

    FILE *inputFile = fopen(filePaths[i], "r");
    if (inputFile == NULL) {
      fprintf(logFile, "Couldn't open file %s for reading. What a bummer!\n", filePaths[i]);
      continue;
    }

    FILE *outputFile = fopen(backupPath, "w");
    if (outputFile == NULL) {
      fprintf(logFile, "Couldn't open backup file %s for writing. Oh dear!\n", backupPath);
      continue;
    }

    char c;
    while ((c = fgetc(inputFile)) != EOF) {
      fputc(c, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    fprintf(logFile, "Successfully backed up %s to %s. Boom!\n", filePaths[i], backupPath);
  }

  // **Step 4: Wrapping up - time to say goodbye!**
  fclose(logFile);
  printf("Phew! We've saved your files like superheroes. Check the backup_log.txt for details.\n");
  return EXIT_SUCCESS;
}