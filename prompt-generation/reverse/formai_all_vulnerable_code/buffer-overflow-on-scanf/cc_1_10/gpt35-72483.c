//FormAI DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    int pages;
} Book;

void display_menu();
int get_choice();
int add_book(Book *library, int num_books);
int remove_book(Book *library, int num_books);
void view_library(Book *library, int num_books);
void search_library(Book *library, int num_books);

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;
    int choice;

    do {
        display_menu();
        choice = get_choice();

        switch(choice) {
            case 1:
                num_books = add_book(library, num_books);
                break;
            case 2:
                num_books = remove_book(library, num_books);
                break;
            case 3:
                view_library(library, num_books);
                break;
            case 4:
                search_library(library, num_books);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while(choice != 5);

    return 0;
}

void display_menu() {
    printf("\n---- Ebook Reader ----\n\n");
    printf("1. Add book to library\n");
    printf("2. Remove book from library\n");
    printf("3. View library\n");
    printf("4. Search library\n");
    printf("5. Exit\n\n");
}

int get_choice() {
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int add_book(Book *library, int num_books) {
    if(num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return num_books;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]", library[num_books].title);

    printf("Enter book author: ");
    scanf(" %[^\n]", library[num_books].author);

    printf("Enter book price: ");
    scanf("%f", &library[num_books].price);

    printf("Enter number of pages: ");
    scanf("%d", &library[num_books].pages);

    printf("Book added to library.\n");

    return num_books + 1;
}

int remove_book(Book *library, int num_books) {
    int i;
    char title[MAX_TITLE_LENGTH];

    printf("Enter book title to remove: ");
    scanf(" %[^\n]", title);

    for(i = 0; i < num_books; i++) {
        if(strcmp(library[i].title, title) == 0) {
            printf("Removing \"%s\" by %s\n", library[i].title, library[i].author);
            memmove(&library[i], &library[i+1], (num_books-i-1)*sizeof(Book));
            return num_books - 1;
        }
    }

    printf("Book not found in library.\n");
    return num_books;
}

void view_library(Book *library, int num_books) {
    int i;

    printf("---- Library ----\n\n");
    for(i = 0; i < num_books; i++) {
        printf("%-30s  %-20s  $%.2f  %3d\n", library[i].title, library[i].author, library[i].price, library[i].pages);
    }
    printf("\n");
}

void search_library(Book *library, int num_books) {
    int i;
    char title[MAX_TITLE_LENGTH];

    printf("Enter book title to search for: ");
    scanf(" %[^\n]", title);

    for(i = 0; i < num_books; i++) {
        if(strcmp(library[i].title, title) == 0) {
            printf("%-30s  %-20s  $%.2f  %3d\n", library[i].title, library[i].author, library[i].price, library[i].pages);
            return;
        }
    }

    printf("Book not found in library.\n");
}