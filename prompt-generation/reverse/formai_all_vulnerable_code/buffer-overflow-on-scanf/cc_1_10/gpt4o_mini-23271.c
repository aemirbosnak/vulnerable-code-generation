//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu();
void addBook(Book *library, int *totalBooks);
void readBook(const Book *library, int totalBooks);
void listBooks(const Book *library, int totalBooks);

int main() {
    Book library[MAX_BOOKS];
    int totalBooks = 0;
    int choice;

    printf("Welcome to the Grand Ebook Reader of the Medieval Kingdom!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                addBook(library, &totalBooks);
                break;
            case 2:
                listBooks(library, totalBooks);
                break;
            case 3:
                readBook(library, totalBooks);
                break;
            case 4:
                printf("Farewell, noble reader! Until we meet again!\n");
                break;
            default:
                printf("Alas! An invalid choice. Please, try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Add a New Book\n");
    printf("2. List All Books\n");
    printf("3. Read a Book\n");
    printf("4. Exit\n");
}

void addBook(Book *library, int *totalBooks) {
    if (*totalBooks >= MAX_BOOKS) {
        printf("The library is full! Cannot add more tomes.\n");
        return;
    }

    printf("Enter the title of the tome: ");
    fgets(library[*totalBooks].title, MAX_TITLE_LENGTH, stdin);

    printf("Enlighten us with the content of the tome:\n");
    printf("(Keep it brief, limited to %d characters)\n", MAX_CONTENT_LENGTH);
    fgets(library[*totalBooks].content, MAX_CONTENT_LENGTH, stdin);

    (*totalBooks)++;
    printf("The tome \"%s\" has been added to the library!\n", library[*totalBooks - 1].title);
}

void listBooks(const Book *library, int totalBooks) {
    if (totalBooks == 0) {
        printf("The library is empty! Time to acquire new tomes!\n");
        return;
    }

    printf("\n--- List of Tomes ---\n");
    for (int i = 0; i < totalBooks; i++) {
        printf("%d. %s", i + 1, library[i].title);
    }
}

void readBook(const Book *library, int totalBooks) {
    if (totalBooks == 0) {
        printf("No tomes available to read. Consider adding some first.\n");
        return;
    }

    int choice;
    printf("Which tome wouldst thou like to read? (1-%d): ", totalBooks);
    scanf("%d", &choice);
    getchar(); // Clear input buffer

    if (choice < 1 || choice > totalBooks) {
        printf("Such a choice is most unwise! Please select a valid tome.\n");
        return;
    }

    choice--; // Adjust index to 0-based
    printf("\n--- Reading \"%s\" ---\n", library[choice].title);
    printf("%s\n", library[choice].content);
    printf("--- End of Tome ---\n");
}