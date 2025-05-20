//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    char filename[MAX_TITLE_LENGTH];
} Book;

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    getchar();  // Clear newline from buffer
    fgets(library[*count].title, MAX_TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0;  // Remove newline

    printf("Enter the author of the book: ");
    fgets(library[*count].author, MAX_TITLE_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0;  // Remove newline

    printf("Enter the filename of the book: ");
    fgets(library[*count].filename, MAX_TITLE_LENGTH, stdin);
    library[*count].filename[strcspn(library[*count].filename, "\n")] = 0;  // Remove newline

    (*count)++;
    printf("Book added successfully!\n");
}

void listBooks(Book *library, int count) {
    printf("\n** List of Books **\n");
    for (int i = 0; i < count; i++) {
        printf("%d. \"%s\" by %s (File: %s)\n", i + 1, library[i].title, library[i].author, library[i].filename);
    }
    printf("\n");
}

void readBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Couldn't open the file %s!\n", filename);
        return;
    }

    printf("\n** Reading Book: %s **\n", filename);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
    printf("\nFinished reading %s!\n", filename);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    printf("📚 Welcome to the Surprising C Ebook Reader! 📖\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a new book\n");
        printf("2. List all books\n");
        printf("3. Read a book\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        // Ensure valid input
        while (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input! Please enter a number (1-4): ");
        }

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;

            case 2:
                if (count == 0) {
                    printf("No books available in the library.\n");
                } else {
                    listBooks(library, count);
                }
                break;

            case 3: {
                if (count == 0) {
                    printf("No books available to read.\n");
                } else {
                    listBooks(library, count);
                    int bookNumber;
                    printf("Enter the number of the book you wish to read: ");
                    
                    // Ensure valid input
                    while (scanf("%d", &bookNumber) != 1 || bookNumber < 1 || bookNumber > count) {
                        clearBuffer();
                        printf("Invalid selection! Please enter a valid book number: ");
                    }
                    readBook(library[bookNumber - 1].filename);
                }
                break;
            }

            case 4:
                printf("Exiting the ebook reader. Goodbye! 👋\n");
                break;

            default:
                printf("Surprising choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}