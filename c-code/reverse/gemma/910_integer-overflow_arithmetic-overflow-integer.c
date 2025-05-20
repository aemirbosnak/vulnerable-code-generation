#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

int main() {
  char filename[MAX_FILE_SIZE];
  FILE *file;
  int file_size = 0;
  int i = 0;

  // Create a directory for backups
  system("mkdir backups");

  // Loop until the maximum number of backups is reached
  while (i < MAX_FILES) {
    // Get the file name and size
    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter file size (in KB): ");
    scanf("%d", &file_size);

    // Calculate the file name and date
    char file_date[20];
    time_t t = time(NULL);
    strftime(file_date, 20, "%Y%m%d_%H%M%S", localtime(&t));

    // Create the file name with a unique identifier
    sprintf(filename, "%s_%s_%d.txt", filename, file_date, i);

    // Open the file
    file = fopen(filename, "w");

    // Write the file data
    fprintf(file, "This is file %d", i);

    // Close the file
    fclose(file);

    // Increment the backup counter
    i++;
  }

  return 0;
}
