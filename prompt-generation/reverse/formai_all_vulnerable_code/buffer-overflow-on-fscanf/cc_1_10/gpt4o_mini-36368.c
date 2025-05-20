//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char *content; // Dynamic memory for the book content
    int lines;
} Book;

void displayMenu() {
    printf("Welcome to the C eBook Reader!\n");
    printf("1. Load a book\n");
    printf("2. Show book content\n");
    printf("3. Quit\n");
}

int loadBook(Book *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file: %s\n", filename);
        return -1;
    }

    fscanf(file, "%[^\n]\n", book->title);
    fscanf(file, "%[^\n]\n", book->author);

    book->content = NULL;
    book->lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        book->lines++;
        book->content = realloc(book->content, book->lines * MAX_LINE_LENGTH);
        if (book->content == NULL) {
            printf("Memory allocation failed!\n");
            fclose(file);
            return -1;
        }
        strcat(book->content, line);
    }
    fclose(file);
    printf("Book '%s' by '%s' loaded successfully!\n", book->title, book->author);
    return 0;
}

void displayBookContent(Book *book) {
    if (book->content == NULL) {
        printf("No book loaded.\n");
        return;
    }
    printf("\n--- %s by %s ---\n", book->title, book->author);
    printf("%s", book->content);
    printf("\n------------------------\n");
}

void cleanupBook(Book *book) {
    free(book->content);
    book->content = NULL;
}

int main() {
    Book books[MAX_BOOKS];
    int choice;
    char filename[MAX_LINE_LENGTH];

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character leftover by scanf

        switch (choice) {
            case 1:
                printf("Enter filename to load: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the trailing newline 

                if (loadBook(&books[0], filename) == 0) {
                    // Book loaded successfully
                }
                break;
            case 2:
                displayBookContent(&books[0]);
                break;
            case 3:
                printf("Thank you for using the C eBook Reader! Goodbye!\n");
                cleanupBook(&books[0]);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}