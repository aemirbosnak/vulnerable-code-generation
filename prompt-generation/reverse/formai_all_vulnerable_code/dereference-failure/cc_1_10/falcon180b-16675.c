//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EBOOK_MAX_SIZE 1000000 // Maximum size of ebook in bytes
#define EBOOK_MAX_PAGES 1000 // Maximum number of pages in ebook

typedef struct {
    char title[100];
    char author[100];
    int num_pages;
    char content[EBOOK_MAX_SIZE];
} Ebook;

int main() {
    Ebook ebook;
    FILE *fp;
    char filename[100];
    char ch;

    // Ask user for filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read ebook data from file
    ebook.title[0] = '\0';
    ebook.author[0] = '\0';
    ebook.num_pages = 0;
    ebook.content[0] = '\0';

    while ((ch = fgetc(fp))!= EOF) {
        if (ebook.num_pages == EBOOK_MAX_PAGES) {
            printf("Error: Maximum number of pages exceeded.\n");
            exit(1);
        }

        if (ebook.content[ebook.num_pages * EBOOK_MAX_SIZE - 1]!= '\0') {
            printf("Error: Maximum size of ebook exceeded.\n");
            exit(1);
        }

        if (ch == '|') {
            if (ebook.title[0] == '\0') {
                strcpy(ebook.title, "");
            } else if (ebook.author[0] == '\0') {
                strcpy(ebook.author, "");
            } else {
                printf("Error: Invalid ebook format.\n");
                exit(1);
            }
        } else if (ch == '\n') {
            ebook.content[ebook.num_pages * EBOOK_MAX_SIZE - 1] = '\0';
            ebook.num_pages++;
        } else {
            strncat(ebook.content, &ch, 1);
        }
    }

    // Close file
    fclose(fp);

    // Print ebook data
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Number of pages: %d\n", ebook.num_pages);

    // Print ebook content
    printf("\n");
    for (int i = 0; i < ebook.num_pages; i++) {
        printf("%s", ebook.content + i * EBOOK_MAX_SIZE);
    }

    return 0;
}