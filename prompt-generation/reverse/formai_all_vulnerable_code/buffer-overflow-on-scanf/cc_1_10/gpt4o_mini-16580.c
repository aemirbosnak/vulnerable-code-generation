//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Book
typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
} Book;

// Function prototypes
void addBook(FILE *file);
void viewBooks(FILE *file);
void searchBook(FILE *file);
void clearInputBuffer(void);

int main() {
    FILE *file;
    int choice;

    // Open the file in read/write binary mode
    file = fopen("library.dat", "a+b");
    if (file == NULL) {
        fprintf(stderr, "Could not open library.dat\n");
        return 1;
    }

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer to avoid issues with fgets

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                viewBooks(file);
                break;
            case 3:
                searchBook(file);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    fclose(file);
    return 0;
}

void addBook(FILE *file) {
    Book newBook;

    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    clearInputBuffer();

    printf("Enter book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    clearInputBuffer();

    // Write the new book record to the file
    fseek(file, 0, SEEK_END);  // Go to the end of the file
    fwrite(&newBook, sizeof(Book), 1, file);
    printf("Book added successfully!\n");
}

void viewBooks(FILE *file) {
    Book book;
    printf("\nBooks in Library:\n");
    printf("ID\tTitle\t\t\tAuthor\t\tYear\n");
    printf("---------------------------------------------------\n");

    rewind(file);  // Go to the start of the file
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("%d\t%-20s\t%-20s\t%d\n", book.id, book.title, book.author, book.year);
    }
}

void searchBook(FILE *file) {
    int searchId, found = 0;
    Book book;

    printf("Enter book ID to search: ");
    scanf("%d", &searchId);
    clearInputBuffer();

    rewind(file);  // Go to the start of the file
    while (fread(&book, sizeof(Book), 1, file)) {
        if (book.id == searchId) {
            printf("Book found:\n");
            printf("ID: %d\n", book.id);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Year: %d\n", book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with ID %d\n", searchId);
    }
}

void clearInputBuffer(void) {
    // Clear the input buffer to avoid issues with fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}