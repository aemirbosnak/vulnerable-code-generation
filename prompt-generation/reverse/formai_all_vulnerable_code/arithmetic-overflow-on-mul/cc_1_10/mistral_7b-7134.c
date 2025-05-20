//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TABLE_SIZE 101

typedef struct Book {
    char title[50];
    int published_year;
    float price;
    struct Book *next;
} Book;

int hash_func(const char *str) {
    int hash = 0, i;
    for (i = 0; str[i]; i++)
        hash = (hash * 33) ^ str[i];
    return (hash % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

Book *create_book(const char *title, int published_year, float price) {
    Book *new_book = (Book *)malloc(sizeof(Book));
    strcpy(new_book->title, title);
    new_book->published_year = published_year;
    new_book->price = price;
    new_book->next = NULL;
    return new_book;
}

void insert_book(Book **hash_table, const char *title, int published_year, float price) {
    int index = hash_func(title);
    Book *new_book = create_book(title, published_year, price);

    if (!hash_table[index]) {
        hash_table[index] = new_book;
    } else {
        Book *current = hash_table[index];
        while (current && strcmp(current->title, title) < 0)
            current = current->next;

        if (current)
            new_book->next = current;
        else
            hash_table[index] = new_book;
    }
}

void print_book(const Book *book) {
    printf("%s (%d) - $%.2f\n", book->title, book->published_year, book->price);
}

void search_book(const Book **hash_table, const char *title) {
    int index = hash_func(title);
    Book *current = hash_table[index];

    if (!current) {
        printf("Book not found.\n");
        return;
    }

    while (current && strcmp(current->title, title) < 0)
        current = current->next;

    if (current)
        print_book(current);
    else
        printf("Book not found.\n");
}

int main() {
    Book *hash_table[TABLE_SIZE];

    insert_book(hash_table, "The Art of Computer Programming", 1968, 10.0);
    insert_book(hash_table, "The C Programming Language", 1978, 15.0);
    insert_book(hash_table, "Concrete Mathematics", 1991, 18.0);
    insert_book(hash_table, "Cracking the Coding Interview", 2001, 20.0);
    insert_book(hash_table, "A Beautiful Mind", 1998, 25.0);

    search_book(hash_table, "The Art of Computer Programming");
    search_book(hash_table, "Cracking the Coding Interview");
    search_book(hash_table, "The C Programming Language");
    search_book(hash_table, "A Hitchhiker's Guide to the Galaxy"); // Not in the table

    return 0;
}