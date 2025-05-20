//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    int pages;
};

void printBook(struct book b) {
    printf("\nTitle: %s\nAuthor: %s\nPages: %d\n", b.title, b.author, b.pages);
}

int main() {
    struct book booksInLibrary[3];
    strcpy(booksInLibrary[0].title, "The Catcher in the Rye");
    strcpy(booksInLibrary[0].author, "J.D. Salinger");
    booksInLibrary[0].pages = 224;
    strcpy(booksInLibrary[1].title, "1984");
    strcpy(booksInLibrary[1].author, "George Orwell");
    booksInLibrary[1].pages = 328;
    strcpy(booksInLibrary[2].title, "Pride and Prejudice");
    strcpy(booksInLibrary[2].author, "Jane Austen");
    booksInLibrary[2].pages = 432;
    int choice;
    printf("Enter the number of the book you wish to read:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d - %s by %s\n", i, booksInLibrary[i].title, booksInLibrary[i].author);
    }
    scanf("%d", &choice);
    if (choice < 0 || choice > 2) {
        printf("Invalid choice.\n");
        exit(0);
    }
    printBook(booksInLibrary[choice]);
    printf("\nWelcome to the Ebook reader for %s.\n", booksInLibrary[choice].title);
    printf("Press 1 to start reading, 2 to bookmark, or 3 to exit.\n");
    int readChoice;
    scanf("%d", &readChoice);
    int bookmarkedPage = 0;
    while (readChoice != 3) {
        switch (readChoice) {
            case 1:
                printf("You are now reading %s.\n", booksInLibrary[choice].title);
                printf("Press enter to turn the page.\n");
                getchar();
                bookmarkedPage++;
                break;
            case 2:
                printf("You have bookmarked page %d.\n", bookmarkedPage);
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("Press 1 to continue reading, 2 to bookmark, or 3 to exit.\n");
        scanf("%d", &readChoice);
    }
    printf("Thank you for reading %s.\n", booksInLibrary[choice].title);
    return 0;
}