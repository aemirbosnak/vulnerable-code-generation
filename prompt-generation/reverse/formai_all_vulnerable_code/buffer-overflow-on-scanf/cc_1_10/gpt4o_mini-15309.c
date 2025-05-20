//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 4096

typedef struct {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
} Book;

void displayMenu() {
    printf("\n---- E-Book Reader ----\n");
    printf("1. Add Book\n");
    printf("2. View Book\n");
    printf("3. List All Books\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
    printf("Enter your choice: ");
}

void addBook(Book* library, int* bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    getchar(); // Clear newline character
    fgets(library[*bookCount].title, MAX_TITLE_LEN, stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = '\0'; // Remove newline
    
    printf("Enter book content (max %d characters):\n", MAX_CONTENT_LEN);
    fgets(library[*bookCount].content, MAX_CONTENT_LEN, stdin);
    library[*bookCount].content[strcspn(library[*bookCount].content, "\n")] = '\0'; // Remove newline
    
    (*bookCount)++;
    printf("Book added successfully!\n");
}

void viewBook(Book* library, int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library!\n");
        return;
    }

    printf("Enter the book number to view (1-%d): ", bookCount);
    int bookNumber;
    scanf("%d", &bookNumber);
    
    if (bookNumber < 1 || bookNumber > bookCount) {
        printf("Invalid book number!\n");
        return;
    }

    printf("\n------ %s ------\n", library[bookNumber - 1].title);
    printf("%s\n", library[bookNumber - 1].content);
    printf("------------------\n");
}

void listBooks(Book* library, int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library!\n");
        return;
    }

    printf("\n---- List of Books ----\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
    printf("-----------------------\n");
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBook(library, bookCount);
                break;
            case 3:
                listBooks(library, bookCount);
                break;
            case 4:
                printf("Exiting the E-Book Reader. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}