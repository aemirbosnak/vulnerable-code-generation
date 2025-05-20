//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int issued; // 0 if not issued, 1 if issued
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function Prototypes
void displayMenu();
void addBook();
void displayBooks();
void issueBook();
void returnBook();
void saveBooksToFile();
void loadBooksFromFile();

int main() {
    loadBooksFromFile();
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                saveBooksToFile();
                printf("Books saved. Exiting...\n");
                break;
            default:
                if (choice != 5) {
                    printf("Invalid choice! Please try again.\n");
                }
        }
    } while (choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display All Books\n");
    printf("3. Issue Book\n");
    printf("4. Return Book\n");
    printf("5. Save and Exit\n");
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter book title: ");
    getchar(); // to consume newline character
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    newBook.issued = 0; // not issued
    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s [%s]\n", 
               i + 1, 
               library[i].title, 
               library[i].author, 
               library[i].issued ? "Issued" : "Available");
    }
}

void issueBook() {
    displayBooks();
    
    int index;
    printf("Enter the book number to issue: ");
    scanf("%d", &index);
    
    if (index < 1 || index > bookCount) {
        printf("Invalid book number!\n");
        return;
    }

    if (library[index - 1].issued) {
        printf("Sorry, this book is already issued.\n");
    } else {
        library[index - 1].issued = 1;
        printf("You have successfully issued '%s'.\n", library[index - 1].title);
    }
}

void returnBook() {
    displayBooks();
    
    int index;
    printf("Enter the book number to return: ");
    scanf("%d", &index);
    
    if (index < 1 || index > bookCount) {
        printf("Invalid book number!\n");
        return;
    }

    if (!library[index - 1].issued) {
        printf("This book was not issued.\n");
    } else {
        library[index - 1].issued = 0;
        printf("You have successfully returned '%s'.\n", library[index - 1].title);
    }
}

void saveBooksToFile() {
    FILE *file = fopen("library.txt", "w");
    if (!file) {
        printf("Error: Could not save file.\n");
        return;
    }
    
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s\n%s\n%d\n", library[i].title, library[i].author, library[i].issued);
    }
    
    fclose(file);
}

void loadBooksFromFile() {
    FILE *file = fopen("library.txt", "r");
    if (!file) {
        return; // No file exists, start with an empty library
    }

    while (fscanf(file, " %[^\n] %[^\n] %d\n", library[bookCount].title, library[bookCount].author, &library[bookCount].issued) != EOF) {
        bookCount++;
    }
    
    fclose(file);
}