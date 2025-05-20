//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <string.h>

struct book {
    char title[100];
    char author[50];
    int year;
    float price;
};

int main()
{
    struct book ebooks[5];
    int i, choice, year;
    char author[50];

    // Book details input
    for (i = 0; i < 5; i++) {
        printf("Enter details of Ebook %d:\n", i+1);
        printf("Title: ");
        fflush(stdin);
        gets(ebooks[i].title);
        printf("Author: ");
        fflush(stdin);
        gets(ebooks[i].author);
        printf("Year published: ");
        scanf("%d", &ebooks[i].year);
        printf("Price: ");
        scanf("%f", &ebooks[i].price);
    }

    // Menu for user
    do {
        printf("\n\nChoose an option: \n");
        printf("1. Display all books\n");
        printf("2. Display books by author\n");
        printf("3. Display books published in a year\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDetails of all books:\n\n");
                printf("Title\tAuthor\tYear\tPrice\n");
                for (i = 0; i < 5; i++) {
                    printf("%s\t%s\t%d\t%.2f\n", ebooks[i].title, ebooks[i].author, ebooks[i].year, ebooks[i].price);
                }
                break;
            case 2:
                printf("\nEnter author name: ");
                fflush(stdin);
                gets(author);
                printf("\nDetails of books by author %s:\n\n", author);
                printf("Title\tAuthor\tYear\tPrice\n");
                for (i = 0; i < 5; i++) {
                    if (strcmp(ebooks[i].author, author) == 0) {
                        printf("%s\t%s\t%d\t%.2f\n", ebooks[i].title, ebooks[i].author, ebooks[i].year, ebooks[i].price);
                    }
                }
                break;
            case 3:
                printf("\nEnter year: ");
                scanf("%d", &year);
                printf("\nDetails of books published in %d:\n\n", year);
                printf("Title\tAuthor\tYear\tPrice\n");
                for (i = 0; i < 5; i++) {
                    if (ebooks[i].year == year) {
                        printf("%s\t%s\t%d\t%.2f\n", ebooks[i].title, ebooks[i].author, ebooks[i].year, ebooks[i].price);
                    }
                }
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}