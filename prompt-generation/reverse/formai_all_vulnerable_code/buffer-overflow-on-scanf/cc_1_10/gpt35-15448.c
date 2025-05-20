//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576

/* Function to check if a file contains a virus */
int is_virus(char *filename, char *virus_signature) {
  FILE *fileptr;
  char *buffer;
  long filelen;

  /* Open the file */
  fileptr = fopen(filename, "rb");
  if (!fileptr) {
    printf("Error: The file could not be opened.\n");
    return 0;
  }

  /* Get the file size */
  fseek(fileptr, 0, SEEK_END);
  filelen = ftell(fileptr);
  rewind(fileptr);

  /* Allocate memory for the buffer */
  buffer = (char *) malloc(filelen * sizeof(char));

  /* Read the file into the buffer */
  fread(buffer, filelen, 1, fileptr);

  /* Check if the virus signature is present */
  if (strstr(buffer, virus_signature) != NULL) {
    printf("Virus found in file: %s\n", filename);
    return 1;
  } else {
    return 0;
  }

  /* Free the memory and close the file */
  free(buffer);
  fclose(fileptr);
}

int main() {
  char *virus_signature = "This file contains a virus!";
  char filename[100];

  /* Get the name of the file to scan */
  printf("Enter the name of the file to scan: ");
  scanf("%s", filename);

  /* Check if the file is too big to scan */
  FILE *fileptr = fopen(filename, "rb");
  if (!fileptr) {
    printf("Error: The file could not be opened.\n");
    return 0;
  }
  fseek(fileptr, 0, SEEK_END);
  long file_size = ftell(fileptr);
  fclose(fileptr);
  if (file_size > MAX_FILE_SIZE) {
    printf("Error: The file is too big to scan.\n");
    return 0;
  }

  /* Scan the file */
  if (is_virus(filename, virus_signature)) {
    printf("The file contains a virus.\n");
  } else {
    printf("The file is safe.\n");
  }

  return 0;
}