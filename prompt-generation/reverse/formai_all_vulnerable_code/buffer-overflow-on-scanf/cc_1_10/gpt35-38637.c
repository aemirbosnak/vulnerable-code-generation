//FormAI DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct ebook {
    char title[50];
    char author[50];
    char genre[20];
    int pageCount;
    char publisher[50];
    float price;
    char language[20];
};

struct ebook library[20]; // initialize the library to hold 20 books
int numBooks = 0; // initialize the number of books in the library to 0

void addBook() {
    if (numBooks < 20) {
        printf("Enter book title: ");
        scanf("%s", library[numBooks].title);
        printf("Enter author name: ");
        scanf("%s", library[numBooks].author);
        printf("Enter genre: ");
        scanf("%s", library[numBooks].genre);
        printf("Enter number of pages: ");
        scanf("%d", &library[numBooks].pageCount);
        printf("Enter publisher: ");
        scanf("%s", library[numBooks].publisher);
        printf("Enter price: ");
        scanf("%f", &library[numBooks].price);
        printf("Enter language: ");
        scanf("%s", library[numBooks].language);
        numBooks++;
    } else {
        printf("The library is full.\n");
    }
}

void viewBooks() {
    if (numBooks == 0) {
        printf("The library is empty.\n");
    } else {
        printf("Library books:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Book %d:\n", i+1);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Genre: %s\n", library[i].genre);
            printf("Number of pages: %d\n", library[i].pageCount);
            printf("Publisher: %s\n", library[i].publisher);
            printf("Price: $%.2f\n", library[i].price);
            printf("Language: %s\n", library[i].language);
        }
    }
}

void searchBook(char keyword[]) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strstr(library[i].title, keyword) != NULL || strstr(library[i].author, keyword) != NULL 
        || strstr(library[i].genre, keyword) != NULL || strstr(library[i].language, keyword) != NULL) {
            printf("Book %d:\n", i+1);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Genre: %s\n", library[i].genre);
            printf("Number of pages: %d\n", library[i].pageCount);
            printf("Publisher: %s\n", library[i].publisher);
            printf("Price: $%.2f\n", library[i].price);
            printf("Language: %s\n", library[i].language);
            found++;
        }
    }
    if (!found) {
        printf("No books found.\n");
    }
}

int main() {
    int choice;
    char search[50];

    do {
        printf("\n******** EBOOK READER ********\n");
        printf("1. Add book\n");
        printf("2. View books\n");
        printf("3. Search book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                printf("Enter keyword to search for: ");
                scanf("%s", search);
                searchBook(search);
                break;
            case 4:
                printf("Thank you for using the ebook reader.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}