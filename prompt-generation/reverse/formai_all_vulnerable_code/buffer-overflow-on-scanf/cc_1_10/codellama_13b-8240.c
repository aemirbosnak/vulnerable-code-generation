//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *publisher;
    int pages;
    float price;
} book;

book books[] = {
    {"The C Programming Language", "Dennis Ritchie", "Prentice Hall", 546, 59.99},
    {"The C++ Programming Language", "Bjarne Stroustrup", "Addison-Wesley", 768, 65.99},
    {"Introduction to Algorithms", "Thomas H. Cormen", "MIT Press", 1184, 135.99},
    {"The Art of Computer Programming", "Donald E. Knuth", "Addison-Wesley", 1312, 115.99},
    {"The C Programming Language, 2nd Edition", "Brian W. Kernighan", "Prentice Hall", 546, 65.99},
    {"The C++ Programming Language, 2nd Edition", "Bjarne Stroustrup", "Addison-Wesley", 768, 85.99},
    {"Introduction to Algorithms, 3rd Edition", "Thomas H. Cormen", "MIT Press", 1296, 155.99},
    {"The Art of Computer Programming, Vol. 1", "Donald E. Knuth", "Addison-Wesley", 972, 125.99},
    {"The Art of Computer Programming, Vol. 2", "Donald E. Knuth", "Addison-Wesley", 1032, 135.99},
    {"The Art of Computer Programming, Vol. 3", "Donald E. Knuth", "Addison-Wesley", 1088, 145.99}
};

int main() {
    int i, j, n;
    char search_title[50];
    char search_author[50];
    char search_publisher[50];
    char search_price[50];
    float search_price_float;

    printf("Enter a book title, author, publisher, or price to search for: ");
    scanf("%s %s %s %s", search_title, search_author, search_publisher, search_price);
    search_price_float = atof(search_price);

    for (i = 0; i < sizeof(books) / sizeof(book); i++) {
        if (strcmp(books[i].title, search_title) == 0 || strcmp(books[i].author, search_author) == 0 ||
            strcmp(books[i].publisher, search_publisher) == 0 || books[i].price == search_price_float) {
            printf("Found a match: ");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Publisher: %s\n", books[i].publisher);
            printf("Price: $%.2f\n", books[i].price);
        }
    }

    return 0;
}