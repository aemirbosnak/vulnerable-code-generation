//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an e-book
typedef struct ebook {
    char *title;                 // Title of the e-book
    char *author;                // Author of the e-book
    int num_pages;               // Number of pages in the e-book
    char **pages;                // Array of strings representing the pages of the e-book
} ebook_t;

// Create a new e-book
ebook_t *ebook_new(char *title, char *author, int num_pages) {
    ebook_t *ebook = malloc(sizeof(ebook_t));
    if (ebook == NULL) {
        return NULL;
    }

    // Allocate memory for the title, author, and pages
    ebook->title = malloc(strlen(title) + 1);
    if (ebook->title == NULL) {
        free(ebook);
        return NULL;
    }
    ebook->author = malloc(strlen(author) + 1);
    if (ebook->author == NULL) {
        free(ebook->title);
        free(ebook);
        return NULL;
    }
    ebook->pages = malloc(sizeof(char *) * num_pages);
    if (ebook->pages == NULL) {
        free(ebook->title);
        free(ebook->author);
        free(ebook);
        return NULL;
    }

    // Initialize the e-book
    strcpy(ebook->title, title);
    strcpy(ebook->author, author);
    ebook->num_pages = num_pages;

    // Return the e-book
    return ebook;
}

// Free the memory allocated for an e-book
void ebook_free(ebook_t *ebook) {
    // Free the memory allocated for the title, author, and pages
    free(ebook->title);
    free(ebook->author);
    for (int i = 0; i < ebook->num_pages; i++) {
        free(ebook->pages[i]);
    }
    free(ebook->pages);

    // Free the memory allocated for the e-book
    free(ebook);
}

// Load an e-book from a file
ebook_t *ebook_load(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the title, author, and number of pages from the file
    char title[256];
    char author[256];
    int num_pages;
    fscanf(file, "%s %s %d", title, author, &num_pages);

    // Create a new e-book
    ebook_t *ebook = ebook_new(title, author, num_pages);
    if (ebook == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the pages from the file
    for (int i = 0; i < num_pages; i++) {
        // Allocate memory for the page
        ebook->pages[i] = malloc(256);
        if (ebook->pages[i] == NULL) {
            ebook_free(ebook);
            fclose(file);
            return NULL;
        }

        // Read the page from the file
        fscanf(file, "%s", ebook->pages[i]);
    }

    // Close the file
    fclose(file);

    // Return the e-book
    return ebook;
}

// Save an e-book to a file
void ebook_save(ebook_t *ebook, char *filename) {
    // Open the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    // Write the title, author, and number of pages to the file
    fprintf(file, "%s %s %d\n", ebook->title, ebook->author, ebook->num_pages);

    // Write the pages to the file
    for (int i = 0; i < ebook->num_pages; i++) {
        fprintf(file, "%s\n", ebook->pages[i]);
    }

    // Close the file
    fclose(file);
}

// Print an e-book to the screen
void ebook_print(ebook_t *ebook) {
    // Print the title, author, and number of pages
    printf("%s by %s (%d pages)\n", ebook->title, ebook->author, ebook->num_pages);

    // Print the pages
    for (int i = 0; i < ebook->num_pages; i++) {
        printf("%s\n", ebook->pages[i]);
    }
}

// Main function
int main() {
    // Load an e-book from a file
    ebook_t *ebook = ebook_load("book.txt");
    if (ebook == NULL) {
        printf("Error loading e-book.\n");
        return 1;
    }

    // Print the e-book to the screen
    ebook_print(ebook);

    // Free the memory allocated for the e-book
    ebook_free(ebook);

    return 0;
}