//FormAI DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_SIZE 1000 // Maximum number of characters in a word
#define MAX_CORRECTIONS 5 // Maximum number of possible corrections

// Function to check if two strings are equal
int strEqual(char* str1, char* str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0') break;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 1;
    else return 0;
}

// Function to remove non-alphabetic characters from a string
void removeNonAlphabetic(char* str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            str[j] = tolower(str[i]);
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

// Function to make corrections to a misspelled word
void makeCorrections(char* word, char* dict[], int dSize, char* corrections[]) {
    int cCount = 0;
    for (int i = 0; i < dSize; i++) {
        int dist = 0;
        int wLen = strlen(word);
        int dLen = strlen(dict[i]);
        if (wLen != dLen) continue;
        for (int j = 0; j < wLen; j++) {
            if (word[j] != dict[i][j]) dist++;
        }
        if (dist == 1) {
            corrections[cCount] = dict[i];
            cCount++;
            if (cCount == MAX_CORRECTIONS) break;
        }
    }
}

int main() {
    // Open dictionary file
    FILE *fp = fopen("./dictionary.txt", "r");
    if (fp == NULL) {
        printf("Dictionary file not found");
        return 0;
    }

    // Read words from dictionary
    char* dictionary[MAX_WORD_SIZE];
    int dSize = 0;
    while (!feof(fp)) {
        char word[MAX_WORD_SIZE];
        fscanf(fp, "%s", word);
        removeNonAlphabetic(word);
        if (strlen(word) > 0) {
            dictionary[dSize] = strdup(word);
            dSize++;
        }
    }
    fclose(fp);

    // Get input from user
    char input[MAX_WORD_SIZE];
    printf("Enter text: ");
    scanf("%[^\n]%*c", input);

    // Check spelling of text
    char* words[MAX_WORD_SIZE];
    int wCount = 0;
    char* corrections[MAX_CORRECTIONS];
    char* token = strtok(input, " ");
    while (token != NULL) {
        removeNonAlphabetic(token);
        if (strlen(token) > 0) {
            int found = 0;
            for (int i = 0; i < dSize; i++) {
                if (strEqual(token, dictionary[i])) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                makeCorrections(token, dictionary, dSize, corrections);
                printf("'%s' is misspelled. Suggestions: ", token);
                for (int i = 0; i < MAX_CORRECTIONS; i++) {
                    if (corrections[i] != NULL) {
                        printf("%s ", corrections[i]);
                    }
                }
                printf("\n");
            }
            words[wCount] = strdup(token);
            wCount++;
        }
        token = strtok(NULL, " ");
    }

    // Print correct words
    printf("Corrected text: ");
    for (int i = 0; i < wCount; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}