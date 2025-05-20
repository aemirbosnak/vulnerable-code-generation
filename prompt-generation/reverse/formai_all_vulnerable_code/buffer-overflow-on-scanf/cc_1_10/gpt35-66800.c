//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 20
#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    float price;
    int year;
    int pages;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    Book b;
    printf("Enter book title: ");
    scanf("%s", &b.title);
    printf("Enter book author: ");
    scanf("%s", &b.author);
    printf("Enter book price: ");
    scanf("%f", &b.price);
    printf("Enter book year: ");
    scanf("%d", &b.year);
    printf("Enter book pages: ");
    scanf("%d", &b.pages);
    library[bookCount] = b;
    bookCount++;
    printf("Book added successfully.\n");
}

void displayBooks() {
    printf("\n------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Price: %.2f\n", library[i].price);
        printf("Year: %d\n", library[i].year);
        printf("Pages: %d\n", library[i].pages);
        printf("------------\n");
    }
}

void loadBooks() {
    char fileName[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", &fileName);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        while (!feof(file) && bookCount < MAX_BOOKS) {
            Book b;
            fscanf(file, "%s%s%f%d%d", b.title, b.author, &b.price, &b.year, &b.pages);
            library[bookCount] = b;
            bookCount++;
        }
        fclose(file);
        printf("Books loaded successfully.\n");
    }
}

int main() {
    int option;
    do {
        printf("\n1. Add book\n");
        printf("2. Display books\n");
        printf("3. Load books from file\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                loadBooks();
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 4);

    return 0;
}