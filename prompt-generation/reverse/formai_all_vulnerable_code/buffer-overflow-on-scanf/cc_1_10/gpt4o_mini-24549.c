//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
    int is_borrowed;
} Book;

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add a Book\n");
    printf("2. Display Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter Year of Publication: ");
    scanf("%d", &newBook.year);
    
    newBook.is_borrowed = 0; // Book is not borrowed initially
    books[*count] = newBook;
    (*count)++;
    printf("Book added successfully.\n");
}

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Author: %s, Year: %d, Status: %s\n", 
               i + 1, 
               books[i].title, 
               books[i].author, 
               books[i].year, 
               books[i].is_borrowed ? "Borrowed" : "Available");
    }
}

void borrowBook(Book books[], int count) {
    int index;
    printf("Enter the index of the book you want to borrow: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid index!\n");
        return;
    }
    
    if (books[index - 1].is_borrowed) {
        printf("The book '%s' is already borrowed.\n", books[index - 1].title);
    } else {
        books[index - 1].is_borrowed = 1; // Mark as borrowed
        printf("You have borrowed the book '%s'.\n", books[index - 1].title);
    }
}

void returnBook(Book books[], int count) {
    int index;
    printf("Enter the index of the book you want to return: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid index!\n");
        return;
    }
    
    if (!books[index - 1].is_borrowed) {
        printf("The book '%s' is not borrowed.\n", books[index - 1].title);
    } else {
        books[index - 1].is_borrowed = 0; // Mark as available
        printf("You have returned the book '%s'.\n", books[index - 1].title);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                borrowBook(books, count);
                break;
            case 4:
                returnBook(books, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}