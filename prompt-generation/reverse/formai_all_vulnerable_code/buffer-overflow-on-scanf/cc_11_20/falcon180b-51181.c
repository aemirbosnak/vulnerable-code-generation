//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_TITLE_LENGTH 64
#define MAX_CHAPTER_LENGTH 64
#define MAX_PAGE_LENGTH 64
#define MAX_LINE_LENGTH 1024

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_TITLE_LENGTH];
    int num_chapters;
    char chapters[MAX_CHAPTER_LENGTH][MAX_CHAPTER_LENGTH];
    int num_pages;
    char pages[MAX_PAGE_LENGTH][MAX_PAGE_LENGTH];
} Book;

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter the name of the ebook file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Book book;
    char line[MAX_LINE_LENGTH];
    int chapter = 0;
    int page = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strlen(line) > 0 && line[0] == '#') {
            if (strstr(line, "title:")!= NULL) {
                strcpy(book.title, line + 7);
            } else if (strstr(line, "author:")!= NULL) {
                strcpy(book.author, line + 8);
            } else if (strstr(line, "chapter:")!= NULL) {
                sscanf(line, "chapter: %d", &book.num_chapters);
            }
        } else {
            strcpy(book.chapters[chapter], line);
            page++;
            if (page == book.num_pages) {
                chapter++;
                page = 0;
            }
        }
    }

    fclose(fp);

    printf("Book Title: %s\n", book.title);
    printf("Book Author: %s\n", book.author);
    printf("Number of Chapters: %d\n", book.num_chapters);

    for (int i = 0; i < book.num_chapters; i++) {
        printf("Chapter %d:\n", i + 1);
        for (int j = 0; j < book.num_pages; j++) {
            printf("%s\n", book.pages[i][j]);
        }
    }

    return 0;
}