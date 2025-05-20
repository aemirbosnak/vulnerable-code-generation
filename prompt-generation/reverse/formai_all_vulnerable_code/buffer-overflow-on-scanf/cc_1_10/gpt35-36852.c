//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_TITLE_LENGTH 50
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_PRICE 999

typedef struct
{
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    float price;
    int pages;
} book;

book ebook[MAX_BOOKS];
int bookCount=0;

void addBook(){
    if (bookCount < MAX_BOOKS){
        printf("\nEnter book details: \n");

        printf("Enter the title: ");
        scanf("%s", ebook[bookCount].title);

        printf("Enter the author: ");
        scanf("%s", ebook[bookCount].author);

        printf("Enter the price: ");
        scanf("%f", &ebook[bookCount].price);

        printf("Enter the number of pages: ");
        scanf("%d", &ebook[bookCount].pages);

        bookCount++;
    }
    else{
        printf("Sorry, the library is full. No more books can be added. \n");
    }
}

void viewBooks(){
    if (bookCount == 0){
        printf("\nNo books in library");
    }
    else{
        printf("\nCurrent books in library are:\n\n");
        printf("Book\t\tAuthor\t\tPrice\t\tPages\n");
        printf("------------------------------------------------\n");
        for(int i=0; i<bookCount; i++){
            printf("%s\t\t%s\t\t%.2f\t\t%d\n", ebook[i].title, ebook[i].author, ebook[i].price, ebook[i].pages);
        }
    }
}

float findAveragePrice(){
    float totalPrice = 0;
    for(int i=0; i<bookCount; i++){
        totalPrice += ebook[i].price;
    }
    float avgPrice = totalPrice / bookCount;
    return avgPrice;
}

void printEbook(book b){
    printf("Title: %s\n",b.title);
    printf("Author: %s\n",b.author);
    printf("Price: %.2f\n",b.price);
    printf("Number of pages: %d\n",b.pages);
}

void searchBook(){
    char title[MAX_BOOK_TITLE_LENGTH];
    printf("Enter book title: ");
    scanf("%s", title);

    for(int i=0; i<bookCount; i++){
        if (strcmp(ebook[i].title, title) == 0){
            printf("\n Book Found!");
            printEbook(ebook[i]);
            return;
        }
    }
    printf("\n Book not found.");
}

int main(){
    int selection;
    while(1){
        printf("\nThe Ebook Library\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Find average book price\n");
        printf("4. Search for a book\n");
        printf("5. Quit\n");

        printf("\nEnter your selection: ");
        scanf("%d", &selection);

        switch(selection){
            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                printf("\nAverage price of all books is: %0.2f\n", findAveragePrice());
                break;

            case 4:
                searchBook();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid selection.\n");
        }
    }
    return 0;
}