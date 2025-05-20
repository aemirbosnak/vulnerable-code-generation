//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_WORD 20
#define MAX_BOOK_TITLE 100
#define MAX_BOOK_AUTHOR 50
#define MAX_BOOK_GENRE 20
#define MAX_BOOK_FILE_NAME 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    char author[MAX_BOOK_AUTHOR];
    char genre[MAX_BOOK_GENRE];
    int num_pages;
} Book;

typedef struct {
    char file_name[MAX_BOOK_FILE_NAME];
    Book book;
} Ebook;

void load_ebook(Ebook* ebook) {
    FILE* fp = fopen(ebook->file_name, "r");
    if (fp == NULL) {
        printf("Error loading ebook.\n");
        exit(1);
    }

    // Read title
    fgets(ebook->book.title, MAX_BOOK_TITLE, fp);
    ebook->book.title[strcspn(ebook->book.title, "\n")] = '\0';

    // Read author
    fgets(ebook->book.author, MAX_BOOK_AUTHOR, fp);
    ebook->book.author[strcspn(ebook->book.author, "\n")] = '\0';

    // Read genre
    fgets(ebook->book.genre, MAX_BOOK_GENRE, fp);
    ebook->book.genre[strcspn(ebook->book.genre, "\n")] = '\0';

    // Read number of pages
    fscanf(fp, "%d", &ebook->book.num_pages);

    fclose(fp);
}

void display_ebook(Ebook* ebook) {
    printf("Title: %s\n", ebook->book.title);
    printf("Author: %s\n", ebook->book.author);
    printf("Genre: %s\n", ebook->book.genre);
    printf("Number of pages: %d\n", ebook->book.num_pages);
}

int main() {
    Ebook my_ebook = {0};
    strcpy(my_ebook.file_name, "my_ebook.txt");

    load_ebook(&my_ebook);
    display_ebook(&my_ebook);

    return 0;
}