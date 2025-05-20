//FormAI DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EBook {
    char title[50];
    char author[50];
    char genre[20];
    int yearPublished;
    char filename[50];
} EBook;

void readEBookInfo(EBook *book) {
    printf("Enter Title: ");
    scanf("%s", book->title);
    printf("Enter Author: ");
    scanf("%s", book->author);
    printf("Enter Genre: ");
    scanf("%s", book->genre);
    printf("Enter Year Published: ");
    scanf("%d", &book->yearPublished);
    printf("Enter Filename: ");
    scanf("%s", book->filename);
}

void displayEBookInfo(EBook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Genre: %s\n", book.genre);
    printf("Year Published: %d\n", book.yearPublished);
    printf("Filename: %s\n", book.filename);
}

void displayEBookList(EBook *bookList, int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s\n", i+1, bookList[i].title);
    }
}

int main() {
    int numBooks = 0;
    EBook *bookList = NULL;
    int choice;

    do {
        printf("\nEBook Reader Menu:\n");
        printf("1. Add New EBook\n");
        printf("2. View EBook List\n");
        printf("3. Open EBook\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                numBooks++;
                bookList = (EBook*) realloc(bookList, numBooks * sizeof(EBook));
                readEBookInfo(&bookList[numBooks-1]);
                printf("EBook Added Successfully!\n");
                break;
            case 2:
                if (numBooks == 0) {
                    printf("No EBooks found!\n");
                } else {
                    printf("\nEBook List:\n");
                    displayEBookList(bookList, numBooks);
                }
                break;
            case 3:
                if (numBooks == 0) {
                    printf("No EBooks found!\n");
                } else {
                    int selection;
                    printf("\nEnter EBook number: ");
                    scanf("%d", &selection);
                    if (selection >= 1 && selection <= numBooks) {
                        printf("\nOpening EBook %s...\n", bookList[selection-1].title);
                        // Insert Code to Open EBook File Here
                    } else {
                        printf("Invalid Selection!\n");
                    }
                }
                break;
            case 4:
                printf("Exiting EBook Reader...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    free(bookList);

    return 0;
}