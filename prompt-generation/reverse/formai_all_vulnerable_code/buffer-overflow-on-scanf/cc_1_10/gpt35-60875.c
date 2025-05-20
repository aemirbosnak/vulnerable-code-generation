//FormAI DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int year;
    float price;
} Ebook;

int main() {
    Ebook library[10]; // can hold up to 10 ebooks
    int num_books = 0; // counter for number of ebooks

    // display welcome message and instructions
    printf("Welcome to the Ebook Library!\n");
    printf("To add a new Ebook, enter the following information:\n");

    // get user input for new ebook
    char title[100];
    char author[50];
    int year;
    float price;

    printf("Title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Author: ");
    fgets(author, 50, stdin);
    author[strcspn(author, "\n")] = '\0';

    printf("Year of publication: ");
    scanf("%d", &year);
    fflush(stdin);

    printf("Price: ");
    scanf("%f", &price);
    fflush(stdin);

    // store new ebook in library
    Ebook new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.year = year;
    new_book.price = price;

    library[num_books] = new_book;
    num_books++;

    // display library
    printf("Ebook Library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s (%d) - $%.2f\n", i+1, library[i].title, library[i].author, library[i].year, library[i].price);
    }

    return 0;
}