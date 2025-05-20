//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 50
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_TITLE_LEN];
    int num_pages;
} Ebook;

Ebook library[MAX_TITLES];
int num_books = 0;

void addBook() {
    if (num_books >= MAX_TITLES) {
        printf("Error: Library is full.\n");
        return;
    }
    Ebook new_book;
    printf("Enter the title: ");
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    printf("Enter the author: ");
    fgets(new_book.author, MAX_TITLE_LEN, stdin);
    printf("Enter the number of pages: ");
    scanf("%d", &new_book.num_pages);
    getchar(); // consume newline character
    library[num_books] = new_book;
    num_books++;
    printf("Book added successfully.\n");
}

void listBooks() {
    if (num_books == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("Title                      Author                     Num Pages\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%-26s%-26s%d\n", library[i].title, library[i].author, library[i].num_pages);
    }
}

void selectBook() {
    if (num_books == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("Select a book:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s", i + 1, library[i].title);
    }
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline character
    if (choice < 1 || choice > num_books) {
        printf("Invalid choice.\n");
        return;
    }
    Ebook selected_book = library[choice - 1];
    printf("Opening %s...\n", selected_book.title);
    printf("----- %s -----", selected_book.title);
    // open ebook file and display contents here
}

int main() {
    int option;
    do {
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("3. Select and read book\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        getchar(); // consume newline character
        switch (option) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                selectBook();
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 4);
    return 0;
}