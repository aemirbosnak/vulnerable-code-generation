//FormAI DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILENAME_LENGTH 100
#define MAX_TEXT_LENGTH 20000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
    char *text;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

int load_book(Book *book) {
    FILE *fp = fopen(book->filename, "r");
    if (fp == NULL) {
        return 0;
    }
    book->text = malloc(MAX_TEXT_LENGTH);
    char line[MAX_TEXT_LENGTH];
    int index = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        strcat(book->text, line);
        index += strlen(line);
    }
    book->text[index] = '\0';
    fclose(fp);
    return 1;
}

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    Book new_book;
    printf("Enter title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strlen(new_book.title) - 1] = '\0';  // remove newline character

    printf("Enter author: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strlen(new_book.author) - 1] = '\0';

    printf("Enter filename: ");
    fgets(new_book.filename, sizeof(new_book.filename), stdin);
    new_book.filename[strlen(new_book.filename) - 1] = '\0';

    if (load_book(&new_book) == 0) {
        printf("Could not open file: %s\n", new_book.filename);
        return;
    }

    library[num_books] = new_book;
    num_books++;
    printf("Book added to library.\n");
}

void list_books() {
    printf("Library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
    }
}

void view_book() {
    int index;
    printf("Enter book number: ");
    scanf("%d", &index);
    getchar();  // consume newline character

    if (index < 1 || index > num_books) {
        printf("Invalid book number.\n");
        return;
    }

    Book book = library[index - 1];
    printf("%s by %s\n\n", book.title, book.author);
    printf("%s", book.text);
}

int main() {
    int choice;
    printf("Ebook Reader Menu:\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. View Book\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline character

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                view_book();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}