//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOKS 10

typedef enum {
    MODE_NORMAL,
    MODE_NIGHT,
    MODE_SEPIA
} DisplayMode;

void displayMenu() {
    printf("\nE-Book Reader\n");
    printf("1. Open Book\n");
    printf("2. Change Display Mode\n");
    printf("3. Exit\n");
}

void displayContent(FILE *file, DisplayMode mode) {
    char line[MAX_LINE_LENGTH];

    printf("\n--- Book Content ---\n");
    
    while (fgets(line, sizeof(line), file)) {
        switch (mode) {
            case MODE_NORMAL:
                printf("\033[0m%s", line);  // Normal mode (default)
                break;
            case MODE_NIGHT:
                printf("\033[1;37;40m%s\033[0m", line);  // White text on black background
                break;
            case MODE_SEPIA:
                printf("\033[38;5;214m%s\033[0m", line);  // Sepia-like color
                break;
        }
    }

    printf("\n---------------------\n");
}

void changeDisplayMode(DisplayMode *mode) {
    printf("\nSelect Display Mode:\n");
    printf("1. Normal\n");
    printf("2. Night\n");
    printf("3. Sepia\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            *mode = MODE_NORMAL;
            break;
        case 2:
            *mode = MODE_NIGHT;
            break;
        case 3:
            *mode = MODE_SEPIA;
            break;
        default:
            printf("Invalid choice. Keeping current mode.\n");
    }
}

void openBook(FILE **file) {
    char filename[100];
    printf("Enter the book file name (with .txt extension): ");
    scanf("%s", filename);
    
    *file = fopen(filename, "r");
    if (*file == NULL) {
        printf("Could not open file %s. Please check the filename.\n", filename);
    }
}

int main() {
    FILE *file = NULL;
    DisplayMode mode = MODE_NORMAL;

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (file != NULL) fclose(file);
                openBook(&file);
                if (file != NULL) {
                    displayContent(file, mode);
                    fclose(file);
                }
                break;
            case 2:
                changeDisplayMode(&mode);
                printf("Display mode changed successfully.\n");
                break;
            case 3:
                printf("Exiting the e-book reader. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}