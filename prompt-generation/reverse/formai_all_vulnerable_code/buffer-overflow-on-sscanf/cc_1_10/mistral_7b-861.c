//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 100
#define MAX_LINES 50
#define MAX_CHARS 256

// Struct for book information
typedef struct {
    char title[MAX_CHARS];
    char author[MAX_CHARS];
    char content[MAX_LINES][MAX_CHARS];
} Book;

// Global variables
Book books[MAX_TITLES];
int num_books = 0;

void read_ceb_file(FILE *file) {
    char line[MAX_CHARS];
    char title[MAX_CHARS];
    char author[MAX_CHARS];
    int line_num = 0;

    // Read title
    fgets(line, MAX_CHARS, file);
    sscanf(line, "Title: %s", title);
    strcpy(books[num_books].title, title);

    // Read author
    fgets(line, MAX_CHARS, file);
    sscanf(line, "Author: %s", author);
    strcpy(books[num_books].author, author);

    // Read content lines
    while (fgets(line, MAX_CHARS, file) != NULL && line_num < MAX_LINES) {
        strcpy(books[num_books].content[line_num], line);
        line_num++;
    }

    num_books++;
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <ceb_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("\n-----------------------\n");
    printf("| Welcome to CebraLib! |\n");
    printf("-----------------------|\n\n");

    // Read each book from file
    while (!feof(file)) {
        read_ceb_file(file);
    }
    fclose(file);

    // Display catalog
    printf("\n---------------------\n");
    printf("| CebraLib Catalog    |\n");
    printf("---------------------|\n\n");

    for (int i = 0; i < num_books; i++) {
        printf("| %d. %s by %s |\n", i+1, books[i].title, books[i].author);
    }

    printf("\n---------------------\n");
    printf("| Press Enter to Quit|\n");
    printf("---------------------|\n\n");

    getchar();

    return 0;
}