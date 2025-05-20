//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} eBook;

typedef struct {
    eBook ebooks[MAX_EBOOKS];
    int count;
} eBookLibrary;

void loadEBooks(eBookLibrary *library, const char *file) {
    FILE *fp = fopen(file, "r");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    while (library->count < MAX_EBOOKS && fscanf(fp, " %[^\n] %[^\n]", library->ebooks[library->count].title, library->ebooks[library->count].content) == 2) {
        library->count++;
    }
    fclose(fp);
}

void displayEBooks(eBookLibrary *library) {
    printf("Available eBooks:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s\n", i + 1, library->ebooks[i].title);
    }
}

void readEBook(eBook *book) {
    printf("\n--- Reading: %s ---\n", book->title);
    printf("%s\n", book->content);
}

int main() {
    eBookLibrary library = {.count = 0};
    loadEBooks(&library, "ebooks.txt");

    if (library.count == 0) {
        printf("No eBooks available to read.\n");
        return 0;
    }

    int choice;
    while (1) {
        displayEBooks(&library);
        printf("Enter the number of the eBook you want to read (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > library.count) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        readEBook(&library.ebooks[choice - 1]);
    }

    printf("Exiting the eBook reader. Goodbye!\n");
    return 0;
}