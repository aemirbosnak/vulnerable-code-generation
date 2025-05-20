//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 1024

typedef struct {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} EbookLibrary;

void initializeLibrary(EbookLibrary* library) {
    library->count = 0;
}

int addBook(EbookLibrary* library, const char* title, const char* content) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return -1;
    }
    
    strncpy(library->books[library->count].title, title, MAX_TITLE_LEN);
    strncpy(library->books[library->count].content, content, MAX_CONTENT_LEN);
    library->count++;
    printf("Book '%s' added successfully.\n", title);
    return 0;
}

void listBooks(const EbookLibrary* library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("Books in the library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s\n", i + 1, library->books[i].title);
    }
}

void readBook(const EbookLibrary* library, int index) {
    if (index < 1 || index > library->count) {
        printf("Invalid book number.\n");
        return;
    }
    
    printf("\nReading Book: %s\n", library->books[index - 1].title);
    printf("%s\n", library->books[index - 1].content);
}

void displayMenu() {
    printf("\n=== Ebook Reader Menu ===\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
}

int main() {
    EbookLibrary library;
    initializeLibrary(&library);
    
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline
        
        if (choice == 1) {
            char title[MAX_TITLE_LEN];
            char content[MAX_CONTENT_LEN];

            printf("Enter book title: ");
            fgets(title, MAX_TITLE_LEN, stdin);
            title[strcspn(title, "\n")] = 0; // remove newline character
            
            printf("Enter book content: ");
            fgets(content, MAX_CONTENT_LEN, stdin);
            content[strcspn(content, "\n")] = 0; // remove newline character

            addBook(&library, title, content);
        } else if (choice == 2) {
            listBooks(&library);
        } else if (choice == 3) {
            int bookNumber;
            printf("Enter book number to read: ");
            scanf("%d", &bookNumber);
            readBook(&library, bookNumber);
        } else if (choice == 4) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}