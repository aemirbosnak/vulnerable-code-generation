//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char title[50];
    char author[50];
    char genre[20];
    char file_name[50];
} Book;

int main() {
    Book my_books[] = {
        {"C Programming", "Dennis Ritchie", "Programming", "c_programming.pdf"},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Fiction", "great_gatsby.pdf"},
        {"The Alchemist", "Paulo Coelho", "Fiction", "the_alchemist.pdf"},
    };

    int num_books = sizeof(my_books) / sizeof(Book);

    printf("Welcome to My Ebook Reader!\n\n");
    printf("Please select a book from the following list:\n");

    for(int i = 0; i < num_books; i++) {
        printf("%d. %s by %s (%s)\n", i+1, my_books[i].title, my_books[i].author, my_books[i].genre);
    }

    int selected_book = 0;
    while(selected_book < 1 || selected_book > num_books) {
        printf("\nEnter the number of the book you want to read: ");
        scanf("%d", &selected_book);
        if(selected_book < 1 || selected_book > num_books) {
            printf("Invalid selection. Please enter a number between 1 and %d.\n", num_books);
        }
    }

    Book book_to_read = my_books[selected_book-1];
    printf("\nOpening %s by %s...\n\n", book_to_read.title, book_to_read.author);

    FILE *fp = fopen(book_to_read.file_name, "r");
    if(fp == NULL) {
        printf("Error opening file %s.\n", book_to_read.file_name);
        return 1;
    }

    int c;
    while((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);

    printf("\n\nThank you for using My Ebook Reader!\n");
    return 0;
}