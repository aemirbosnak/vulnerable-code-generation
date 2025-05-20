//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>

struct eBook {
    char title[50];
    char author[50];
    int pages;
    float price;
    char format[10];
};

void printBook(struct eBook book);
double calculateDiscountedPrice(struct eBook book, int discount);

int main() {
    struct eBook myBook;
    
    printf("Enter the title of the book: ");
    fgets(myBook.title, 50, stdin);
    
    printf("Enter the author of the book: ");
    fgets(myBook.author, 50, stdin);
    
    printf("Enter the number of pages in the book: ");
    scanf("%d", &myBook.pages);
    
    printf("Enter the price of the book: ");
    scanf("%f", &myBook.price);
    
    printf("Enter the format of the book (e.g. PDF, EPUB, MOBI): ");
    scanf("%s", myBook.format);
    
    printf("\n");
    printBook(myBook);
    
    printf("Discounted price for 10%% off: $%.2f\n", calculateDiscountedPrice(myBook, 10));
    
    return 0;
}

void printBook(struct eBook book) {
    printf("Title: %s", book.title);
    printf("Author: %s", book.author);
    printf("Number of pages: %d\n", book.pages);
    printf("Price: $%.2f\n", book.price);
    printf("Format: %s\n", book.format);
}

double calculateDiscountedPrice(struct eBook book, int discount) {
    double discountedPrice = book.price - (book.price * (discount/100.0));
    return discountedPrice;
}