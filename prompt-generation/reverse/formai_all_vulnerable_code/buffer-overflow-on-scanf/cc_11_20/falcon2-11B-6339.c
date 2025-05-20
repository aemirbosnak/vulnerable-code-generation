//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char title[50];
    int pages;
} Book;

int main() {
    // Create an array to store books
    Book books[10];

    // Initialize books array with default values
    for (int i = 0; i < 10; i++) {
        books[i].id = -1;
        books[i].title[0] = '\0';
        books[i].pages = 0;
    }

    // Display initial books in the library
    printf("Initial Library:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %s - %d pages\n", i, books[i].title, books[i].pages);
    }

    // Add a new book to the library
    printf("Add a book:\n");
    int choice = -1;
    while (choice < 0 || choice > 1) {
        printf("Enter 1 to add a book.\n");
        printf("Enter 2 to exit.\n");
        scanf("%d", &choice);
    }
    if (choice == 1) {
        char title[50];
        int pages;
        printf("Enter book title: ");
        scanf("%s", title);
        printf("Enter book pages: ");
        scanf("%d", &pages);
        books[0].id = 1;
        strcpy(books[0].title, title);
        books[0].pages = pages;
        printf("Book added successfully.\n");
    }

    // Remove a book from the library
    printf("Remove a book:\n");
    choice = -1;
    while (choice < 0 || choice > 1) {
        printf("Enter 1 to remove a book.\n");
        printf("Enter 2 to exit.\n");
        scanf("%d", &choice);
    }
    if (choice == 1) {
        int index;
        printf("Enter book index to remove (0-%d): ", 10);
        scanf("%d", &index);
        if (index >= 0 && index < 10) {
            for (int i = index; i < 10; i++) {
                books[i].id = i + 1;
            }
            strcpy(books[0].title, books[index].title);
            books[0].pages = books[index].pages;
            printf("Book removed successfully.\n");
        } else {
            printf("Invalid book index.\n");
        }
    }

    // Display updated books in the library
    printf("Updated Library:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %s - %d pages\n", i, books[i].title, books[i].pages);
    }

    return 0;
}