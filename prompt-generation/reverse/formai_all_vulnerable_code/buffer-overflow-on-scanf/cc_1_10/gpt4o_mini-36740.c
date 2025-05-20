//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50

// Structure to hold book information
typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int isBorrowed;
} Book;

// Function prototypes
void addBook(Book library[], int *count);
void removeBook(Book library[], int *count);
void displayBooks(Book library[], int count);
void borrowBook(Book library[], int count);
void returnBook(Book library[], int count);
void clearInputBuffer();

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int option;

    do {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        
        scanf("%d", &option);
        clearInputBuffer();

        switch (option) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                removeBook(library, &count);
                break;
            case 3:
                displayBooks(library, count);
                break;
            case 4:
                borrowBook(library, count);
                break;
            case 5:
                returnBook(library, count);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose a valid option.\n");
        }
    } while (option != 6);

    return 0;
}

void addBook(Book library[], int *count) {
    if (*count < MAX_BOOKS) {
        printf("Enter the title of the book: ");
        fgets(library[*count].title, MAX_TITLE_LEN, stdin);
        library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline
        printf("Enter the author of the book: ");
        fgets(library[*count].author, MAX_AUTHOR_LEN, stdin);
        library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline
        library[*count].isBorrowed = 0;  // available
        (*count)++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void removeBook(Book library[], int *count) {
    char title[MAX_TITLE_LEN];
    printf("Enter the title of the book to remove: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1]; // Shift books down
            }
            (*count)--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void displayBooks(Book library[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    
    printf("\n=== Available Books ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Author: %s, %s\n", 
               i + 1,
               library[i].title, 
               library[i].author, 
               library[i].isBorrowed ? "Borrowed" : "Available");
    }
}

void borrowBook(Book library[], int count) {
    char title[MAX_TITLE_LEN];
    printf("Enter the title of the book to borrow: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].isBorrowed) {
                printf("Sorry, this book is already borrowed.\n");
            } else {
                library[i].isBorrowed = 1;
                printf("You have successfully borrowed the book: %s\n", library[i].title);
            }
            return;
        }
    }
    printf("Book not found!\n");
}

void returnBook(Book library[], int count) {
    char title[MAX_TITLE_LEN];
    printf("Enter the title of the book to return: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (!library[i].isBorrowed) {
                printf("This book was not borrowed.\n");
            } else {
                library[i].isBorrowed = 0;
                printf("You have successfully returned the book: %s\n", library[i].title);
            }
            return;
        }
    }
    printf("Book not found!\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}