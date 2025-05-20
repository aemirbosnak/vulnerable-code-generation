//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_RECORDS 100

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
} Book;

void displayBooks(Book books[], int count);
void addBook(Book books[], int *count);
void searchBook(Book books[], int count);
void deleteBook(Book books[], int *count);
void saveBooks(Book books[], int count);
void loadBooks(Book books[], int *count);

int main() {
    Book books[MAX_RECORDS];
    int count = 0;
    int choice;

    loadBooks(books, &count);

    do {
        printf("\n--- Book Database ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                deleteBook(books, &count);
                break;
            case 5:
                saveBooks(books, count);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }
    printf("\nID\tTitle\t\t\tAuthor\n");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\n", books[i].id, books[i].title, books[i].author);
    }
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    newBook.id = *count + 1; // Simple ID assignment based on the count
    printf("Enter title: ");
    fgets(newBook.title, MAX_TITLE_LEN, stdin);
    strtok(newBook.title, "\n"); // Remove newline character

    printf("Enter author: ");
    fgets(newBook.author, MAX_AUTHOR_LEN, stdin);
    strtok(newBook.author, "\n"); // Remove newline character

    books[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

void searchBook(Book books[], int count) {
    if (count == 0) {
        printf("No books available to search.\n");
        return;
    }
    
    char searchTitle[MAX_TITLE_LEN];
    printf("Enter title to search: ");
    fgets(searchTitle, MAX_TITLE_LEN, stdin);
    strtok(searchTitle, "\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found: ID: %d, Title: %s, Author: %s\n",
                    books[i].id, books[i].title, books[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook(Book books[], int *count) {
    if (*count == 0) {
        printf("No books available to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Invalid ID. No book deleted.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        books[i] = books[i + 1];
    }

    (*count)--;
    printf("Book with ID %d deleted successfully.\n", id);
}

void saveBooks(Book books[], int count) {
    FILE *file = fopen("books.dat", "wb");
    if (!file) {
        printf("Error saving books.\n");
        return;
    }
    fwrite(books, sizeof(Book), count, file);
    fclose(file);
    printf("Books saved successfully.\n");
}

void loadBooks(Book books[], int *count) {
    FILE *file = fopen("books.dat", "rb");
    if (file) {
        *count = fread(books, sizeof(Book), MAX_RECORDS, file);
        fclose(file);
        printf("Books loaded successfully. Count: %d\n", *count);
    } else {
        printf("No saved books found. Start adding new books.\n");
    }
}