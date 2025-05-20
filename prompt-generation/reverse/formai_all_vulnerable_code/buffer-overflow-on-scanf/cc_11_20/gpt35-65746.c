//FormAI DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
    char title[50];
    char author[50];
    char genre[20];
    float price;
    int rating;
    int pages;
}book;

int main()
{
    FILE *fptr;
    char e_title[50], ch;
    int choice, i;
    long int fileSize;

    printf("\n Welcome to Unique Ebook Reader!\n");
    printf("------------------------------\n");

    do {
        printf("\nPlease choose an option: \n");
        printf("1. View Ebook Details\n");
        printf("2. Search Ebook\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\nEnter the title of the Ebook you want to view: ");
            scanf("%s", e_title);

            fptr = fopen("ebooks.dat", "rb");

            if (fptr == NULL) {
                printf("\nError opening file\n");
                exit(1);
            }

            fseek(fptr, 0, SEEK_END);
            fileSize = ftell(fptr);
            rewind(fptr);

            while (ftell(fptr) < fileSize) {
                fread(&book, sizeof(book), 1, fptr);

                if (strcmp(book.title, e_title) == 0) {
                    printf("\nTitle: %s \nAuthor: %s \nGenre: %s \nPrice: $%.2f \nRating: %d stars \nTotal Pages: %d\n", book.title, book.author, book.genre, book.price, book.rating, book.pages);
                    break;
                }
            }
            if (ftell(fptr) == fileSize) {
                printf("\nEbook not found\n");
            }

            fclose(fptr);

            break;

        case 2:

            printf("\nEnter the title of the Ebook you want to search for: ");
            scanf("%s", e_title);

            fptr = fopen("ebooks.dat", "rb");

            if (fptr == NULL) {
                printf("\nError opening file\n");
                exit(1);
            }

            fseek(fptr, 0, SEEK_END);
            fileSize = ftell(fptr);
            rewind(fptr);

            while (ftell(fptr) < fileSize) {
                fread(&book, sizeof(book), 1, fptr);

                if (strstr(book.title, e_title) != NULL) {
                    printf("\nTitle: %s \nAuthor: %s \nGenre: %s \nPrice: $%.2f \nRating: %d stars \nTotal Pages: %d\n", book.title, book.author, book.genre, book.price, book.rating, book.pages);
                }
            }

            fclose(fptr);

            break;

        case 3:
            printf("\nThank you for using Unique Ebook Reader!\n");
            printf("------------------------------\n");
            exit(0);

        default:
            printf("\nInvalid choice, please try again!\n");
            break;
        }

    } while (1);

    return 0;
}