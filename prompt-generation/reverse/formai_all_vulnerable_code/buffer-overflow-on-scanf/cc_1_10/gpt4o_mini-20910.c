//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Function prototypes
void initLibrary(Library *lib);
void addBook(Library *lib, const char *title, const char *author, int year);
void listBooks(const Library *lib);
void searchBookByTitle(const Library *lib, const char *title);
void searchBookByAuthor(const Library *lib, const char *author);
void sortBooksByYear(Library *lib);

int main() {
    Library myLibrary;
    initLibrary(&myLibrary);

    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Search Book by Author\n");
        printf("5. Sort Books by Year\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';  // Remove newline character

                printf("Enter book author: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0';  // Remove newline character

                printf("Enter publication year: ");
                scanf("%d", &year);
                getchar();  // Consume newline character

                addBook(&myLibrary, title, author, year);
                break;
            case 2:
                listBooks(&myLibrary);
                break;
            case 3:
                printf("Enter book title to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';  // Remove newline character
                searchBookByTitle(&myLibrary, title);
                break;
            case 4:
                printf("Enter author name to search: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0';  // Remove newline character
                searchBookByAuthor(&myLibrary, author);
                break;
            case 5:
                sortBooksByYear(&myLibrary);
                printf("Books sorted by year.\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initLibrary(Library *lib) {
    lib->count = 0;
}

void addBook(Library *lib, const char *title, const char *author, int year) {
    if (lib->count < MAX_BOOKS) {
        strncpy(lib->books[lib->count].title, title, MAX_TITLE_LENGTH);
        strncpy(lib->books[lib->count].author, author, MAX_AUTHOR_LENGTH);
        lib->books[lib->count].year = year;
        lib->count++;
        printf("Book \"%s\" added to the library.\n", title);
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void listBooks(const Library *lib) {
    if (lib->count == 0) {
        printf("The library is empty.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < lib->count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, lib->books[i].title, lib->books[i].author, lib->books[i].year);
    }
}

void searchBookByTitle(const Library *lib, const char *title) {
    printf("Searching for book titled \"%s\"...\n", title);
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->books[i].title, title) == 0) {
            printf("Found: %s by %s (%d)\n", lib->books[i].title, lib->books[i].author, lib->books[i].year);
            return;
        }
    }
    printf("No book found with title \"%s\".\n", title);
}

void searchBookByAuthor(const Library *lib, const char *author) {
    printf("Searching for books by author \"%s\"...\n", author);
    int found = 0;
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->books[i].author, author) == 0) {
            printf("Found: %s by %s (%d)\n", lib->books[i].title, lib->books[i].author, lib->books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by author \"%s\".\n", author);
    }
}

void sortBooksByYear(Library *lib) {
    for (int i = 0; i < lib->count - 1; i++) {
        for (int j = 0; j < lib->count - i - 1; j++) {
            if (lib->books[j].year > lib->books[j + 1].year) {
                Book temp = lib->books[j];
                lib->books[j] = lib->books[j + 1];
                lib->books[j + 1] = temp;
            }
        }
    }
}