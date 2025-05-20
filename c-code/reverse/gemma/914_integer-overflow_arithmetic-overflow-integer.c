#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int file_num = 0;
  char filename[256];

  // Loop to handle multiple files
  while (1) {
    // Get file name from user
    printf("Enter file name: ");
    scanf("%s", filename);

    // Check if file name is valid
    if (strlen(filename) > 255) {
      printf("Error: File name too long.\n");
      continue;
    }

    // Increment file number
    file_num++;

    // Concatenate file number with file name
    sprintf(filename, "%s%d", filename, file_num);

    // Backup file
    FILE *file = fopen(filename, "w");
    fclose(file);

    // Break out of loop when user enters "quit"
    if (strcmp(filename, "quit") == 0) {
      break;
    }
  }

  return 0;
}
