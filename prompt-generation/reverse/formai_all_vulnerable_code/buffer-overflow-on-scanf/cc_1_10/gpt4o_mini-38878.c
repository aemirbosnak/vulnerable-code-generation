//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define FILENAME "books.dat"

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void saveBooksToFile();
void loadBooksFromFile();
void clearInputBuffer();

Book books[MAX_BOOKS];
int bookCount = 0;

int main() {
    int choice;

    loadBooksFromFile();

    do {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

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
                saveBooksToFile();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Cannot add more books. Book limit reached.\n");
        return;
    }
    
    printf("Enter book title: ");
    fgets(books[bookCount].title, TITLE_LENGTH, stdin);
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(books[bookCount].author, AUTHOR_LENGTH, stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &books[bookCount].year);
    clearInputBuffer();

    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books found.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d: \n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
    }
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    int found = 0;

    printf("Enter the title of the book to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < bookCount; i++) {
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
        printf("Book not found.\n");
    }
}

void deleteBook() {
    char deleteTitle[TITLE_LENGTH];
    int found = 0;

    printf("Enter the title of the book to delete: ");
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(books[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void saveBooksToFile() {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(books, sizeof(Book), bookCount, file);
    fclose(file);
    printf("Books saved to file.\n");
}

void loadBooksFromFile() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Error opening file for reading. Starting with empty book list.\n");
        return;
    }

    bookCount = fread(books, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    printf("Books loaded from file.\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}