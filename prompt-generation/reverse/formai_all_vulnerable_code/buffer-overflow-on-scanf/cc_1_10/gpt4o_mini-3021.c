//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKS 10
#define MAX_FILENAME_LENGTH 50

void displayMenu();
void readBook(const char *filename);
void searchInBook(const char *filename, const char *keyword);
void clearScreen();

int main() {
    printf("*****************************************\n");
    printf("      WELCOME TO YOUR eBOOK READER!     \n");
    printf("*****************************************\n\n");

    char option;
    char filename[MAX_FILENAME_LENGTH];
    char keyword[MAX_LINE_LENGTH];

    while (1) {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf(" %c", &option);
        getchar(); // To consume the newline character

        switch (option) {
            case '1':
                printf("Enter the filename to read (max %d characters): ", MAX_FILENAME_LENGTH - 1);
                fgets(filename, MAX_FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                readBook(filename);
                break;

            case '2':
                printf("Enter the filename to search in (max %d characters): ", MAX_FILENAME_LENGTH - 1);
                fgets(filename, MAX_FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;

                printf("Enter the keyword to search for (max %d characters): ", MAX_LINE_LENGTH - 1);
                fgets(keyword, MAX_LINE_LENGTH, stdin);
                keyword[strcspn(keyword, "\n")] = 0;

                searchInBook(filename, keyword);
                break;

            case '3':
                printf("Exiting the eBook Reader. Happy Reading! 📖\n");
                exit(0);

            case '4':
                clearScreen();
                break;

            case '5':
                printf("Invalid option! Please select a valid one.\n");
                break;

            default:
                printf("Invalid option! Please select a valid one.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- eBook Reader Menu ---\n");
    printf("1. Read a Book\n");
    printf("2. Search in a Book\n");
    printf("3. Exit\n");
    printf("4. Clear Screen\n");
    printf("5. Help\n");
}

void readBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    printf("\n--- Reading the book: %s ---\n", filename);
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\n--- End of Book ---\n");
}

void searchInBook(const char *filename, const char *keyword) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    printf("\n--- Searching for '%s' in %s ---\n", keyword, filename);
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (strstr(line, keyword) != NULL) {
            printf("Found on line %d: %s", lineNumber, line);
            found = 1;
        }
    }
    if (!found) {
        printf("Keyword '%s' not found in %s.\n", keyword, filename);
    }
    fclose(file);
    printf("--- Search Completed ---\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
    printf("Screen cleared! Ready for the next adventure! 🚀\n");
}