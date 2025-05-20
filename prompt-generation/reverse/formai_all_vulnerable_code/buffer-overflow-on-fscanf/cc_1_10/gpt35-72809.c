//FormAI DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

void readBooksFromFile(Book[], int*);
void addNewBook(Book[], int*);
void displayBooks(Book[], int);
void searchBookByAuthor(Book[], int);
void searchBookByTitle(Book[], int);
void menu();

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;
    readBooksFromFile(books, &numBooks);
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: displayBooks(books, numBooks);
                    break;
            case 2: addNewBook(books, &numBooks);
                    break;
            case 3: searchBookByTitle(books, numBooks);
                    break;
            case 4: searchBookByAuthor(books, numBooks);
                    break;
            case 5: printf("Exiting program.\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}

void readBooksFromFile(Book books[], int *numBooks) {
    FILE *fp = fopen("books.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while(!feof(fp)) {
        fscanf(fp, "%s %s %d", books[*numBooks].title, books[*numBooks].author, &books[*numBooks].pages);
        (*numBooks)++;
    }
    fclose(fp);
}

void addNewBook(Book books[], int *numBooks) {
    if(*numBooks == MAX_BOOKS) {
        printf("Maximum number of books reached. Cannot add more books.\n");
    } else {
        printf("Enter the title of the book: ");
        scanf("%s", books[*numBooks].title);
        printf("Enter the author of the book: ");
        scanf("%s", books[*numBooks].author);
        printf("Enter the number of pages in the book: ");
        scanf("%d", &books[*numBooks].pages);
        printf("New book added successfully.\n");
        (*numBooks)++;
    }
}

void displayBooks(Book books[], int numBooks) {
    if(numBooks == 0) {
        printf("No books in collection.\n");
    } else {
        printf("%-30s %-20s %s\n", "Title", "Author", "Pages");
        for(int i = 0; i < numBooks; i++) {
            printf("%-30s %-20s %d\n", books[i].title, books[i].author, books[i].pages);
        }
    }
}

void searchBookByAuthor(Book books[], int numBooks) {
    char author[MAX_AUTHOR_LENGTH];
    printf("Enter the author name to search for: ");
    scanf("%s", author);
    int found = 0;
    for(int i = 0; i < numBooks; i++) {
        if(strcmp(author, books[i].author) == 0) {
            printf("%-30s %-20s %d\n", books[i].title, books[i].author, books[i].pages);
            found = 1;
        }
    }
    if(!found) {
        printf("No books found with author name \"%s\".\n", author);
    }
}

void searchBookByTitle(Book books[], int numBooks) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the book title to search for: ");
    scanf("%s", title);
    int found = 0;
    for(int i = 0; i < numBooks; i++) {
        if(strcmp(title, books[i].title) == 0) {
            printf("%-30s %-20s %d\n", books[i].title, books[i].author, books[i].pages);
            found = 1;
        }
    }
    if(!found) {
        printf("No books found with title \"%s\".\n", title);
    }
}

void menu() {
    printf("==============================================\n");
    printf("              C E-BOOK READER                  \n");
    printf("==============================================\n");
    printf("1. View all books in library\n");
    printf("2. Add new book to library\n");
    printf("3. Search book by title\n");
    printf("4. Search book by author\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}