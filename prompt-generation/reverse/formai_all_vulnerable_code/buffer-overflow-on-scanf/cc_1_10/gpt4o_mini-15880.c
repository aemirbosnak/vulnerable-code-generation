//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define FILE_NAME "library.dat"

// Structure to hold book information
typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

// Function prototypes
void addBook();
void listBooks();
void searchBook();
void deleteBook();
void saveToFile(Book* books, int count);
int loadFromFile(Book* books);

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. List Books\n");
        printf("3. Search a Book\n");
        printf("4. Delete a Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

void addBook() {
    Book book;
    FILE* file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter Book Title: ");
    getchar(); // clear newline from previous input
    fgets(book.title, TITLE_LEN, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline

    printf("Enter Author Name: ");
    fgets(book.author, AUTHOR_LEN, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline

    printf("Enter Year of Publication: ");
    scanf("%d", &book.year);

    // Write book to file
    fwrite(&book, sizeof(Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void listBooks() {
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);
    
    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", books[i].title, books[i].author, books[i].year);
    }
}

void searchBook() {
    char searchTitle[TITLE_LEN];
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    printf("Enter the title of the book to search: ");
    getchar(); // clear newline
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, searchTitle) == 0) { // case insensitive comparison
            printf("Book found! Title: %s, Author: %s, Year: %d\n", books[i].title, books[i].author, books[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook() {
    char deleteTitle[TITLE_LEN];
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    printf("Enter the title of the book to delete: ");
    getchar(); // clear newline
    fgets(deleteTitle, TITLE_LEN, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    FILE* file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, deleteTitle) != 0) {
            fwrite(&books[i], sizeof(Book), 1, file);
        } else {
            found = 1;
        }
    }
    fclose(file);

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found to delete.\n");
    }
}

void saveToFile(Book* books, int count) {
    FILE* file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(books, sizeof(Book), count, file);
        fclose(file);
    }
}

int loadFromFile(Book* books) {
    FILE* file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        return 0; // If file doesn't exist, return 0
    }

    int count = fread(books, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    return count;
}