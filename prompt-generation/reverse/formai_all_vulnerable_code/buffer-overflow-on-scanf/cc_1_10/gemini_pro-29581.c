//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: peaceful
// Enchanting Spellcheck in the Realm of Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lexicon of enchantments to banish misspellings
char *lexicon[] = {
    "abracadabra", "alacrity", "auspicious", "benevolence",
    "cacophony", "celestial", "chromatic", "deftness",
    "effervescence", "eloquent", "ephemeral", "felicity",
    "genesis", "jubilant", "luminous", "magnanimous",
    "nefarious", "opulent", "radiant", "serene",
    "trepidation", "ubiquitous", "valor", "zenith"
};

// An invocation to check if a word is enchanted (exists in lexicon)
int isEnchanted(char *word) {
    for (int i = 0; i < sizeof(lexicon) / sizeof(char *); i++) {
        if (strcmp(word, lexicon[i]) == 0) {
            return 1; // Abracadabra! The word is found
        }
    }
    return 0; // Alas, the word is not in our lexicon
}

// A spell to find the closest enchantment (suggestion)
char *findSuggestion(char *word) {
    int minDistance = strlen(word);
    char *closestSuggestion = NULL;
    for (int i = 0; i < sizeof(lexicon) / sizeof(char *); i++) {
        int distance = levenshtein(word, lexicon[i]);
        if (distance < minDistance) {
            minDistance = distance;
            closestSuggestion = lexicon[i];
        }
    }
    return closestSuggestion; // May the closest suggestion guide you
}

// A helper function to calculate the distance between two words (Levenshtein distance)
int levenshtein(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    return matrix[len1][len2]; // The distance between the two words
}

// A simple function to return the minimum of three values
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int main() {
    char input[100];

    printf("Speak your word, and let us cast a spell upon it!\n");
    scanf("%s", input);

    if (isEnchanted(input)) {
        printf("Your word is pure magic, no need for enchantment!\n");
    } else {
        char *suggestion = findSuggestion(input);
        printf("Alas, your word needs a touch of magic. We suggest '%s'.\n", suggestion);
    }

    return 0; // May your words always be enchanted!
}