//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOK_SIZE 1000000 // Maximum size of ebook in bytes
#define MAX_LINE_SIZE 1000 // Maximum size of each line in ebook

// Ebook struct to store ebook data
typedef struct {
    char *title;
    char *author;
    char *content;
    int content_size;
} Ebook;

// Function to read ebook from file
Ebook *read_ebook(const char *filename) {
    FILE *fp;
    Ebook *ebook = NULL;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    int ebook_size = ftell(fp);
    rewind(fp);

    ebook = malloc(sizeof(Ebook));
    ebook->title = malloc(ebook_size + 1);
    ebook->author = malloc(ebook_size + 1);
    ebook->content = malloc(ebook_size + 1);
    ebook->content_size = ebook_size;

    fread(ebook->title, ebook_size, 1, fp);
    fread(ebook->author, ebook_size, 1, fp);
    fread(ebook->content, ebook_size, 1, fp);

    fclose(fp);

    return ebook;
}

// Function to display ebook content
void display_ebook(Ebook *ebook) {
    printf("Title: %s\nAuthor: %s\n", ebook->title, ebook->author);

    char *content_ptr = ebook->content;
    int line_start = 0;

    while (line_start < ebook->content_size) {
        int line_end = line_start;

        while (line_end < ebook->content_size && ebook->content[line_end]!= '\n') {
            line_end++;
        }

        if (line_end - line_start > MAX_LINE_SIZE) {
            printf("Error: Line too long\n");
            return;
        }

        printf("%s", content_ptr + line_start);
        line_start = line_end + 1;
    }
}

// Main function
int main() {
    Ebook *ebook = read_ebook("example.ebook");
    if (ebook == NULL) {
        return 1;
    }

    display_ebook(ebook);

    free(ebook->title);
    free(ebook->author);
    free(ebook->content);
    free(ebook);

    return 0;
}