//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

typedef struct book Book;

void displayBookDetails(Book b) {
    printf("\nTitle: %s\nAuthor: %s\nPages: %d\nPrice: $%.2f\n", b.title, b.author, b.pages, b.price);
}

int main() {
    int numBooks;
    printf("How many books do you want to add? ");
    scanf("%d", &numBooks);
    Book *myLibrary = (Book*)malloc(numBooks * sizeof(Book));

    for (int i=0; i<numBooks; i++) {
        printf("\nEnter details for book #%d:\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]s", myLibrary[i].title);
        printf("Author: ");
        scanf(" %[^\n]s", myLibrary[i].author);
        printf("Number of pages: ");
        scanf("%d", &myLibrary[i].pages);
        printf("Price: ");
        scanf("%f", &myLibrary[i].price);
    }

    while (1) {
        printf("\nEnter the book number to read or 0 to exit: ");
        int selection;
        scanf("%d", &selection);
        if (selection == 0) {
            break;  
        }
        else if (selection > 0 && selection <= numBooks) {
            displayBookDetails(myLibrary[selection-1]);
        }
        else {
            printf("Invalid selection.\n");
        }
    }

    free(myLibrary);

    return 0;
}