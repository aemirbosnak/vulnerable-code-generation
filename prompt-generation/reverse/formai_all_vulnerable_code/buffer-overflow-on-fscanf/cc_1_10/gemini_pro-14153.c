//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: immersive
// Embark on a Cerebral Voyage through the Realm of Spellbound Words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A Lexicon of Valid Words where Knowledge Resides
char **dictionary;
int dictionarySize;

// A Tome of Errors where Misspellings Lurk
char **misspellings;
int misspellingsSize;

// The Manuscript to be Scrutinized
char *manuscript;
int manuscriptSize;

// The Spellchecker's Oracle, Guiding Us in the Quest for Correctness
int isWordValid(char *word) {
    for (int i = 0; i < dictionarySize; i++) {
        if (!strcmp(word, dictionary[i])) {
            return 1;
        }
    }
    return 0;
}

// The Spellchecker's Scryer, Revealing Misspellings that Defile the Text
void findMisspellings() {
    for (int i = 0; i < manuscriptSize; i++) {
        char word[100];
        int j = 0;
        while (isalpha(manuscript[i]) && i < manuscriptSize) {
            word[j++] = manuscript[i++];
        }
        word[j] = '\0';
        if (!isWordValid(word)) {
            misspellings[misspellingsSize++] = strdup(word);
        }
    }
}

// The Spellchecker's Scribe, Rectifying Misspellings with a Stroke of Inspiration
void correctMisspellings() {
    for (int i = 0; i < misspellingsSize; i++) {
        printf("%s -> %s\n", misspellings[i], dictionary[rand() % dictionarySize]);
        free(misspellings[i]);
    }
}

int main() {
    // Load the Lexicon of Valid Words
    dictionarySize = 1000;
    dictionary = malloc(sizeof(char *) * dictionarySize);
    FILE *dictFile = fopen("dictionary.txt", "r");
    for (int i = 0; i < dictionarySize; i++) {
        dictionary[i] = malloc(sizeof(char) * 100);
        fscanf(dictFile, "%s", dictionary[i]);
    }
    fclose(dictFile);

    // Load the Manuscript to be Scrutinized
    manuscriptSize = 10000;
    manuscript = malloc(sizeof(char) * manuscriptSize);
    FILE *manuscriptFile = fopen("manuscript.txt", "r");
    for (int i = 0; i < manuscriptSize; i++) {
        fscanf(manuscriptFile, "%c", &manuscript[i]);
    }
    fclose(manuscriptFile);

    // Summon the Spellchecker's Oracle and Scryer
    misspellingsSize = 0;
    misspellings = malloc(sizeof(char *) * manuscriptSize);
    findMisspellings();

    // Allow the Spellchecker's Scribe to Correct Misspellings
    correctMisspellings();

    // Release the Spells and Return to the Mortal Realm
    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    free(manuscript);
    for (int i = 0; i < misspellingsSize; i++) {
        free(misspellings[i]);
    }
    free(misspellings);

    return 0;
}