//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: sophisticated
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

void addBook(FILE *file);
void listBooks(FILE *file);
void searchBook(FILE *file);
void saveBooksToFile(FILE *file, Book *books, int count);
int loadBooksFromFile(FILE *file, Book *books);
void displayMenu();

int main() {
    FILE *file;
    file = fopen("books.dat", "a+");
    if (file == NULL) {
        perror("Error opening the file");
        return EXIT_FAILURE;
    }

    Book books[MAX_BOOKS];
    int count = loadBooksFromFile(file, books);
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                listBooks(file);
                break;
            case 3:
                searchBook(file);
                break;
            case 4:
                saveBooksToFile(file, books, count);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    fclose(file);
    return EXIT_SUCCESS;
}

void addBook(FILE *file) {
    Book newBook;

    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // Remove newline character

    printf("Enter author's name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n"); // Remove newline character

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    getchar();  // Clear newline from input buffer

    fprintf(file, "%s\n%s\n%d\n", newBook.title, newBook.author, newBook.year);
    printf("Book added successfully!\n");
}

void listBooks(FILE *file) {
    rewind(file);
    char line[256];
    printf("\nList of Books:\n");
    printf("====================\n");
    
    while (fgets(line, sizeof(line), file)) {
        printf("Title: %s", line);
        fgets(line, sizeof(line), file);
        printf("Author: %s", line);
        fgets(line, sizeof(line), file);
        printf("Year: %s\n", line);
        printf("--------------------\n");
    }
}

void searchBook(FILE *file) {
    char searchTitle[MAX_TITLE_LENGTH];
    rewind(file);
    int found = 0;

    printf("Enter book title to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    strtok(searchTitle, "\n"); // Remove newline character

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, searchTitle) != NULL) {
            found = 1;
            printf("Book found:\n");
            printf("Title: %s", line);
            fgets(line, sizeof(line), file);
            printf("Author: %s", line);
            fgets(line, sizeof(line), file);
            printf("Year: %s\n", line);
            break;
        }
        fgets(line, sizeof(line), file); // Skip author
        fgets(line, sizeof(line), file); // Skip year
    }
    
    if (!found) {
        printf("No book found with title \"%s\".\n", searchTitle);
    }
}

void saveBooksToFile(FILE *file, Book *books, int count) {
    rewind(file);
    FILE *tempFile = fopen("temp_books.dat", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(tempFile, "%s\n%s\n%d\n", books[i].title, books[i].author, books[i].year);
    }

    fclose(tempFile);
    fclose(file);
    rename("temp_books.dat", "books.dat");
    printf("Books saved successfully!\n");
}

int loadBooksFromFile(FILE *file, Book *books) {
    rewind(file);
    int count = 0;

    while (!feof(file)) {
        fgets(books[count].title, MAX_TITLE_LENGTH, file);
        strtok(books[count].title, "\n"); // Remove newline character
        fgets(books[count].author, MAX_AUTHOR_LENGTH, file);
        strtok(books[count].author, "\n");
        fscanf(file, "%d\n", &books[count].year);
        count++;
    }
    
    return count - 1; // Return the count of valid books
}

void displayMenu() {
    printf("\n--- Book Management System ---\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Search Book\n");
    printf("4. Save Books\n");
    printf("5. Exit\n");
}