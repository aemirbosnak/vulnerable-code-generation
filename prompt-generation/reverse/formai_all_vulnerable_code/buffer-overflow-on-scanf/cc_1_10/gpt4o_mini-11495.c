//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50
#define FILENAME "books.dat"

typedef struct Book {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char content[1000];
} Book;

void displayMainMenu() {
    printf("\n--- Cyberpunk E-Book Reader ---\n");
    printf("1. Load Books\n");
    printf("2. List Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void loadBooks(Book *books, int *bookCount) {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("No books found! Please add books first.\n");
        return;
    }
    
    *bookCount = fread(books, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    printf("%d books loaded.\n", *bookCount);
}

void listBooks(Book *books, int bookCount) {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }
    
    printf("\nAvailable Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s\n", i + 1, books[i].title, books[i].author);
    }
}

void readBook(Book *books, int bookCount) {
    if (bookCount == 0) {
        printf("No books available to read.\n");
        return;
    }
    
    int choice;
    printf("Enter the book number to read: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > bookCount) {
        printf("Invalid choice. Please select a valid book number.\n");
        return;
    }
    
    Book selectedBook = books[choice - 1];
    
    printf("\nReading \"%s\" by %s...\n", selectedBook.title, selectedBook.author);
    printf("-----\n");
    printf("%s\n", selectedBook.content);
    printf("-----\n");
}

int main() {
    Book books[MAX_BOOKS];
    int bookCount = 0;
    
    while (1) {
        displayMainMenu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                loadBooks(books, &bookCount);
                break;
            case 2: 
                listBooks(books, bookCount);
                break;
            case 3: 
                readBook(books, bookCount);
                break;
            case 4: 
                printf("Disconnecting from the network...\n");
                sleep(1);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}