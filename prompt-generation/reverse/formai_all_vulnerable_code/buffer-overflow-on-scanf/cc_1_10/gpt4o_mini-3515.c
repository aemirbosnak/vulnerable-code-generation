//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 255

void printMenu() {
    printf("\nText Processing Program\n");
    printf("1. Read Text from File\n");
    printf("2. Display Text\n");
    printf("3. Count Words\n");
    printf("4. Find Word\n");
    printf("5. Save to New File\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void readFromFile(char lines[MAX_LINES][MAX_LENGTH], int *lineCount) {
    char filename[50];
    printf("Enter the filename to read from: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    *lineCount = 0;
    while (*lineCount < MAX_LINES && fgets(lines[*lineCount], MAX_LENGTH, file)) {
        (*lineCount)++;
    }
    
    fclose(file);
    printf("Text read successfully! %d lines loaded.\n", *lineCount);
}

void displayText(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    printf("\nDisplaying Text:\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }
    printf("\n");
}

int countWords(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    int wordCount = 0;
    for (int i = 0; i < lineCount; i++) {
        char *token = strtok(lines[i], " \n");
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " \n");
        }
    }
    return wordCount;
}

int findWord(char lines[MAX_LINES][MAX_LENGTH], int lineCount, const char *word) {
    for (int i = 0; i < lineCount; i++) {
        if (strstr(lines[i], word) != NULL) {
            printf("Word '%s' found in line %d: %s", word, i + 1, lines[i]);
            return 1; // Word found
        }
    }
    printf("Word '%s' not found in the text.\n", word);
    return 0; // Word not found
}

void saveToFile(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    char filename[50];
    printf("Enter the filename to save to: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s", lines[i]);
    }

    fclose(file);
    printf("Text saved successfully to '%s'.\n", filename);
}

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
    int choice = 0;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readFromFile(lines, &lineCount);
                break;
            case 2:
                displayText(lines, lineCount);
                break;
            case 3:
                {
                    int totalWords = countWords(lines, lineCount);
                    printf("Total Word Count: %d\n", totalWords);
                }
                break;
            case 4:
                {
                    char word[MAX_LENGTH];
                    printf("Enter the word to find: ");
                    scanf("%s", word);
                    findWord(lines, lineCount, word);
                }
                break;
            case 5:
                saveToFile(lines, lineCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}