//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct book{
    char title[100];
    char author[100];
    int pages;
    char content[MAX_SIZE];
}Book;

void createBook(Book *book){
    printf("Enter the title of the book: ");
    scanf("%s",book->title);

    printf("Enter the author of the book: ");
    scanf("%s",book->author);

    printf("Enter the number of pages: ");
    scanf("%d",&book->pages);

    printf("Enter the content of the book: ");
    fgets(book->content,MAX_SIZE,stdin);
}

void displayBook(Book *book){
    printf("Title: %s\n",book->title);
    printf("Author: %s\n",book->author);
    printf("Pages: %d\n",book->pages);
    printf("Content:\n%s",book->content);
}

void menu(){
    printf("\nMenu:\n");
    printf("1. Create book\n");
    printf("2. Display book\n");
    printf("3. Exit\n");
}

int main(){
    Book book;
    int choice;

    do{
        menu();
        scanf("%d",&choice);

        switch(choice){
            case 1:
                createBook(&book);
                break;

            case 2:
                displayBook(&book);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice!=3);

    return 0;
}