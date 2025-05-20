//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of pages in the ebook
#define MAX_PAGES 1000

// Define the structure for each page in the ebook
typedef struct {
    char* content;
} Page;

// Define the structure for the ebook
typedef struct {
    char* title;
    int page_count;
    Page pages[MAX_PAGES];
} Ebook;

// Define a function to load the ebook content from a file
Ebook load_ebook(char* file_name) {
    Ebook book;
    book.title = file_name;
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }
    int page_num = 0;
    while (1) {
        // Read in each line of the file as a page
        char* line = NULL;
        size_t len = 0;
        int read = getline(&line, &len, fp);
        if (read == -1) break;
        if (page_num >= MAX_PAGES) {
            printf("Error: Ebook too large!\n");
            exit(1);
        }
        Page p;
        p.content = line;
        book.pages[page_num++] = p;
    }
    book.page_count = page_num;
    fclose(fp);
    return book;
}

// Define a function to display the ebook
void display_ebook(Ebook book, int page_num) {
    printf("%s\n\n", book.title);
    if (page_num < 1 || page_num > book.page_count) {
        printf("Error: Invalid page number!\n");
        return;
    }
    printf("%s\n", book.pages[page_num-1].content);
}

// Define the main function
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: Please provide ebook file name!\n");
        return 1;
    }
    Ebook book = load_ebook(argv[1]);
    int page_num;
    while (1) {
        printf("Enter page number (1 - %d): ", book.page_count);
        scanf("%d", &page_num);
        if (page_num == 0) break;
        display_ebook(book, page_num);
    }
    return 0;
}