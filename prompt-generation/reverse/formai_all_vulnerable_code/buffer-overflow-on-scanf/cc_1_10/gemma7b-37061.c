//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ebook {
    char title[50];
    char author[50];
    char genre[50];
    int pages;
    float price;
} Ebook;

Ebook ebooks[100];

void addEbook() {
    Ebook newBook;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter author's name: ");
    scanf("%s", newBook.author);
    printf("Enter genre: ");
    scanf("%s", newBook.genre);
    printf("Enter number of pages: ");
    scanf("%d", &newBook.pages);
    printf("Enter book price: ");
    scanf("%f", &newBook.price);

    strcpy(ebooks[0].title, newBook.title);
    strcpy(ebooks[0].author, newBook.author);
    strcpy(ebooks[0].genre, newBook.genre);
    ebooks[0].pages = newBook.pages;
    ebooks[0].price = newBook.price;

    for (int i = 1; ebooks[i].title[0] != '\0'; i++) {
        ebooks[i].pages++;
    }
}

void listEbooks() {
    printf("List of ebooks:\n");
    for (int i = 0; ebooks[i].title[0] != '\0'; i++) {
        printf("Title: %s\n", ebooks[i].title);
        printf("Author: %s\n", ebooks[i].author);
        printf("Genre: %s\n", ebooks[i].genre);
        printf("Pages: %d\n", ebooks[i].pages);
        printf("Price: %.2f\n", ebooks[i].price);
        printf("\n");
    }
}

int main() {
    addEbook();
    listEbooks();

    return 0;
}