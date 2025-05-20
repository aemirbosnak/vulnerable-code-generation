//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
} Book;

void addBook(Book *library, int *count);
void viewBooks(Book *library, int count);
void updateBook(Book *library, int count);
void deleteBook(Book *library, int *count);
void saveToFile(Book *library, int count);
void loadFromFile(Book *library, int *count);

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    
    loadFromFile(library, &count);
    
    int option;
    
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Update Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                viewBooks(library, count);
                break;
            case 3:
                updateBook(library, count);
                break;
            case 4:
                deleteBook(library, &count);
                break;
            case 5:
                saveToFile(library, count);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(option != 5);
    
    return 0;
}

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = *count + 1; // Simple ID assignment
    printf("Enter the book title: ");
    getchar(); // clear the newline character from previous input
    fgets(newBook.title, MAX_TITLE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // remove newline
    printf("Enter the author: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // remove newline
    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);
    
    library[*count] = newBook; // store the new book
    (*count)++;
    printf("Book added successfully.\n");
}

void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nBooks in the Library:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s | Year: %d\n", 
            library[i].id, library[i].title, library[i].author, library[i].year);
    }
}

void updateBook(Book *library, int count) {
    int id, found = 0;
    printf("Enter the book ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            printf("Updating book ID %d\n", id);
            printf("Enter new title (leave blank to keep original): ");
            getchar(); // clear the newline character
            char newTitle[MAX_TITLE];
            fgets(newTitle, MAX_TITLE, stdin);
            newTitle[strcspn(newTitle, "\n")] = '\0'; // remove newline
            
            if (strlen(newTitle) > 0) {
                strcpy(library[i].title, newTitle);
            }
            
            printf("Enter new author (leave blank to keep original): ");
            char newAuthor[MAX_AUTHOR];
            fgets(newAuthor, MAX_AUTHOR, stdin);
            newAuthor[strcspn(newAuthor, "\n")] = '\0'; // remove newline
            
            if (strlen(newAuthor) > 0) {
                strcpy(library[i].author, newAuthor);
            }
            
            printf("Enter new year of publication (enter 0 to keep original): ");
            int newYear;
            scanf("%d", &newYear);
            
            if (newYear > 0) {
                library[i].year = newYear;
            }
            printf("Book updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book ID not found.\n");
    }
}

void deleteBook(Book *library, int *count) {
    int id, found = 0;
    printf("Enter the book ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Book deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book ID not found.\n");
    }
}

void saveToFile(Book *library, int count) {
    FILE *file = fopen("library.dat", "wb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }
    fwrite(library, sizeof(Book), count, file);
    fclose(file);
    printf("Library data saved to file.\n");
}

void loadFromFile(Book *library, int *count) {
    FILE *file = fopen("library.dat", "rb");
    if (file == NULL) {
        printf("No previous library data found.\n");
        return;
    }
    *count = fread(library, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    printf("Library data loaded from file.\n");
}