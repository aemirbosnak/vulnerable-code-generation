//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int is_checked_out;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

// Function declarations
void addBook();
void listBooks();
void checkOutBook();
void returnBook();
void paranoidEntry(char *message);
void paranoidLog(char *action, char *title);

int main() {
    int choice;

    while (1) {
        printf("C Music Library Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Check Out Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                checkOutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting the system... paranoidly.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }
    return 0;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }

    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];

    printf("Enter book title: ");
    getchar(); // consume newline
    fgets(title, MAX_TITLE_LEN, stdin);
    strtok(title, "\n"); // remove newline

    printf("Enter author name: ");
    fgets(author, MAX_AUTHOR_LEN, stdin);
    strtok(author, "\n"); // remove newline

    paranoidEntry("Adding new book");
    strcpy(library[book_count].title, title);
    strcpy(library[book_count].author, author);
    library[book_count].is_checked_out = 0;
    book_count++;
    
    paranoidLog("Added", title);
    printf("Book added successfully!\n");
}

void listBooks() {
    printf("Listing all books...\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. Title: %s, Author: %s, ", i + 1, library[i].title, library[i].author);
        printf(library[i].is_checked_out ? "Status: Checked Out\n" : "Status: Available\n");
    }
}

void checkOutBook() {
    int index;
    printf("Enter the book number to check out: ");
    scanf("%d", &index);
    
    if (index < 1 || index > book_count) {
        printf("Invalid book number!\n");
        return;
    }

    if (library[index - 1].is_checked_out) {
        printf("Book already checked out!\n");
        return;
    }

    library[index - 1].is_checked_out = 1;
    paranoidLog("Checked out", library[index - 1].title);
    printf("You have checked out: %s\n", library[index - 1].title);
}

void returnBook() {
    int index;
    printf("Enter the book number to return: ");
    scanf("%d", &index);
    
    if (index < 1 || index > book_count) {
        printf("Invalid book number!\n");
        return;
    }

    if (!library[index - 1].is_checked_out) {
        printf("Book was not checked out!\n");
        return;
    }

    library[index - 1].is_checked_out = 0;
    paranoidLog("Returned", library[index - 1].title);
    printf("You have returned: %s\n", library[index - 1].title);
}

void paranoidEntry(char *message) {
    printf("[PARANOID ALERT]: %s - Proceed with caution!\n", message);
}

void paranoidLog(char *action, char *title) {
    FILE *logFile = fopen("library_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "[%s] Book: '%s' was %s.\n", __DATE__, title, action);
        fclose(logFile);
    } else {
        printf("[ERROR]: Unable to log the activity. Stay vigilant!\n");
    }
}