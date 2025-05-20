//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: excited
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

void addBook(Book *books, int *bookCount);
void displayBooks(Book *books, int bookCount);
void searchBooks(Book *books, int bookCount);
void saveBooksToFile(Book *books, int bookCount);
void loadBooksFromFile(Book *books, int *bookCount);

int main() {
    Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    
    loadBooksFromFile(books, &bookCount);

    do {
        printf("\nWelcome to the Mini Library Management System!\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Search for a Book\n");
        printf("4. Save and Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                searchBooks(books, bookCount);
                break;
            case 4:
                saveBooksToFile(books, bookCount);
                printf("All books have been saved. Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(Book *books, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    printf("Enter book title: ");
    getchar(); // to consume any leftover newline character
    fgets(books[*bookCount].title, sizeof(books[*bookCount].title), stdin);
    books[*bookCount].title[strcspn(books[*bookCount].title, "\n")] = 0; // remove newline

    printf("Enter author name: ");
    fgets(books[*bookCount].author, sizeof(books[*bookCount].author), stdin);
    books[*bookCount].author[strcspn(books[*bookCount].author, "\n")] = 0; // remove newline

    printf("Enter publication year: ");
    scanf("%d", &books[*bookCount].year);

    (*bookCount)++;
    printf("Book added successfully!\n");
}

void displayBooks(Book *books, int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the library!\n");
        return;
    }
    printf("\n--- List of Books in the Library ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n\n", books[i].year);
    }
}

void searchBooks(Book *books, int bookCount) {
    char query[MAX_TITLE_LENGTH];
    printf("Enter the title or author to search: ");
    getchar(); // consume leftover newline
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0; // remove newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
            printf("Found Book %d:\n", i + 1);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n\n", books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found matching your query.\n");
    }
}

void saveBooksToFile(Book *books, int bookCount) {
    FILE *file = fopen("books.txt", "w");
    if (!file) {
        printf("Error opening file to save books!\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s\n%s\n%d\n", books[i].title, books[i].author, books[i].year);
    }
    fclose(file);
    printf("Books saved to file successfully!\n");
}

void loadBooksFromFile(Book *books, int *bookCount) {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("No previous data found. Starting with an empty library.\n");
        return;
    }
    while (fscanf(file, "%[^\n]\n%[^\n]\n%d\n", books[*bookCount].title, books[*bookCount].author,
                  &books[*bookCount].year) != EOF) {
        (*bookCount)++;
    }
    fclose(file);
    printf("Books loaded from file successfully!\n");
}