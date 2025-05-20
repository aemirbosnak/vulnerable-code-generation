//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structures for futuristic ebook reader
typedef struct Chapter {
    char *title;
    int pages;
    char *text;
} Chapter;

typedef struct Book {
    char *title;
    char *author;
    int chapters;
    Chapter *chapters_list;
} Book;

// Function to load a book from a file
Book *load_book(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the book title and author
    char line[256];
    fscanf(fp, "%[^\n]\n", line);
    book->title = strdup(line);
    fscanf(fp, "%[^\n]\n", line);
    book->author = strdup(line);

    // Read the number of chapters
    fscanf(fp, "%d\n", &book->chapters);

    // Allocate memory for the chapters
    book->chapters_list = malloc(sizeof(Chapter) * book->chapters);
    if (book->chapters_list == NULL) {
        free(book->title);
        free(book->author);
        free(book);
        fclose(fp);
        return NULL;
    }

    // Read each chapter
    for (int i = 0; i < book->chapters; i++) {
        // Read the chapter title
        fscanf(fp, "%[^\n]\n", line);
        book->chapters_list[i].title = strdup(line);

        // Read the number of pages
        fscanf(fp, "%d\n", &book->chapters_list[i].pages);

        // Allocate memory for the chapter text
        book->chapters_list[i].text = malloc(sizeof(char) * book->chapters_list[i].pages);
        if (book->chapters_list[i].text == NULL) {
            for (int j = 0; j < i; j++) {
                free(book->chapters_list[j].title);
            }
            free(book->chapters_list);
            free(book->title);
            free(book->author);
            free(book);
            fclose(fp);
            return NULL;
        }

        // Read the chapter text
        fread(book->chapters_list[i].text, sizeof(char), book->chapters_list[i].pages, fp);
    }

    // Close the file
    fclose(fp);

    // Return the book
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    // Free the memory allocated for the book title and author
    free(book->title);
    free(book->author);

    // Free the memory allocated for each chapter
    for (int i = 0; i < book->chapters; i++) {
        // Free the memory allocated for the chapter title
        free(book->chapters_list[i].title);

        // Free the memory allocated for the chapter text
        free(book->chapters_list[i].text);
    }

    // Free the memory allocated for the chapters list
    free(book->chapters_list);

    // Free the memory allocated for the book
    free(book);
}

// Function to print the book details
void print_book_details(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Chapters: %d\n", book->chapters);
}

// Function to read and navigate the book interactively
void read_book(Book *book) {
    // Loop until the user exits the program
    while (1) {
        // Display the book details
        print_book_details(book);

        // Prompt the user to enter a chapter number
        printf("\nEnter a chapter number (1-%d) or q to exit: ", book->chapters);
        char input[16];
        fgets(input, 16, stdin);

        // Check if the user entered q to exit the program
        if (strcmp(input, "q\n") == 0) {
            break;
        }

        // Convert the chapter number to an integer
        int chapter_number = atoi(input);

        // Check if the chapter number is valid
        if (chapter_number < 1 || chapter_number > book->chapters) {
            printf("Invalid chapter number. Please enter a number between 1 and %d.\n", book->chapters);
            continue;
        }

        // Read the specified chapter
        Chapter *chapter = &book->chapters_list[chapter_number - 1];

        // Display the chapter title
        printf("\n%s\n", chapter->title);

        // Display the chapter text
        printf("%s\n", chapter->text);

        // Prompt the user to press any key to continue
        printf("\nPress any key to continue...");
        getchar();
    }
}

// Main function
int main() {
    // Load the book from a file
    Book *book = load_book("book.txt");

    // Check if the book was loaded successfully
    if (book == NULL) {
        printf("Error loading book. Please check the file and try again.\n");
        return 1;
    }

    // Read and navigate the book interactively
    read_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}