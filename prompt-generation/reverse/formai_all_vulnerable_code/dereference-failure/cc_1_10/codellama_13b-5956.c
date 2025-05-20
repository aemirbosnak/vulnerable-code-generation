//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *title;
    char *author;
    char *genre;
    char *description;
    int pages;
} Book;

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Description: %s\n", book->description);
    printf("Pages: %d\n", book->pages);
}

int main() {
    Book *books = (Book *)malloc(sizeof(Book) * 3);

    books[0].title = "The Great Gatsby";
    books[0].author = "F. Scott Fitzgerald";
    books[0].genre = "Fiction";
    books[0].description = "A novel set in the Roaring Twenties that follows the life of Jay Gatsby, a man who tries to win back his lost love, Daisy Buchanan.";
    books[0].pages = 224;

    books[1].title = "To Kill a Mockingbird";
    books[1].author = "Harper Lee";
    books[1].genre = "Fiction";
    books[1].description = "A novel about racial injustice and the loss of innocence in a small Alabama town during the Great Depression.";
    books[1].pages = 304;

    books[2].title = "1984";
    books[2].author = "George Orwell";
    books[2].genre = "Science Fiction";
    books[2].description = "A dystopian novel set in a totalitarian future where the government exercises total control over its citizens.";
    books[2].pages = 320;

    for (int i = 0; i < 3; i++) {
        print_book(&books[i]);
        printf("\n");
    }

    free(books);

    return 0;
}