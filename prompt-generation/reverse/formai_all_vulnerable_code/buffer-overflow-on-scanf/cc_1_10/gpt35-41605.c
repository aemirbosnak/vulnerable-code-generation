//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE_SIZE 50

struct book{
    char title[MAX_TITLE_SIZE];
    char author[50];
    int year_published;
    float price;
};

int total_books;
struct book library[MAX_BOOKS];

void add_book(){
    if(total_books >= MAX_BOOKS){
        printf("Error: Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", library[total_books].title);

    printf("Enter book author: ");
    scanf("%s", library[total_books].author);

    printf("Enter year published: ");
    scanf("%d", &library[total_books].year_published);

    printf("Enter book price: ");
    scanf("%f", &library[total_books].price);

    printf("Book added successfully.\n");

    total_books++;
}

void display_books(){
    if(total_books == 0){
        printf("Library is empty.\n");
        return;
    }

    printf("Title\t\tAuthor\t\tYear Published\t\tPrice\n");
    for(int i=0; i<total_books; i++){
        printf("%s\t\t%s\t\t%d\t\t\t%.2f\n", 
            library[i].title, library[i].author, 
            library[i].year_published, library[i].price);
    }
}

int main(){
    int choice = 0;

    while(choice != 3){
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_book();
                break;

            case 2:
                display_books();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}