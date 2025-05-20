//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOK_SIZE 1000 // Maximum size of a book

// Structure for a book
typedef struct {
    char title[100];
    char author[100];
    char content[MAX_BOOK_SIZE];
    int pageCount;
} Book;

// Function to read a book from file
Book readBook(FILE* fp) {
    Book book;
    char line[200];
    int pageCount = 0;

    // Read title
    fgets(line, 200, fp);
    strcpy(book.title, line);

    // Read author
    fgets(line, 200, fp);
    strcpy(book.author, line);

    // Read content
    while(fgets(line, 200, fp)) {
        strcat(book.content, line);
        pageCount++;
    }

    book.pageCount = pageCount;
    return book;
}

// Function to display a book
void displayBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Page Count: %d\n", book.pageCount);
    printf("Content:\n%s", book.content);
}

// Function to search for a word in a book
int searchBook(Book book, char* word) {
    int count = 0;
    char* token;
    char* contentCopy = strdup(book.content); // Make a copy of the content to avoid modifying the original
    token = strtok(contentCopy, " ");

    while(token!= NULL) {
        if(strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    free(contentCopy);
    return count;
}

int main() {
    FILE* fp;
    char filename[100];
    Book book;

    // Read filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Read book from file
    book = readBook(fp);

    // Display book
    displayBook(book);

    // Search for a word in the book
    char word[100];
    printf("Enter word to search: ");
    scanf("%s", word);
    int count = searchBook(book, word);
    printf("'%s' appears %d times in the book.\n", word, count);

    // Close file
    fclose(fp);
    return 0;
}