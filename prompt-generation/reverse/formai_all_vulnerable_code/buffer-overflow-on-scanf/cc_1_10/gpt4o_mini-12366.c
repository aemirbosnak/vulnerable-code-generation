//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

void addBook(Book *books, int *count);
void displayBooks(const Book *books, int count);
void searchBook(const Book *books, int count);
void clearBuffer();

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\nSimple Book Database System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline left by scanf

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(Book *books, int *count) {
    Book newBook;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    clearBuffer(); // Clear newline left by scanf

    books[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book *books, int count) {
    if (count == 0) {
        printf("No books found in the database.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", books[i].title);
        printf("  Author: %s\n", books[i].author);
        printf("  Year: %d\n", books[i].year);
    }
}

void searchBook(const Book *books, int count) {
    char searchTitle[TITLE_LEN];
    int found = 0;

    printf("Enter title or author to search: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, searchTitle) != NULL || 
            strstr(books[i].author, searchTitle) != NULL) {
            printf("Found Book %d:\n", i + 1);
            printf("  Title: %s\n", books[i].title);
            printf("  Author: %s\n", books[i].author);
            printf("  Year: %d\n", books[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching books found.\n");
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}