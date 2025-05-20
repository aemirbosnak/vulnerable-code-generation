//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice;
    char book_title[20];
    char book_author[20];
    FILE *book_file;

    printf("Welcome to the immersive ebook reader!\n");
    printf("Please choose an option:\n");
    printf("1. Open a book\n");
    printf("2. Search for a book\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the book title: ");
            scanf("%s", book_title);

            printf("Enter the book author: ");
            scanf("%s", book_author);

            book_file = fopen(book_title, "r");

            if (book_file == NULL)
            {
                printf("Error opening book file.\n");
            }
            else
            {
                printf("Book title: %s\n", book_title);
                printf("Book author: %s\n", book_author);

                char book_content[1000];

                while (fgets(book_content, 1000, book_file) != NULL)
                {
                    printf("%s", book_content);
                }

                fclose(book_file);
            }
            break;

        case 2:
            printf("Enter the book title: ");
            scanf("%s", book_title);

            book_file = fopen(book_title, "r");

            if (book_file == NULL)
            {
                printf("Error opening book file.\n");
            }
            else
            {
                char book_content[1000];

                while (fgets(book_content, 1000, book_file) != NULL)
                {
                    printf("%s", book_content);
                }

                fclose(book_file);
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}