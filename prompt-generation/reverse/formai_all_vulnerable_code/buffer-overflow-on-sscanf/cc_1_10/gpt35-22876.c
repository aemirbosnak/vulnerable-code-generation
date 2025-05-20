//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char* file_path;
} Ebook;

typedef struct {
    Ebook books[MAX_BOOKS];
    int num_books;
} EbookLibrary;

void load_books(EbookLibrary* library, const char* filename);
void add_book(EbookLibrary* library, Ebook book);
void print_books(EbookLibrary library);
void delete_book(EbookLibrary* library, const char* title);
void search_book(EbookLibrary library, const char* term);

int main() {
    EbookLibrary library = { .num_books = 0 };
    char choice;
    
    load_books(&library, "books.txt");
    
    while (1) {
        printf("Welcome to the Ebook Library!\n");
        printf("Select an option:\n");
        printf("1. Add a book\n");
        printf("2. Print all books\n");
        printf("3. Delete a book\n");
        printf("4. Search books\n");
        printf("0. Exit\n");
        
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1': {
                Ebook book;
                printf("Enter the book title: ");
                scanf("%s", book.title);
                printf("Enter the author name: ");
                scanf("%s", book.author);
                printf("Enter the number of pages: ");
                scanf("%d", &book.num_pages);
                printf("Enter the file path: ");
                char buffer[50];
                scanf("%s", buffer);
                book.file_path = strdup(buffer);
                add_book(&library, book);
                printf("Book added!\n");
                break;
            }
            case '2':
                printf("Printing all books...\n");
                print_books(library);
                break;
            case '3': {
                char title[50];
                printf("Enter the book title to delete: ");
                scanf("%s", title);
                delete_book(&library, title);
                printf("Book deleted!\n");
                break;
            }
            case '4': {
                char term[50];
                printf("Enter a search term: ");
                scanf("%s", term);
                search_book(library, term);
                break;
            }
            case '0':
                printf("Exiting Ebook Library. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}

void load_books(EbookLibrary* library, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    
    char buffer[200];
    
    while (fgets(buffer, 200, fp) != NULL) {
        Ebook book;
        sscanf(buffer, "%[^,],%[^,],%d,%s", book.title, book.author, &book.num_pages, buffer);
        book.file_path = strdup(buffer);
        add_book(library, book);
    }
    
    fclose(fp);
}

void add_book(EbookLibrary* library, Ebook book) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Error: Ebook library is full!\n");
        exit(1);
    }
    
    library->books[library->num_books] = book;
    library->num_books++;
}

void print_books(EbookLibrary library) {
    printf("%-50s| %-50s| %-10s| %-50s\n", "Title", "Author", "Pages", "File Path");
    printf("---------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < library.num_books; i++) {
        Ebook book = library.books[i];
        printf("%-50s| %-50s| %-10d| %-50s\n", book.title, book.author, book.num_pages, book.file_path);
    }
}

void delete_book(EbookLibrary* library, const char* title) {
    int index = -1;
    for (int i = 0; i < library->num_books; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }
    
    for (int i = index; i < library->num_books - 1; i++) {
        library->books[i] = library->books[i+1];
    }
    
    library->num_books--;
}

void search_book(EbookLibrary library, const char* term) {
    printf("%-50s| %-50s| %-10s| %-50s\n", "Title", "Author", "Pages", "File Path");
    printf("---------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < library.num_books; i++) {
        Ebook book = library.books[i];
        if (strstr(book.title, term) != NULL || strstr(book.author, term) != NULL) {
            printf("%-50s| %-50s| %-10d| %-50s\n", book.title, book.author, book.num_pages, book.file_path);
        }
    }
}