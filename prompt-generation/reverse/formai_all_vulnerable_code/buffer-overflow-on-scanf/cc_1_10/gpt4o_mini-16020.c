//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOK_TITLE_LENGTH 100

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char **lines;
    int total_lines;
} eBook;

// Function prototypes
eBook *load_eBook(const char *filename);
void display_book(eBook *book);
void search_keyword(eBook *book, const char *keyword);
void free_book(eBook *book);

int main() {
    char filename[100];
    eBook *book;
    char option;
    char keyword[MAX_BOOK_TITLE_LENGTH];

    printf("Welcome to the Simple eBook Reader!\n");
    printf("Enter the name of the eBook (with .txt extension): ");
    scanf("%s", filename);

    book = load_eBook(filename);
    if (!book) {
        printf("Failed to load the book. Please check the filename.\n");
        return 1;
    }

    do {
        printf("\nOptions:\n");
        printf("1. Display eBook content\n");
        printf("2. Search for a keyword\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                display_book(book);
                break;
            case '2':
                printf("Enter keyword to search: ");
                scanf("%s", keyword);
                search_keyword(book, keyword);
                break;
            case '3':
                printf("Exiting the eBook Reader. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != '3');

    free_book(book);
    return 0;
}

eBook *load_eBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    eBook *book = malloc(sizeof(eBook));
    if (!book) {
        fclose(file);
        return NULL;
    }

    strncpy(book->title, filename, MAX_BOOK_TITLE_LENGTH);
    book->lines = malloc(sizeof(char*) * 1000); // Allocate memory for up to 1000 lines
    book->total_lines = 0;

    while (fgets(book->lines[book->total_lines], MAX_LINE_LENGTH, file)) {
        book->lines[book->total_lines][strcspn(book->lines[book->total_lines], "\n")] = 0;  // Remove the newline
        book->total_lines++;
    }

    fclose(file);
    return book;
}

void display_book(eBook *book) {
    printf("\nDisplaying eBook: %s\n", book->title);
    for (int i = 0; i < book->total_lines; i++) {
        printf("%s\n", book->lines[i]);
    }
}

void search_keyword(eBook *book, const char *keyword) {
    printf("Searching for keyword: %s\n", keyword);
    int found = 0;

    for (int i = 0; i < book->total_lines; i++) {
        if (strstr(book->lines[i], keyword) != NULL) {
            printf("Found in line %d: %s\n", i + 1, book->lines[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No occurrences found for keyword: %s\n", keyword);
    }
}

void free_book(eBook *book) {
    for (int i = 0; i < book->total_lines; i++) {
        free(book->lines[i]); // Free each line
    }
    free(book->lines);
    free(book);
}