//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

void addBook(const char *filename);
void viewBooks(const char *filename);
void deleteBook(const char *filename);
void listBooks(Book books[], int count);
int loadBooks(const char *filename, Book books[]);

int main() {
    char filename[] = "library.dat";
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(filename);
                break;
            case 2:
                viewBooks(filename);
                break;
            case 3:
                deleteBook(filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void addBook(const char *filename) {
    Book newBook;
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter book title: ");
    getchar(); // consume newline
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    fwrite(&newBook, sizeof(Book), 1, file);
    fclose(file);

    printf("Book added successfully!\n");
}

void viewBooks(const char *filename) {
    Book books[MAX_BOOKS];
    int count = loadBooks(filename, books);
    
    if (count == 0) {
        printf("No books found.\n");
        return;
    }
    
    printf("\nBooks in Library:\n");
    listBooks(books, count);
}

int loadBooks(const char *filename, Book books[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return 0;
    }
    
    int count = 0;
    while (fread(&books[count], sizeof(Book), 1, file) == 1) {
        count++;
    }
    
    fclose(file);
    return count;
}

void listBooks(Book books[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Book %d: Title: %s, Author: %s, Year: %d\n", 
               i+1, books[i].title, books[i].author, books[i].year);
    }
}

void deleteBook(const char *filename) {
    Book books[MAX_BOOKS];
    int count = loadBooks(filename, books);
    
    if (count == 0) {
        printf("No books found to delete.\n");
        return;
    }
    
    listBooks(books, count);
    
    int index;
    printf("Select the book number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid book number.\n");
        return;
    }
    
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != index - 1) {
            fwrite(&books[i], sizeof(Book), 1, file);
        }
    }

    fclose(file);
    printf("Book deleted successfully!\n");
}