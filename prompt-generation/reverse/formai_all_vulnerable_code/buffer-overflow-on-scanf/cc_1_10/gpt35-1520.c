//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char title[100];
    char author[100];
    char isbn[13];
    char content[10000];
} book;

void printMenu() {
    printf("\nEBOOK READER\n");
    printf("1. View Book\n");
    printf("2. Go to Next Page\n");
    printf("3. Go to Previous Page\n");
    printf("4. Quit\n");
}

int main() {
    book myBook = {"The Great Gatsby", "F. Scott Fitzgerald", "978-0199536405", "content of the book"};
    int currentPage = 0;
    int totalPages = 100;
    int choice = 0;

    while (choice != 4) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nTitle: %s\nAuthor: %s\nISBN: %s\nPage %d of %d\n\n", myBook.title, myBook.author, myBook.isbn, currentPage+1, totalPages);
                printf("%s", myBook.content);
                break;
            case 2:
                if (currentPage < totalPages) {
                    currentPage++;
                    printf("Page %d of %d\n", currentPage+1, totalPages);
                }
                else {
                    printf("End of book.\n");
                }
                break;
            case 3:
                if (currentPage > 0) {
                    currentPage--;
                    printf("Page %d of %d\n", currentPage+1, totalPages);
                }
                else {
                    printf("Beginning of book.\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}