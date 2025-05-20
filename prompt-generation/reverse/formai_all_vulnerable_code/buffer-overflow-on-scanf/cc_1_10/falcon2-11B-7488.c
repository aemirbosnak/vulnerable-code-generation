//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
  char filename[MAX_SIZE];
  char buffer[MAX_SIZE];
  int line_number = 1;
  int char_number = 1;
  int page_number = 1;
  int total_pages = 0;
  int file_size = 0;
  
  printf("Enter the filename of the ebook: ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  while (!feof(file)) {
    fgets(buffer, MAX_SIZE, file);
    total_pages++;

    if (buffer[0] == '*' && buffer[1] == '*' && buffer[2] == '*') {
      char* str = strchr(buffer, '*');
      str += 3;
      char* end_ptr = strchr(str, '*');
      page_number = atoi(str) - 1;

      if (page_number > total_pages) {
        page_number = total_pages;
      }

      printf("Page %d\n", page_number);
      total_pages++;
      line_number = 1;
      char_number = 1;
    } else {
      line_number++;
      char_number++;
      printf("%3d %3d %s\n", line_number, char_number, buffer);
    }
  }

  fclose(file);
  printf("Total number of pages: %d\n", total_pages);
  return 0;
}