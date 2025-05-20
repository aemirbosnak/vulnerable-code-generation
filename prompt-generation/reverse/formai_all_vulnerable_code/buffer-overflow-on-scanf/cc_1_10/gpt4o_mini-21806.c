//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display a simple menu
void displayMenu() {
    printf("\n--- Word Count Tool ---\n");
    printf("1. Count Words in File\n");
    printf("2. Count Words from Standard Input\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to count words in the provided filename
int countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return -1;
    }
    
    char ch;
    int inWord = 0, wordCount = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            // Not in word, reset inWord flag
            inWord = 0;
        } else {
            // In word, if we were not already in a word
            if (inWord == 0) {
                inWord = 1; // Mark as in a word
                wordCount++; // Increment word count
            }
        }
    }
    fclose(file);
    return wordCount;
}

// Function to count words from standard input
int countWordsFromInput() {
    char buffer[1024], *token;
    int wordCount = 0;

    printf("Enter text (Ctrl+D to end):\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        token = strtok(buffer, " \n\t");
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " \n\t");
        }
    }
    return wordCount;
}

// Main function
int main() {
    int choice;
    char filename[256];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clean newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline

                int wordCountFile = countWordsInFile(filename);
                if (wordCountFile != -1) {
                    printf("Total words in file '%s': %d\n", filename, wordCountFile);
                }
                break;
                
            case 2:
                {
                    int wordCountInput = countWordsFromInput();
                    printf("Total words entered: %d\n", wordCountInput);
                }
                break;

            case 3:
                printf("Exiting the Word Count Tool. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
    return 0;
}