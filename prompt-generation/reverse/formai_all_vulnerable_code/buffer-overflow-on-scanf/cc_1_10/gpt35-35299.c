//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

// define datatype for book
typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char path[50];
} Book;

Book books[MAX_BOOKS]; // create an array of books
int bookCount = 0; // keep track of number of books in array

void addBook() {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char path[50];

    // get title and author from user input
    printf("Enter title: ");
    scanf("%s", title);
    printf("Enter author: ");
    scanf("%s", author);
    printf("Enter file path: ");
    scanf("%s", path);
    
    // check if book array is full
    if (bookCount >= MAX_BOOKS) {
        printf("Bookshelf full! Cannot add more books\n");
        return;
    }

    // create a new book and add it to the book array
    Book newBook;
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
    strcpy(newBook.path, path);
    books[bookCount++] = newBook;
    printf("%s by %s added to bookshelf successfully!\n", title, author);
}

void listBooks() {
    if (bookCount == 0) {
        printf("No books found on bookshelf\n");
        return;
    }

    printf("%-30s %-20s %s\n", "Title", "Author", "Path");
    for (int i = 0; i < bookCount; i++) {
        printf("%-30s %-20s %s\n", books[i].title, books[i].author, books[i].path);
    }
}

bool isBookFound(char* title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return true;
        }
    }
    return false;
}

void readBook() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter title of book to read: ");
    scanf("%s", title);

    // check if book exists
    if (!isBookFound(title)) {
        printf("%s not found on bookshelf\n", title);
        return;
    }

    // open book file for reading
    FILE* bookFile;
    char filePath[50];
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            strcpy(filePath, books[i].path);
            break;
        }
    }
    bookFile = fopen(filePath, "r");
    if (bookFile == NULL) {
        printf("Error opening file\n");
        return;
    }

    // read contents of book and display on console
    char c;
    while ((c = fgetc(bookFile)) != EOF) {
        printf("%c", c);
    }

    fclose(bookFile);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add book\n2. List books\n3. Read book\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                readBook();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}