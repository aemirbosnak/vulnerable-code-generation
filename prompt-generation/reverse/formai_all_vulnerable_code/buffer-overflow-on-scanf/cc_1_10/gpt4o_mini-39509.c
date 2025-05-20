//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1024

// Structure to hold book information
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

// Function to add a new book to the library
void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Alas! The library is full, no more books can be added!\n");
        return;
    }
    printf("Enter the title of the book (max %d characters): ", MAX_TITLE_LENGTH - 1);
    getchar(); // Clear the newline from previous input
    fgets(library[*count].title, MAX_TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove trailing newline
    printf("Enter the content of the book (max %d characters): ", MAX_CONTENT_LENGTH - 1);
    fgets(library[*count].content, MAX_CONTENT_LENGTH, stdin);
    library[*count].content[strcspn(library[*count].content, "\n")] = 0; // Remove trailing newline
    (*count)++;
    printf("The tome has been inscribed!\n");
}

// Function to display all books in the library
void displayBooks(Book *library, int count) {
    if (count == 0) {
        printf("The library is vacant, no tomes to be found.\n");
        return;
    }
    printf("The library contains the following tomes:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

// Function to read a book's content
void readBook(Book *library, int count) {
    int choice;
    printf("Enter the number of the tome you wish to read (1-%d): ", count);
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("Alas! That is not a valid choice.\n");
        return;
    }
    printf("\n--- The content of '%s' ---\n", library[choice - 1].title);
    printf("%s\n", library[choice - 1].content);
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n--- The Grand Library ---\n");
        printf("1. Add a new tome\n");
        printf("2. View all tomes\n");
        printf("3. Read a tome\n");
        printf("4. Quit\n");
        printf("Select your quest: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                readBook(library, count);
                break;
            case 4:
                printf("Farewell, brave seeker of knowledge. Till we meet again!\n");
                break;
            default:
                printf("I cannot comprehend your choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}