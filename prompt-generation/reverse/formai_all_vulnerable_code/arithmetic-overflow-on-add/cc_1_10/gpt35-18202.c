//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 500
#define PAGE_SIZE 25

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content;
} Book;

Book books[MAX_BOOKS];

// function declarations
void load_books();
void save_books();
void print_books();
void read_book();

int main() {
    // load books from file
    load_books();

    // print book list
    print_books();

    // prompt user to select a book to read
    read_book();

    // save books to file
    save_books();

    return 0;
}

void load_books() {
    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error loading books\n");
        return;
    }

    int book_count = 0;
    while (book_count < MAX_BOOKS && !feof(file)) {
        Book book;
        fgets(book.title, MAX_TITLE_LENGTH, file);
        fgets(book.author, MAX_AUTHOR_LENGTH, file);
        fscanf(file, "%d\n", &book.pages);
        
        book.content = malloc(book.pages * PAGE_SIZE + 1);
        fgets(book.content, book.pages * PAGE_SIZE + 1, file);

        books[book_count] = book;
        book_count++;
    }

    fclose(file);
}

void save_books() {
    FILE* file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Error saving books\n");
        return;
    }

    for (int i = 0; i < MAX_BOOKS; i++) {
        Book book = books[i];
        if (strlen(book.title) == 0) {
            continue;
        }

        fprintf(file, "%s", book.title);
        fprintf(file, "%s", book.author);
        fprintf(file, "%d\n", book.pages);
        fprintf(file, "%s", book.content);

        free(book.content);
    }

    fclose(file);
}

void print_books() {
    printf("Available books:\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        Book book = books[i];
        if (strlen(book.title) == 0) {
            printf("%d. --EMPTY--\n", i + 1);
            continue;
        }

        printf("%d. %s by %s\n", i + 1, book.title, book.author);
    }
}

void read_book() {
    printf("Enter the number of the book you want to read: ");
    int book_num;
    scanf("%d", &book_num);
    getchar(); // consume newline

    if (book_num < 1 || book_num > MAX_BOOKS) {
        printf("Invalid book number\n");
        return;
    }

    Book book = books[book_num - 1];
    if (strlen(book.title) == 0) {
        printf("That book doesn't exist\n");
        return;
    }

    printf("Reading %s by %s\n", book.title, book.author);
    getchar(); // consume newline

    int num_pages = (book.pages + PAGE_SIZE - 1) / PAGE_SIZE; // round up
    for (int i = 0; i < num_pages; i++) {
        printf("Page %d\n", i + 1);
        int start = i * PAGE_SIZE;
        int end = start + PAGE_SIZE;
        if (end > book.pages) {
            end = book.pages;
        }
        fwrite(book.content + start, end - start, 1, stdout);
        printf("\n");
        getchar(); // wait for user input
    }
}