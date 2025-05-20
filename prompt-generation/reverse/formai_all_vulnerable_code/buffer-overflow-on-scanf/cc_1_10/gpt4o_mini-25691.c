//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 512

void displayMenu() {
    printf("--------------- eBook Reader ---------------\n");
    printf("1. Load a new book\n");
    printf("2. Read current book\n");
    printf("3. Exit\n");
    printf("---------------------------------------------\n");
    printf("Choose an option: ");
}

void readBook(const char *filename) {
    FILE *file;
    char buffer[MAX_BUFFER];
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    printf("\n--- Reading book: %s ---\n", filename);
    
    while (fgets(buffer, MAX_BUFFER, file)) {
        printf("%s", buffer);
    }

    fclose(file);
    printf("\n--- End of book ---\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    char filename[100];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter the filename to load (with .txt extension): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                break;

            case 2:
                if (strlen(filename) == 0) {
                    printf("No book is loaded. Please load a book first.\n");
                } else {
                    readBook(filename);
                }
                break;

            case 3:
                printf("Exiting the eBook Reader. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}