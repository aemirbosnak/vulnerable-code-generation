//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *filename;
} Book;

int main() {
    int num_books;
    printf("Please enter the number of books you want to add: ");
    scanf("%d", &num_books);
    printf("\n");

    Book *books = (Book*)malloc(num_books * sizeof(Book));

    for (int i = 0; i < num_books; i++) {
        char title[100];
        char author[100];
        char filename[100];
        printf("Please enter the title of book %d: ", i+1);
        scanf("%s", title);
        printf("\n");

        printf("Please enter the author of book %d: ", i+1);
        scanf("%s", author);
        printf("\n");

        printf("Please enter the filename of book %d: ", i+1);
        scanf("%s", filename);
        printf("\n");

        books[i].title = (char*)malloc((strlen(title)+1) * sizeof(char));
        books[i].author = (char*)malloc((strlen(author)+1) * sizeof(char));
        books[i].filename = (char*)malloc((strlen(filename)+1) * sizeof(char));
        strcpy(books[i].title, title);
        strcpy(books[i].author, author);
        strcpy(books[i].filename, filename);
    }

    int choice = 0;
    do {
        printf("[1] View all books\n");
        printf("[2] Read a book\n");
        printf("[3] Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Books\n");
                printf("-----\n");
                for (int i = 0; i < num_books; i++) {
                    printf("[%d] %s by %s\n", i+1, books[i].title, books[i].author);
                }
                printf("\n");
                break;
            case 2:
                printf("Which book do you want to read? ");
                int index;
                scanf("%d", &index);
                if (index < 1 || index > num_books) {
                    printf("Invalid book selected.\n\n");
                    break;
                }

                char command[200];
                snprintf(command, sizeof(command), "open %s", books[index-1].filename);
                system(command);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;

        }
    } while (choice != 3);

    for (int i = 0; i < num_books; i++) {
        free(books[i].title);
        free(books[i].author);
        free(books[i].filename);
    }
    free(books);

    return 0;
}