//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }
    
    Book newBook;
    newBook.id = *count + 1; // Book ID is 1-based index

    printf("Enter the title of the book: ");
    getchar(); // to consume the newline character left by previous input
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline

    printf("Enter the author of the book: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline

    printf("Enter the publication year: ");
    scanf("%d", &newBook.year);
    
    library[*count] = newBook; // Store the new book in the library
    (*count)++; // Increment the count of books
    printf("Book added successfully!\n");
}

void displayBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", library[i].id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n\n", library[i].year);
    }
}

void searchBookByTitle(Book *library, int count, const char *title) {
    int found = 0;
    printf("\nSearching for books by title '%s':\n", title);
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, title) != NULL) {
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n\n", library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with the title '%s'.\n", title);
    }
}

void searchBookByAuthor(Book *library, int count, const char *author) {
    int found = 0;
    printf("\nSearching for books by author '%s':\n", author);
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].author, author) != NULL) {
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n\n", library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by the author '%s'.\n", author);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Search Book by Author\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3: {
                char title[TITLE_LENGTH];
                printf("Enter the title to search: ");
                getchar(); // to consume the newline character
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                searchBookByTitle(library, count, title);
                break;
            }
            case 4: {
                char author[AUTHOR_LENGTH];
                printf("Enter the author to search: ");
                getchar(); // to consume the newline character
                fgets(author, AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline
                searchBookByAuthor(library, count, author);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}