//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 64
#define MAX_BOOK_TITLE_LENGTH 128
#define MAX_AUTHOR_NAME_LENGTH 64
#define MAX_BOOK_SIZE_MB 200

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    int pages;
    float size;
} eBook;

int main(int argc, char *argv[]) {
    char fileName[MAX_FILE_NAME_LENGTH];  // variable to hold name of file to open
    char userInput[MAX_LINE_LENGTH];  // variable to hold user input
    eBook currentBook;  // variable to hold data of current book
    FILE *filePointer;  // pointer to file that holds book data

    printf("Welcome to the eBook reader!\n");

    // Prompt user to enter file name
    printf("Enter name of file to open: ");
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = 0;  // remove newline character from file name

    // Open file for reading
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read data of first book from file
    fscanf(filePointer, "%[^,],%[^,],%d,%f\n", currentBook.title, currentBook.author, &currentBook.pages, &currentBook.size);

    while (1) {
        // Print current book data
        printf("\nTitle: %s\nAuthor: %s\nPages: %d\nSize (MB): %.2f\n", currentBook.title, currentBook.author, currentBook.pages, currentBook.size);

        // Prompt user to enter 'n' to go to next book, 'q' to quit, or 's' to search for a book by title
        printf("\nEnter 'n' for next book, 'q' to quit, or 's' to search for a book by title: ");
        fgets(userInput, MAX_LINE_LENGTH, stdin);
        userInput[strcspn(userInput, "\n")] = 0;  // remove newline character from user input

        // Check user input
        if (strcmp(userInput, "n") == 0) {
            // Read data of next book from file
            fscanf(filePointer, "%[^,],%[^,],%d,%f\n", currentBook.title, currentBook.author, &currentBook.pages, &currentBook.size);
        } else if (strcmp(userInput, "q") == 0) {
            // Exit program
            printf("\nGoodbye!\n");
            break;
        } else if (strcmp(userInput, "s") == 0) {
            // Prompt user to enter book title to search for
            printf("\nEnter book title to search for: ");
            fgets(userInput, MAX_LINE_LENGTH, stdin);
            userInput[strcspn(userInput, "\n")] = 0;  // remove newline character from user input

            // Read data of next book from file and check if it matches user input
            while (fscanf(filePointer, "%[^,],%[^,],%d,%f\n", currentBook.title, currentBook.author, &currentBook.pages, &currentBook.size) != EOF) {
                if (strcmp(currentBook.title, userInput) == 0) {
                    printf("\nTitle: %s\nAuthor: %s\nPages: %d\nSize (MB): %.2f\n", currentBook.title, currentBook.author, currentBook.pages, currentBook.size);
                    break;
                }
            }

            // If book was not found, print error message
            if (feof(filePointer)) {
                printf("\nBook not found.\n");
            }

            // Seek to beginning of file to start reading books from beginning again
            fseek(filePointer, 0, SEEK_SET);
            fscanf(filePointer, "%[^,],%[^,],%d,%f\n", currentBook.title, currentBook.author, &currentBook.pages, &currentBook.size);
        } else {
            // Invalid input
            printf("\nInvalid input. Please try again.\n");
        }
    }

    // Close file
    fclose(filePointer);

    return 0;
}