//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
} Book;

void addBook(FILE *file);
void showBooks(FILE *file);
void searchBooks(FILE *file);
void clearBuffer();

int main() {
    FILE *file;
    int choice;

    // Attempt to open books.txt for reading and writing, create if not exists
    file = fopen("books.txt", "a+");
    if (file == NULL) {
        printf("Could not open the file!\n");
        return 1;
    }

    do {
        printf("\n*** Book Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Show All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                showBooks(file);
                break;
            case 3:
                searchBooks(file);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    fclose(file);
    return 0;
}

void addBook(FILE *file) {
    Book newBook;

    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE, stdin);
    strtok(newBook.title, "\n"); // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    strtok(newBook.author, "\n"); // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    clearBuffer(); // To clear newline character after integer input

    fprintf(file, "%s;%s;%d\n", newBook.title, newBook.author, newBook.year);
    printf("Book added successfully!\n");
}

void showBooks(FILE *file) {
    rewind(file); // Go back to the beginning of the file
    Book book;

    printf("\n*** List of Books ***\n");
    while (fscanf(file, "%[^;];%[^;];%d\n", book.title, book.author, &book.year) != EOF) {
        printf("Title: %s\nAuthor: %s\nYear: %d\n\n", book.title, book.author, book.year);
    }
}

void searchBooks(FILE *file) {
    rewind(file);
    char searchTitle[MAX_TITLE];
    Book book;
    int found = 0;

    printf("Enter the title of the book to search: ");
    fgets(searchTitle, MAX_TITLE, stdin);
    strtok(searchTitle, "\n"); // Remove newline character

    while (fscanf(file, "%[^;];%[^;];%d\n", book.title, book.author, &book.year) != EOF) {
        if (strcasecmp(book.title, searchTitle) == 0) {
            printf("Book Found!\nTitle: %s\nAuthor: %s\nYear: %d\n", book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with the title: %s\n", searchTitle);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}