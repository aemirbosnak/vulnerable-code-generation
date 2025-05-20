//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a cyberpunk ebook
typedef struct {
  char *title;
  char *author;
  int num_pages;
  char *text;
} Ebook;

// Load an ebook from a file
Ebook *load_ebook(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return NULL;
  }

  // Read the title
  char *title = NULL;
  size_t title_len = 0;
  getline(&title, &title_len, fp);

  // Read the author
  char *author = NULL;
  size_t author_len = 0;
  getline(&author, &author_len, fp);

  // Read the number of pages
  int num_pages;
  fscanf(fp, "%d", &num_pages);

  // Read the text
  char *text = NULL;
  size_t text_len = 0;
  while (!feof(fp)) {
    char *line = NULL;
    size_t line_len = 0;
    getline(&line, &line_len, fp);
    text = realloc(text, text_len + line_len + 1);
    strcat(text, line);
  }

  // Close the file
  fclose(fp);

  // Create the ebook struct
  Ebook *ebook = malloc(sizeof(Ebook));
  ebook->title = title;
  ebook->author = author;
  ebook->num_pages = num_pages;
  ebook->text = text;

  return ebook;
}

// Free the memory allocated for an ebook
void free_ebook(Ebook *ebook) {
  free(ebook->title);
  free(ebook->author);
  free(ebook->text);
  free(ebook);
}

// Print the ebook to the console
void print_ebook(Ebook *ebook) {
  printf("Title: %s\nAuthor: %s\nNumber of pages: %d\n\n", ebook->title, ebook->author, ebook->num_pages);
  printf("%s", ebook->text);
}

int main() {
  // Load the ebook from a file
  Ebook *ebook = load_ebook("ebook.txt");
  if (ebook == NULL) {
    return EXIT_FAILURE;
  }

  // Print the ebook to the console
  print_ebook(ebook);

  // Free the memory allocated for the ebook
  free_ebook(ebook);

  return EXIT_SUCCESS;
}