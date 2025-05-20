//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR_NAME 50

typedef struct{
    char title[50];
    char author[MAX_AUTHOR_NAME];
    int year;
    float price;
} Book;

int main(){
    int numBooks;
    Book books[MAX_BOOKS];

    printf("Welcome to the Ebook Reader Program!\n");
    printf("Please enter the number of books you want to add: ");
    scanf("%d", &numBooks);

    for(int i = 0; i < numBooks; i++){
        printf("\nBook #%d\n", i+1);

        printf("Title: ");
        scanf("%s", books[i].title);

        printf("Author's name: ");
        scanf("%s", books[i].author);

        printf("Year: ");
        scanf("%d", &books[i].year);

        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\n\nYour books:\n");

    for(int i = 0; i < numBooks; i++){
        printf("\nBook #%d\n", i+1);

        printf("Title: %s\n", books[i].title);

        printf("Author: %s\n", books[i].author);

        printf("Year: %d\n", books[i].year);

        printf("Price: $%.2f\n", books[i].price);
    }

    printf("\nThank you for using the Ebook Reader Program!\n");

    return 0;
}