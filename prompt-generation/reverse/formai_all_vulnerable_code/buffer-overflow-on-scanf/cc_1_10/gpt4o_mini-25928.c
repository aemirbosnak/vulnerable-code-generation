//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: real-life
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

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", library[*count].author);
    printf("Enter publication year: ");
    scanf("%d", &library[*count].year);
    
    (*count)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    
    printf("\nList of Books in Library:\n");
    for (int i = 0; i < count; i++) {
        printf("Book %d: %s by %s (Year: %d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

void removeBook(Book *library, int *count) {
    if (*count == 0) {
        printf("No books to remove.\n");
        return;
    }
    
    int index;
    printf("Enter the book number to remove (1 to %d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid book number.\n");
        return;
    }
    
    for (int i = index - 1; i < *count - 1; i++) {
        library[i] = library[i + 1];
    }
    
    (*count)--;
    printf("Book removed successfully!\n");
}

void saveLibraryToFile(Book *library, int count) {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%d\n", library[i].title, library[i].author, library[i].year);
    }
    
    fclose(file);
    printf("Library saved to file successfully!\n");
}

void loadLibraryFromFile(Book *library, int *count) {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("No existing library file found. Start adding books.\n");
        return;
    }
    
    while (fscanf(file, " %[^\n]|%[^\n]|%d\n", library[*count].title, library[*count].author, &library[*count].year) != EOF) {
        (*count)++;
    }
    
    fclose(file);
    printf("Library loaded from file successfully!\n");
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    loadLibraryFromFile(library, &count);

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Remove Book\n");
        printf("4. Save Library to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                viewBooks(library, count);
                break;
            case 3:
                removeBook(library, &count);
                break;
            case 4:
                saveLibraryToFile(library, count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}