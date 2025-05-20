//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    int pages;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void display_menu() {
    printf("\n---CyberBook Ebook Reader Menu---\n\n");
    printf("1. Load ebook from file\n");
    printf("2. Add ebook to library\n");
    printf("3. View library\n");
    printf("4. Sort library by title\n");
    printf("5. Sort library by author\n");
    printf("6. Exit\n");
}

void load_book_from_file() {
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: File not found\n");
        return;
    }

    Book book;
    while (fscanf(fp, "%s %s %f %d", book.title, book.author, &book.price, &book.pages) != EOF) {
        if (num_books < MAX_BOOKS) {
            library[num_books++] = book;
        } else {
            printf("Error: Library is full\n");
            break;
        }
    }

    printf("%d books loaded from file\n", num_books);

    fclose(fp);
}

void add_book_to_library() {
    Book book;

    printf("Enter the title: ");
    scanf("%s", book.title);

    printf("Enter the author: ");
    scanf("%s", book.author);

    printf("Enter the price: ");
    scanf("%f", &book.price);

    printf("Enter the number of pages: ");
    scanf("%d", &book.pages);

    if (num_books < MAX_BOOKS) {
        library[num_books++] = book;
    } else {
        printf("Error: Library is full\n");
    }
}

void view_library() {
    if (num_books == 0) {
        printf("Library is empty\n");
    } else {
        printf("Library contents:\n\n");
        for (int i = 0; i < num_books; i++) {
            printf("%d. Title: %s\n   Author: %s\n   Price: $%.2f\n   Pages: %d\n\n", i+1, library[i].title, library[i].author, library[i].price, library[i].pages);
        }
    }
}

int compare_books_by_title(const void* a, const void* b) {
    Book* book1 = (Book*) a;
    Book* book2 = (Book*) b;
    return strcmp(book1->title, book2->title);
}

int compare_books_by_author(const void* a, const void* b) {
    Book* book1 = (Book*) a;
    Book* book2 = (Book*) b;
    return strcmp(book1->author, book2->author);
}

void sort_library_by_title() {
    qsort(library, num_books, sizeof(Book), compare_books_by_title);
}

void sort_library_by_author() {
    qsort(library, num_books, sizeof(Book), compare_books_by_author);
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                load_book_from_file();
                break;
            case 2:
                add_book_to_library();
                break;
            case 3:
                view_library();
                break;
            case 4:
                sort_library_by_title();
                printf("Library sorted by title\n");
                break;
            case 5:
                sort_library_by_author();
                printf("Library sorted by author\n");
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}