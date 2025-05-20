//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define MAX_USERS 10

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
} Book;

typedef struct {
    char username[50];
    char password[50];
    Book borrowedBook;
} User;

Book library[MAX_BOOKS];
int bookCount = 0;

User users[MAX_USERS];
int userCount = 0;

// Function declarations
void addBook();
void viewBooks();
void searchBook();
void registerUser();
void loginUser();
int findBookById(int id);
void saveBooks();
void loadBooks();

int main() {
    loadBooks();

    int choice;
    do {
        printf("\nWelcome to the Library Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Register User\n");
        printf("5. Login User\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                registerUser();
                break;
            case 5:
                loginUser();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    saveBooks();
    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", 
            library[i].id, library[i].title, library[i].author);
    }
}

void searchBook() {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    getchar(); // Clear newline character from input buffer

    int index = findBookById(id);
    if (index != -1) {
        printf("Book found!\nID: %d, Title: %s, Author: %s\n", 
            library[index].id, library[index].title, library[index].author);
    } else {
        printf("No book found with ID %d.\n", id);
    }
}

int findBookById(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            return i;
        }
    }
    return -1;
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    fgets(newUser.username, sizeof(newUser.username), stdin);
    newUser.username[strcspn(newUser.username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(newUser.password, sizeof(newUser.password), stdin);
    newUser.password[strcspn(newUser.password, "\n")] = 0; // Remove newline

    users[userCount] = newUser;
    userCount++;
    printf("User registered successfully!\n");
}

void loginUser() {
    char username[50], password[50];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && 
            strcmp(users[i].password, password) == 0) {
            printf("Successfully logged in as %s.\n", username);
            return;
        }
    }
    printf("Invalid username or password.\n");
}

void saveBooks() {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%d|%s|%s\n", library[i].id, library[i].title, library[i].author);
    }
    fclose(file);
}

void loadBooks() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        return; // File might not exist, which is fine at startup
    }

    while (fscanf(file, "%d|%49[^|]|%49[^\n]\n", 
            &library[bookCount].id, 
            library[bookCount].title, 
            library[bookCount].author) == 3) {
        bookCount++;
    }
    fclose(file);
}