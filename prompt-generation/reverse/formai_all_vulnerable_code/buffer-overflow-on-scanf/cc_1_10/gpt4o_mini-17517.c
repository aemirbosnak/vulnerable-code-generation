//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int is_borrowed; // 1 if borrowed, 0 if not
} Book;

void add_book(Book *books, int *book_count) {
    if (*book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book new_book;
    new_book.id = *book_count + 1; // ID will be 1-based
    printf("Enter title: ");
    getchar(); // to consume newline from previous input
    fgets(new_book.title, TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // remove newline
    printf("Enter author: ");
    fgets(new_book.author, AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // remove newline
    new_book.is_borrowed = 0; // Initially not borrowed

    books[*book_count] = new_book;
    (*book_count)++;
    printf("Book added successfully!\n");
}

void view_books(Book *books, int book_count) {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("ID\tTitle\t\tAuthor\t\tStatus\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%-16s\t%-16s\t%s\n", 
               books[i].id, 
               books[i].title, 
               books[i].author, 
               books[i].is_borrowed ? "Borrowed" : "Available");
    }
}

void borrow_book(Book *books, int book_count) {
    int id;
    printf("Enter book ID to borrow: ");
    scanf("%d", &id);

    if (id < 1 || id > book_count) {
        printf("Invalid book ID!\n");
        return;
    }

    if (books[id - 1].is_borrowed) {
        printf("Sorry, this book is already borrowed.\n");
    } else {
        books[id - 1].is_borrowed = 1;
        printf("You have borrowed \"%s\" by %s.\n", books[id - 1].title, books[id - 1].author);
    }
}

void return_book(Book *books, int book_count) {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);

    if (id < 1 || id > book_count) {
        printf("Invalid book ID!\n");
        return;
    }

    if (!books[id - 1].is_borrowed) {
        printf("This book was not borrowed.\n");
    } else {
        books[id - 1].is_borrowed = 0;
        printf("You have returned \"%s\" by %s.\n", books[id - 1].title, books[id - 1].author);
    }
}

void save_books_to_file(Book *books, int book_count) {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < book_count; i++) {
        fprintf(file, "%d|%s|%s|%d\n", books[i].id, books[i].title, books[i].author, books[i].is_borrowed);
    }

    fclose(file);
    printf("Books saved to file.\n");
}

void load_books_from_file(Book *books, int *book_count) {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("No saved library found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d|%[^|]|%[^|]|%d\n", &books[*book_count].id, 
                  books[*book_count].title, books[*book_count].author, 
                  &books[*book_count].is_borrowed) != EOF) {
        (*book_count)++;
    }

    fclose(file);
    printf("Books loaded from file.\n");
}

int main() {
    Book books[MAX_BOOKS];
    int book_count = 0;
    int choice;

    load_books_from_file(books, &book_count);

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Save Books to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &book_count);
                break;
            case 2:
                view_books(books, book_count);
                break;
            case 3:
                borrow_book(books, book_count);
                break;
            case 4:
                return_book(books, book_count);
                break;
            case 5:
                save_books_to_file(books, book_count);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}