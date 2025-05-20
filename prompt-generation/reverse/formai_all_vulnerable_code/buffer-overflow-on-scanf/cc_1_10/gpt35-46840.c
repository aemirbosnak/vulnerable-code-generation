//FormAI DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    char publisher[50];
    int year;
    int pages;
} Book;

int main() {
    // Declare variables
    int num_books;
    Book *library;
    char filename[100];

    // Prompt user for number of books
    printf("How many books are in your library?\n");
    scanf("%d", &num_books);

    // Allocate memory for library array using dynamic memory allocation
    library = (Book*)malloc(num_books * sizeof(Book));

    // Prompt user to enter book information for each book
    for (int i = 0; i < num_books; i++) {
        printf("\nEnter information for Book #%d\n", i+1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Author: ");
        scanf("%s", library[i].author);
        printf("Publisher: ");
        scanf("%s", library[i].publisher);
        printf("Year of publication: ");
        scanf("%d", &library[i].year);
        printf("Number of pages: ");
        scanf("%d", &library[i].pages);
    }

    // Prompt user for filename to save library to
    printf("\nEnter filename to save library to: ");
    scanf("%s", filename);

    // Open file to write library to
    FILE *fp;
    fp = fopen(filename, "w");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Write library to file
    fprintf(fp, "%d\n", num_books); // Write number of books to file
    for (int i = 0; i < num_books; i++) {
        fprintf(fp, "%s\n%s\n%s\n%d\n%d\n", library[i].title, library[i].author,
                library[i].publisher, library[i].year, library[i].pages);
    }
    printf("Library saved to %s\n", filename);

    // Close file
    fclose(fp);

    // Prompt user to enter filename to load library from
    printf("\nEnter filename to load library from: ");
    scanf("%s", filename);

    // Open file to read library from
    fp = fopen(filename, "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Read number of books in library from file
    fscanf(fp, "%d", &num_books);

    // Allocate memory for library array using dynamic memory allocation
    library = (Book*)realloc(library, num_books * sizeof(Book));

    // Read book information from file and add to library
    for (int i = 0; i < num_books; i++) {
        fscanf(fp, "%s%s%s%d%d", library[i].title, library[i].author, library[i].publisher,
               &library[i].year, &library[i].pages);
    }
    printf("Library loaded from %s\n", filename);

    // Close file
    fclose(fp);

    // Display library
    printf("\nLibrary:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Book #%d:\nTitle: %s\nAuthor: %s\nPublisher: %s\nYear of publication: %d\nNumber of pages: %d\n",
               i+1, library[i].title, library[i].author, library[i].publisher, library[i].year, library[i].pages);
    }
    
    // Free memory allocated for library
    free(library);

    return 0;
}