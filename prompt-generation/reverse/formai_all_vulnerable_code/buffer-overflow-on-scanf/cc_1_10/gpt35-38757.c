//FormAI DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE 50
#define MAX_AUTHOR 20

struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
    int year;
};

void display_menu();
int get_menu_choice();
void add_book(struct Book books[]);
void remove_book(struct Book books[]);
void search_book(struct Book books[]);
void list_books(struct Book books[]);

int main() {
    struct Book books[MAX_BOOKS];
    int choice, book_count = 0;

    do {
        display_menu();
        choice = get_menu_choice();

        switch(choice) {
            case 1:
                add_book(books);
                book_count++;
                break;
            case 2:
                remove_book(books);
                book_count--;
                break;
            case 3:
                search_book(books);
                break;
            case 4:
                list_books(books);
                break;
            case 5:
                printf("Exiting Ebook Reader. Thank you for using!\n");
                break;
            default:
                printf("Invalid choice. Please input a number between 1 and 5.\n");
                break;
        }
    } while(choice != 5);

    return 0; 
}

void display_menu() {
    printf("========= Ebook Reader Menu =========\n");
    printf("1. Add a book\n");
    printf("2. Remove a book\n");
    printf("3. Search for a book\n");
    printf("4. List all books\n");
    printf("5. Exit\n");
    printf("====================================\n");
}

int get_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_book(struct Book books[]) {
    if(MAX_BOOKS < 1) {
        printf("Cannot add more books. The library is full.\n");
        return;
    }

    printf("Enter the book title: ");
    scanf("%s", books[MAX_BOOKS - 1].title);
    printf("Enter the book author: ");
    scanf("%s", books[MAX_BOOKS - 1].author);
    printf("Enter the book price: ");
    scanf("%f", &books[MAX_BOOKS - 1].price);
    printf("Enter the year of publication: ");
    scanf("%d", &books[MAX_BOOKS - 1].year);

    printf("The book %s by %s has been added to the library.\n", books[MAX_BOOKS - 1].title, books[MAX_BOOKS - 1].author);
}

void remove_book(struct Book books[]) {
    if(MAX_BOOKS >= 1) {
        printf("Cannot remove books. The library is empty.\n");
        return;
    }

    char title[MAX_TITLE];
    printf("Enter the title of the book to remove: ");
    scanf("%s", title);

    for(int i = 0; i < MAX_BOOKS; i++) {
        if(strcmp(title, books[i].title) == 0) {
            printf("The book %s by %s has been removed from the library.\n", books[i].title, books[i].author);
            memset(&books[i], 0, sizeof(struct Book));
            return;
        }
    }

    printf("The book %s was not found in the library.\n", title);
}

void search_book(struct Book books[]) {
    if(MAX_BOOKS >= 1) {
        printf("Cannot search for books. The library is empty.\n");
        return;
    }

    char title[MAX_TITLE];
    printf("Enter the title of the book to search for: ");
    scanf("%s", title);

    for(int i = 0; i < MAX_BOOKS; i++) {
        if(strcmp(title, books[i].title) == 0) {
            printf("The book %s by %s was found at position %d.\n", books[i].title, books[i].author, i+1);
            return;
        }
    }

    printf("The book %s was not found in the library.\n", title);
}

void list_books(struct Book books[]) {
    if(MAX_BOOKS >= 1) {
        printf("No books to list. The library is empty.\n");
        return;
    }

    printf("Listing all books in the library:\n");

    for(int i = 0; i < MAX_BOOKS; i++) {
        if(strlen(books[i].title) > 0) {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Year: %d\n\n", books[i].year);
        }
    }
}