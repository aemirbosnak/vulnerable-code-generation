//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 30
#define USER_INPUT_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
    int available; // 1 for available, 0 for borrowed
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initializeLibrary(Library *library) {
    library->count = 0;
}

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    
    Book new_book;
    printf("Enter title of the book: ");
    fgets(new_book.title, TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;  // Remove newline character
    
    printf("Enter author of the book: ");
    fgets(new_book.author, AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;  // Remove newline character
    
    printf("Enter publication year: ");
    scanf("%d", &new_book.year);
    getchar();  // Clear newline character from the buffer

    new_book.available = 1; // New books are available
    library->books[library->count++] = new_book;
    
    printf("Book added successfully!\n");
}

void displayBooks(Library *library) {
    if (library->count == 0) {
        printf("No books available in the library!\n");
        return;
    }
    
    printf("\n--- Books in the Library ---\n");
    for (int i = 0; i < library->count; ++i) {
        printf("%d. Title: %s, Author: %s, Year: %d, Available: %s\n", 
               i + 1, 
               library->books[i].title, 
               library->books[i].author, 
               library->books[i].year, 
               library->books[i].available ? "Yes" : "No");
    }
    printf("----------------------------\n");
}

void borrowBook(Library *library) {
    displayBooks(library);
    
    if (library->count == 0) return;

    int index;
    printf("Enter the number of the book you want to borrow: ");
    scanf("%d", &index);
    getchar();  // Clear newline character from the buffer

    if (index < 1 || index > library->count) {
        printf("Invalid selection!\n");
        return;
    }
    
    if (library->books[index - 1].available) {
        library->books[index - 1].available = 0; // Mark book as borrowed
        printf("You have borrowed: %s\n", library->books[index - 1].title);
    } else {
        printf("Sorry, this book is already borrowed!\n");
    }
}

void returnBook(Library *library) {
    displayBooks(library);
    
    if (library->count == 0) return;

    int index;
    printf("Enter the number of the book you want to return: ");
    scanf("%d", &index);
    getchar();  // Clear newline character from the buffer

    if (index < 1 || index > library->count) {
        printf("Invalid selection!\n");
        return;
    }

    if (!library->books[index - 1].available) {
        library->books[index - 1].available = 1; // Mark book as returned
        printf("You have returned: %s\n", library->books[index - 1].title);
    } else {
        printf("This book was not borrowed!\n");
    }
}

void saveLibrary(Library *library) {
    FILE *file = fopen("library.dat", "wb");
    if (!file) {
        printf("Could not open file for writing!\n");
        return;
    }
    fwrite(library, sizeof(Library), 1, file);
    fclose(file);
    printf("Library data saved to library.dat.\n");
}

void loadLibrary(Library *library) {
    FILE *file = fopen("library.dat", "rb");
    if (!file) {
        printf("No saved data found. Please add books.\n");
        return;
    }
    fread(library, sizeof(Library), 1, file);
    fclose(file);
    printf("Library data loaded from library.dat.\n");
}

void displayMenu() {
    printf("\n--- Apocalypse Library Management System ---\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Save Library\n");
    printf("6. Load Library\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Library library;
    initializeLibrary(&library);
    
    loadLibrary(&library);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Clear newline character from the buffer

        switch (choice) {
            case 1: 
                addBook(&library);
                break;
            case 2:
                displayBooks(&library);
                break;
            case 3:
                borrowBook(&library);
                break;
            case 4:
                returnBook(&library);
                break;
            case 5:
                saveLibrary(&library);
                break;
            case 6:
                loadLibrary(&library);
                break;
            case 7:
                printf("Exiting the system. Stay safe out there!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}