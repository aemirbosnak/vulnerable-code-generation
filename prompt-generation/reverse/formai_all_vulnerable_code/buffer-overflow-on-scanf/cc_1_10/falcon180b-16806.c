//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOK_LENGTH 1000000 // 1 million characters

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_BOOK_LENGTH];
} Book;

int main() {
    FILE *fp;
    char filename[50];
    int choice, search_result;
    Book book;

    printf("Enter the name of the ebook file (with extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    if (filesize <= 0 || filesize >= MAX_BOOK_LENGTH) {
        printf("Error: Invalid file size.\n");
        fclose(fp);
        exit(1);
    }

    fread(&book, sizeof(Book), 1, fp);
    fclose(fp);

    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Read ebook\n");
        printf("2. Search for a word/phrase\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEbook content:\n%s", book.content);
                break;
            case 2:
                printf("\nEnter the word/phrase to search: ");
                scanf("%s", book.content); // overwrite the content with the search query
                search_result = strstr(book.content, book.content)!= NULL;
                if (search_result) {
                    printf("\nThe word/phrase was found in the ebook.\n");
                } else {
                    printf("\nThe word/phrase was not found in the ebook.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}