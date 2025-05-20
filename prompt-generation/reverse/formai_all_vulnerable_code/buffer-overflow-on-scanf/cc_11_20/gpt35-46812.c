//FormAI DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_TITLE 50
#define MAX_FILE_NAME 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    char file_name[MAX_FILE_NAME];
} ebook;

int main() {
    ebook library[MAX_BOOKS];
    int num_books = 0;
    int selection = 0;

    while (1) {
        printf("Welcome to the E-Book library!\n");
        printf("Please select an option:\n");
        printf("1. Add a new book\n");
        printf("2. View all books\n");
        printf("3. Read a book\n");
        printf("4. Exit\n");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                if (num_books == MAX_BOOKS) {
                    printf("Library is full! Cannot add more books.\n");
                } else {
                    ebook new_book;
                    printf("Enter Book Title: ");
                    scanf("%s", new_book.title);
                    printf("Enter File name: ");
                    scanf("%s", new_book.file_name);

                    library[num_books++] = new_book;
                    printf("Book added successfully!\n");
                }
                break;
            case 2:
                printf("List of Books in the library:\n");
                for (int i = 0; i < num_books; i++) {
                    printf("%d. %s\n", i+1, library[i].title);
                }
                break;
            case 3:
                if (num_books == 0) {
                    printf("No books available to read!\n");
                } else {
                    printf("Select book number to read (1-%d): ", num_books);
                    int book_num;
                    scanf("%d", &book_num);

                    if (book_num < 1 || book_num > num_books) {
                        printf("Invalid book number!\n");
                    } else {
                        ebook selected_book = library[book_num-1];
                        char command[MAX_FILE_NAME+10];
                        sprintf(command, "open %s", selected_book.file_name);
                        system(command);
                    }
                }
                break;
            case 4:
                printf("Thank you for visiting the E-Book library!\n");
                exit(0);
                break;
            default:
                printf("Invalid selection! Please try again.\n");
        }

        printf("\n"); // extra line for clarity
    }

    return 0;
}