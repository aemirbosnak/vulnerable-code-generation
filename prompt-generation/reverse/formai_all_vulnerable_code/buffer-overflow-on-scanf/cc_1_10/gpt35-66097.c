//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
    float price;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Maximum number of books reached.\n");
        return;
    }

    Book new_book;

    printf("Enter book title: ");
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0';

    printf("Enter book author: ");
    fgets(new_book.author, MAX_AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';

    printf("Enter year of publication: ");
    scanf("%d", &new_book.year);

    printf("Enter book price: ");
    scanf("%f", &new_book.price);

    library[num_books] = new_book;
    num_books++;

    printf("Book added successfully.\n");
}

void list_books() {
    if (num_books == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("Library contents:\n");

    for (int i = 0; i < num_books; i++) {
        printf("%s by %s, published in %d, costs $%.2f\n", library[i].title, library[i].author, library[i].year, library[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("Ebook reader menu:\n");
        printf("1. Add book to library.\n");
        printf("2. List books in library.\n");
        printf("3. Quit.\n");

        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}