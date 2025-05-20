//FormAI DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent each book
typedef struct {
    char title[50];
    char author[50];
    int year;
    char ebook_file[50];
} Book;

// A structure to represent the current ebook being read
typedef struct {
    Book* book;
    int current_page;
} Ebook;

// Function to read in and create a new book
Book* create_book() {
    Book* book = (Book*) malloc(sizeof(Book));
    printf("Enter title: ");
    scanf("%s", book->title);
    printf("Enter author: ");
    scanf("%s", book->author);
    printf("Enter year published: ");
    scanf("%d", &book->year);
    printf("Enter ebook file name: ");
    scanf("%s", book->ebook_file);
    return book;
}

// Function to print out information about a book
void print_book(Book* book) {
    printf("Title: %s\nAuthor: %s\nYear published: %d\nEbook file name: %s\n\n", book->title, book->author, book->year, book->ebook_file);
}

// Main function
int main() {
    int num_books;
    printf("Enter number of books: ");
    scanf("%d", &num_books);
    Book* library[num_books];
    Ebook* current_ebook = NULL;
    int library_size = 0;
    while (1) {
        printf("Enter command (add, list, read, quit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("\n");
            Book* new_book = create_book();
            library[library_size] = new_book;
            library_size++;
            printf("Book added to library.\n\n");
        } else if (strcmp(command, "list") == 0) {
            printf("\n");
            for (int i = 0; i < library_size; i++) {
                printf("Book %d:\n", i+1);
                print_book(library[i]);
            }
        } else if (strcmp(command, "read") == 0) {
            printf("\n");
            int book_num;
            printf("Enter book number: ");
            scanf("%d", &book_num);
            if (book_num <= 0 || book_num > library_size) {
                printf("Invalid book number.\n\n");
            } else {
                current_ebook = (Ebook*) malloc(sizeof(Ebook));
                current_ebook->book = library[book_num-1];
                current_ebook->current_page = 1;
                printf("Now reading: %s by %s\n\n", current_ebook->book->title, current_ebook->book->author);
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("\n");
            printf("Goodbye.\n");
            return 0;
        } else {
            printf("\n");
            printf("Invalid command.\n\n");
        }
    }
}