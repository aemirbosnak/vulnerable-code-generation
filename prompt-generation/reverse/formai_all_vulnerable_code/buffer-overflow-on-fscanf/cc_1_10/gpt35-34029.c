//FormAI DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50], author[50], publisher[50];
    int year, pages;
};

void displayBook(struct Book *book) {
    printf("\nTitle: %s", book->title);
    printf("\nAuthor: %s", book->author);
    printf("\nPublisher: %s", book->publisher);
    printf("\nYear: %d", book->year);
    printf("\nPages: %d\n", book->pages);
}

int main() {
    FILE *filePointer;
    struct Book *book;
    int numBooks;

    // Open the file for reading
    filePointer = fopen("ebooks.txt", "r");
    if (filePointer == NULL) {
        printf("Error! Could not open file.\n");
        exit(1);
    }

    // Read the number of books from the file
    fscanf(filePointer, "%d", &numBooks);

    // Allocate memory for the books
    book = (struct Book*) malloc(numBooks * sizeof(struct Book));

    // Read the books from the file
    for (int i = 0; i < numBooks; i++) {
        fscanf(filePointer, "%s", book[i].title);
        fscanf(filePointer, "%s", book[i].author);
        fscanf(filePointer, "%s", book[i].publisher);
        fscanf(filePointer, "%d", &book[i].year);
        fscanf(filePointer, "%d", &book[i].pages);
    }

    // Close the file
    fclose(filePointer);

    // Display the books
    for (int i = 0; i < numBooks; i++) {
        displayBook(&book[i]);
    }

    // Free the memory
    free(book);

    return 0;
}