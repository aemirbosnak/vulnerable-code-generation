//FormAI DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[50];
    int year;
    double price;
    char isbn[20];
    char* file_name; // for storing name of the ebook file
};

void read_book(struct book* book_ptr) {
    // read book details from user
    printf("Enter title: ");
    fgets(book_ptr->title, sizeof(book_ptr->title), stdin);
    book_ptr->title[strcspn(book_ptr->title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(book_ptr->author, sizeof(book_ptr->author), stdin);
    book_ptr->author[strcspn(book_ptr->author, "\n")] = '\0';

    printf("Enter year of publication: ");
    scanf("%d", &book_ptr->year);

    printf("Enter price: ");
    scanf("%lf", &book_ptr->price);

    printf("Enter ISBN: ");
    getchar(); // flush newline character from input buffer
    fgets(book_ptr->isbn, sizeof(book_ptr->isbn), stdin);
    book_ptr->isbn[strcspn(book_ptr->isbn, "\n")] = '\0';
}

void display_book(struct book* book_ptr) {
    // display book details
    printf("\nTitle: %s\n", book_ptr->title);
    printf("Author: %s\n", book_ptr->author);
    printf("Year of publication: %d\n", book_ptr->year);
    printf("Price: $%.2lf\n", book_ptr->price);
    printf("ISBN: %s\n", book_ptr->isbn);
}

void read_books(struct book* books_ptr, int num_books) {
    // read details for multiple books
    for (int i = 0; i < num_books; i++) {
        printf("\nEnter details for book %d:\n", i + 1);
        read_book(&books_ptr[i]);
    }
}

void display_books(struct book* books_ptr, int num_books) {
    // display details for multiple books
    for (int i = 0; i < num_books; i++) {
        printf("\nDetails for book %d:\n", i + 1);
        display_book(&books_ptr[i]);
    }
}

int main() {
    int num_books;
    struct book* books_ptr;
    char filename[100];

    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    // allocate memory for the books array
    books_ptr = (struct book*)malloc(num_books * sizeof(struct book));
    if (books_ptr == NULL) {
        printf("Error: Unable to allocate memory!\n");
        exit(1);
    }

    // read details for the books
    read_books(books_ptr, num_books);

    // display details for the books
    display_books(books_ptr, num_books);

    // open ebooks
    for (int i = 0; i < num_books; i++) {
        printf("\nEnter file name for ebook '%s': ", books_ptr[i].title);
        scanf("%s", filename);
        books_ptr[i].file_name = (char*)malloc(strlen(filename) + 1);
        strcpy(books_ptr[i].file_name, filename);
    }

    // display ebook names
    printf("\nEbooks associated with the books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s: %s\n", books_ptr[i].title, books_ptr[i].file_name);
    }

    // free memory
    for (int i = 0; i < num_books; i++) {
        free(books_ptr[i].file_name);
    }
    free(books_ptr);

    return 0;
}