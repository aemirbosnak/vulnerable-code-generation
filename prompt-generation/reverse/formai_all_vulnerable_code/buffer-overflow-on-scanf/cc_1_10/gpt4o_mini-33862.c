//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook(Book *library, int *bookCount);
void displayBooks(const Book *library, int bookCount);
void searchBook(const Book *library, int bookCount);
void deleteBook(Book *library, int *bookCount);
void saveLibrary(const Book *library, int bookCount);
void loadLibrary(Book *library, int *bookCount);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    loadLibrary(library, &bookCount);

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Save Library\n");
        printf("6. Load Library\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                deleteBook(library, &bookCount);
                break;
            case 5:
                saveLibrary(library, bookCount);
                break;
            case 6:
                loadLibrary(library, &bookCount);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter title of the book: ");
    fgets(library[*bookCount].title, TITLE_LENGTH, stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = 0; // Remove newline
    printf("Enter author of the book: ");
    fgets(library[*bookCount].author, AUTHOR_LENGTH, stdin);
    library[*bookCount].author[strcspn(library[*bookCount].author, "\n")] = 0; // Remove newline
    printf("Enter year of publication: ");
    scanf("%d", &library[*bookCount].year);
    getchar(); // Consume the newline character

    (*bookCount)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

void searchBook(const Book *library, int bookCount) {
    char query[TITLE_LENGTH];
    printf("Enter title or author to search: ");
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching books found.\n");
    }
}

void deleteBook(Book *library, int *bookCount) {
    int index;
    printf("Enter the number of the book to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > *bookCount) {
        printf("Invalid book number!\n");
        return;
    }

    for (int i = index - 1; i < *bookCount - 1; i++) {
        library[i] = library[i + 1];
    }

    (*bookCount)--;
    printf("Book deleted successfully!\n");
}

void saveLibrary(const Book *library, int bookCount) {
    FILE *file = fopen("library.dat", "wb");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    fwrite(library, sizeof(Book), bookCount, file);
    fclose(file);
    printf("Library saved successfully!\n");
}

void loadLibrary(Book *library, int *bookCount) {
    FILE *file = fopen("library.dat", "rb");
    if (!file) {
        printf("No saved library found. Starting fresh.\n");
        *bookCount = 0;
        return;
    }
    *bookCount = fread(library, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    printf("Library loaded successfully! %d books loaded.\n", *bookCount);
}