//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_BOOKS 50
#define MAX_BOOK_LEN 1000

// Struct for individual books
struct Book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char *content;
};

// Main function to run program
int main() {
    int num_books = 0;
    struct Book library[MAX_BOOKS];

    // Read in book files and create Books objects
    FILE *fp;
    char file_name[MAX_BOOK_LEN];
    printf("Welcome to C Ebook Reader\n");
    printf("Enter the number of books in the library: ");
    scanf("%d", &num_books);

    for (int i = 0; i < num_books; i++) {
        printf("\nEnter title of book %d: ", i + 1);
        scanf("%s", library[i].title);
        printf("Enter author of book %d: ", i + 1);
        scanf("%s", library[i].author);
        printf("Enter name of file for book %d: ", i + 1);
        scanf("%s", file_name);
        fp = fopen(file_name, "r");
        if (fp == NULL) {
            printf("Could not open file %s\n", file_name);
            exit(1);
        }
        // Allocate memory for book content
        library[i].content = (char*) malloc(MAX_BOOK_LEN*sizeof(char));
        char line[MAX_BOOK_LEN];
        while (fgets(line, sizeof(line), fp)) {
            strcat(library[i].content, line);
        }
        fclose(fp);
    }

    // Print library of books
    printf("\nCatalog of Books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. Title: %s\n   Author: %s\n", i + 1, library[i].title, library[i].author);
    }

    // Allow user to select book to read
    int book_choice;
    printf("\nEnter the number of the book you want to read: ");
    scanf("%d", &book_choice);
    book_choice--;

    // Display selected book
    printf("\nTitle: %s\n\n%s\n", library[book_choice].title, library[book_choice].content);

    // Free memory from allocated book content
    free(library[book_choice].content);
    return 0;
}