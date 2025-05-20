//FormAI DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for ebook information
typedef struct Ebook {
  char title[50];
  char author[50];
  char format[10];
  size_t size;
} Ebook;

// Function to open ebook
void openEbook(Ebook* ebook) {
  printf("\nOpening %s by %s in %s format...\n", ebook->title, ebook->author, ebook->format);
  printf("Ebook size: %zu bytes\n\n", ebook->size);
}

int main() {
  // Create an array of ebooks
  Ebook ebooks[3];

  // Set ebook information
  strcpy(ebooks[0].title, "The Great Gatsby");
  strcpy(ebooks[0].author, "F. Scott Fitzgerald");
  strcpy(ebooks[0].format, "PDF");
  ebooks[0].size = 1500;

  strcpy(ebooks[1].title, "1984");
  strcpy(ebooks[1].author, "George Orwell");
  strcpy(ebooks[1].format, "EPUB");
  ebooks[1].size = 2000;

  strcpy(ebooks[2].title, "To Kill a Mockingbird");
  strcpy(ebooks[2].author, "Harper Lee");
  strcpy(ebooks[2].format, "MOBI");
  ebooks[2].size = 1800;

  // Prompt user for ebook selection
  int selection;
  printf("Select an ebook to open: \n\n");
  printf("1. The Great Gatsby\n");
  printf("2. 1984\n");
  printf("3. To Kill a Mockingbird\n\n");
  scanf("%d", &selection);

  // Open selected ebook
  switch (selection) {
    case 1: openEbook(&ebooks[0]);
            break;
    case 2: openEbook(&ebooks[1]);
            break;
    case 3: openEbook(&ebooks[2]);
            break;
    default: printf("Invalid selection.\n");
             break;
  }

  return 0;
}