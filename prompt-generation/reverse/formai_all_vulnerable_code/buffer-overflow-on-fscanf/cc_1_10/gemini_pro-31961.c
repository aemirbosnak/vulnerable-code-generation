//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

// Define the maximum line length for the ebook
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines in the ebook
#define MAX_LINES 1000

// Define the maximum number of chapters in the ebook
#define MAX_CHAPTERS 10

// Define the maximum number of characters in a chapter title
#define MAX_CHAPTER_TITLE_LENGTH 100

// Define the structure of an ebook
typedef struct ebook {
    char *title;
    char *author;
    int num_chapters;
    char *chapters[MAX_CHAPTERS];
} ebook;

// Define the structure of a chapter
typedef struct chapter {
    char *title;
    int num_lines;
    char *lines[MAX_LINES];
} chapter;

// Define the structure of a line
typedef struct line {
    char *text;
} line;

// Create a new ebook
ebook *new_ebook(char *title, char *author) {
    ebook *e = malloc(sizeof(ebook));
    e->title = strdup(title);
    e->author = strdup(author);
    e->num_chapters = 0;
    return e;
}

// Add a chapter to an ebook
void add_chapter(ebook *e, chapter *c) {
    e->chapters[e->num_chapters++] = c;
}

// Create a new chapter
chapter *new_chapter(char *title) {
    chapter *c = malloc(sizeof(chapter));
    c->title = strdup(title);
    c->num_lines = 0;
    return c;
}

// Add a line to a chapter
void add_line(chapter *c, line *l) {
    c->lines[c->num_lines++] = l;
}

// Create a new line
line *new_line(char *text) {
    line *l = malloc(sizeof(line));
    l->text = strdup(text);
    return l;
}

// Read an ebook from a file
ebook *read_ebook_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title and author
    char title[MAX_CHAPTER_TITLE_LENGTH];
    char author[MAX_CHAPTER_TITLE_LENGTH];
    fscanf(fp, "%s %s\n", title, author);

    // Create the ebook
    ebook *e = new_ebook(title, author);

    // Read the chapters
    while (1) {
        // Read the chapter title
        char chapter_title[MAX_CHAPTER_TITLE_LENGTH];
        fscanf(fp, "%s\n", chapter_title);
        if (strcmp(chapter_title, "EOF") == 0) {
            break;
        }

        // Create the chapter
        chapter *c = new_chapter(chapter_title);

        // Read the lines in the chapter
        while (1) {
            // Read the line
            char line_text[MAX_LINE_LENGTH];
            fscanf(fp, "%s\n", line_text);
            if (strcmp(line_text, "EOF") == 0) {
                break;
            }

            // Create the line
            line *l = new_line(line_text);

            // Add the line to the chapter
            add_line(c, l);
        }

        // Add the chapter to the ebook
        add_chapter(e, c);
    }

    // Close the file
    fclose(fp);

    // Return the ebook
    return e;
}

// Write an ebook to a file
void write_ebook_to_file(ebook *e, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title and author
    fprintf(fp, "%s %s\n", e->title, e->author);

    // Write the chapters
    for (int i = 0; i < e->num_chapters; i++) {
        chapter *c = e->chapters[i];

        // Write the chapter title
        fprintf(fp, "%s\n", c->title);

        // Write the lines in the chapter
        for (int j = 0; j < c->num_lines; j++) {
            line *l = c->lines[j];

            // Write the line
            fprintf(fp, "%s\n", l->text);
        }

        // Write the EOF marker
        fprintf(fp, "EOF\n");
    }

    // Write the EOF marker
    fprintf(fp, "EOF");

    // Close the file
    fclose(fp);
}

// Print an ebook to the console
void print_ebook(ebook *e) {
    printf("%s by %s\n\n", e->title, e->author);

    for (int i = 0; i < e->num_chapters; i++) {
        chapter *c = e->chapters[i];

        printf("%s\n\n", c->title);

        for (int j = 0; j < c->num_lines; j++) {
            line *l = c->lines[j];

            printf("%s\n", l->text);
        }

        printf("\n");
    }
}

// Free an ebook
void free_ebook(ebook *e) {
    // Free the title and author
    free(e->title);
    free(e->author);

    // Free the chapters
    for (int i = 0; i < e->num_chapters; i++) {
        chapter *c = e->chapters[i];

        // Free the title
        free(c->title);

        // Free the lines
        for (int j = 0; j < c->num_lines; j++) {
            line *l = c->lines[j];

            // Free the text
            free(l->text);

            // Free the line
            free(l);
        }

        // Free the chapter
        free(c);
    }

    // Free the ebook
    free(e);
}

int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the ebook from the file
    ebook *e = read_ebook_from_file(argv[1]);
    if (e == NULL) {
        printf("Error: Could not read ebook from file.\n");
        return 1;
    }

    // Print the ebook to the console
    print_ebook(e);

    // Free the ebook
    free_ebook(e);

    return 0;
}