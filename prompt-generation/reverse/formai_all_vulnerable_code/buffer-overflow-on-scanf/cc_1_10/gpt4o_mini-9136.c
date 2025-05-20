//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

// Function prototypes
void addBook(Book books[], int *count);
void displayBooks(const Book books[], int count);
void searchBook(const Book books[], int count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Book Database Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (count < MAX_BOOKS) {
                    addBook(books, &count);
                } else {
                    printf("Database is full! Cannot add more books.\n");
                }
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(Book books[], int *count) {
    printf("Enter book title: ");
    getchar(); // Clear the newline character from buffer
    fgets(books[*count].title, MAX_TITLE_LENGTH, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0; // Remove trailing newline

    printf("Enter author name: ");
    fgets(books[*count].author, MAX_AUTHOR_LENGTH, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0; // Remove trailing newline

    printf("Enter year of publication: ");
    scanf("%d", &books[*count].year);

    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book books[], int count) {
    if (count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\n--- List of Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
        printf("-----------------------\n");
    }
}

void searchBook(const Book books[], int count) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear the newline character from buffer
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in the database.\n");
    }
}