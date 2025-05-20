//FormAI DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGE_SIZE 5000

struct book {
    char title[50];
    char author[30];
    int pageCount;
    char genre[20];
    char* content;
};

struct ebookReader {
    struct book* books[MAX_BOOKS];
    int numBooks;
};

void createBook(struct ebookReader* reader);
void loadBook(struct ebookReader* reader);
void viewBooks(struct ebookReader* reader);
void displayBook(struct book* book);
void freeBooks(struct ebookReader* reader);

int main() {
    struct ebookReader reader;
    reader.numBooks = 0;

    int option = 0;
    do {
        printf("Ebook Reader\n");
        printf("-----------\n");
        printf("1. Create a new book\n");
        printf("2. Load an existing book\n");
        printf("3. View all books\n");
        printf("4. Quit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                createBook(&reader);
                break;
            case 2:
                loadBook(&reader);
                break;
            case 3:
                viewBooks(&reader);
                break;
            case 4:
                freeBooks(&reader);
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 4);

    return 0;
}

void createBook(struct ebookReader* reader) {
    if (reader->numBooks == MAX_BOOKS) {
        printf("No more space for new books.\n");
        return;
    }

    struct book* newBook = (struct book*) malloc(sizeof(struct book));
    if (!newBook) {
        printf("Failed to allocate memory for new book.\n");
        return;
    }

    printf("\nEnter book title: ");
    fgets(newBook->title, 50, stdin);
    strtok(newBook->title, "\n"); // remove newline character

    printf("Enter author name: ");
    fgets(newBook->author, 30, stdin);
    strtok(newBook->author, "\n");

    printf("Enter number of pages: ");
    scanf("%d", &newBook->pageCount);
    fflush(stdin);

    printf("Enter genre: ");
    fgets(newBook->genre, 20, stdin);
    strtok(newBook->genre, "\n");

    newBook->content = (char*) malloc(MAX_PAGE_SIZE * newBook->pageCount);
    if (!newBook->content) {
        printf("Failed to allocate memory for book content.\n");
        free(newBook);
        return;
    }

    for (int i = 0; i < newBook->pageCount; i++) {
        printf("Enter text for page %d:\n", i + 1);
        fgets(newBook->content + (i * MAX_PAGE_SIZE), MAX_PAGE_SIZE, stdin);
    }

    reader->books[reader->numBooks++] = newBook;
}

void loadBook(struct ebookReader* reader) {
    if (reader->numBooks == 0) {
        printf("No books loaded yet.\n");
        return;
    }

    printf("\nEnter the index of the book to load (1-%d): ", reader->numBooks);
    int index = 0;
    scanf("%d", &index);
    fflush(stdin);

    if (index < 1 || index > reader->numBooks) {
        printf("Invalid book index.\n");
        return;
    }

    struct book* book = reader->books[index - 1];
    displayBook(book);
}

void viewBooks(struct ebookReader* reader) {
    if (reader->numBooks == 0) {
        printf("No books loaded yet.\n");
        return;
    }

    printf("\nList of loaded books:\n");
    for (int i = 0; i < reader->numBooks; i++) {
        printf("%d. %s by %s (%d pages, %s)\n", i + 1, reader->books[i]->title,
            reader->books[i]->author, reader->books[i]->pageCount, reader->books[i]->genre);
    }
}

void displayBook(struct book* book) {
    for (int i = 0; i < book->pageCount; i++) {
        printf("Page %d:\n%s\n", i + 1, book->content + (i * MAX_PAGE_SIZE));
        printf("\nPress enter to continue...");
        getchar();
    }
}

void freeBooks(struct ebookReader* reader) {
    for (int i = 0; i < reader->numBooks; i++) {
        free(reader->books[i]->content);
        free(reader->books[i]);
    }
}