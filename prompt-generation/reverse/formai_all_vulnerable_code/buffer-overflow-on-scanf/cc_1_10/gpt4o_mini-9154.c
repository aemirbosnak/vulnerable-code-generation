//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    char genre[MAX_TITLE_LENGTH];
} Book;

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter the title of the book: ");
    getchar(); // Clear the newline character from the previous input
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter the author of the book: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);

    printf("Enter the genre of the book: ");
    getchar(); // Clear the newline character
    fgets(newBook.genre, MAX_TITLE_LENGTH, stdin);
    newBook.genre[strcspn(newBook.genre, "\n")] = 0;

    library[*count] = newBook;
    (*count)++;

    printf("Book added successfully!\n");
}

void displayBooks(const Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nLibrary Collection:\n");
    for (int i = 0; i < count; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("Genre: %s\n", library[i].genre);
        printf("--------------\n");
    }
}

void searchBook(const Book library[], int count) {
    if (count == 0) {
        printf("No books in the library to search.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear the newline character
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Book Found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("Genre: %s\n", library[i].genre);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in the library.\n");
    }
}

void removeBook(Book library[], int *count) {
    if (*count == 0) {
        printf("No books in the library to remove.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to remove: ");
    getchar(); // Clear the newline character
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            found = 1;
            // Shifting books to the left to remove
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found in the library.\n");
    }
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Remove Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                removeBook(library, &count);
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}