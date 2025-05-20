//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100
#define DATABASE_FILE "books.txt"

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void saveBooks(Book books[], int count);
int loadBooks(Book books[]);

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Book Database Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void addBook() {
    Book book;
    FILE *file;

    file = fopen(DATABASE_FILE, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &book.id);
    getchar(); // To consume the newline character
    printf("Enter book title: ");
    fgets(book.title, MAX_TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline
    printf("Enter book author: ");
    fgets(book.author, MAX_AUTHOR_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline

    fprintf(file, "%d|%s|%s\n", book.id, book.title, book.author);
    fclose(file);
    printf("Book added successfully!\n");
}

void displayBooks() {
    Book books[MAX_BOOKS];
    int count = loadBooks(books);

    if (count == 0) {
        printf("No books available in the database.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
}

void searchBook() {
    char title[MAX_TITLE_LENGTH];
    Book books[MAX_BOOKS];
    int count = loadBooks(books);

    if (count == 0) {
        printf("No books available in the database.\n");
        return;
    }

    printf("Enter book title to search: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found: ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Book not found in the database.\n");
    }
}

void deleteBook() {
    int id;
    Book books[MAX_BOOKS];
    int count = loadBooks(books);

    if (count == 0) {
        printf("No books available in the database.\n");
        return;
    }

    printf("Enter book ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            deleted = 1;
            printf("Book with ID %d deleted.\n", id);
            continue; // Skip writing this book
        }
        fprintf(file, "%d|%s|%s\n", books[i].id, books[i].title, books[i].author);
    }
    fclose(file);
    
    if (!deleted) {
        printf("No book was found with ID %d.\n", id);
    }
}

int loadBooks(Book books[]) {
    FILE *file;
    char line[256];
    int count = 0;

    file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        return 0; // No books available
    }

    while (fgets(line, sizeof(line), file) && count < MAX_BOOKS) {
        sscanf(line, "%d|%[^|]|%[^|]", &books[count].id, books[count].title, books[count].author);
        count++;
    }
    fclose(file);
    return count;
}