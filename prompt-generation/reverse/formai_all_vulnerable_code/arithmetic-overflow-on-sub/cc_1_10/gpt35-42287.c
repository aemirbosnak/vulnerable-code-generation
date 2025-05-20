//FormAI DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_BOOKS 10
#define MAX_PAGES 200

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int totalPages;
    char** pages;
};

struct EbookReader {
    int numBooks;
    int currentBookIndex;
    struct Book library[MAX_BOOKS];
};

void initBook(struct Book* book) {
    book->totalPages = 0;
    book->pages = (char**) malloc(MAX_PAGES * sizeof(char*));
    for (int i = 0; i < MAX_PAGES; i++) {
        book->pages[i] = (char*) malloc(100 * sizeof(char));
    }
}

void loadBook(struct EbookReader* reader, char* title, char* author, int numPages) {
    if (reader->numBooks >= MAX_BOOKS) {
        printf("Sorry, the library is full.\n");
        return;
    }

    struct Book newBook;
    strncpy(newBook.title, title, MAX_TITLE_LENGTH);
    strncpy(newBook.author, author, MAX_AUTHOR_LENGTH);
    newBook.totalPages = numPages;
    initBook(&newBook);

    for (int i = 0; i < numPages; i++) {
        printf("Enter page %d:\n", i+1);
        fgets(newBook.pages[i], 100, stdin);
    }

    reader->library[reader->numBooks] = newBook;
    reader->numBooks++;
}

void printLibrary(struct EbookReader* reader) {
    printf("Current library:\n");
    for (int i = 0; i < reader->numBooks; i++) {
        printf("%d. %s by %s\n", i+1, reader->library[i].title, reader->library[i].author);
    }
}

void printBook(struct EbookReader* reader) {
    struct Book currentBook = reader->library[reader->currentBookIndex];
    printf("Currently reading %s by %s.\n", currentBook.title, currentBook.author);
    for (int i = 0; i < currentBook.totalPages; i++) {
        printf("\nPage %d:\n", i+1);
        printf("%s", currentBook.pages[i]);
    }
}

int main() {

    struct EbookReader reader;
    reader.numBooks = 0;
    reader.currentBookIndex = -1;

    while (1) { // Infinite loop to simulate a running program
        printf("\nOptions:\n1. Load book\n2. Select book\n3. Read book\n4. Exit program\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character left behind by scanf

        switch (choice) {
            case 1: {
                char title[MAX_TITLE_LENGTH];
                printf("Enter title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                strtok(title, "\n"); // Remove newline character from input
                char author[MAX_AUTHOR_LENGTH];
                printf("Enter author: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                strtok(author, "\n"); // Remove newline character from input
                int numPages;
                printf("Enter number of pages: ");
                scanf("%d", &numPages);
                getchar(); // To consume newline character left behind by scanf
                loadBook(&reader, title, author, numPages);
                break;
            }
            case 2: {
                printLibrary(&reader);
                int bookIndex;
                printf("Select a book by entering its number (0 to cancel): ");
                scanf("%d", &bookIndex);
                getchar(); // To consume newline character left behind by scanf
                if (bookIndex == 0) {
                    break;
                }
                reader.currentBookIndex = bookIndex - 1;
                break;
            }
            case 3: {
                if (reader.currentBookIndex == -1) {
                    printf("No book selected.\n");
                    break;
                }
                printBook(&reader);
                break;
            }
            case 4: {
                printf("Exiting program\n");
                exit(0);
            }
            default: {
                printf("Invalid input\n");
                break;
            }
        }
    }
    return 0;
}