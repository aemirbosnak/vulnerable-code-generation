//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char filePath[MAX_LINE_LENGTH];
} eBook;

void displayMenu() {
    printf("=== eBook Reader ===\n");
    printf("1. Add eBook\n");
    printf("2. List eBooks\n");
    printf("3. Read eBook\n");
    printf("4. Exit\n");
    printf("====================\n");
    printf("Select an option: ");
}

void addEBook(eBook **library, int *count) {
    eBook newBook;
    printf("Enter eBook title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    strtok(newBook.title, "\n"); // Remove newline character

    printf("Enter eBook author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    strtok(newBook.author, "\n");

    printf("Enter eBook file path: ");
    fgets(newBook.filePath, sizeof(newBook.filePath), stdin);
    strtok(newBook.filePath, "\n");

    *library = realloc(*library, sizeof(eBook) * (*count + 1));
    (*library)[*count] = newBook;
    (*count)++;
    printf("eBook added successfully!\n");
}

void listEBooks(eBook *library, int count) {
    if (count == 0) {
        printf("No eBooks available.\n");
        return;
    }

    printf("=== List of eBooks ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
    }
    printf("=======================\n");
}

void readEBook(eBook *library, int count) {
    int choice;
    printf("Enter the number of the eBook to read: ");
    scanf("%d", &choice);
    getchar(); // Clear newline character from input buffer

    if (choice < 1 || choice > count) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    choice--; // Adjust for zero-based index
    FILE *file = fopen(library[choice].filePath, "r");
    
    if (file == NULL) {
        printf("Error opening file: %s\n", library[choice].filePath);
        return;
    }

    printf("=== Reading %s by %s ===\n", library[choice].title, library[choice].author);
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    printf("=======================\n");
}

int main() {
    eBook *library = NULL;
    int ebookCount = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline character from input buffer

        switch (option) {
            case 1:
                addEBook(&library, &ebookCount);
                break;
            case 2:
                listEBooks(library, ebookCount);
                break;
            case 3:
                readEBook(library, ebookCount);
                break;
            case 4:
                free(library);
                printf("Exiting eBook Reader. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}