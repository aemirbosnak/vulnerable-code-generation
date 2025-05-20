//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000

typedef struct {
    char title[50];
    char author[30];
    int pages;
    float price;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    Book new_book;
    printf("Enter book title: ");
    scanf("%[^\n]%*c", new_book.title);
    printf("Enter book author: ");
    scanf("%[^\n]%*c", new_book.author);
    printf("Enter number of pages: ");
    scanf("%d", &new_book.pages);
    printf("Enter book price: ");
    scanf("%f", &new_book.price);
    library[num_books] = new_book;
    num_books++;
}

void display_books() {
    printf("Title\t\tAuthor\t\tPages\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t\t%s\t\t%d\t%.2f\n", library[i].title, library[i].author, library[i].pages, library[i].price);
    }
}

void search_book() {
    char search_title[50];
    printf("Enter book title to search: ");
    scanf("%[^\n]%*c", search_title);
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            found = 1;
            printf("%s\t\t%s\t\t%d\t%.2f\n", library[i].title, library[i].author, library[i].pages, library[i].price);
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice = 0;
    while (1) {
        printf("\nEbook Reader\n");
        printf("1. Add book\n");
        printf("2. Display all books\n");
        printf("3. Search book by title\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_books >= MAX_BOOKS) {
                    printf("Sorry, library is full.\n");
                } else {
                    add_book();
                }
                break;
            case 2:
                if (num_books == 0) {
                    printf("Library is empty.\n");
                } else {
                    display_books();
                }
                break;
            case 3:
                if (num_books == 0) {
                    printf("Library is empty.\n");
                } else {
                    search_book();
                }
                break;
            case 4:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}