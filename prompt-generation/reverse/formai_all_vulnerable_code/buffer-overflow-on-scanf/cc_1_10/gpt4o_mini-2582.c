//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int is_checked_out;
} Book;

void addBook(Book library[], int *count);
void displayBooks(const Book library[], int count);
void checkOutBook(Book library[], int count);
void returnBook(Book library[], int count);

int main() {
    Book library[MAX_BOOKS];
    int book_count = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Check Out Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook(library, &book_count);
                break;
            case 2:
                displayBooks(library, book_count);
                break;
            case 3:
                checkOutBook(library, book_count);
                break;
            case 4:
                returnBook(library, book_count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    getchar(); // Clear input buffer
    fgets(library[*count].title, MAX_TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(library[*count].author, MAX_AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline

    library[*count].is_checked_out = 0; // Book is not checked out
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s [%s]\n", 
               i + 1, 
               library[i].title, 
               library[i].author, 
               library[i].is_checked_out ? "Checked Out" : "Available");
    }
}

void checkOutBook(Book library[], int count) {
    if (count == 0) {
        printf("No books available to check out.\n");
        return;
    }

    displayBooks(library, count);
    int index;
    printf("Enter the number of the book to check out: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid book number.\n");
        return;
    }

    if (library[index - 1].is_checked_out) {
        printf("Book is already checked out!\n");
    } else {
        library[index - 1].is_checked_out = 1;
        printf("You have checked out '%s'.\n", library[index - 1].title);
    }
}

void returnBook(Book library[], int count) {
    if (count == 0) {
        printf("No books available for return.\n");
        return;
    }

    displayBooks(library, count);
    int index;
    printf("Enter the number of the book to return: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid book number.\n");
        return;
    }

    if (!library[index - 1].is_checked_out) {
        printf("Book is not checked out!\n");
    } else {
        library[index - 1].is_checked_out = 0;
        printf("You have returned '%s'. Thank you!\n", library[index - 1].title);
    }
}