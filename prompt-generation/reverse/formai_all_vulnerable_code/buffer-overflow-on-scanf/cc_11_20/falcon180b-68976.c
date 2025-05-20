//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    bool is_read;
} Book;

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (true) {
        printf("Enter a book title (or type 'done' to finish):\n");
        scanf("%s", books[num_books].title);
        if (strcmp(books[num_books].title, "done") == 0) {
            break;
        }
        printf("Enter the author:\n");
        scanf("%s", books[num_books].author);
        printf("Enter the genre:\n");
        scanf("%s", books[num_books].genre);
        books[num_books].is_read = false;
        num_books++;
    }

    printf("You have entered %d books.\n", num_books);

    while (true) {
        int choice;
        printf("Select an option:\n");
        printf("1. View all books\n");
        printf("2. Mark a book as read\n");
        printf("3. Search for a book\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < num_books; i++) {
                printf("%s by %s (%s) - read: %s\n", books[i].title, books[i].author, books[i].genre, books[i].is_read? "yes" : "no");
            }
            break;
        case 2:
            printf("Enter the title of the book to mark as read:\n");
            scanf("%s", books[num_books - 1].title);
            books[num_books - 1].is_read = true;
            break;
        case 3:
            printf("Enter a search term:\n");
            char search_term[MAX_TITLE_LENGTH];
            scanf("%s", search_term);
            for (int i = 0; i < num_books; i++) {
                if (strcmp(books[i].title, search_term) == 0) {
                    printf("%s by %s (%s)\n", books[i].title, books[i].author, books[i].genre);
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}