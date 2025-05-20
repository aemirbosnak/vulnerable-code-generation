//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 50
#define MAX_BOOK_NAME 50
#define MAX_USER_NAME 50

typedef struct {
    char bookName[MAX_BOOK_NAME];
    char author[MAX_USER_NAME];
    int pages;
} Book;

typedef struct {
    char userName[MAX_USER_NAME];
    int bookIds[MAX_BOOKS];
    int numBooks;
} User;

Book books[MAX_BOOKS];
int numBooks;

User users[MAX_USERS];
int numUsers;

int currentUserIndex = -1;

void displayMenu() {
    printf("1. Add Book\n");
    printf("2. Add User\n");
    printf("3. Display Books\n");
    printf("4. Display Users\n");
    printf("5. Login\n");
    printf("6. Logout\n");
    printf("7. View My Books\n");
    printf("8. Add Book to My Shelf\n");
    printf("9. Remove Book from My Shelf\n");
    printf("0. Exit\n");
}

void addBook() {
    Book newBook;
    printf("Enter Book Name: ");
    scanf("%s", newBook.bookName);
    printf("Enter Author Name: ");
    scanf("%s", newBook.author);
    printf("Enter Number of Pages: ");
    scanf("%d", &newBook.pages);

    // Add book to array
    books[numBooks] = newBook;
    numBooks++;

    printf("Book Added Successfully!\n");
}

void addUser() {
    User newUser;
    printf("Enter User Name: ");
    scanf("%s", newUser.userName);
    newUser.numBooks = 0;

    // Add user to array
    users[numUsers] = newUser;
    numUsers++;

    printf("User Added Successfully!\n");
}

void displayBooks() {
    printf("List of Books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].bookName, books[i].author, books[i].pages);
    }
}

void displayUsers() {
    printf("List of Users:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%d. %s\n", i+1, users[i].userName);
    }
}

void login() {
    char userName[MAX_USER_NAME];
    printf("Enter User Name: ");
    scanf("%s", userName);

    // Find user index
    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].userName, userName) == 0) {
            userIndex = i;
            break;
        }
    }

    // Login if found
    if (userIndex != -1) {
        currentUserIndex = userIndex;
        printf("Welcome, %s!\n", userName);
    } else {
        printf("User Name not found. Please try again.\n");
    }
}

void logout() {
    currentUserIndex = -1;
    printf("Logged Out Successfully!\n");
}

void viewMyBooks() {
    printf("%s's Books:\n", users[currentUserIndex].userName);
    for (int i = 0; i < users[currentUserIndex].numBooks; i++) {
        int bookId = users[currentUserIndex].bookIds[i];
        printf("%d. %s by %s (%d pages)\n", i+1, books[bookId].bookName, books[bookId].author, books[bookId].pages);
    }
}

void addBookToMyShelf() {
    int bookId;
    printf("Enter Book Id to add to your shelf: ");
    scanf("%d", &bookId);

    if (bookId >= 1 && bookId <= numBooks) {
        int userId = currentUserIndex;
        users[userId].bookIds[users[userId].numBooks] = bookId - 1;
        users[userId].numBooks++;
        printf("Book Added Successfully to your shelf!\n");
    } else {
        printf("Invalid Book Id. Please try again.\n");
    }
}

void removeBookFromMyShelf() {
    int bookId;
    printf("Enter Book Id to remove from your shelf: ");
    scanf("%d", &bookId);
    bookId--;

    int userId = currentUserIndex;

    if (bookId >= 0 && bookId < users[userId].numBooks) {
        // Shift elements to fill the gap
        for (int i = bookId; i < users[userId].numBooks - 1; i++) {
            users[userId].bookIds[i] = users[userId].bookIds[i+1];
        }
        users[userId].numBooks--;
        printf("Book Removed Successfully from your shelf!\n");
    } else {
        printf("Invalid Book Id. Please try again.\n");
    }
}

int main() {
    int option;
    do {
        displayMenu();
        printf("Enter Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addBook();
                break;
            case 2:
                addUser();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                displayUsers();
                break;
            case 5:
                login();
                break;
            case 6:
                logout();
                break;
            case 7:
                if (currentUserIndex != -1) {
                    viewMyBooks();
                } else {
                    printf("Please Login First!\n");
                }
                break;
            case 8:
                if (currentUserIndex != -1) {
                    addBookToMyShelf();
                } else {
                    printf("Please Login First!\n");
                }
                break;
            case 9:
                if (currentUserIndex != -1) {
                    removeBookFromMyShelf();
                } else {
                    printf("Please Login First!\n");
                }
                break;
            case 0:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Option. Please try again.\n");
                break;
        }

    } while(option != 0);

    return 0;
}