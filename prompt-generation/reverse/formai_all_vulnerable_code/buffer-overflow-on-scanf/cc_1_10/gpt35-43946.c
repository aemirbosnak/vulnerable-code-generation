//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char publisher[100];
    int year_published;
    int page_count;
} Book;

typedef struct {
    char name[100];
    int age;
    char email[100];
    char password[100];
} User;

int main() {
    int choice = 0, i, j, num_books = 0;
    Book library[100];
    User user;

    printf("Welcome to the Ebook Reader!\n\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your email: ");
    scanf("%s", user.email);
    printf("Please enter your password: ");
    scanf("%s", user.password);

    while (choice != 3) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a book to your library\n");
        printf("2. View your library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter book title: ");
            scanf("%s", library[num_books].title);
            printf("Enter book author: ");
            scanf("%s", library[num_books].author);
            printf("Enter book publisher: ");
            scanf("%s", library[num_books].publisher);
            printf("Enter year published: ");
            scanf("%d", &library[num_books].year_published);
            printf("Enter page count: ");
            scanf("%d", &library[num_books].page_count);
            num_books++;
        } else if (choice == 2) {
            if (num_books == 0) {
                printf("\nYour library is empty!\n");
            } else {
                printf("\nYour library contains:\n");

                for (i = 0; i < num_books; i++) {
                    printf("\nBook %d\n", i + 1);
                    printf("Title: %s\n", library[i].title);
                    printf("Author: %s\n", library[i].author);
                    printf("Publisher: %s\n", library[i].publisher);
                    printf("Year published: %d\n", library[i].year_published);
                    printf("Page count: %d\n", library[i].page_count);
                }
            }
        } else if (choice == 3) {
            printf("\nThank you for using the Ebook Reader! Goodbye!\n");
        } else {
            printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}