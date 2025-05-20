//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

struct ebook{
    char title[50];
    char author[50];
    int numOfPages;
    float price;
    char fileFormat[20];
    char publisher[50];
}book;

void display_menu(){
    printf("\n===============================\n");
    printf("          EBOOK READER          \n");
    printf("===============================\n");
    printf("1. Display Book Information\n");
    printf("2. Read EBook\n");
    printf("3. Exit\n");
    printf("===============================\n");
    printf("[Enter your choice]: ");
}

void display_book_info(){
    printf("\nBOOK INFORMATION\n");
    printf("===============================\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.numOfPages);
    printf("Price: %.2f\n", book.price);
    printf("File Format: %s\n", book.fileFormat);
    printf("Publisher: %s\n", book.publisher);
    printf("===============================\n");
}

void read_ebook(){
    printf("\nREADING EBOOK\n");
    printf("===============================\n");
    printf("Opening file: %s.%s\n", book.title, book.fileFormat);
    printf("Please start reading...\n");
    printf("===============================\n");
}

int main(){
    strcpy(book.title, "C Programming for Beginners");
    strcpy(book.author, "John Smith");
    book.numOfPages = 250;
    book.price = 9.99;
    strcpy(book.fileFormat, "pdf");
    strcpy(book.publisher, "Book Publishers Inc.");

    int choice;
    do{
        display_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display_book_info();
                break;
            case 2:
                read_ebook();
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }while(1);
    return 0;
}