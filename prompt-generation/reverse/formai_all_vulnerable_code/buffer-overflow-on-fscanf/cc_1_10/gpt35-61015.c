//FormAI DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum book size constant
#define MAX_BOOK_SIZE 10000

// Define the book struct
typedef struct book_struct {
    char title[256];
    char author[256];
    char content[MAX_BOOK_SIZE];
    int current_page;
    int total_pages;
} Book;

// Define the Ebook reader struct
typedef struct ebook_reader_struct {
    Book* book;
    int current_page;
} EbookReader;

// Function prototype for loading a book
Book* load_book(char*);

// Function prototype for displaying the current page
void display_current_page(EbookReader*);

// Function prototype for going to the next page
void next_page(EbookReader*);

// Function prototype for going to the previous page
void previous_page(EbookReader*);

int main(int argc, char* argv[]) {
    // Check if the user provided a book file
    if(argc < 2) {
        printf("Please provide a book file.\n");
        exit(1);
    }

    // Load and initialize the book
    Book* book = load_book(argv[1]);

    // Create an Ebook reader and set the book to read
    EbookReader* ebook_reader = (EbookReader*)malloc(sizeof(EbookReader));
    ebook_reader->book = book;
    ebook_reader->current_page = 1;

    // Display the current page
    display_current_page(ebook_reader);

    // Enter a loop to allow the user to navigate the book
    char input[256];
    while(1) {
        printf("\n\nEnter a command (n for next page, p for previous page, q to quit): ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if(strcmp(input, "q") == 0) {
            // Quit the program
            printf("Goodbye!\n");
            break;
        } else if(strcmp(input, "n") == 0) {
            // Go to the next page and display it
            next_page(ebook_reader);
            display_current_page(ebook_reader);
        } else if(strcmp(input, "p") == 0) {
            // Go to the previous page and display it
            previous_page(ebook_reader);
            display_current_page(ebook_reader);
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Free memory
    free(ebook_reader);

    return 0;
}

Book* load_book(char* file_path) {
    // Open the file
    FILE* file = fopen(file_path, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Allocate memory for the book
    Book* book = (Book*)malloc(sizeof(Book));

    // Read the title and author
    fscanf(file, "%[^\n]s", book->title);
    fgetc(file);
    fscanf(file, "%[^\n]s", book->author);
    fgetc(file);

    // Read the content
    char current_char;
    int page_number = 1;
    int content_length = 0;
    while((current_char = fgetc(file)) != EOF) {
        if(current_char == '\n') {
            page_number++;
        }

        if(content_length >= MAX_BOOK_SIZE) {
            printf("Book is too large.\n");
            exit(1);
        }

        book->content[content_length] = current_char;
        content_length++;
    }

    // Set the book properties
    book->total_pages = page_number;
    book->current_page = 1;

    // Close the file and return the book
    fclose(file);
    return book;
}

void display_current_page(EbookReader* ebook_reader) {
    // Get the current page content
    char page_content[1000];
    int start_index = (ebook_reader->current_page - 1) * 1000;
    int end_index = start_index + 1000;
    strncpy(page_content, ebook_reader->book->content + start_index, end_index - start_index);
    page_content[end_index - start_index] = '\0';

    // Display the page number and content
    printf("\n\nPage %d/%d:\n\n%s", ebook_reader->current_page, ebook_reader->book->total_pages, page_content);
}

void next_page(EbookReader* ebook_reader) {
    if(ebook_reader->current_page < ebook_reader->book->total_pages) {
        ebook_reader->current_page++;
    }
}

void previous_page(EbookReader* ebook_reader) {
    if(ebook_reader->current_page > 1) {
        ebook_reader->current_page--;
    }
}