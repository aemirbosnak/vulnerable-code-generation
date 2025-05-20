//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Introspective C Ebook Reader
// This program introspectively analyzes the structure of an ebook file and
// presents its contents in a user-friendly format.

// Define the structure of an ebook file.
typedef struct {
    char *title;
    char *author;
    int num_chapters;
    char **chapters;
} Ebook;

// Function to load an ebook file into memory.
Ebook *load_ebook(char *filename) {
    // Open the ebook file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the title of the ebook.
    char title[1024];
    fscanf(file, "%s", title);

    // Read the author of the ebook.
    char author[1024];
    fscanf(file, "%s", author);

    // Read the number of chapters in the ebook.
    int num_chapters;
    fscanf(file, "%d", &num_chapters);

    // Allocate memory for the ebook struct.
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->title = strdup(title);
    ebook->author = strdup(author);
    ebook->num_chapters = num_chapters;
    ebook->chapters = malloc(sizeof(char *) * num_chapters);

    // Read the chapters of the ebook.
    for (int i = 0; i < num_chapters; i++) {
        // Read the length of the chapter.
        int chapter_length;
        fscanf(file, "%d", &chapter_length);

        // Allocate memory for the chapter.
        char *chapter = malloc(chapter_length + 1);

        // Read the chapter from the file.
        fread(chapter, 1, chapter_length, file);
        chapter[chapter_length] = '\0';

        // Store the chapter in the ebook struct.
        ebook->chapters[i] = chapter;
    }

    // Close the ebook file.
    fclose(file);

    // Return the ebook struct.
    return ebook;
}

// Function to free the memory allocated for an ebook.
void free_ebook(Ebook *ebook) {
    // Free the title of the ebook.
    free(ebook->title);

    // Free the author of the ebook.
    free(ebook->author);

    // Free the chapters of the ebook.
    for (int i = 0; i < ebook->num_chapters; i++) {
        free(ebook->chapters[i]);
    }

    // Free the memory allocated for the ebook struct.
    free(ebook);
}

// Function to print the contents of an ebook.
void print_ebook(Ebook *ebook) {
    // Print the title of the ebook.
    printf("Title: %s\n", ebook->title);

    // Print the author of the ebook.
    printf("Author: %s\n", ebook->author);

    // Print the number of chapters in the ebook.
    printf("Number of chapters: %d\n", ebook->num_chapters);

    // Print the chapters of the ebook.
    for (int i = 0; i < ebook->num_chapters; i++) {
        printf("Chapter %d:\n", i + 1);
        printf("%s\n", ebook->chapters[i]);
    }
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user has provided an ebook file.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    // Load the ebook file into memory.
    Ebook *ebook = load_ebook(argv[1]);
    if (ebook == NULL) {
        return 1;
    }

    // Print the contents of the ebook.
    print_ebook(ebook);

    // Free the memory allocated for the ebook.
    free_ebook(ebook);

    return 0;
}