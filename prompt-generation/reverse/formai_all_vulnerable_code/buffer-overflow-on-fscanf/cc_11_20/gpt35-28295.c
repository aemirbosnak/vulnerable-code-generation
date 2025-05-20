//FormAI DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a letter
int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

// Function to check if a character is a space
int isSpace(char c) {
    if (c == ' ')
        return 1;
    else
        return 0;
}

// Function to check if a character is a punctuation mark
int isPunct(char c) {
    if ((c == '!') || (c == '.') || (c == '?'))
        return 1;
    else
        return 0;
}

int main() {
    char word[100];
    char dict[100][100];
    int i, j, k, m, n;
    int wordlen, dictlen;
    int count = 0;
    int found = 0;
    int spelling_error = 0;

    // Open the dictionary file and read all the words into an array
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary\n");
        exit(1);
    }
    while (fscanf(fp, "%s", dict[count]) != EOF) {
        count++;
    }
    fclose(fp);

    // Get the word to be spell checked from the user
    printf("Enter a word to be spell checked: ");
    scanf("%s", word);
    wordlen = strlen(word);

    // Convert all the letters to lowercase
    for (i = 0; i < wordlen; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + ('a' - 'A');
        }
    }

    // Check the word against the dictionary
    for (i = 0; i < count; i++) {
        dictlen = strlen(dict[i]);
        if (wordlen == dictlen) {
            found = 1;
            for (j = 0; j < wordlen; j++) {
                if (word[j] != dict[i][j]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                printf("The word '%s' is spelled correctly!\n", word);
                return 0;
            }
        }
    }

    // If the word is not in the dictionary, check for spelling errors
    if (!found) {
        printf("The word '%s' is not in the dictionary.\n", word);

        // Check for spelling errors due to extra characters
        for (i = 0; i < count; i++) {
            dictlen = strlen(dict[i]);
            if (wordlen == dictlen + 1) {
                j = 0;
                while (j < wordlen && dict[i][j] == word[j]) {
                    j++;
                }
                if (j == dictlen && isPunct(word[j])) {
                    printf("Did you mean '%s'?\n", dict[i]);
                    spelling_error = 1;
                } else if (j == dictlen && isSpace(word[j])) {
                    k = j + 1;
                    while (k < wordlen && isSpace(word[k])) {
                        k++;
                    }
                    if (k == wordlen && isPunct(word[j - 1])) {
                        printf("Did you mean '%s'?\n", dict[i]);
                        spelling_error = 1;
                    }
                }
            }
        }

        // Check for spelling errors due to missing characters
        for (i = 0; i < count; i++) {
            dictlen = strlen(dict[i]);
            if (wordlen + 1 == dictlen) {
                j = 0;
                while (j < dictlen && dict[i][j] == word[j]) {
                    j++;
                }
                if (j == wordlen && isPunct(dict[i][j])) {
                    printf("Did you mean '%s'?\n", dict[i]);
                    spelling_error = 1;
                } else if (j == wordlen && isSpace(dict[i][j])) {
                    k = j + 1;
                    while (k < dictlen && isSpace(dict[i][k])) {
                        k++;
                    }
                    if (k == dictlen && isPunct(dict[i][j - 1])) {
                        printf("Did you mean '%s'?\n", dict[i]);
                        spelling_error = 1;
                    }
                }
            }
        }

        // Check for spelling errors due to transposed characters
        for (i = 0; i < count; i++) {
            dictlen = strlen(dict[i]);
            if (wordlen == dictlen) {
                for (j = 0; j < wordlen - 1; j++) {
                    if (word[j] != dict[i][j]) {
                        char temp = word[j];
                        word[j] = word[j + 1];
                        word[j + 1] = temp;

                        if (strcmp(word, dict[i]) == 0) {
                            printf("Did you mean '%s'?\n", dict[i]);
                            spelling_error = 1;
                            break;
                        } else {
                            temp = word[j];
                            word[j] = word[j + 1];
                            word[j + 1] = temp;
                        }
                    }
                }
            }
            if (spelling_error)
                break;
        }
    }

    if (spelling_error == 0)
        printf("Could not find any suggestions for '%s'.\n", word);

    return 0;
}