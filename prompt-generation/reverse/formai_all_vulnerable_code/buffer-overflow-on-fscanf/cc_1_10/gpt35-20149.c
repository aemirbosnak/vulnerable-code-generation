//FormAI DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books the program can handle
#define MAX_BOOKS 10

// Structure to hold book information
typedef struct {
    int id;
    char title[50];
    char author[50];
    char filename[50];
} Book;

// Function to display the main menu
void displayMenu() {
    printf("\n\n EBOOK READER\n\n");
    printf("1. View Library\n");
    printf("2. Add Book\n");
    printf("3. Remove Book\n");
    printf("4. Read Book\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to load the library of books from a file
int loadLibrary(Book library[]) {
    FILE *fp;
    int count = 0;

    fp = fopen("library.txt", "r");
    if (fp != NULL) {
        while (!feof(fp) && count < MAX_BOOKS) {
            fscanf(fp, "%d %[^\n] %[^\n] %[^\n]\n", &library[count].id, library[count].title, library[count].author, library[count].filename);
            count++;
        }
        fclose(fp);
    }

    return count;
}

// Function to save the library of books to a file
void saveLibrary(Book library[], int count) {
    FILE *fp;
    int i;

    fp = fopen("library.txt", "w");
    if (fp != NULL) {
        for (i = 0; i < count; i++) {
            fprintf(fp, "%d %s %s %s\n", library[i].id, library[i].title, library[i].author, library[i].filename);
        }
        fclose(fp);
    }
}

// Function to view the library of books
void viewLibrary(Book library[], int count) {
    int i;

    printf("\n\n EBOOK LIBRARY\n\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s - %s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to add a book to the library
void addBook(Book library[], int *count) {
    int id;
    char title[50];
    char author[50];
    char filename[50];

    printf("\n\n ADD BOOK\n\n");
    printf("Enter the title: ");
    scanf(" %[^\n]", title);
    printf("Enter the author: ");
    scanf(" %[^\n]", author);
    printf("Enter the filename: ");
    scanf(" %[^\n]", filename);

    id = *count + 1;

    library[*count].id = id;
    strcpy(library[*count].title, title);
    strcpy(library[*count].author, author);
    strcpy(library[*count].filename, filename);

    *count += 1;

    printf("\nBook added successfully!\n");
}

// Function to remove a book from the library
void removeBook(Book library[], int *count) {
    int i, id;

    printf("\n\n REMOVE BOOK\n\n");
    printf("Enter the ID of the book to remove: ");
    scanf(" %d", &id);

    for (i = 0; i < *count; i++) {
        if (library[i].id == id) {
            if (i != *count - 1) {
                library[i] = library[*count - 1];
            }
            *count -= 1;
            printf("\nBook removed successfully!\n");
            return;
        }
    }

    printf("\nBook not found.\n");
}

// Function to read a book
void readBook(Book library[], int count) {
    int i, id;
    char cmd[50];

    printf("\n\n READ BOOK\n\n");
    printf("Enter the ID of the book to read: ");
    scanf(" %d", &id);

    for (i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nREADING: %s - %s\n", library[i].title, library[i].author);
            system(library[i].filename);
            return;
        }
    }

    printf("\nBook not found.\n");
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    // Load the library from a file
    count = loadLibrary(library);

    // Display the main menu and handle user input
    do {
        displayMenu();
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                viewLibrary(library, count);
                break;
            case 2:
                addBook(library, &count);
                break;
            case 3:
                removeBook(library, &count);
                break;
            case 4:
                readBook(library, count);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

        // Save the library to a file
        saveLibrary(library, count);

    } while (choice != 5);

    return 0;
}