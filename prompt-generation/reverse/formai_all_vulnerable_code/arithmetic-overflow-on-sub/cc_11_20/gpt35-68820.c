//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_PAGES 1000

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int num_pages;
    char **pages;
} book;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <bookfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *infile = fopen(filename, "r");
    if (!infile) {
        printf("Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    book my_book;

    // Read the title and author
    fgets(my_book.title, MAX_LINE_LENGTH, infile);
    fgets(my_book.author, MAX_LINE_LENGTH, infile);

    // Read the number of pages
    fscanf(infile, "%d\n", &my_book.num_pages);

    // Allocate memory for the pages
    my_book.pages = malloc(sizeof(char*) * my_book.num_pages);
    if (!my_book.pages) {
        printf("Error: out of memory!\n");
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < my_book.num_pages; i++) {
        my_book.pages[i] = malloc(sizeof(char) * MAX_LINE_LENGTH);
    }

    // Read in the book pages
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    for (i = 0; i < my_book.num_pages; i++) {
        nread = getline(&line, &len, infile);
        if (nread == -1) {
            printf("Error: unexpected end of file\n");
            exit(EXIT_FAILURE);
        }
        strcpy(my_book.pages[i], line);
    }

    // Clean up
    if (line) {
        free(line);
    }
    fclose(infile);

    // Ebook reader interface
    int page_number = 0;
    char choice;
    while (1) {
        printf("*** %s by %s - Page %d/%d ***\n", my_book.title, my_book.author, page_number+1, my_book.num_pages);
        printf("%s\n", my_book.pages[page_number]);
        printf("(N)ext page, (P)revious page, (Q)uit?\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'n':
            case 'N':
                if (page_number < my_book.num_pages - 1) {
                    page_number++;
                }
                break;

            case 'p':
            case 'P':
                if (page_number > 0) {
                    page_number--;
                }
                break;

            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    // Free memory
    for (i = 0; i < my_book.num_pages; i++) {
        free(my_book.pages[i]);
    }
    free(my_book.pages);

    return 0;
}