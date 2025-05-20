//FormAI DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 100

int main() {
    char word[MAXLENGTH], dictionary[MAXLENGTH];
    FILE *fp;

    // Open the dictionary file
    fp = fopen("dictionary.txt", "r");

    // Check if the file is open
    if (fp == NULL) {
        printf("Error opening dictionary file.");
        exit(1);
    }

    // Get the word to be checked
    printf("Enter the word to be checked: ");
    scanf("%s", word);

    // Convert word to lowercase
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }

    // Check the dictionary file for the word
    while (fscanf(fp, "%s", dictionary) != EOF) {
        // Convert dictionary word to lowercase
        len = strlen(dictionary);
        for (int i = 0; i < len; i++) {
            dictionary[i] = tolower(dictionary[i]);
        }

        // Compare the words
        if (strcmp(dictionary, word) == 0) {
            printf("%s is spelled correctly!\n", word);
            fclose(fp);
            return 0;
        }
    }

    // If the loop reaches here, the word was not found in the dictionary
    printf("%s is misspelled. The correct spelling is:\n", word);

    // Check for possible corrections
    rewind(fp);
    char current_word[MAXLENGTH];
    int min_distance = MAXLENGTH;
    while (fscanf(fp, "%s", current_word) != EOF) {
        int distance = levenshtein_distance(word, current_word);
        if (distance < min_distance) {
            min_distance = distance;
            strcpy(dictionary, current_word);
        }
    }

    // Print the correction
    printf("%s\n", dictionary);

    fclose(fp);
    return 0;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                int deletion = matrix[i-1][j] + 1;
                int insertion = matrix[i][j-1] + 1;
                int substitution = matrix[i-1][j-1] + 1;

                int min = deletion;
                if (insertion < min) {
                    min = insertion;
                }
                if (substitution < min) {
                    min = substitution;
                }

                matrix[i][j] = min;
            }
        }
    }

    return matrix[len1][len2];
}