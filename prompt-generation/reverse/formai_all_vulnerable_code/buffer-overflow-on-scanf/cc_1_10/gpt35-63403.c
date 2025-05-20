//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

void viewMenu() {
    printf("\n\n\t\t-- Welcome to EBook Reader --\n\n");
    printf("1. View all books\n");
    printf("2. Search for a book\n");
    printf("3. Add a new book\n");
    printf("4. Delete a book\n");
    printf("5. Exit\n");
}

void viewAllBooks(struct Book books[], int count) {
    printf("\n\n\t\t-- All Books --\n\n");
    for(int i=0; i<count; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: %.2f\n\n", books[i].price);
    }
}

void searchBook(struct Book books[], int count, char query[]) {
    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp(books[i].title, query)==0) {
            printf("\n\n\t\t-- Book Found --\n\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            printf("Price: %.2f\n\n", books[i].price);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\n\n\t\t-- Book Not Found --\n\n");
    }
}

void addBook(struct Book books[], int *count) {
    printf("\n\n\t\t-- Add Book --\n\n");
    printf("Enter the Title of the Book: ");
    fflush(stdin);
    scanf("%[^\n]", books[*count].title);
    printf("Enter the Author of the Book: ");
    fflush(stdin);
    scanf("%[^\n]", books[*count].author);
    printf("Enter the Number of Pages in the Book: ");
    scanf("%d", &books[*count].pages);
    printf("Enter the Price of the Book: ");
    scanf("%f", &books[*count].price);
    (*count)++;
}

int deleteBook(struct Book books[], int *count, char query[]) {
    int found = 0;
    int index;

    for(int i=0; i<*count; i++) {
        if(strcmp(books[i].title, query)==0) {
            printf("\n\n\t\t-- Book Found --\n\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            printf("Price: %.2f\n\n", books[i].price);
            found = 1;
            index = i;
            break;
        }
    }

    if(found) {
        for(int i=index; i<*count-1; i++) {
            books[i] = books[i+1];
        }
        (*count)--;
        printf("\n\n\t\t-- Book Deleted --\n\n");
        return 1; // Successful delete
    }
    else {
        printf("\n\n\t\t-- Book Not Found --\n\n");
        return 0; // Unsuccessful delete
    }
}

int main() {
    struct Book books[100];
    int count = 0;
    int choice;
    char query[50];
    int result;

    do {
        viewMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                viewAllBooks(books, count);
                break;
            case 2:
                printf("\n\n\t\t-- Search Book --\n\n");
                printf("Enter the Title of the Book you want to search for: ");
                fflush(stdin);
                scanf("%[^\n]", query);
                searchBook(books, count, query);
                break;
            case 3:
                addBook(books, &count);
                break;
            case 4:
                printf("\n\n\t\t-- Delete Book --\n\n");
                printf("Enter the Title of the Book you want to delete: ");
                fflush(stdin);
                scanf("%[^\n]", query);
                result = deleteBook(books, &count, query);
                if(result) {
                    printf("Do you want to view all books? (1=Yes, Any other number=No)");
                    scanf("%d", &result);
                    if(result==1) {
                        viewAllBooks(books, count);
                    }
                }
                break;
            case 5:
                printf("\n\nThank you for using EBook Reader!\n\n");
                break;
            default:
                printf("\nInvalid choice, please enter a valid choice!\n");
        }

    } while(choice!=5);

    return 0;
}