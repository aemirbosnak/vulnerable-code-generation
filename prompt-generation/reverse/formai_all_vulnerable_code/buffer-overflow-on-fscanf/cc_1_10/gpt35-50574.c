//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int pageCount;
    char content[1000];
} ebook; // create ebook object of Book struct

int main() {
    FILE *fp = fopen("ebook.txt", "r"); // read the ebook text file
    if (fp == NULL) {
        printf("Failed to open the ebook file. Please check if it exists or not.\n");
        return 0;
    }
    // extract book information from the text file
    fgets(ebook.title, 100, fp);
    fgets(ebook.author, 100, fp);
    fscanf(fp, "%d\n", &ebook.pageCount);
    int i = 0;
    while (fgets(ebook.content + i, 1000 - i, fp)) {
        i = strlen(ebook.content);
    }
    fclose(fp); // close the ebook file

    printf("Welcome to the C Ebook Reader Program!\n\n");
    printf("Title: %sAuthor: %sPage Count: %d\n\n", ebook.title, ebook.author, ebook.pageCount);

    // display ebook content
    int currentPage = 1;
    int totalPages = ebook.pageCount;
    int contentStart = 0;
    int contentEnd = strlen(ebook.content);
    int contentLength = contentEnd - contentStart + 1;
    char input[10];
    while (1) {
        printf("Page %d of %d\n", currentPage, totalPages);
        printf("%.*s\n", contentLength, ebook.content + contentStart);
        printf("\nWhat would you like to do? (next/prev/exit): ");
        fgets(input, 10, stdin);
        if (strcmp(input, "next\n") == 0 && currentPage < totalPages) {
            contentStart += contentLength;
            contentEnd = strlen(ebook.content) - contentStart;
            contentLength = contentEnd - contentStart + 1;
            currentPage++;
        } else if (strcmp(input, "prev\n") == 0 && currentPage > 1) {
            contentEnd = contentStart - 2;
            if (contentEnd < 0) {
                contentEnd = 0;
            }
            contentStart = 0;
            contentLength = contentEnd - contentStart + 1;
            currentPage--;
        } else if (strcmp(input, "exit\n") == 0) {
            break;
        } else {
            printf("\nInvalid input! Please try again.\n\n");
        }
    }

    printf("\nThank you for using the C Ebook Reader Program! Goodbye!\n");

    return 0;
}