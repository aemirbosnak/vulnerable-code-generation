//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_PATH_LENGTH 260
#define MAX_BUFFER 4096

typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char path[MAX_PATH_LENGTH];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void load_library(const char *library_file) {
    FILE *file = fopen(library_file, "r");
    if (!file) {
        perror("Failed to open library file");
        return;
    }

    while (fscanf(file, "%99[^\n]\n%259[^\n]\n", library[book_count].title, library[book_count].path) != EOF) {
        book_count++;
    }
    fclose(file);
}

void display_books() {
    printf("\nAvailable Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d: %s\n", i + 1, library[i].title);
    }
}

void read_book(int book_index) {
    char buffer[MAX_BUFFER];
    FILE *file = fopen(library[book_index].path, "r");
    if (!file) {
        perror("Failed to open book file");
        return;
    }

    printf("\nReading %s...\n", library[book_index].title);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void search_in_book(int book_index, const char *query) {
    char buffer[MAX_BUFFER];
    FILE *file = fopen(library[book_index].path, "r");
    if (!file) {
        perror("Failed to open book file");
        return;
    }

    printf("\nSearching for \"%s\" in %s...\n", query, library[book_index].title);
    int line_number = 0;
    int found = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        line_number++;
        if (strstr(buffer, query)) {
            printf("Found at line %d: %s", line_number, buffer);
            found = 1;
        }
    }
    if (!found) {
        printf("No occurrences of \"%s\" found in %s.\n", query, library[book_index].title);
    }
    fclose(file);
}

int main() {
    load_library("library.txt");

    if (book_count == 0) {
        printf("No books found in the library.\n");
        return 1;
    }

    int choice, book_index;
    char search_query[100];

    while (1) {
        display_books();
        
        printf("\nChoose an option:\n");
        printf("1: Read a book\n");
        printf("2: Search in a book\n");
        printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book number to read: ");
                scanf("%d", &book_index);
                if (book_index < 1 || book_index > book_count) {
                    printf("Invalid book number.\n");
                } else {
                    read_book(book_index - 1);
                }
                break;

            case 2:
                printf("Enter book number to search: ");
                scanf("%d", &book_index);
                if (book_index < 1 || book_index > book_count) {
                    printf("Invalid book number.\n");
                } else {
                    printf("Enter search query: ");
                    scanf(" %[^\n]", search_query); // Read string with spaces
                    search_in_book(book_index - 1, search_query);
                }
                break;

            case 3:
                printf("Exiting the eBook reader...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}