//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    char title[50];
    char author[50];
    int pages;
    int year;
    char language[50];
    int size;
    char filetype[10];
};

typedef struct book BOOK;

void display_book(BOOK book[], int n)
{
    printf("\n All books available: \n");
    for(int i=0;i<n;i++)
    {
        printf("\nTitle: %s", book[i].title);
        printf("\nAuthor: %s", book[i].author);
        printf("\nPages: %d", book[i].pages);
        printf("\nYear: %d", book[i].year);
        printf("\nLanguage: %s", book[i].language);
        printf("\nSize: %d", book[i].size);
        printf("\nFile type: %s \n", book[i].filetype);    
    }
}

void display_book_details(BOOK book[], int n, int index)
{
    printf("\n Book details for %s: \n", book[index].title);
    printf("\nTitle: %s", book[index].title);
    printf("\nAuthor: %s", book[index].author);
    printf("\nPages: %d", book[index].pages);
    printf("\nYear: %d", book[index].year);
    printf("\nLanguage: %s", book[index].language);
    printf("\nSize: %d", book[index].size);
    printf("\nFile type: %s \n", book[index].filetype);    
}

int main()
{
    BOOK books[5] = {
        {"The Alchemist", "Paulo Coelho", 180, 1988, "English", 1, ".epub"},
        {"The Catcher in the Rye", "J.D. Salinger", 277, 1951, "English", 2, ".pdf"},
        {"Pride and Prejudice", "Jane Austen", 279, 1813, "English", 2, ".txt"},
        {"Harry Potter and the Philosopher's Stone", "J.K. Rowling", 223, 1997, "English", 3, ".mobi"},
        {"Crime and Punishment", "Fyodor Dostoevsky", 671, 1866, "Russian", 4, ".epub"}
    };
    
    int num_books = 5;
    
    display_book(books, num_books);
    
    int index;
    printf("\n Enter the book you want to read (1-5): ");
    scanf("%d", &index);
    if(index<1 || index>5){
        printf("\n Invalid input.\n");
        return 0;
    }
    
    printf("\n Opening book %s... \n", books[index-1].title);
    display_book_details(books, num_books, index-1);
    printf("\n Enjoy reading! \n");
    
    return 0;
}