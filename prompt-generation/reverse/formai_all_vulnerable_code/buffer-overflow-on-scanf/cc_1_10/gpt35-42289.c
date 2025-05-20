//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our custom e-book struct
typedef struct {
    char title[50];
    char author[50];
    char* content;
} Ebook;

// Declare our functions
void print_menu();
Ebook* load_ebook(char* file_path);
void print_ebook(Ebook* book);
void free_ebook(Ebook* book);

int main() {
    char file_path[100];
    Ebook* book = NULL;

    // Display welcome message
    printf("Welcome to our unique C E-Book Reader!\n");

    // Prompt user to enter file path
    printf("Please enter the file path of the e-book you want to load: ");
    scanf("%s", file_path);

    // Load e-book
    book = load_ebook(file_path);

    if (book == NULL) {
        printf("Error loading e-book from file '%s'", file_path);
        return 1;
    }

    // Display e-book
    print_ebook(book);

    // Free e-book memory
    free_ebook(book);

    return 0;
}

/**
 * Function to load e-book content from file and return as an Ebook struct
 */
Ebook* load_ebook(char* file_path) {
    // Declare variables
    FILE* file;
    char buffer[1000];
    int file_size;
    Ebook* book = NULL;

    // Open file for reading
    file = fopen(file_path, "r");

    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for e-book struct
    book = (Ebook*)malloc(sizeof(Ebook));

    // Read e-book title from file
    fgets(book->title, sizeof(book->title), file);

    // Read e-book author from file
    fgets(book->author, sizeof(book->author), file);

    // Read e-book content from file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);
    book->content = (char*)malloc(sizeof(char) * file_size);
    fread(buffer, 1, file_size, file);
    strcpy(book->content, buffer);

    // Close file
    fclose(file);

    return book;
}

/**
 * Function to display e-book content (title, author and content)
 */
void print_ebook(Ebook* book) {
    printf("\n\n");
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Content: %s", book->content);
}

/**
 * Function to free memory allocated for ebook
 */
void free_ebook(Ebook* book) {
    free(book->content);
    free(book);
}