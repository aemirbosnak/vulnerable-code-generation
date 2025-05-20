//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    char* author;
    char* genre;
    int pages;
} Book;

void read_file(FILE* file, Book* book) {
    char line[1024];
    char* delimiter = ":";
    char* token;

    fgets(line, sizeof(line), file);
    sscanf(line, "Title: %ms", &book->title);

    fgets(line, sizeof(line), file);
    sscanf(line, "Author: %ms", &book->author);

    fgets(line, sizeof(line), file);
    sscanf(line, "Genre: %ms", &book->genre);

    fgets(line, sizeof(line), file);
    sscanf(line, "Pages: %d", &book->pages);
}

void print_book(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Pages: %d\n", book->pages);
}

int main() {
    FILE* file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Book book;
    read_file(file, &book);

    print_book(&book);

    fclose(file);
    return 0;
}