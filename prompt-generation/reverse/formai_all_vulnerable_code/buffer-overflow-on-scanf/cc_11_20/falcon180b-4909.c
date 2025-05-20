//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

int main() {
    int choice, num_books = 0;
    char filename[20];
    FILE *fp;
    Book books[MAX_BOOKS];

    printf("Welcome to the Ebook Reader!\n");
    printf("Please choose an option:\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search for a book\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the filename of the book: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if (fp == NULL) {
                printf("Error: File not found.\n");
            } else {
                fseek(fp, 0, SEEK_END);
                int size = ftell(fp);
                fseek(fp, 0, SEEK_SET);

                if (num_books >= MAX_BOOKS) {
                    printf("Error: Maximum number of books reached.\n");
                } else {
                    books[num_books].title[0] = '\0';
                    books[num_books].author[0] = '\0';
                    books[num_books].content[0] = '\0';

                    char line[MAX_TITLE_LENGTH];
                    fgets(line, MAX_TITLE_LENGTH, fp);
                    strcpy(books[num_books].title, line);

                    fgets(line, MAX_AUTHOR_LENGTH, fp);
                    strcpy(books[num_books].author, line);

                    fgets(line, MAX_CONTENT_LENGTH, fp);
                    strcpy(books[num_books].content, line);

                    num_books++;
                    printf("Book added successfully.\n");
                }

                fclose(fp);
            }

            break;

        case 2:
            if (num_books == 0) {
                printf("No books found.\n");
            } else {
                printf("List of books:\n");
                for (int i = 0; i < num_books; i++) {
                    printf("%d. Title: %s\nAuthor: %s\n", i+1, books[i].title, books[i].author);
                }
            }

            break;

        case 3:
            printf("Enter the title or author of the book to search: ");
            scanf("%s", filename);

            for (int i = 0; i < num_books; i++) {
                if (strstr(books[i].title, filename)!= NULL || strstr(books[i].author, filename)!= NULL) {
                    printf("%d. Title: %s\nAuthor: %s\n", i+1, books[i].title, books[i].author);
                }
            }

            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}