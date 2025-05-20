//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100

struct book {
    char title[50];
    char author[50];
    char genre[20];
    int page_count;
    float price;
};

typedef struct book Book;

Book bookshelf[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Sorry, the bookshelf is full!\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    fgets(new_book.title, 50, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;

    printf("Enter book author: ");
    fgets(new_book.author, 50, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter book genre: ");
    fgets(new_book.genre, 20, stdin);
    new_book.genre[strcspn(new_book.genre, "\n")] = 0;

    printf("Enter page count: ");
    scanf("%d", &new_book.page_count);
    getchar();

    printf("Enter price: ");
    scanf("%f", &new_book.price);
    getchar();

    bookshelf[num_books++] = new_book;
    printf("Book added successfully!\n");
}

void display_books() {
    printf("Title\tAuthor\tGenre\tPage Count\tPrice\n");
    for (int i = 0; i < num_books; i++) {
        Book current_book = bookshelf[i];
        printf("%s\t%s\t%s\t%d\t\t%.2f\n", current_book.title, current_book.author, 
               current_book.genre, current_book.page_count, current_book.price);
    }
}

void search_books() {
    char search_term[50];
    printf("Enter search term: ");
    fgets(search_term, 50, stdin);
    search_term[strcspn(search_term, "\n")] = 0;

    printf("Title\tAuthor\tGenre\tPage Count\tPrice\n");
    for (int i = 0; i < num_books; i++) {
        Book current_book = bookshelf[i];
        if (strstr(current_book.title, search_term) != NULL || 
            strstr(current_book.author, search_term) != NULL ||
            strstr(current_book.genre, search_term) != NULL) {
            printf("%s\t%s\t%s\t%d\t\t%.2f\n", current_book.title, current_book.author, 
                   current_book.genre, current_book.page_count, current_book.price);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nEbook Reader Main Menu\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Books\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: search_books(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice, please try again.\n"); break;
        }

    } while (choice != 4);

    return 0;
}