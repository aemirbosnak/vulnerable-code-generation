//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct Ebook {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    int pages;
};

void display(struct Ebook book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("Year Published: %d\n", book.year);
    printf("Number of Pages: %d\n", book.pages);
}

void open_book(struct Ebook book) {
    printf("\nOpening EBook: %s\n", book.title);
    // Code to open the ebook file and display its contents
}

int main() {
    struct Ebook book1, book2;
    
    printf("Enter details for Ebook 1:\n");
    printf("Enter title: ");
    gets(book1.title);
    printf("Enter author: ");
    gets(book1.author);
    printf("Enter publisher: ");
    gets(book1.publisher);
    printf("Enter year published: ");
    scanf("%d", &book1.year);
    printf("Enter number of pages: ");
    scanf("%d", &book1.pages);
    
    printf("\nEnter details for Ebook 2:\n");
    printf("Enter title: ");
    getchar();
    gets(book2.title);
    printf("Enter author: ");
    gets(book2.author);
    printf("Enter publisher: ");
    gets(book2.publisher);
    printf("Enter year published: ");
    scanf("%d", &book2.year);
    printf("Enter number of pages: ");
    scanf("%d", &book2.pages);
    
    // Display the details of both ebooks
    display(book1);
    display(book2);
    
    // Open Ebook 1
    open_book(book1);
    
    return 0;
}