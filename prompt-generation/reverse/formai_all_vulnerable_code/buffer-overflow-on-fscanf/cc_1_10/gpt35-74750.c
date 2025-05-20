//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 30
#define MAX_DICT_WORDS 1000

// Function to strip off any non-alphabetic characters from a word
void stripWord(char *word) {
    int i, j;
    for (i = 0; word[i]; i++) {
        while (!isalpha(word[i]) && word[i])
            for (j = i; word[j]; j++)
                word[j] = word[j + 1];
    }
}

// Function to check if a given word is spelled correctly or not
bool isSpelledCorrectly(char *word, char dictionary[][MAX_WORD_LENGTH]) {
    int i;
    stripWord(word);
    for (i = 0; i < MAX_DICT_WORDS; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char dictionary[MAX_DICT_WORDS][MAX_WORD_LENGTH], input[MAX_WORD_LENGTH], ch;
    int dictSize = 0, i, j;
    FILE *dictFile = fopen("dictionary.txt", "r");
    // Read the dictionary file and store all the words in the array
    while (fscanf(dictFile, "%s", dictionary[dictSize]) != EOF) {
        dictSize++;
    }
    fclose(dictFile);

    // Take input from the user and check if each word is spelled correctly or not
    printf("Enter a few sentences to check for spelling errors:\n");
    while ((ch = getchar()) != EOF) {
        i = 0;
        // Read each word until a space, newline or tab character is encountered
        while (ch != ' ' && ch != '\n' && ch != '\t') {
            input[i++] = ch;
            ch = getchar();
        }
        input[i] = '\0';
        // Check if the word is spelled correctly or not
        if (!isSpelledCorrectly(input, dictionary)) {
            printf("'%s' is not spelled correctly\n", input);
        }
        // Skip any leading whitespace characters in the input
        while (ch == ' ' || ch == '\n' || ch == '\t') {
            ch = getchar();
        }
        // Stop reading input if we encounter a period character
        if (ch == '.') {
            break;
        }
    }

    return 0;
}