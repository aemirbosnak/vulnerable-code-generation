//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
} Book;

void addBook(Book library[], int *bookCount);
void viewBooks(Book library[], int bookCount);
void deleteBook(Book library[], int *bookCount);
void displayMenu();

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    printf("🎉 Welcome to the Happy Library Management System! 📚\n");
    
    do {
        displayMenu();
        printf("Please choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                deleteBook(library, &bookCount);
                break;
            case 4:
                printf("🚪 Exiting the Happy Library Management System. Have a great day! 🌞\n");
                break;
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("🎈 Menu 🎈\n");
    printf("1. Add a Book\n");
    printf("2. View Available Books\n");
    printf("3. Delete a Book\n");
    printf("4. Exit\n");
}

void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("😢 Sorry, the library is full! Cannot add more books.\n");
        return;
    }
    
    printf("📖 Enter the title of the book: ");
    getchar(); // clear the newline from the previous input
    fgets(library[*bookCount].title, MAX_TITLE_LEN, stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = '\0'; // remove newline
    (*bookCount)++;
    printf("✅ Book '%s' has been added to the library! 🎊\n", library[*bookCount - 1].title);
}

void viewBooks(Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("😟 No books available in the library. Add some books first!\n");
        return;
    }
    
    printf("📚 Available Books in the Happy Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void deleteBook(Book library[], int *bookCount) {
    if (*bookCount == 0) {
        printf("😟 No books to delete! Add some books first!\n");
        return;
    }

    viewBooks(library, *bookCount);
    int indexToDelete;
    printf("❓ Enter the number of the book to delete: ");
    scanf("%d", &indexToDelete);
    
    if (indexToDelete < 1 || indexToDelete > *bookCount) {
        printf("❌ Invalid number! Please try again. \n");
        return;
    }

    for (int i = indexToDelete - 1; i < *bookCount - 1; i++) {
        library[i] = library[i + 1]; // shift books left
    }
    (*bookCount)--;
    printf("🎉 Book has been deleted successfully! 📚\n");
}