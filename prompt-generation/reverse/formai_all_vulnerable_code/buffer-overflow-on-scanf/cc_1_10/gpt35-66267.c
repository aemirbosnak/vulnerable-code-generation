//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char genre[20];
    float price;
} Book;

int main() {
    int books_count = 0;
    printf("Welcome to the Cybertech Ebook Reader.\n\n");

    while(1) {
        printf("Please enter how many books you want to add to your library: ");
        scanf("%d", &books_count);

        if (books_count < 1) {
            printf("Invalid input. Please enter a number greater than 0.\n");
        } else {
            break;
        }
    }

    Book *books = malloc(sizeof(Book) * books_count);

    for (int i = 0; i < books_count; i++) {
        printf("\nEnter Book %d Details:\n", i+1);

        printf("Title: ");
        scanf("%s", books[i].title);

        printf("Author: ");
        scanf("%s", books[i].author);

        printf("Genre: ");
        scanf("%s", books[i].genre);

        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\nYour library has been successfully created!\n");

    while(1) {
        int book_index = -1;
        char book_title[50];

        printf("\nEnter the title of the book you want to read (or type 'exit' to quit): ");
        scanf("%s", book_title);

        if(strcmp(book_title, "exit") == 0){
            break;
        }

        for (int i = 0; i < books_count; i++) {
            if(strcmp(books[i].title, book_title) == 0){
                book_index = i;
                break;
            }
        }

        if(book_index == -1){
            printf("Sorry, the book you entered does not exist in your library.\n");
        } else {
            printf("Here are the details of the book you selected:\n\n");

            printf("Title: %s\n", books[book_index].title);
            printf("Author: %s\n", books[book_index].author);
            printf("Genre: %s\n", books[book_index].genre);
            printf("Price: %.2f\n", books[book_index].price);

            printf("\nReading book...\n\n");
        }
    }

    free(books);

    printf("\nThank you for using the Cybertech Ebook Reader. Goodbye!\n");

    return 0;
}