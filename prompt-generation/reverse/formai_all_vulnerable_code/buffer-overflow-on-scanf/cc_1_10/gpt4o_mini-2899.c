//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOKS 10

typedef struct {
    char title[100];
    char author[100];
    char text[5000];
} Ebook;

Ebook ebooks[MAX_BOOKS];
int ebookCount = 0;

void displayMenu();
void loadEbook(char *filename);
void displayEbook(int index);
void clearScreen();
void closeProgram();

int main() {
    int choice = 0;

    while (choice != 3) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character from input buffer

        switch (choice) {
            case 1:
                if (ebookCount < MAX_BOOKS) {
                    char filename[100];
                    printf("Enter the filename of the ebook: ");
                    fgets(filename, sizeof(filename), stdin);
                    filename[strcspn(filename, "\n")] = 0;  // Remove newline from input
                    loadEbook(filename);
                } else {
                    printf("Maximum number of ebooks loaded.\n");
                }
                break;
            case 2:
                printf("Available ebooks:\n");
                for (int i = 0; i < ebookCount; i++) {
                    printf("%d. %s by %s\n", i + 1, ebooks[i].title, ebooks[i].author);
                }
                if (ebookCount > 0) {
                    int ebookIndex;
                    printf("Select an ebook to read (1-%d): ", ebookCount);
                    scanf("%d", &ebookIndex);
                    getchar();  // Consume newline character from input buffer
                    if (ebookIndex > 0 && ebookIndex <= ebookCount) {
                        displayEbook(ebookIndex - 1);
                    } else {
                        printf("Invalid selection.\n");
                    }
                }
                break;
            case 3:
                closeProgram();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    clearScreen();
    printf("Ebook Reader Menu:\n");
    printf("1. Load a new ebook\n");
    printf("2. Read a loaded ebook\n");
    printf("3. Exit\n");
}

void loadEbook(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Ebook ebook;
    fgets(ebook.title, sizeof(ebook.title), file);
    fgets(ebook.author, sizeof(ebook.author), file);
    ebook.text[0] = '\0';

    while (fgets(ebook.text + strlen(ebook.text), sizeof(ebook.text) - strlen(ebook.text), file) != NULL) {
        // Continue reading until EOF
    }

    fclose(file);
    ebooks[ebookCount++] = ebook;
    printf("Loaded ebook: %s by %s\n", ebook.title, ebook.author);
    getchar();  // Wait for user to press Enter
}

void displayEbook(int index) {
    clearScreen();
    printf("Reading: %s by %s\n\n", ebooks[index].title, ebooks[index].author);
    
    // Display the text in pages
    int lineCount = 0;
    char *line = strtok(ebooks[index].text, "\n");
    while (line != NULL) {
        printf("%s\n", line);
        lineCount++;
        if (lineCount % 25 == 0) {  // Change page after 25 lines
            printf("\n--- Press Enter to continue ---\n");
            getchar();  // Wait for user to press Enter
        }
        line = strtok(NULL, "\n");
    }
    printf("\nEnd of ebook.\n");
    getchar();  // Wait for user to press Enter
}

void clearScreen() {
    // Clear the console screen with ANSI escape code
    printf("\033[H\033[J");
}

void closeProgram() {
    clearScreen();
    printf("Exiting the Ebook Reader. Thank you for reading!\n");
}