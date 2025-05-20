//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 1000

// Function prototypes
void getInput(char lines[MAX_LINES][MAX_LENGTH], int *lineCount);
void displayLines(char lines[MAX_LINES][MAX_LENGTH], int lineCount);
void toUpperCase(char lines[MAX_LINES][MAX_LENGTH], int lineCount);
void toLowerCase(char lines[MAX_LINES][MAX_LENGTH], int lineCount);
void sortLines(char lines[MAX_LINES][MAX_LENGTH], int lineCount);
void searchSubstring(char lines[MAX_LINES][MAX_LENGTH], int lineCount);
void clearBuffer();

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
    int choice;

    while (1) {
        printf("\n=== String Manipulation Program ===\n");
        printf("1. Get Input\n");
        printf("2. Display Lines\n");
        printf("3. Convert to Upper Case\n");
        printf("4. Convert to Lower Case\n");
        printf("5. Sort Lines\n");
        printf("6. Search for Substring\n");
        printf("7. Exit\n");
        printf("Select an option (1-7): ");
        
        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input. Please select a valid option.\n");
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                getInput(lines, &lineCount);
                break;
            case 2:
                displayLines(lines, lineCount);
                break;
            case 3:
                toUpperCase(lines, lineCount);
                break;
            case 4:
                toLowerCase(lines, lineCount);
                break;
            case 5:
                sortLines(lines, lineCount);
                break;
            case 6:
                searchSubstring(lines, lineCount);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
    return 0;
}

void getInput(char lines[MAX_LINES][MAX_LENGTH], int *lineCount) {
    printf("Enter up to %d lines of text (blank line to stop):\n", MAX_LINES);
    for (int i = 0; i < MAX_LINES; i++) {
        printf("Line %d: ", i + 1);
        if (fgets(lines[i], MAX_LENGTH, stdin) == NULL || 
            (strlen(lines[i]) == 1 && lines[i][0] == '\n')) {
            break;  // stop on blank line
        }
        (*lineCount)++;
    }
}

void displayLines(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    printf("\nDisplaying %d lines of input:\n", lineCount);
    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }
}

void toUpperCase(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; lines[i][j]; j++) {
            lines[i][j] = toupper((unsigned char)lines[i][j]);
        }
    }
    printf("All lines converted to upper case.\n");
}

void toLowerCase(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; lines[i][j]; j++) {
            lines[i][j] = tolower((unsigned char)lines[i][j]);
        }
    }
    printf("All lines converted to lower case.\n");
}

void sortLines(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    for (int i = 0; i < lineCount - 1; i++) {
        for (int j = i + 1; j < lineCount; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }
    printf("Lines sorted in alphabetical order.\n");
}

void searchSubstring(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    char substring[MAX_LENGTH];
    printf("Enter the substring to search: ");
    fgets(substring, MAX_LENGTH, stdin);
    substring[strcspn(substring, "\n")] = 0;  // Remove newline

    printf("Searching for substring '%s'...\n", substring);
    int found = 0;
    for (int i = 0; i < lineCount; i++) {
        if (strstr(lines[i], substring) != NULL) {
            printf("Found in line %d: %s", i + 1, lines[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Substring not found in any line.\n");
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}