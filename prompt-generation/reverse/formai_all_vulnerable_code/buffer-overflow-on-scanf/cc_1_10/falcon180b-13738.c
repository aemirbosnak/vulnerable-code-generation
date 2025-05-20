//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_SUMMARY_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    char summary[MAX_SUMMARY_LEN];
} Book;

Book books[MAX_BOOKS];
int numBooks;

void addBook() {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter author name: ");
    scanf("%s", books[numBooks].author);
    printf("Enter genre: ");
    scanf("%s", books[numBooks].genre);
    printf("Enter summary: ");
    scanf("%s", books[numBooks].summary);
    numBooks++;
}

void displayBooks() {
    printf("\nBook List:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%s)\n", i+1, books[i].title, books[i].author, books[i].genre);
        printf("%s\n\n", books[i].summary);
    }
}

void searchBookByTitle() {
    char searchTitle[MAX_TITLE_LEN];
    printf("Enter book title to search: ");
    scanf("%s", searchTitle);
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("\nBook found:\n");
            printf("%s by %s (%s)\n", books[i].title, books[i].author, books[i].genre);
            printf("%s\n", books[i].summary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    printf("Welcome to the Ebook Reader!\n");
    while (1) {
        printf("\n1. Add book\n2. Display book list\n3. Search book by title\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBookByTitle();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}