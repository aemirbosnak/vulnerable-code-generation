//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_PATH_LENGTH 255
#define MAX_LINE_LENGTH 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char path[MAX_PATH_LENGTH];
} Ebook;

void printEbookInfo(Ebook ebook) {
    printf("\n--- Ebook Information ---\n");
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Path: %s\n", ebook.path);
    printf("-------------------------\n");
}

void readEbook(Ebook ebook) {
    FILE *file = fopen(ebook.path, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", ebook.path);
        return;
    }

    printf("\n--- Reading Ebook ---\n");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\n--- End of Ebook ---\n");
}

void createEbook(Ebook *ebook) {
    printf("Enter the title of the ebook: ");
    fgets(ebook->title, MAX_TITLE_LENGTH, stdin);
    ebook->title[strcspn(ebook->title, "\n")] = 0;  // Remove newline character

    printf("Enter the author of the ebook: ");
    fgets(ebook->author, MAX_AUTHOR_LENGTH, stdin);
    ebook->author[strcspn(ebook->author, "\n")] = 0;  // Remove newline character

    printf("Enter the path to the ebook file: ");
    fgets(ebook->path, MAX_PATH_LENGTH, stdin);
    ebook->path[strcspn(ebook->path, "\n")] = 0;  // Remove newline character
}

void menu() {
    printf("1. Create new Ebook\n");
    printf("2. Read existing Ebook\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Ebook ebook;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar();  // Consume the newline character after scanf

        switch (choice) {
            case 1:
                createEbook(&ebook);
                printEbookInfo(ebook);
                break;
            case 2:
                if (strlen(ebook.path) == 0) {
                    printf("No ebook available to read. Please create one first.\n");
                } else {
                    readEbook(ebook);
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}