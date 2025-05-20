//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 100
#define AUTHOR_SIZE 100
#define FILENAME "books.dat"

typedef struct {
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int year;
} Book;

void pressEnterToContinue() {
    printf("Press Enter to continue...\n");
    while(getchar() != '\n');
}

void addBook() {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    Book book;
    printf("Enter book title: ");
    fgets(book.title, TITLE_SIZE, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline
    printf("Enter author name: ");
    fgets(book.author, AUTHOR_SIZE, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline
    printf("Enter year of publication: ");
    scanf("%d", &book.year);
    getchar(); // Clearing newline from buffer

    fwrite(&book, sizeof(Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
    pressEnterToContinue();
}

void displayBooks() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No books found.\n");
        return;
    }

    Book book;
    printf("List of Books:\n");
    printf("------------------------------------------------\n");
    while(fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s | Author: %s | Year: %d\n", book.title, book.author, book.year);
    }
    fclose(file);
    pressEnterToContinue();
}

void deleteBook() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No books found to delete.\n");
        return;
    }

    int bookIndex;
    printf("Select the book number to delete (1 to N): ");
    scanf("%d", &bookIndex);
    getchar(); // Clearing newline from buffer

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error opening temp file!\n");
        return;
    }

    Book book;
    int currentIndex = 1;
    while(fread(&book, sizeof(Book), 1, file)) {
        if (currentIndex == bookIndex) {
            printf("Deleted book: %s\n", book.title);
            currentIndex++;
            continue; // Skip this book
        }
        fwrite(&book, sizeof(Book), 1, tempFile);
        currentIndex++;
    }
    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.dat", FILENAME);

    printf("Book deleted successfully!\n");
    pressEnterToContinue();
}

void menu() {
    int choice;
    
    while (1) {
        printf("\n*** Book Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clearing newline from buffer
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Book Management System!\n");
    menu();
    return 0;
}