//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
// Linus Torvalds style C Ebook reader.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct of an ebook.
struct ebook {
    char *title;
    char *author;
    char *text;
    int num_pages;
};

// Function to create a new ebook.
struct ebook *new_ebook(char *title, char *author, char *text, int num_pages) {
    struct ebook *ebook = malloc(sizeof(struct ebook));
    if (ebook == NULL) {
        return NULL;
    }
    ebook->title = strdup(title);
    ebook->author = strdup(author);
    ebook->text = strdup(text);
    ebook->num_pages = num_pages;
    return ebook;
}

// Function to free an ebook.
void free_ebook(struct ebook *ebook) {
    free(ebook->title);
    free(ebook->author);
    free(ebook->text);
    free(ebook);
}

// Function to print an ebook.
void print_ebook(struct ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Text: %s\n", ebook->text);
    printf("Number of pages: %d\n", ebook->num_pages);
}

// Function to read an ebook from a file.
struct ebook *read_ebook(char *filename) {
    // Open the file.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title.
    char title[1024];
    if (fgets(title, sizeof(title), fp) == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the author.
    char author[1024];
    if (fgets(author, sizeof(author), fp) == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the text.
    char *text = NULL;
    int size = 0;
    while (1) {
        char buffer[1024];
        int n = fread(buffer, 1, sizeof(buffer), fp);
        if (n == 0) {
            break;
        }
        text = realloc(text, size + n);
        memcpy(text + size, buffer, n);
        size += n;
    }
    fclose(fp);

    // Read the number of pages.
    int num_pages;
    if (fscanf(fp, "%d", &num_pages) != 1) {
        free(text);
        return NULL;
    }

    // Create the ebook.
    struct ebook *ebook = new_ebook(title, author, text, num_pages);
    free(text);
    return ebook;
}

// Function to write an ebook to a file.
int write_ebook(char *filename, struct ebook *ebook) {
    // Open the file.
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the title.
    if (fprintf(fp, "%s\n", ebook->title) < 0) {
        fclose(fp);
        return -1;
    }

    // Write the author.
    if (fprintf(fp, "%s\n", ebook->author) < 0) {
        fclose(fp);
        return -1;
    }

    // Write the text.
    if (fprintf(fp, "%s", ebook->text) < 0) {
        fclose(fp);
        return -1;
    }

    // Write the number of pages.
    if (fprintf(fp, "%d", ebook->num_pages) < 0) {
        fclose(fp);
        return -1;
    }

    // Close the file.
    fclose(fp);

    return 0;
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the user specified a filename.
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the ebook from the file.
    struct ebook *ebook = read_ebook(argv[1]);
    if (ebook == NULL) {
        printf("Error reading ebook from file.\n");
        return 1;
    }

    // Print the ebook.
    print_ebook(ebook);

    // Free the ebook.
    free_ebook(ebook);

    return 0;
}