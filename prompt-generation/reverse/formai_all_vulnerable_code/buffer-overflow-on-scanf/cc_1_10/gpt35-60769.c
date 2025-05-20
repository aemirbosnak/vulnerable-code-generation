//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char filename[50];
  int size;
  char* data;
} File;

void printFile(File* file) {
  printf("Filename: %s\nSize: %d bytes\n", file->filename, file->size);
  printf("Data:\n");
  for (int i = 0; i < file->size; i++) {
    printf("%c", file->data[i]);
  }
  printf("\n");
}

File* recoverFile(char* filename) {
  printf("Attempting to recover file: %s\n", filename);
  File* file = malloc(sizeof(File));
  strcpy(file->filename, filename);
  file->size = rand() % 100 + 1;
  file->data = malloc(sizeof(char) * file->size);
  for (int i = 0; i < file->size; i++) {
    file->data[i] = rand() % 26 + 65;
  }
  printf("Recovered file:\n");
  printFile(file);
  return file;
}

int main() {
  printf("Welcome to the data recovery tool!\n");
  printf("Please enter the name of a file to recover:\n");
  char filename[50];
  scanf("%s", filename);
  File* file = recoverFile(filename);
  printf("Would you like to save this file? (Y/N):\n");
  char choice;
  scanf(" %c", &choice);
  if (choice == 'Y' || choice == 'y') {
    printf("Saving file...\n");
    FILE* savedFile = fopen(file->filename, "w");
    fprintf(savedFile, "%s", file->data);
    fclose(savedFile);
    printf("File saved!\n");
  } else {
    printf("File not saved. Exiting...\n");
  }
  free(file->data);
  free(file);
  return 0;
}