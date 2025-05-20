//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLUES 10
#define MAX_LENGTH 256

void convertToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int countOccurrences(const char *str, const char *word) {
    int count = 0;
    const char *temp = str;
    while ((temp = strstr(temp, word)) != NULL) {
        count++;
        temp++;
    }
    return count;
}

void displayClues(char clues[MAX_CLUES][MAX_LENGTH], int clueCount) {
    printf("\nList of Clues:\n");
    for (int i = 0; i < clueCount; i++) {
        printf("%d. %s\n", i + 1, clues[i]);
    }
}

void analyzeClue(char *clue) {
    int length = strlen(clue);
    printf("\nAnalyzing Clue: \"%s\"\n", clue);
    printf("Length: %d characters\n", length);
    
    char word[MAX_LENGTH];
    printf("Enter a keyword to search for: ");
    scanf("%s", word);
    
    convertToLower(clue);
    convertToLower(word);
    
    int occurrences = countOccurrences(clue, word);
    printf("The keyword \"%s\" occurs %d time(s) in the clue.\n", word, occurrences);
}

int main() {
    char clues[MAX_CLUES][MAX_LENGTH];
    int clueCount = 0;

    printf("Welcome, dear user, to the Sherlock Holmes Clue Analysis System!\n");
    
    while (1) {
        printf("\nWould you like to add a new clue? (y/n): ");
        char response;
        scanf(" %c", &response);

        if (response != 'y') {
            break;
        }

        if (clueCount >= MAX_CLUES) {
            printf("Maximum number of clues reached.\n");
            break;
        }

        printf("Enter your clue (max %d characters): ", MAX_LENGTH - 1);
        scanf(" %[^\n]", clues[clueCount]);
        clueCount++;
    }

    displayClues(clues, clueCount);

    for (int i = 0; i < clueCount; i++) {
        analyzeClue(clues[i]);
    }

    printf("\nAh, another mystery solved through the power of deduction! Farewell!\n");
    return 0;
}