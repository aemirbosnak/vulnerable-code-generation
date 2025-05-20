#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[256];
  FILE *fp;

  printf("Enter book file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Read book data from file
  // (Assuming book data is in a specific format, e.g., title, author, pages)
  char book_data[1024];
  fread(book_data, 1024, 1, fp);

  fclose(fp);

  // Display book data
  printf("Book data: \n%s", book_data);

  return 0;
}
