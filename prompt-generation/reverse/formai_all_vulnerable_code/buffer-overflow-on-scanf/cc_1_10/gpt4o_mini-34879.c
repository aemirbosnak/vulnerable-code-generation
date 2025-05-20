//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library* library) {
    library->count = 0;
}

void displayBooks(const Library* library) {
    if (library->count == 0) {
        printf("The library is empty. Scavenger, find more books!\n");
        return;
    }
    printf("Books found in the Crimson Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d: \"%s\" by %s, published in %d\n", 
                i + 1, 
                library->books[i].title, 
                library->books[i].author, 
                library->books[i].year);
    }
}

void addBook(Library* library) {
    if (library->count >= MAX_BOOKS) {
        printf("The library has no more space for new books!\n");
        return;
    }
    
    Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, MAX_TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove trailing newline

    printf("Enter the author of the book: ");
    fgets(newBook.author, MAX_AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove trailing newline

    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);
    getchar(); // Clear newline from buffer

    library->books[library->count] = newBook;
    library->count++;

    printf("Book added to the library: \"%s\" by %s, published in %d\n", 
            newBook.title, newBook.author, newBook.year);
}

void searchBook(const Library* library) {
    char title[MAX_TITLE_LEN];
    printf("Enter the title of the book you wish to find: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->books[i].title, title) == 0) {
            printf("Found: \"%s\" by %s, published in %d\n",
                    library->books[i].title, 
                    library->books[i].author, 
                    library->books[i].year);
            return;
        }
    }
    printf("Book not found. Venture deeper into the wasteland!\n");
}

void removeBook(Library* library) {
    char title[MAX_TITLE_LEN];
    printf("Enter the title of the book you wish to remove: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->books[i].title, title) == 0) {
            library->books[i] = library->books[library->count - 1];
            library->count--;
            printf("Book \"%s\" removed from the library. The wasteland now feels lighter.\n", title);
            return;
        }
    }
    printf("Book not found. Perhaps it's been burned in the flame of war...\n");
}

void displayMenu() {
    printf("\n--- Crimson Library Management System ---\n");
    printf("1. Display all books\n");
    printf("2. Add a new book\n");
    printf("3. Search for a book\n");
    printf("4. Remove a book\n");
    printf("5. Exit\n");
}

int main() {
    Library library;
    initializeLibrary(&library);
    
    int choice;
    do {
        displayMenu();
        printf("Choose an action: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                displayBooks(&library);
                break;
            case 2:
                addBook(&library);
                break;
            case 3:
                searchBook(&library);
                break;
            case 4:
                removeBook(&library);
                break;
            case 5:
                printf("Leaving the Crimson Library. May fortune favor your path.\n");
                break;
            default:
                printf("Invalid choice. Choose wisely, wanderer!\n");
        }
    } while (choice != 5);
    
    return 0;
}