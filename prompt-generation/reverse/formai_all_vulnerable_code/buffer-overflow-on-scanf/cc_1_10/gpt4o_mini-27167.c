//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void displayMenu() {
    printf("\n======== Welcome to the C Word Count Tool! ========\n");
    printf("Please select an option:\n");
    printf("1. Count words in a file\n");
    printf("2. Count words from user input\n");
    printf("3. Exit\n");
    printf("===================================================\n");
}

int countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return -1;
    }

    int wordCount = 0;
    char word[256];

    while (fscanf(file, "%255s", word) == 1) {
        if (isalpha(word[0])) { // considering a word starts with an alphabet character
            wordCount++;
        }
    }

    fclose(file);
    return wordCount;
}

int countWordsFromInput() {
    printf("Enter your text (Type 'END' on a new line to finish):\n");
    char input[2048];
    int wordCount = 0;

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "END\n") == 0) {
            break;
        }

        char *token = strtok(input, " \n");
        while (token != NULL) {
            if (isalpha(token[0])) {
                wordCount++;
            }
            token = strtok(NULL, " \n");
        }
    }

    return wordCount;
}

void wordCountTool() {
    int choice;
    char filename[256];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                printf("Enter the filename to count words: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline
                int fileWordCount = countWordsInFile(filename);
                if (fileWordCount != -1) {
                    printf("The number of words in the file '%s' is: %d\n", filename, fileWordCount);
                }
                break;
            case 2:
                {
                    int inputWordCount = countWordsFromInput();
                    printf("The number of words you entered is: %d\n", inputWordCount);
                }
                break;
            case 3:
                printf("Thank you for using the Word Count Tool! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    wordCountTool();
    return 0;
}