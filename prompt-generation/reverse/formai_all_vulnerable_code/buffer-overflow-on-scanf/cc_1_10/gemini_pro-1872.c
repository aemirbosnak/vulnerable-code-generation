//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

//Sherlock Holmes-style C program to synchronize files
//The program starts by defining the necessary header files and variables
int main() {
  //Declaring variables
  char sourceFileName[100], destinationFileName[100];
  int sourceFile, destinationFile, bytesRead, bytesWritten;
  char buffer[1024];
  struct stat sourceFileStat, destinationFileStat;
  char timestamp[20];

  //Sherlock Holmes-style introduction
  printf("Elementary, my dear Watson!\nI am taking the liberty of presenting you with a C program to synchronize two files.\n");

  //Prompting the user for the source and destination file names
  printf("Watson, kindly provide me with the name of the source file: ");
  scanf("%s", sourceFileName);
  printf("And now, Watson, the name of the destination file: ");
  scanf("%s", destinationFileName);

  //Opening the source file in read-only mode
  sourceFile = open(sourceFileName, O_RDONLY);
  if (sourceFile == -1) {
    perror("Watson, there seems to be a problem opening the source file.");
    exit(EXIT_FAILURE);
  }

  //Opening the destination file in read/write mode
  destinationFile = open(destinationFileName, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (destinationFile == -1) {
    perror("Watson, there seems to be a problem opening the destination file.");
    exit(EXIT_FAILURE);
  }

  //Getting the file statistics
  fstat(sourceFile, &sourceFileStat);
  fstat(destinationFile, &destinationFileStat);

  //Checking if the source file is newer than the destination file
  if (sourceFileStat.st_mtime > destinationFileStat.st_mtime) {
    //If the source file is newer, copying its contents to the destination file
    printf("Watson, the source file is newer than the destination file. Copying its contents...\n");
    while ((bytesRead = read(sourceFile, buffer, 1024)) > 0) {
      bytesWritten = write(destinationFile, buffer, bytesRead);
      if (bytesWritten != bytesRead) {
        perror("Watson, there seems to be a problem writing to the destination file.");
        exit(EXIT_FAILURE);
      }
    }
  } else {
    //If the destination file is newer or of the same age as the source file, do nothing
    printf("Watson, the destination file is newer or of the same age as the source file. No action required.\n");
  }

  //Closing both files
  close(sourceFile);
  close(destinationFile);

  //Getting the current timestamp
  struct tm *current_time = localtime(&sourceFileStat.st_mtime);
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", current_time);

  printf("Watson, the file synchronization is complete. The destination file has been updated with the contents of the source file as of %s.\n", timestamp);
  return 0;
}