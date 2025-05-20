//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PAGES 100
#define MAX_BOOK_SIZE 1000
#define MIN_ZOOM 0.5
#define MAX_ZOOM 2.0

typedef struct {
    char *name;
    char *author;
    char *description;
    int pages;
    int size;
} Book;

typedef struct {
    int current_page;
    int total_pages;
    float zoom;
} Page;

Book books[] = {
    {"The Great Gatsby", "F. Scott Fitzgerald", "A classic novel set in the roaring twenties", 256, 512},
    {"To Kill a Mockingbird", "Harper Lee", "A timeless tale of racial injustice and the loss of innocence", 320, 768},
    {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "A comedic science fiction adventure through space", 400, 1024},
};

int main() {
    int i;
    int choice;
    Page current_page;

    // Initialize current page and zoom
    current_page.current_page = 0;
    current_page.total_pages = 0;
    current_page.zoom = 1.0;

    // Display main menu
    printf("Welcome to the eBook Reader!\n");
    printf("Choose a book to read: ");
    for (i = 0; i < sizeof(books) / sizeof(Book); i++) {
        printf("%d. %s by %s\n", i + 1, books[i].name, books[i].author);
    }
    printf("\nEnter a number to select a book: ");

    // Read user input and select book
    scanf("%d", &choice);
    if (choice > 0 && choice <= sizeof(books) / sizeof(Book)) {
        current_page.total_pages = books[choice - 1].pages;
        current_page.current_page = 0;
        current_page.zoom = 1.0;
        printf("You have selected %s by %s\n", books[choice - 1].name, books[choice - 1].author);
    } else {
        printf("Invalid input. Please try again.\n");
    }

    // Display book content
    while (current_page.current_page < current_page.total_pages) {
        // Calculate page size based on zoom
        int page_size = (current_page.total_pages * current_page.zoom) / 100;
        if (page_size > MAX_BOOK_SIZE) {
            page_size = MAX_BOOK_SIZE;
        }
        if (page_size < MIN_ZOOM) {
            page_size = MIN_ZOOM;
        }

        // Display page number and update current page
        printf("Page %d of %d\n", current_page.current_page + 1, current_page.total_pages);
        current_page.current_page++;

        // Update zoom based on user input
        printf("Zoom: ");
        scanf("%f", &current_page.zoom);
        if (current_page.zoom < MIN_ZOOM) {
            current_page.zoom = MIN_ZOOM;
        } else if (current_page.zoom > MAX_ZOOM) {
            current_page.zoom = MAX_ZOOM;
        }

        // Display book content based on current page and zoom
        for (int j = 0; j < page_size; j++) {
            printf("%c", books[choice - 1].description[j]);
        }
    }

    // Display final page number and exit
    printf("Page %d of %d\n", current_page.current_page + 1, current_page.total_pages);
    return 0;
}