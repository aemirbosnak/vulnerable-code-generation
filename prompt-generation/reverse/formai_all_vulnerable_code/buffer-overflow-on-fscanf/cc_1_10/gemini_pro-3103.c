//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define chapter and page constants
#define CHAPTERS 10
#define PAGES_PER_CHAPTER 10

// Declare the Ebook structure
typedef struct Ebook {
  char title[100];
  char author[100];
  int numChapters;
  int numPages;
  char **pages;
} Ebook;

// Create a new Ebook
Ebook* createEbook(char *title, char *author, int numChapters, int numPages) {
  Ebook *ebook = (Ebook*)malloc(sizeof(Ebook));
  strcpy(ebook->title, title);
  strcpy(ebook->author, author);
  ebook->numChapters = numChapters;
  ebook->numPages = numPages;

  // Allocate memory for the pages
  ebook->pages = (char**)malloc(sizeof(char*) * numChapters);
  for (int i = 0; i < numChapters; i++) {
    ebook->pages[i] = (char*)malloc(sizeof(char) * numPages);
  }

  return ebook;
}

// Load an Ebook from a file
Ebook* loadEbook(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return NULL;
  }

  // Read the title and author
  char title[100];
  char author[100];
  fscanf(fp, "%s %s\n", title, author);

  // Read the number of chapters and pages
  int numChapters;
  int numPages;
  fscanf(fp, "%d %d\n", &numChapters, &numPages);

  // Create a new Ebook
  Ebook *ebook = createEbook(title, author, numChapters, numPages);

  // Read the pages
  for (int i = 0; i < numChapters; i++) {
    for (int j = 0; j < numPages; j++) {
      fscanf(fp, "%s\n", ebook->pages[i][j]);
    }
  }

  // Close the file
  fclose(fp);

  return ebook;
}

// Print an Ebook
void printEbook(Ebook *ebook) {
  printf("Title: %s\n", ebook->title);
  printf("Author: %s\n", ebook->author);
  printf("Number of Chapters: %d\n", ebook->numChapters);
  printf("Number of Pages: %d\n", ebook->numPages);

  for (int i = 0; i < ebook->numChapters; i++) {
    printf("Chapter %d:\n", i + 1);
    for (int j = 0; j < ebook->numPages; j++) {
      printf("%s\n", ebook->pages[i][j]);
    }
  }
}

// Free an Ebook
void freeEbook(Ebook *ebook) {
  // Free the pages
  for (int i = 0; i < ebook->numChapters; i++) {
    free(ebook->pages[i]);
  }

  // Free the Ebook
  free(ebook);
}

// Main function
int main() {
  // Load an Ebook from a file
  Ebook *ebook = loadEbook("book.txt");

  // Print the Ebook
  printEbook(ebook);

  // Free the Ebook
  freeEbook(ebook);

  return 0;
}