//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Create a struct to store book data
typedef struct Book {
    char *title;
    char *author;
    int pages;
} Book;

// Create a function to read a book from a file
Book *read_book(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the book's title
    char *title = malloc(100);
    if (title == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    fscanf(fp, "%s", title);
    book->title = title;

    // Read the book's author
    char *author = malloc(100);
    if (author == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    fscanf(fp, "%s", author);
    book->author = author;

    // Read the book's pages
    int pages;
    fscanf(fp, "%d", &pages);
    book->pages = pages;

    // Close the file
    fclose(fp);

    // Return the book
    return book;
}

// Create a function to print a book
void print_book(Book *book) {
    // Print the book's title
    printf("Title: %s\n", book->title);

    // Print the book's author
    printf("Author: %s\n", book->author);

    // Print the book's pages
    printf("Pages: %d\n", book->pages);
}

// Create a function to free the memory allocated for a book
void free_book(Book *book) {
    // Free the book's title
    free(book->title);

    // Free the book's author
    free(book->author);

    // Free the book
    free(book);
}

// Create a function to read a command from the user
char *read_command() {
    // Allocate memory for the command
    char *command = malloc(100);
    if (command == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the command from the user
    scanf("%s", command);

    // Return the command
    return command;
}

// Create a function to process a command
void process_command(char *command, Book **book) {
    // Check if the command is "read"
    if (strcmp(command, "read") == 0) {
        // Prompt the user for a filename
        printf("Enter the name of the book you want to read: ");

        // Read the filename from the user
        char *filename = malloc(100);
        if (filename == NULL) {
            perror("Error allocating memory");
            exit(1);
        }
        scanf("%s", filename);

        // Read the book from the file
        *book = read_book(filename);

        // Print the book
        print_book(*book);

        // Free the memory allocated for the filename
        free(filename);
    }

    // Check if the command is "quit"
    else if (strcmp(command, "quit") == 0) {
        // Free the memory allocated for the book
        free_book(*book);

        // Exit the program
        exit(0);
    }

    // Otherwise, print an error message
    else {
        printf("Invalid command\n");
    }
}

// Create a function to run the program
void run_program() {
    // Allocate memory for the book
    Book *book = NULL;

    // Create a loop to process commands
    while (1) {
        // Read a command from the user
        char *command = read_command();

        // Process the command
        process_command(command, &book);

        // Free the memory allocated for the command
        free(command);
    }
}

// Create a function to welcome the user
void welcome() {
    printf("Welcome to the E-book reader!\n");
    printf("Enter \"read\" to read a book, or \"quit\" to quit.\n");
}

// Main function
int main() {
    // Welcome the user
    welcome();

    // Run the program
    run_program();

    return 0;
}