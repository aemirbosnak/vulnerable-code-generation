//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publication_year;
    double price;
    char filename[100];
} Book;

void add_book(Book *library, int *book_count);
void display_library(Book *library, int book_count);
void search_book(Book *library, int book_count, char *title);
void read_book(Book book);
void delete_book(Book *library, int *book_count, char *title);

int main() {
    Book library[MAX_BOOKS];
    int book_count = 0;

    int menu_choice;
    char title[MAX_TITLE_LENGTH];

    do {
        printf("Ebook Reader Menu\n");
        printf("1. Add Book\n");
        printf("2. Display Library\n");
        printf("3. Search for Book\n");
        printf("4. Read Book\n");
        printf("5. Delete Book\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                add_book(library, &book_count);
                break;
            case 2:
                display_library(library, book_count);
                break;
            case 3:
                printf("Enter title of book to search: ");
                scanf("%s", title);
                search_book(library, book_count, title);
                break;
            case 4:
                printf("Enter title of book to read: ");
                scanf("%s", title);
                int read_book_index = 0;
                while (strcmp(library[read_book_index].title, title) != 0 && read_book_index < book_count) {
                    read_book_index++;
                }
                if (read_book_index == book_count) {
                    printf("Book not found!\n");
                } else {
                    read_book(library[read_book_index]);
                }
                break;
            case 5:
                printf("Enter title of book to delete: ");
                scanf("%s", title);
                delete_book(library, &book_count, title);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (menu_choice != 6);

    return 0;
}

void add_book(Book *library, int *book_count) {
    if (*book_count == MAX_BOOKS) {
        printf("Cannot add more books, library is full!\n");
    } else {
        printf("Enter title of book: ");
        scanf("%s", library[*book_count].title);

        printf("Enter author of book: ");
        scanf("%s", library[*book_count].author);

        printf("Enter publication year of book: ");
        scanf("%d", &library[*book_count].publication_year);

        printf("Enter price of book: ");
        scanf("%lf", &library[*book_count].price);

        printf("Enter filename of book: ");
        scanf("%s", library[*book_count].filename);

        (*book_count)++;

        printf("Book added!\n");
    }
}

void display_library(Book *library, int book_count) {
    if (book_count == 0) {
        printf("Library is empty!\n");
    } else {
        printf("Library contents:\n");

        for (int i = 0; i < book_count; i++) {
            printf("Title: %s\nAuthor: %s\nPublication Year: %d\nPrice: %.2lf\nFilename: %s\n\n", 
                    library[i].title, library[i].author, library[i].publication_year, library[i].price, library[i].filename);
        }
    }
}

void search_book(Book *library, int book_count, char *title) {
    int found_books = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found!\n");
            printf("Title: %s\nAuthor: %s\nPublication Year: %d\nPrice: %.2lf\nFilename: %s\n\n", 
                    library[i].title, library[i].author, library[i].publication_year, library[i].price, library[i].filename);
            found_books++;
        }
    }

    if (found_books == 0) {
        printf("Book not found!\n");
    }
}

void read_book(Book book) {
    FILE *file = fopen(book.filename, "r");
    char c;

    if (file) {
        printf("\n---- %s by %s (%d) ----\n\n", book.title, book.author, book.publication_year);

        while ((c = getc(file)) != EOF) {
            putchar(c);
        }

        fclose(file);
        printf("\n\n");
    } else {
        printf("Error opening file %s!\n", book.filename);
    }
}

void delete_book(Book *library, int *book_count, char *title) {
    int found_books = 0;

    for (int i = 0; i < *book_count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found_books++;

            for (int j = i; j < *book_count - 1; j++) {
                library[j] = library[j+1]; // Shift books to the left
            }

            (*book_count)--;
            i--; // Check current index again in case next book has same title

            printf("Book deleted!\n");
        }
    }

    if (found_books == 0) {
        printf("Book not found!\n");
    }
}