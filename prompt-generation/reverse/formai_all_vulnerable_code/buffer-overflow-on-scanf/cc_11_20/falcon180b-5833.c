//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
} Book;

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    printf("Welcome to the Ebook Reader!\n");
    while (true) {
        printf("\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Search for a book\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numBooks >= MAX_BOOKS) {
                printf("Sorry, you cannot add more books.\n");
                break;
            }

            printf("Enter book name: ");
            scanf("%s", books[numBooks].name);
            printf("Enter author name: ");
            scanf("%s", books[numBooks].author);
            printf("Enter book description: ");
            scanf("%s", books[numBooks].description);

            numBooks++;
            printf("Book added successfully!\n");
            break;

        case 2:
            if (numBooks == 0) {
                printf("No books found.\n");
            } else {
                printf("\nList of books:\n");
                for (int i = 0; i < numBooks; i++) {
                    printf("%d. %s by %s\n%s\n", i + 1, books[i].name, books[i].author, books[i].description);
                }
            }
            break;

        case 3:
            printf("Enter book name to search: ");
            char searchTerm[MAX_BOOK_NAME_LENGTH];
            scanf("%s", searchTerm);

            bool found = false;
            for (int i = 0; i < numBooks; i++) {
                if (strcmp(books[i].name, searchTerm) == 0) {
                    printf("\nBook found:\n");
                    printf("%s by %s\n%s\n", books[i].name, books[i].author, books[i].description);
                    found = true;
                }
            }

            if (!found) {
                printf("Book not found.\n");
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}