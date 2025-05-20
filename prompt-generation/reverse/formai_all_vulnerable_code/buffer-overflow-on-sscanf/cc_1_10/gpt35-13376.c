//FormAI DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100 // maximum number of books

// structure for holding book information
typedef struct {
    char title[50];
    char author[50];
    int year;
    float price;
    char filename[50];
} Book;

// function to read book information from file
void readBooks(Book books[], int *numBooks) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: could not open books.txt\n");
        exit(1);
    }

    char line[100];
    *numBooks = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%d,%f,%s", books[*numBooks].title, books[*numBooks].author,
               &books[*numBooks].year, &books[*numBooks].price, books[*numBooks].filename);
        (*numBooks)++;
    }

    fclose(file);
}

// function to display book information
void displayBooks(Book books[], int numBooks) {
    printf("Title                 Author                Year  Price  Filename\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%-20s  %-20s  %4d  %5.2f  %s\n", books[i].title, books[i].author,
               books[i].year, books[i].price, books[i].filename);
    }
}

// function to open and read a book file
void readBookFile(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open %s\n", filename);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks;

    readBooks(books, &numBooks);
    displayBooks(books, numBooks);

    int choice;
    do {
        printf("\nEnter the number of the book that you want to read (0 to quit): ");
        scanf("%d", &choice);
        if (choice != 0 && (choice < 1 || choice > numBooks)) {
            printf("Error: invalid choice\n");
        } else if (choice != 0) {
            readBookFile(books[choice - 1].filename);
        }
    } while (choice != 0);

    return 0;
}