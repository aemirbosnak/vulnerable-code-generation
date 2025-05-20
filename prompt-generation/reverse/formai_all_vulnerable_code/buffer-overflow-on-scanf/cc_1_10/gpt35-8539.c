//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_NAME_LENGTH 50
#define MAX_PAGES 500

typedef struct Ebook {
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int pageCount;
    int currentPage;
    char* content[MAX_PAGES];
} Ebook;

typedef struct EbookReader {
    Ebook* library[MAX_BOOKS];
    int librarySize;
    Ebook* currentBook;
    int currentBookIndex;
} EbookReader;

// function to display the main menu
void displayMainMenu() {
    printf("\nWelcome to the Ebook Reader!\n\n");
    printf("1. Add a new Ebook\n");
    printf("2. Browse the library\n");
    printf("3. Read Ebook\n");
    printf("4. Exit the program\n\n");
    printf("Enter your choice: ");
}

// function to add a new Ebook to the library
void addEbookToLibrary(EbookReader* reader) {
    if (reader->librarySize >= MAX_BOOKS) {
        printf("\nError: library is full.\n");
        return;
    }

    Ebook* newEbook = malloc(sizeof(Ebook));
    printf("\nEnter the title of the Ebook: ");
    fgets(newEbook->title, MAX_NAME_LENGTH, stdin);
    printf("Enter the author of the Ebook: ");
    fgets(newEbook->author, MAX_NAME_LENGTH, stdin);
    printf("Enter the page count of the Ebook: ");
    scanf("%d", &newEbook->pageCount);
    getchar(); // to remove the newline character from the input buffer

    printf("\nEnter the content of the Ebook:\n");
    for (int i = 0; i < newEbook->pageCount; i++) {
        newEbook->content[i] = malloc(MAX_PAGES * sizeof(char));
        fgets(newEbook->content[i], MAX_PAGES, stdin);
    }

    reader->library[reader->librarySize] = newEbook;
    reader->librarySize++;
    printf("\nEbook added to the library successfully!\n");
}

// function to display the library
void displayLibrary(EbookReader* reader) {
    if (reader->librarySize == 0) {
        printf("\nThe library is empty.\n");
        return;
    }

    printf("\nEbook Library:\n\n");
    for (int i = 0; i < reader->librarySize; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, reader->library[i]->title,
               reader->library[i]->author, reader->library[i]->pageCount);
    }
}

// function to set the current book for reading
void setCurrentBook(EbookReader* reader) {
    displayLibrary(reader);
    printf("\nEnter the index of the book you want to read: ");
    scanf("%d", &reader->currentBookIndex);
    getchar(); // to remove the newline character from the input buffer

    if (reader->currentBookIndex < 1 || reader->currentBookIndex > reader->librarySize) {
        printf("\nInvalid book index.\n");
        return;
    }

    reader->currentBook = reader->library[reader->currentBookIndex-1];
    reader->currentBook->currentPage = 1;
}

// function to display the current page
void displayCurrentPage(EbookReader* reader) {
    if (reader->currentBook == NULL) {
        printf("\nNo book is currently being read.\n");
        return;
    }

    printf("\nTitle: %s\n", reader->currentBook->title);
    printf("Author: %s\n\n", reader->currentBook->author);
    printf("%s\n", reader->currentBook->content[reader->currentBook->currentPage-1]);
    printf("\nCurrent Page: %d/%d\n", reader->currentBook->currentPage, reader->currentBook->pageCount);
}

// function to move to the previous page
void goToPreviousPage(EbookReader* reader) {
    if (reader->currentBook == NULL) {
        printf("\nNo book is currently being read.\n");
        return;
    }

    if (reader->currentBook->currentPage == 1) {
        printf("\nYou are already on the first page.\n");
        return;
    }

    reader->currentBook->currentPage--;
    displayCurrentPage(reader);
}

// function to move to the next page
void goToNextPage(EbookReader* reader) {
    if (reader->currentBook == NULL) {
        printf("\nNo book is currently being read.\n");
        return;
    }

    if (reader->currentBook->currentPage == reader->currentBook->pageCount) {
        printf("\nYou are already on the last page.\n");
        return;
    }

    reader->currentBook->currentPage++;
    displayCurrentPage(reader);
}

int main() {
    EbookReader reader;
    reader.librarySize = 0;
    reader.currentBook = NULL;

    int choice;
    do {
        displayMainMenu();
        scanf("%d", &choice);
        getchar(); // to remove the newline character from the input buffer

        switch (choice) {
            case 1:
                addEbookToLibrary(&reader);
                break;
            case 2:
                displayLibrary(&reader);
                break;
            case 3:
                setCurrentBook(&reader);
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

        if (choice == 3 && reader.currentBook != NULL) {
            char pageChoice;
            do {
                printf("\n\n");
                printf("a. Previous page\n");
                printf("b. Next page\n");
                printf("c. Back to main menu\n\n");
                printf("Enter your choice: ");
                scanf("%c", &pageChoice);
                getchar(); // to remove the newline character from the input buffer

                switch (pageChoice) {
                    case 'a':
                        goToPreviousPage(&reader);
                        break;
                    case 'b':
                        goToNextPage(&reader);
                        break;
                    case 'c':
                        printf("\nReturning to main menu.\n");
                        break;
                    default:
                        printf("\nInvalid choice.\n");
                        break;
                }
            } while (pageChoice != 'c');
        }
    } while (choice != 4);

    for (int i = 0; i < reader.librarySize; i++) {
        for (int j = 0; j < reader.library[i]->pageCount; j++) {
            free(reader.library[i]->content[j]);
        }
        free(reader.library[i]);
    }

    return 0;
}