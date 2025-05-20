//FormAI DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[50];
    char author[50];
    char category[20];
    char language[20];
    int totalPages;
    float version;
} Book;

typedef struct BookReader {
    Book *bookList;
    int currentBookIndex;
    int bookCount;
} BookReader;

void addBook(BookReader *reader, Book *book) {
    reader->bookList = realloc(reader->bookList, (reader->bookCount + 1) * sizeof(Book));
    reader->bookList[reader->bookCount] = *book;
    reader->bookCount++;
}

void printMenu() {
    printf("\n");
    printf("===== Ebook Reader Menu =====\n");
    printf("1. Add Book\n");
    printf("2. List All Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
    printf("============================\n");
}

void printBook(Book book) {
    printf("\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Category: %s\n", book.category);
    printf("Language: %s\n", book.language);
    printf("Total Pages: %d\n", book.totalPages);
    printf("Version: %.1f\n", book.version);
}

void listBooks(BookReader reader) {
    printf("\n");
    printf("===== Book List =====\n");
    for (int i = 0; i < reader.bookCount; i++) {
        printf("%d. %s by %s\n", i + 1, reader.bookList[i].title, reader.bookList[i].author);
    }
    printf("=====================\n");
}

void readBook(Book book) {
    printf("\nReading %s by %s...\n", book.title, book.author);
    // code for reading the ebook goes here
}

int main() {
    BookReader reader;
    reader.bookList = malloc(0);
    reader.currentBookIndex = -1;
    reader.bookCount = 0;

    int choice;

    do {
        printMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("===== Add Book =====\n");
                Book book;
                printf("Title: ");
                fgets(book.title, 50, stdin);
                printf("Author: ");
                fgets(book.author, 50, stdin);
                printf("Category: ");
                fgets(book.category, 20, stdin);
                printf("Language: ");
                fgets(book.language, 20, stdin);
                printf("Total Pages: ");
                scanf("%d", &book.totalPages);
                printf("Version: ");
                scanf("%f", &book.version);
                addBook(&reader, &book);
                printf("Book added successfully!\n");
                break;
            case 2:
                listBooks(reader);
                break;
            case 3:
                if (reader.bookCount == 0) {
                    printf("There are no books added to the reader yet.\n");
                    break;
                }
                listBooks(reader);
                printf("Enter the index of the book you want to read: ");
                scanf("%d", &reader.currentBookIndex);
                readBook(reader.bookList[reader.currentBookIndex - 1]);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    free(reader.bookList);

    return 0;
}