//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to hold a page of text.
typedef struct page {
    char* text;
    int num_lines;
    int current_line;
} page;

// Function to create a new page.
page* new_page(char* text) {
    page* new_page = malloc(sizeof(page));
    new_page->text = strdup(text);
    new_page->num_lines = 0;
    new_page->current_line = 0;
    return new_page;
}

// Function to free a page.
void free_page(page* page) {
    free(page->text);
    free(page);
}

// Function to render a page to the screen.
void render_page(page* page) {
    for (int i = 0; i < page->num_lines; i++) {
        printf("%s\n", page->text + page->current_line * 80);
        page->current_line++;
    }
}

// Function to turn a string into pages.
page** string_to_pages(char* text) {
    int num_pages = strlen(text) / 80;
    page** pages = malloc(sizeof(page*) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        pages[i] = new_page(text + i * 80);
    }
    return pages;
}

// Function to free an array of pages.
void free_pages(page** pages, int num_pages) {
    for (int i = 0; i < num_pages; i++) {
        free_page(pages[i]);
    }
    free(pages);
}

// Main function.
int main() {
    // Open the file.
    FILE* file = fopen("book.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Read the file into a string.
    char* text = NULL;
    size_t len = 0;
    ssize_t read = getline(&text, &len, file);
    if (read == -1) {
        fprintf(stderr, "Error reading file.\n");
        return EXIT_FAILURE;
    }

    // Close the file.
    fclose(file);

    // Turn the string into pages.
    page** pages = string_to_pages(text);

    // Render the first page.
    render_page(pages[0]);

    // Wait for user input.
    getchar();

    // Render the next page.
    render_page(pages[1]);

    // Free the pages.
    free_pages(pages, 2);

    // Free the string.
    free(text);

    return EXIT_SUCCESS;
}