//FormAI DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
    char title[50];
    char author[50];
    char publisher[50];
    char language[10];
    int pages;
};

int main() {
    int num_books, i;
    printf("How many Ebooks do you want to add? ");
    scanf("%d", &num_books);

    struct Ebook* books = (struct Ebook*)malloc(num_books * sizeof(struct Ebook));

    printf("Enter details of each Ebook:\n");
    for (i = 0; i < num_books; i++) {
        printf("Ebook %d:\n", i+1);
        printf("Enter Title: ");
        scanf("%s", books[i].title);
        printf("Enter Author: ");
        scanf("%s", books[i].author);
        printf("Enter Publisher: ");
        scanf("%s", books[i].publisher);
        printf("Enter Language: ");
        scanf("%s", books[i].language);
        printf("Enter Number of Pages: ");
        scanf("%d", &books[i].pages);
        printf("\n");
    }

    int choice;
    while (1) {
        printf("\n1. Display all Ebooks\n");
        printf("2. Search for an Ebook by Title\n");
        printf("3. Exit\n");

        printf("\nEnter choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nDisplaying all Ebooks:\n");
            for (i = 0; i < num_books; i++) {
                printf("Title: %s\n", books[i].title);
                printf("Author: %s\n", books[i].author);
                printf("Publisher: %s\n", books[i].publisher);
                printf("Language: %s\n", books[i].language);
                printf("Pages: %d\n\n", books[i].pages);
            }
        }
        else if (choice == 2) {
            char search_title[50];
            int found = 0;
            printf("\nEnter title to search for: ");
            scanf("%s", search_title);
            for (i = 0; i < num_books; i++) {
                if (strcmp(search_title, books[i].title) == 0) {
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Publisher: %s\n", books[i].publisher);
                    printf("Language: %s\n", books[i].language);
                    printf("Pages: %d\n\n", books[i].pages);
                    found = 1;
                }
            }
            if (!found) {
                printf("\nBook not found with title %s\n", search_title);
            }
        }
        else if (choice == 3) {
            printf("\nExiting Program. Goodbye!\n");
            break;
        }
        else {
            printf("\nInvalid Choice. Please enter a choice between 1-3.\n");
        }
    }

    free(books);

    return 0;
}