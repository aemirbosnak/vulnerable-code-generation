//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library* library) {
    library->count = 0;
    printf("\nWelcome to the Happy Library! Your library is ready! 📚🌟\n");
}

void addBook(Library* library) {
    if (library->count >= MAX_BOOKS) {
        printf("Oh no! The library is full! Can't add more books! 😞\n");
        return;
    }
    
    Book newBook;
    printf("\nAdding a new book! 🎉\n");
    printf("Enter the title: ");
    getchar(); // to consume newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove newline
    printf("Enter the author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove newline
    printf("Enter the publication year: ");
    scanf("%d", &newBook.year);
    
    library->books[library->count] = newBook;
    library->count++;
    
    printf("Hooray! Added '%s' by %s (%d) to the library! 🎈\n", 
           newBook.title, newBook.author, newBook.year);
}

void viewBooks(const Library* library) {
    if (library->count == 0) {
        printf("Oops! No books available in the library. 🏚️\n");
        return;
    }
    
    printf("\nHere are the books in the Happy Library! 📖✨\n");
    for (int i = 0; i < library->count; i++) {
        Book b = library->books[i];
        printf("%d. '%s' by %s (%d)\n", i + 1, b.title, b.author, b.year);
    }
}

void searchBook(const Library* library) {
    if (library->count == 0) {
        printf("Oops! No books available to search. 📚❌\n");
        return;
    }

    char searchString[TITLE_LENGTH];
    printf("\n🔍 Searching for a book! Enter title or author: ");
    getchar(); // to consume newline
    fgets(searchString, TITLE_LENGTH, stdin);
    searchString[strcspn(searchString, "\n")] = 0; // remove newline

    printf("Results for '%s':\n", searchString);
    int found = 0;
    
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, searchString) != NULL ||
            strstr(library->books[i].author, searchString) != NULL) {
            found = 1;
            Book b = library->books[i];
            printf("- '%s' by %s (%d)\n", b.title, b.author, b.year);
        }
    }
    
    if (!found) {
        printf("Sorry, no books found matching '%s'. 🥺\n", searchString);
    }
}

void showMenu() {
    printf("\n=== Happy Library Menu ===\n");
    printf("1. Add a Book\n");
    printf("2. View All Books\n");
    printf("3. Search for a Book\n");
    printf("4. Quit\n");
    printf("==========================\n");
}

int main() {
    Library myLibrary;
    initializeLibrary(&myLibrary);
    
    int choice;
    do {
        showMenu();
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(&myLibrary);
                break;
            case 2:
                viewBooks(&myLibrary);
                break;
            case 3:
                searchBook(&myLibrary);
                break;
            case 4:
                printf("Thank you for visiting the Happy Library! Goodbye! 😊📚\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option. 🎯\n");
                break;
        }
    } while (choice != 4);

    return 0;
}