//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ebook struct
typedef struct {
    char title[100];
    char author[100];
    char content[100000];
    int num_pages;
} ebook_t;

// Function to read ebook file and populate ebook struct
ebook_t read_ebook_file(const char *filename) {
    ebook_t ebook;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    fscanf(file, "%s %s\n", ebook.title, ebook.author);
    fscanf(file, "%s", ebook.content);
    ebook.num_pages = 0;
    while (fscanf(file, "%d", &ebook.num_pages) == 1) {
        // Skip the page number line
        fscanf(file, "%s", ebook.content);
    }

    fclose(file);
    return ebook;
}

// Function to print ebook title, author, and content
void print_ebook(const ebook_t *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Content:\n");
    printf("%s\n", ebook->content);
    printf("Pages: %d\n", ebook->num_pages);
}

// Function to search for a word in ebook content
int search_word(const ebook_t *ebook, const char *word) {
    int count = 0;
    char *search_word = (char *)malloc(strlen(word) + 1);
    strcpy(search_word, word);
    for (int i = 0; i < strlen(ebook->content); i++) {
        if (strstr(ebook->content + i, search_word)!= NULL) {
            count++;
        }
    }
    free(search_word);
    return count;
}

// Main function
int main(int argc, char *argv[]) {
    ebook_t ebook;
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        exit(1);
    }

    ebook = read_ebook_file(argv[1]);
    print_ebook(&ebook);
    printf("Word count: %d\n", search_word(&ebook, "the"));
    return 0;
}