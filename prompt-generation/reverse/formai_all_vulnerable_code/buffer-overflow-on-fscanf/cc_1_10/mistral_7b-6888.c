//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

// Function to capitalize the first letter of a string
void capitalizeFirstLetter(char *str) {
    if (strlen(str) > 0) {
        *str = toupper(*str);
    }
}

int main() {
    FILE *file;
    char loveLetter[MAX_WORDS][WORD_LENGTH];
    char temp[WORD_LENGTH];
    int wordCount = 0;
    int i, j;

    // Read the file "loveLetter.txt"
    file = fopen("loveLetter.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file 'loveLetter.txt'\n");
        return 1;
    }

    // Read words from the file and store them in the array
    while (fscanf(file, "%s%s", loveLetter[wordCount], temp) != EOF) {
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many words in the letter.\n");
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    // Capitalize the first letter of each word in the array
    for (i = 0; i < wordCount; i++) {
        capitalizeFirstLetter(loveLetter[i]);
        for (j = 0; j < strlen(loveLetter[i]); j++) {
            if (isalpha(loveLetter[i][j]) && j > 0 && (loveLetter[i][j - 1] == ' ')) {
                capitalizeFirstLetter(&loveLetter[i][j]);
            }
        }
    }

    // Replace the word "dear" with "Amelia"
    for (i = 0; i < wordCount; i++) {
        if (strstr(loveLetter[i], "dear") != NULL) {
            strcpy(temp, "Amelia");
            strcpy(loveLetter[i], strstr(loveLetter[i], "dear") - 1);
            strcat(loveLetter[i], temp);
        }
    }

    // Print the modified content of the array to the console
    for (i = 0; i < wordCount; i++) {
        printf("%s ", loveLetter[i]);
    }

    printf("\n");

    return 0;
}