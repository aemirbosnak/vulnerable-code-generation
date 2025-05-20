//FormAI DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct ebook {
    char title[50];
    char author[50];
    int pages;
    double price;
};

int main() {
    int num_of_books, i = 0;
    printf("How many ebooks do you want to enter? ");
    scanf("%d", &num_of_books);

    // Dynamically allocating memory for the array of structs
    struct ebook *books = (struct ebook*) malloc(num_of_books * sizeof(struct ebook));

    // Taking user input for each ebook
    while (i < num_of_books) {
        printf("\nEnter details for Ebook %d: \n", i+1);

        printf("Title: ");
        scanf(" %[^\n]%*c", books[i].title);

        printf("Author: ");
        scanf(" %[^\n]%*c", books[i].author);

        printf("Number of pages: ");
        scanf("%d", &books[i].pages);

        printf("Price: ");
        scanf("%lf", &books[i].price);

        i++;
    }

    // Displaying the details of all the ebooks
    printf("\nDetails of all ebooks: \n");
    for (int j = 0; j < num_of_books; j++) {
        printf("\nEbook %d: \n", j+1);
        printf("Title: %s\n", books[j].title);
        printf("Author: %s\n", books[j].author);
        printf("Number of pages: %d\n", books[j].pages);
        printf("Price: $%.2lf\n", books[j].price);
    }

    // Freeing the dynamically allocated memory
    free(books);

    return 0;
}