//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10

typedef struct {
    char title[100];
    char author[100];
    int year;
    char format[10];
    int pages;
} Book;

Book library[MAX_BOOKS];
int numBooks = 0;

void addBook(Book newBook) {
    if (numBooks < MAX_BOOKS) {
        library[numBooks++] = newBook;
        printf("%s successfully added to the library!\n", newBook.title);
    } else {
        printf("Sorry, the library is full.\n");
    }
}

void listBooks() {
    if (numBooks == 0) {
        printf("The library is currently empty.\n");
        return;
    }
    printf("TITLE\t\tAUTHOR\t\tYEAR\tFORMAT\tPAGES\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s\t\t%s\t\t%d\t%s\t%d\n", library[i].title, library[i].author, library[i].year, library[i].format, library[i].pages);
    }
}

void readBook(int index) {
    if (index < 0 || index >= numBooks) {
        printf("Invalid index.\n");
        return;
    }
    printf("Reading %s...\n", library[index].title);
    // code to open and read book goes here
}

int main() {
    int choice, index;
    Book newBook;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("3. Read book\n");
        printf("4. Exit program\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf("%s", newBook.title);
                printf("Enter book author: ");
                scanf("%s", newBook.author);
                printf("Enter book publication year: ");
                scanf("%d", &newBook.year);
                printf("Enter book format (e.g. epub, pdf): ");
                scanf("%s", newBook.format);
                printf("Enter number of pages: ");
                scanf("%d", &newBook.pages);
                addBook(newBook);
                break;
            case 2:
                listBooks();
                break;
            case 3:
                printf("Enter index of book to read: ");
                scanf("%d", &index);
                readBook(index);
                break;
            case 4:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}