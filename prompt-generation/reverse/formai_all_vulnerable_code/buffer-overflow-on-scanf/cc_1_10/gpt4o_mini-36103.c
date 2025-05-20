//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

// Function prototypes
void inputBooks(Book books[], int *count);
void printBooks(const Book books[], int count);
void sortBooksByTitle(Book books[], int count);
void sortBooksByYear(Book books[], int count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;
    
    // Input books
    inputBooks(books, &count);

    do {
        printf("\nChoose sorting option:\n");
        printf("1. Sort by Title\n");
        printf("2. Sort by Year\n");
        printf("3. Print Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                sortBooksByTitle(books, count);
                printf("Books sorted by Title.\n");
                break;
            case 2:
                sortBooksByYear(books, count);
                printf("Books sorted by Year.\n");
                break;
            case 3:
                printBooks(books, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void inputBooks(Book books[], int *count) {
    printf("Enter the number of books (Max %d): ", MAX_BOOKS);
    scanf("%d", count);
    
    for (int i = 0; i < *count; i++) {
        printf("\nEnter details for book %d:\n", i + 1);
        printf("Title: ");
        getchar(); // consume newline character
        fgets(books[i].title, TITLE_LENGTH, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // remove newline

        printf("Author: ");
        fgets(books[i].author, AUTHOR_LENGTH, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0'; // remove newline

        printf("Year of publication: ");
        scanf("%d", &books[i].year);
    }
}

void printBooks(const Book books[], int count) {
    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, books[i].title, books[i].author, books[i].year);
    }
}

void sortBooksByTitle(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(books[j].title, books[j + 1].title) > 0) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortBooksByYear(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].year > books[j + 1].year) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}