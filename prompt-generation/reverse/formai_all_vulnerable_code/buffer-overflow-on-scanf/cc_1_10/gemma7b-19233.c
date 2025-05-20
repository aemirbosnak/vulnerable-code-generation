//Gemma-7B DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_SIZE 1024

typedef struct Book {
    char title[50];
    char author[50];
    int year;
    float price;
} Book;

Book books[1000];

int main() {

    // Inserting sample data
    Book book1 = {"The Lord of the Flies", "William Golding", 1954, 12.5};
    Book book2 = {"To Kill a Mockingbird", "Harper Lee", 1960, 15.0};
    Book book3 = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 17.5};

    books[0] = book1;
    books[1] = book2;
    books[2] = book3;

    // Querying the database
    char query[MAX_QUERY_SIZE];

    printf("Enter your query: ");
    scanf("%s", query);

    // Matching books to the query
    int result = matchBooks(query);

    // Printing the results
    if (result) {
        printf("Results:\n");
        for (int i = 0; books[i].title && matchBook(query, books[i]); i++) {
            printf("%s by %s, %d\n", books[i].title, books[i].author, books[i].year);
        }
    } else {
        printf("No books found.\n");
    }

    return 0;
}

int matchBooks(char *query) {
    for (int i = 0; books[i].title; i++) {
        if (matchBook(query, books[i])) {
            return 1;
        }
    }

    return 0;
}

int matchBook(char *query, Book book) {
    return strstr(book.title, query) || strstr(book.author, query) || book.year == atoi(query) || book.price == atof(query);
}