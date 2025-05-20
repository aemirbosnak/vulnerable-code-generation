//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_CONTENT_LENGTH 5000
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

int bookCount = 0;
Book library[MAX_BOOKS];

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter book author: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove trailing newline

    printf("Enter book content (end with 'END'):\n");
    char buffer[MAX_CONTENT_LENGTH];
    int contentSize = 0;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "END", 3) == 0) {
            break;
        }
        if (contentSize + strlen(buffer) < MAX_CONTENT_LENGTH) {
            strcat(newBook.content, buffer);
            contentSize += strlen(buffer);
        } else {
            printf("Content too long, truncating...\n");
            break;
        }
    }

    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Content:\n%s\n", library[i].content);
        printf("------------------------------\n");
    }
}

void searchBookByTitle() {
    char titleToSearch[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(titleToSearch, MAX_TITLE_LENGTH, stdin);
    titleToSearch[strcspn(titleToSearch, "\n")] = '\0'; // Remove trailing newline
    
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, titleToSearch) == 0) {
            printf("Found Book:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Content:\n%s\n", library[i].content);
            return;
        }
    }
    
    printf("No book found with the title '%s'.\n", titleToSearch);
}

void menu() {
    while (1) {
        printf("\n--- E-Book Reader Menu ---\n");
        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Search for a book by title\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline after number input
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBookByTitle();
                break;
            case 4:
                printf("Exiting program...\n");
                return;
            default:
                printf("Invalid option, please choose again.\n");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}