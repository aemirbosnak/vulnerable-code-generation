//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
} Book;

void addBook(Book *library, int *count);
void displayBooks(const Book *library, int count);
void searchBook(const Book *library, int count);

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    printf("📚 Welcome to the Library Management System! 📚\n");
    printf("What would you like to do today?\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from buffer

        switch(choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                printf("Thank you for using the Library Management System! Goodbye! 👋\n");
                break;
            default:
                printf("🚫 Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a book
void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("😱 Library is full! Can't add more books.\n");
        return;
    }
    
    printf("Enter book ID: ");
    scanf("%d", &library[*count].id);
    getchar(); // Clear the newline character from buffer

    printf("Enter book title: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author's name: ");
    fgets(library[*count].author, AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline

    (*count)++;
    printf("🎉 Book added successfully! 🎉\n");
}

// Function to display all books
void displayBooks(const Book *library, int count) {
    if (count == 0) {
        printf("📖 No books available in the library.\n");
        return;
    }

    printf("\n📚 List of Books in the Library 📚\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book by title
void searchBook(const Book *library, int count) {
    if (count == 0) {
        printf("🔍 No books to search in the library.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book you want to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("📖 Book Found! ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("🚫 Book not found in the library!\n");
    }
}