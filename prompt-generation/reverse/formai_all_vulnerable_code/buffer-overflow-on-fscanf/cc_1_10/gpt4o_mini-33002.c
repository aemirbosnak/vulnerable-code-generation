//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 5

typedef struct {
    char **words;
    int size;
} Dictionary;

// Function prototypes
Dictionary loadDictionary(const char *filename);
void freeDictionary(Dictionary dict);
int isWordInDictionary(const char *word, Dictionary dict);
void suggestCorrections(const char *word, Dictionary dict);
char **getEditDistanceSuggestions(const char *word, Dictionary dict, int *suggestionCount);
int calculateEditDistance(const char *word1, const char *word2);
void toLowerCase(char *str);

int main() {
    Dictionary dict = loadDictionary("dictionary.txt");
    char inputWord[MAX_WORD_LENGTH];

    printf("Enter a word to spell check: ");
    while (scanf("%s", inputWord) != EOF) {
        // Convert input to lowercase for case insensitive comparison
        toLowerCase(inputWord);
        
        if (isWordInDictionary(inputWord, dict)) {
            printf("'%s' is spelled correctly.\n", inputWord);
        } else {
            printf("'%s' is not found. Suggestions: ");
            suggestCorrections(inputWord, dict);
        }
        printf("\nEnter another word to spell check: ");
    }

    freeDictionary(dict);
    return 0;
}

Dictionary loadDictionary(const char *filename) {
    Dictionary dict;
    char word[MAX_WORD_LENGTH];
    dict.words = malloc(DICTIONARY_SIZE * sizeof(char *));
    dict.size = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", word) != EOF) {
        dict.words[dict.size] = malloc((strlen(word) + 1) * sizeof(char));
        strcpy(dict.words[dict.size], word);
        dict.size++;
    }

    fclose(file);
    return dict;
}

void freeDictionary(Dictionary dict) {
    for (int i = 0; i < dict.size; i++) {
        free(dict.words[i]);
    }
    free(dict.words);
}

int isWordInDictionary(const char *word, Dictionary dict) {
    for (int i = 0; i < dict.size; i++) {
        if (strcmp(word, dict.words[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void suggestCorrections(const char *word, Dictionary dict) {
    int suggestionCount = 0;
    char **suggestions = getEditDistanceSuggestions(word, dict, &suggestionCount);
    
    if (suggestionCount == 0) {
        printf("No suggestions available.\n");
    } else {
        for (int i = 0; i < suggestionCount && i < MAX_SUGGESTIONS; i++) {
            printf("'%s' ", suggestions[i]);
            free(suggestions[i]); // Free suggestions individually
        }
        free(suggestions); // Free the array of suggestions
    }
}

char **getEditDistanceSuggestions(const char *word, Dictionary dict, int *suggestionCount) {
    *suggestionCount = 0;
    char **suggestions = malloc(DICTIONARY_SIZE * sizeof(char *));
    
    for (int i = 0; i < dict.size; i++) {
        if (calculateEditDistance(word, dict.words[i]) == 1) {
            suggestions[*suggestionCount] = malloc((strlen(dict.words[i]) + 1) * sizeof(char));
            strcpy(suggestions[*suggestionCount], dict.words[i]);
            (*suggestionCount)++;
        }
    }
    
    return suggestions;
}

int calculateEditDistance(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j; // If the first string is empty
            } else if (j == 0) {
                dp[i][j] = i; // If the second string is empty
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + (dp[i - 1][j - 1] < dp[i - 1][j] ? 
                                (dp[i - 1][j - 1] < dp[i][j - 1] ? 
                                 dp[i - 1][j - 1] : dp[i][j - 1]) : 
                                (dp[i - 1][j] < dp[i][j - 1] ? 
                                 dp[i - 1][j] : dp[i][j - 1]));
            }
        }
    }
    return dp[len1][len2];
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A'); // Convert it to lower case
        }
    }
}