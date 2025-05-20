//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 10000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook(const char* title, const char* content) {
    if (bookCount < MAX_BOOKS) {
        strncpy(library[bookCount].title, title, MAX_TITLE_LENGTH - 1);
        library[bookCount].title[MAX_TITLE_LENGTH - 1] = '\0';
        strncpy(library[bookCount].content, content, MAX_CONTENT_LENGTH - 1);
        library[bookCount].content[MAX_CONTENT_LENGTH - 1] = '\0';
        bookCount++;
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void displayBooks() {
    printf("Your Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("[%d] %s\n", i + 1, library[i].title);
    }
    printf("\n");
}

void readBook(int index) {
    if (index >= 0 && index < bookCount) {
        printf("\nReading '%s':\n\n", library[index].title);
        printf("%s\n", library[index].content);
    } else {
        printf("Invalid book index!\n");
    }
}

void menu() {
    printf("Welcome to the C Ebook Reader!\n");
    printf("1. Add a new book\n");
    printf("2. Display all books\n");
    printf("3. Read a book\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    
    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer
        
        switch (choice) {
            case 1:
                printf("Enter the book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove the newline character
                
                printf("Enter the book content:\n");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = 0; // Remove the newline character
                
                addBook(title, content);
                printf("Book added successfully!\n");
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                printf("Enter the book index to read: ");
                int index;
                scanf("%d", &index);
                readBook(index - 1); // Adjust for 0-based index
                break;

            case 4:
                printf("Exiting the program. Happy reading!\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}