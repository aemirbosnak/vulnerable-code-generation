//FormAI DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 500
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    char* ebook_file;
} Book;

void print_books(Book book_list[], int num_books);
void print_book_details(Book book);
void add_book(Book book_list[], int* num_books);
int select_book(Book book_list[], int num_books);
void read_book(Book book);

int main() {
    Book book_list[MAX_BOOKS];
    int num_books = 0;
    int choice;

    do {
        printf("1. Add a book\n");
        printf("2. Select a book to read\n");
        printf("3. View all books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_book(book_list, &num_books);
                break;
            case 2:
                read_book(book_list[select_book(book_list, num_books)]);
                break;
            case 3:
                print_books(book_list, num_books);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void print_books(Book book_list[], int num_books) {
    if(num_books == 0) {
        printf("No books added yet.\n");
    } else {
        printf("List of books:\n\n");
        for(int i = 0; i < num_books; i++) {
            printf("%d. %s by %s\n", i+1, book_list[i].title, book_list[i].author);
        }
        printf("\n");
    }
}

void print_book_details(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.num_pages);
    printf("Ebook File: %s\n", book.ebook_file);
}

void add_book(Book book_list[], int* num_books) {
    Book new_book;

    printf("Enter the book title (max %d characters): ", MAX_TITLE_LENGTH);
    scanf(" %[^\n]s", new_book.title);

    printf("Enter the book author (max %d characters): ", MAX_AUTHOR_LENGTH);
    scanf(" %[^\n]s", new_book.author);

    printf("Enter the number of pages (max %d pages): ", MAX_PAGES);
    scanf("%d", &new_book.num_pages);

    new_book.ebook_file = malloc(sizeof(char) * MAX_TITLE_LENGTH);
    printf("Enter the ebook file name (max %d characters): ", MAX_TITLE_LENGTH);
    scanf(" %[^\n]s", new_book.ebook_file);

    book_list[*num_books] = new_book;
    (*num_books)++;
}

int select_book(Book book_list[], int num_books) {
    int choice;

    if(num_books == 0) {
        printf("No books added yet.\n");
        return -1;
    } else {
        print_books(book_list, num_books);
        printf("Enter the number of the book you would like to read: ");
        scanf("%d", &choice);

        if(choice > num_books || choice <= 0) {
            printf("Invalid choice. Please try again.\n");
            return -1;
        } else {
            return choice-1;
        }  
    } 
}

void read_book(Book book) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(book.ebook_file, "r");
    if(fp == NULL) {
        printf("Cannot open ebook file.\n");
    } else {
        printf("\n******* %s *******\n\n", book.title);
        while((read = getline(&line, &len, fp)) != -1) {
            printf("%s", line);
        }
        printf("\n\n*********************\n");
        fclose(fp);
    }

    if(line) {
        free(line);
    }
}