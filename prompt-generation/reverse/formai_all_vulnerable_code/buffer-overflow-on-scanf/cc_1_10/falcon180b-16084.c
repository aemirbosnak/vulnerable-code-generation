//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a book
typedef struct {
    char title[100];
    char author[50];
    int pages;
    char genre[20];
} Book;

// Function to display a book
void displayBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Genre: %s\n", book.genre);
    printf("\n");
}

// Function to read a CSV file and store books in an array
int readCSV(char* filename, Book books[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%s,%s,%d,%s", books[count].title, books[count].author, &books[count].pages, books[count].genre)!= EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

// Function to search for a book by title
int searchBook(Book books[], int count, char* title) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            displayBook(books[i]);
            return 1;
        }
    }

    printf("Book not found.\n");
    return 0;
}

int main() {
    Book books[100];
    int count = readCSV("books.csv", books);

    char searchTitle[100];
    printf("Enter a book title to search: ");
    scanf("%s", searchTitle);

    searchBook(books, count, searchTitle);

    return 0;
}