//FormAI DATASET v1.0 Category: Ebook reader ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BOOK_NAME_SIZE 50    // Maximum number of characters allowed in the book name.
#define MAX_BOOKS 50    // Maximum number of books that can be present in the library.
#define MAX_USERS 10    // Maximum number of users that can use the library.

// Structure to represent a book.
typedef struct {
    char name[BOOK_NAME_SIZE];
    int pages;
    int current_page;
} Book;

// Structure to represent a user.
typedef struct {
    char username[20];
    int current_book_index;
} User;

// Function to print the list of available books.
void print_books(Book *books, int num_books) {
    printf("\nAvailable books:\n");
    for(int i=0; i<num_books; i++) {
        printf("%d. %s by %d pages\n", i+1, books[i].name, books[i].pages);
    }
}

// Function to get the index of the book selected by the user.
int select_book(Book *books, int num_books) {
    int choice;
    while(1) {
        printf("\nEnter the index of the book you would like to read: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= num_books) {
            return choice-1;
        }
        printf("Invalid choice. Please enter a valid index.\n");
    }
}

// Function to get the name of the user.
void get_username(char *username) {
    printf("\nEnter your username: ");
    scanf("%s", username);
}

int main() {
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int num_books = 0;
    int num_users = 0;

    // Adding some sample books.
    strcpy(books[num_books].name, "The Catcher in the Rye");
    books[num_books].pages = 224;
    books[num_books].current_page = 1;
    num_books++;

    strcpy(books[num_books].name, "To Kill a Mockingbird");
    books[num_books].pages = 336;
    books[num_books].current_page = 1;
    num_books++;

    // Displaying the list of books.
    print_books(books, num_books);

    while(1) {
        // Getting the index of the book selected by the user.
        int book_index = select_book(books, num_books);

        // Checking if the book is already being read by some other user.
        for(int i=0; i<num_users; i++) {
            if(users[i].current_book_index == book_index) {
                printf("\nSorry, this book is already being read by %s. Please select another book.\n", users[i].username);
                break;
            }
        }

        // Adding a new user.
        if(num_users == MAX_USERS) {
            printf("\nSorry, the library is currently full. Please try again later.\n");
            return 0;
        } else {
            get_username(users[num_users].username);
            users[num_users].current_book_index = book_index;
            num_users++;
        }
    }

    return 0;
}