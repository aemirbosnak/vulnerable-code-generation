#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char book_data[1024];
  FILE *fp;
  char search_term[256];

  fp = fopen("books.txt", "r");
  fscanf(fp, "%[^\n]%*c", book_data);
  fclose(fp);

  printf("Enter search term: ");
  scanf("%s", search_term);

  char *book_ptr = book_data;
  while (*book_ptr) {
    if (strstr(book_ptr, search_term) != NULL) {
      printf("Book found: %s\n", book_ptr);
    }
    book_ptr++;
  }

  return 0;
}
