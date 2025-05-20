//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
} book;

book *library[MAX_PAGES];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_PAGES) {
        printf("Library is full\n");
        return;
    }
    book *new_book = (book *)malloc(sizeof(book));
    printf("Enter title: ");
    fgets(new_book->title, MAX_TITLE_LENGTH, stdin);
    printf("Enter author: ");
    fgets(new_book->author, MAX_AUTHOR_LENGTH, stdin);
    printf("Enter number of pages: ");
    scanf("%d", &new_book->num_pages);
    getchar(); // consume newline from scanf
    library[num_books] = new_book;
    num_books++;
    printf("Book added to library\n");
}

void list_books() {
    if (num_books == 0) {
        printf("Library is empty\n");
        return;
    }
    printf("Library contents:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s by %s (%d pages)\n", library[i]->title, library[i]->author, library[i]->num_pages);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline from scanf
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
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);
    return 0;
}