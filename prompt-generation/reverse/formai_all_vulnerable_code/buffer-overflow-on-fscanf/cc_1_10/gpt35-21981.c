//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    char publisher[100];
    char isbn[100];
    char year[100];
    char edition[100];
    char filepath[100];
} Book;

// Function to show book information
void show_book_info(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("ISBN: %s\n", book.isbn);
    printf("Year: %s\n", book.year);
    printf("Edition: %s\n", book.edition);
    printf("Filepath: %s\n", book.filepath);
}

// Function to read book file
void read_book_file(char filepath[]) {
    FILE *fp;
    char ch;
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filepath);
        return;
    }
    printf("\n--- Book Content ---\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    printf("\n\n--- End of Book ---\n");
    fclose(fp);
}

// Function to search for book
int search_book(Book books[], int count, char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i;
        }
    }
    return -1; // Book not found
}

int main() {
    Book books[100];
    int count = 0;

    // Reading book information from file
    FILE *fp;
    char filename[] = "books.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }
    printf("--- Reading Book Information from File ---\n");
    while (!feof(fp)) {
        Book book;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", book.title, book.author, book.publisher, book.isbn, book.year, book.edition, book.filepath);
        books[count] = book;
        count++;
    }
    fclose(fp);

    // Displaying book information
    printf("\n--- Displaying Book Information ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nBook %d:\n", i + 1);
        show_book_info(books[i]);
    }

    // Searching for a book
    printf("\n--- Searching for a Book ---\n");
    char search_title[100];
    printf("Enter the title of the book you want to search: ");
    scanf("%s", search_title);
    int search_result = search_book(books, count, search_title);
    if (search_result == -1) {
        printf("Book not found.\n");
        return 0;
    }
    printf("\nBook found!\n");
    show_book_info(books[search_result]);

    // Reading book file
    printf("\n--- Reading Book File ---\n");
    printf("Enter the filepath of the book you want to read: ");
    char read_filepath[100];
    scanf("%s", read_filepath);
    read_book_file(read_filepath);

    return 0;
}