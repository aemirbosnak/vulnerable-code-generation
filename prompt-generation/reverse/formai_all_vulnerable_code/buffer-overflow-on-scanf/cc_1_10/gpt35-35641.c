//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct ebook {
  char title[50];
  char author[50];
  int year;
  float price;
  int pages;
  char filename[50];
};


int main() {
  int n, i;

  printf("Enter the number of ebooks: ");
  scanf("%d", &n);

  // Dynamically allocate memory for ebook struct array
  struct ebook *library = (struct ebook*) malloc(n * sizeof(struct ebook));

  // Input data for each ebook
  for (i = 0; i < n; i++) {
    printf("\nEnter the title of ebook %d: ", i+1);
    scanf("%s", (library+i)->title);

    printf("Enter the author of ebook %d: ", i+1);
    scanf("%s", (library+i)->author);

    printf("Enter the year of ebook %d: ", i+1);
    scanf("%d", &(library+i)->year);

    printf("Enter the price of ebook %d: ", i+1);
    scanf("%f", &(library+i)->price);

    printf("Enter the number of pages of ebook %d: ", i+1);
    scanf("%d", &(library+i)->pages);

    printf("Enter the filename of ebook %d: ", i+1);
    scanf("%s", (library+i)->filename);
  }

  // Display the details of all ebooks
  printf("\n\nEbooks in library:\n");
  for (i = 0; i < n; i++) {
    printf("\nTitle: %s\n", (library+i)->title);
    printf("Author: %s\n", (library+i)->author);
    printf("Year: %d\n", (library+i)->year);
    printf("Price: %.2f\n", (library+i)->price);
    printf("Pages: %d\n", (library+i)->pages);
    printf("Filename: %s\n", (library+i)->filename);
  }

  // Free memory allocated for ebook struct array
  free(library);

  return 0;
}