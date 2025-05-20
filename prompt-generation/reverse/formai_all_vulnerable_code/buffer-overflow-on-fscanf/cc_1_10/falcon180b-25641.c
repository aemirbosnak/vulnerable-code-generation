//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

//function to load dictionary into memory
void load_dictionary(char **dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        dictionary[count] = strdup(word);
        count++;
    }
    fclose(fp);
}

//function to check if word is in dictionary
int is_word(char *word, char **dictionary) {
    int i = 0;
    while (dictionary[i]!= NULL) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

//function to suggest corrections for misspelled words
void suggest_corrections(char *word, char **suggestions) {
    int i = 0;
    char *correct_word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(correct_word, word);
    correct_word[strcspn(correct_word, "aeiouAEIOU")] = '\0';
    char *prefix = strtok(correct_word, "aeiouAEIOU");
    while (prefix!= NULL) {
        strcat(prefix, "aeiouAEIOU");
        suggestions[i] = strdup(prefix);
        i++;
        prefix = strtok(NULL, "aeiouAEIOU");
    }
    free(correct_word);
}

//function to spell check a sentence
void spell_check(char *sentence, char **dictionary, char **suggestions) {
    char *token = strtok(sentence, ",.?!;:");
    while (token!= NULL) {
        int word_length = strlen(token);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' is too long.\n", token);
        } else if (!is_word(token, dictionary)) {
            printf("Possible spelling error: '%s'\n", token);
            suggest_corrections(token, suggestions);
        }
        token = strtok(NULL, ",.?!;:");
    }
}

int main() {
    char *dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char *sentence = "Helloworld! This is a test of the spellcheking program.";
    char *suggestions[MAX_WORDS];
    spell_check(sentence, dictionary, suggestions);

    return 0;
}