//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_PATH_LENGTH 255
#define BUFFER_SIZE 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char path[MAX_PATH_LENGTH];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library *library) {
    library->count = 0;
}

void addBook(Library *library, const char *title, const char *path) {
    if (library->count < MAX_BOOKS) {
        strncpy(library->books[library->count].title, title, MAX_TITLE_LENGTH);
        strncpy(library->books[library->count].path, path, MAX_PATH_LENGTH);
        library->count++;
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void listBooks(const Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Your Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s\n", i + 1, library->books[i].title);
    }
}

void readBook(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Unable to open book: %s\n", path);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void getBookFromUser(Library *library) {
    char title[MAX_TITLE_LENGTH];
    char path[MAX_PATH_LENGTH];
    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    printf("Enter file path: ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = 0; // Remove trailing newline

    addBook(library, title, path);
}

void displayMenu() {
    printf("E-Book Reader\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Library library;
    initializeLibrary(&library);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf
        switch (choice) {
        case 1:
            getBookFromUser(&library);
            break;
        case 2:
            listBooks(&library);
            break;
        case 3:
            if (library.count == 0) {
                printf("No books available to read.\n");
            } else {
                int index;
                printf("Select a book by number to read: ");
                scanf("%d", &index);
                getchar(); // To consume the newline character left by scanf
                if (index > 0 && index <= library.count) {
                    readBook(library.books[index - 1].path);
                } else {
                    printf("Invalid selection.\n");
                }
            }
            break;
        case 4:
            printf("Exiting E-book Reader. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}