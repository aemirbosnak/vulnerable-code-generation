//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of file path
#define MAX_FILE_PATH_LENGTH 256

// Define the maximum length of file name
#define MAX_NAME_LENGTH 32

// Define the maximum number of books that can be stored
#define MAX_BOOKS 100

// Define the book struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    char genre[MAX_NAME_LENGTH];
    char file_path[MAX_FILE_PATH_LENGTH];
} book_t;

// Define the books array
book_t books[MAX_BOOKS];

// Define the number of books stored
int num_books = 0;

// Define the function to add a book
void add_book() {
    // Make sure there's room for another book
    if (num_books >= MAX_BOOKS) {
        printf("Error: maximum number of books reached\n");
        return;
    }

    // Get the book name
    printf("Enter the name of the book: ");
    fgets(books[num_books].name, MAX_NAME_LENGTH, stdin);
    strtok(books[num_books].name, "\n"); // remove the newline character

    // Get the book author
    printf("Enter the name of the author: ");
    fgets(books[num_books].author, MAX_NAME_LENGTH, stdin);
    strtok(books[num_books].author, "\n"); // remove the newline character

    // Get the book genre
    printf("Enter the genre of the book: ");
    fgets(books[num_books].genre, MAX_NAME_LENGTH, stdin);
    strtok(books[num_books].genre, "\n"); // remove the newline character

    // Get the file path of the book
    printf("Enter the file path of the book: ");
    fgets(books[num_books].file_path, MAX_FILE_PATH_LENGTH, stdin);
    strtok(books[num_books].file_path, "\n"); // remove the newline character

    // Increment the number of books stored
    num_books++;

    printf("Book added successfully!\n");
}

// Define the function to read a book
void read_book() {
    // Make sure there are books to read
    if (num_books == 0) {
        printf("Error: no books stored\n");
        return;
    }

    // Get the book index
    int index;
    printf("Enter the index of the book you want to read: ");
    scanf("%d", &index);

    // Make sure the index is in range
    if (index < 0 || index >= num_books) {
        printf("Error: invalid index\n");
        return;
    }

    // Print the book information
    printf("\n");
    printf("Name: %s\n", books[index].name);
    printf("Author: %s\n", books[index].author);
    printf("Genre: %s\n", books[index].genre);
    printf("\n");

    // Open the file and print its contents
    FILE* fp = fopen(books[index].file_path, "r");
    if (fp == NULL) {
        printf("Error: unable to open file\n");
        return;
    }

    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
}

int main() {
    // Initialize the books array to empty
    memset(books, 0, sizeof(books));

    int choice;

    // Display the menu and prompt for input
    do {
        printf("EBook Reader Menu:\n");
        printf("1. Add a book\n");
        printf("2. Read a book\n");
        printf("3. Quit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_book();
        } else if (choice == 2) {
            read_book();
        } else if (choice == 3) {
            // Quit the program
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: invalid choice\n");
        }

        // Clear the input buffer
        while (getchar() != '\n');
    } while (1);

    return 0;
}