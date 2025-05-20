//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100
#define MAX_BOOK_DESCRIPTION_LENGTH 1000

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
} Book;

int main() {
    FILE *fp;
    fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int numBooks = 0;
    Book books[MAX_BOOKS];
    while (fscanf(fp, "%s %s %s", books[numBooks].name, books[numBooks].author, books[numBooks].description)!= EOF) {
        numBooks++;
        if (numBooks == MAX_BOOKS) {
            break;
        }
    }
    fclose(fp);

    printf("Welcome to the Ada Lovelace Ebook Reader!\n");
    printf("Please select a book from the following list:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s\n", i + 1, books[i].name, books[i].author);
    }

    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > numBooks) {
        printf("Invalid selection. Exiting program.\n");
        exit(1);
    }

    printf("You have selected '%s' by %s.\n", books[choice - 1].name, books[choice - 1].author);
    printf("Book description:\n%s\n", books[choice - 1].description);

    return 0;
}