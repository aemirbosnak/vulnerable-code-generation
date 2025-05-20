//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->content = malloc(strlen(content) + 1);
    strcpy(book->content, content);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Function to open an ebook file and return a book object
Book *open_ebook(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title
    char title[1024];
    fgets(title, sizeof(title), fp);

    // Read the author
    char author[1024];
    fgets(author, sizeof(author), fp);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d\n", &num_pages);

    // Read the content
    char content[100000];
    while (!feof(fp)) {
        fgets(content, sizeof(content), fp);
    }

    // Close the file
    fclose(fp);

    // Create a book object and return it
    return create_book(title, author, num_pages, content);
}

// Function to save a book object to an ebook file
void save_ebook(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write the title
    fprintf(fp, "%s\n", book->title);

    // Write the author
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages
    fprintf(fp, "%d\n", book->num_pages);

    // Write the content
    fprintf(fp, "%s", book->content);

    // Close the file
    fclose(fp);
}

// Function to print the menu
void print_menu() {
    printf("1. Open an ebook\n");
    printf("2. Save an ebook\n");
    printf("3. Print an ebook\n");
    printf("4. Quit\n");
}

// Function to get a choice from the user
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    Book *book = NULL;
    while (1) {
        print_menu();
        int choice = get_choice();
        switch (choice) {
            case 1:
                book = open_ebook("book.txt");
                if (book == NULL) {
                    printf("Error opening book\n");
                }
                break;
            case 2:
                if (book == NULL) {
                    printf("No book to save\n");
                } else {
                    save_ebook(book, "book.txt");
                    printf("Book saved\n");
                }
                break;
            case 3:
                if (book == NULL) {
                    printf("No book to print\n");
                } else {
                    print_book(book);
                }
                break;
            case 4:
                if (book != NULL) {
                    free_book(book);
                }
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}