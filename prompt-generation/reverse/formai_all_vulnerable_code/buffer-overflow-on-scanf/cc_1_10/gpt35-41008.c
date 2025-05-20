//FormAI DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char* title;
    char* author;
    char* publisher;
    int year;
    char* isbn;
    char* filename;
} Book;

Book* create_book(char* title, char* author, char* publisher, int year, char* isbn, char* filename)
{
    Book* book = (Book*)malloc(sizeof(Book));
    book->title = title;
    book->author = author;
    book->publisher = publisher;
    book->year = year;
    book->isbn = isbn;
    book->filename = filename;
    return book;
}

void display_book(Book* book)
{
    printf("************************************************************\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Publisher: %s\n", book->publisher);
    printf("Year: %d\n", book->year);
    printf("ISBN: %s\n", book->isbn);
    printf("Filename: %s\n", book->filename);
}

typedef struct 
{
    Book** books;
    int num_books;
} Library;

Library* create_library()
{
    Library* library = (Library*)malloc(sizeof(Library));
    library->books = (Book**)malloc(sizeof(Book*));
    library->num_books = 0;
    return library;
}

void add_book_to_library(Library* library, Book* book)
{
    library->books[library->num_books] = book;
    library->num_books++;
    library->books = (Book**)realloc(library->books, (library->num_books+1)*sizeof(Book*));
}

Book* find_book_in_library(Library* library, char* title)
{
    for (int i=0; i<library->num_books; i++)
    {
        if (strcmp(library->books[i]->title, title) == 0)
        {
            return library->books[i];
        }
    }
    return NULL;
}

void display_library(Library* library)
{
    printf("************************************************************\n");
    printf("Library Contents:\n");
    for (int i=0; i<library->num_books; i++)
    {
        printf("Book %d:\n", i+1);
        display_book(library->books[i]);
    }
}

void display_menu()
{
    printf("************************************************************\n");
    printf("C Ebook Reader Menu:\n");
    printf("1. Display Library Contents\n");
    printf("2. Add Book to Library\n");
    printf("3. Find Book in Library\n");
    printf("4. Exit\n");
}

int main()
{
    Library* library = create_library();
    char choice;
    while(1)
    {
        display_menu();
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice)
        {
            case '1':
                display_library(library);
                break;
            case '2':
                printf("Enter Book Title: ");
                char title[100];
                scanf("%s", title);
                printf("Enter Book Author: ");
                char author[100];
                scanf("%s", author);
                printf("Enter Book Publisher: ");
                char publisher[100];
                scanf("%s", publisher);
                printf("Enter Book Year: ");
                int year;
                scanf("%d", &year);
                printf("Enter Book ISBN: ");
                char isbn[100];
                scanf("%s", isbn);
                printf("Enter Book Filename: ");
                char filename[100];
                scanf("%s", filename);
                Book* new_book = create_book(title, author, publisher, year, isbn, filename);
                add_book_to_library(library, new_book);
                printf("Book added to Library.\n");
                break;
            case '3':
                printf("Enter Book Title: ");
                char search_title[100];
                scanf("%s", search_title);
                Book* found_book = find_book_in_library(library, search_title);
                if (found_book == NULL)
                {
                    printf("Book not found in Library.\n");
                }
                else
                {
                    display_book(found_book);
                }
                break;
            case '4':
                printf("Exiting C Ebook Reader.\n");
                exit(0);
            default:
                printf("Invalid Choice. Please try again.\n");
                break;
        }
    }
    return 0;
}