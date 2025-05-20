//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char author[100];
    char genre[100];
    int year;
} Book;

int main() {
    Book books[5];
    int n, i, choice, status;

    printf("Library Management System\n");
    printf("1. Add Book\n");
    printf("2. Remove Book\n");
    printf("3. Search Book\n");
    printf("4. Display All Books\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the details of the book: \n");
            scanf("%s %s %s %d", books[n].name, books[n].author, books[n].genre, &books[n].year);
            printf("Book added successfully.\n");
            break;
        case 2:
            printf("Enter the name of the book you want to remove: \n");
            scanf("%s", books[n].name);
            status = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(books[i].name, books[n].name) == 0) {
                    status = 1;
                    break;
                }
            }
            if (status == 1) {
                printf("Book removed successfully.\n");
                for (i = 0; i < n-1; i++) {
                    books[i] = books[i+1];
                }
                n--;
            }
            else {
                printf("Book not found.\n");
            }
            break;
        case 3:
            printf("Enter the name of the book you want to search: \n");
            scanf("%s", books[n].name);
            status = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(books[i].name, books[n].name) == 0) {
                    status = 1;
                    break;
                }
            }
            if (status == 1) {
                printf("Book found.\n");
                printf("Name: %s\n", books[n].name);
                printf("Author: %s\n", books[n].author);
                printf("Genre: %s\n", books[n].genre);
                printf("Year: %d\n", books[n].year);
            }
            else {
                printf("Book not found.\n");
            }
            break;
        case 4:
            printf("All books are:\n");
            for (i = 0; i < n; i++) {
                printf("Name: %s\n", books[i].name);
                printf("Author: %s\n", books[i].author);
                printf("Genre: %s\n", books[i].genre);
                printf("Year: %d\n", books[i].year);
            }
            break;
        case 5:
            printf("Thank you for using Library Management System.\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }
    return 0;
}