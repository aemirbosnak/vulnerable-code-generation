//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BOOKS 100
#define MAX_TITLE 256
#define MAX_AUTHOR 256

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int pages;
    char *content;
} Book;

void loadBook(Book *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read title
    fgets(book->title, MAX_TITLE, file);
    book->title[strcspn(book->title, "\n")] = 0; // Remove newline

    // Read author
    fgets(book->author, MAX_AUTHOR, file);
    book->author[strcspn(book->author, "\n")] = 0; // Remove newline

    // Read pages
    fscanf(file, "%d\n", &book->pages);

    // Read content
    book->content = malloc(1024 * book->pages); // Rough estimate
    if (book->content == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    fread(book->content, sizeof(char), 1024 * book->pages, file);

    fclose(file);
}

void displayBook(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("\nContents:\n%s\n", book->content);
}

void freeBook(Book *book) {
    free(book->content);
}

void menu() {
    printf("Welcome to the Puzzling Ebook Reader!\n");
    printf("======================================\n");
    printf("1. Load a book\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Book book = {0};
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: {
                char filename[256];
                printf("Enter the book filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline

                loadBook(&book, filename);
                displayBook(&book);
                freeBook(&book);
                break;
            }
            case 2: {
                printf("Exiting the ebook reader. Goodbye!\n");
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}