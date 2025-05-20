//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// define the maximum length of a word and the maximum number of words in a sentence
#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 200

int main() {
    // open the dictionary file for reading
    FILE *dict = fopen("dictionary.txt", "r");
    if (!dict) {
        printf("Dictionary file not found!\n");
        return 1;
    }

    // create an array of words from the dictionary
    char words[10000][MAX_WORD_LEN];
    int num_words = 0;
    char word[MAX_WORD_LEN];
    while (fscanf(dict, "%s", word) != EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }
    fclose(dict);

    // prompt the user to enter a sentence to be spell-checked
    char sentence[MAX_SENTENCE_LEN];
    printf("Enter a sentence to be spell-checked:\n");
    fgets(sentence, sizeof(sentence), stdin);

    // remove newline character from the end of the sentence if present
    int len = strlen(sentence);
    if (sentence[len-1] == '\n') {
        sentence[len-1] = '\0';
    }

    // loop through the sentence and extract each word
    char *pch = strtok(sentence, " ");
    while (pch != NULL) {
        // convert the word to lower case and remove punctuation marks
        char lower_word[MAX_WORD_LEN];
        int i = 0, j = 0;
        while (pch[i]) {
            if (isalpha(pch[i])) {
                lower_word[j] = tolower(pch[i]);
                j++;
            }
            i++;
        }
        lower_word[j] = '\0';

        // check if the word is in the dictionary
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(lower_word, words[i]) == 0) {
                found = 1;
                break;
            }
        }

        // print the word and its status (found or not found)
        printf("%s %s\n", lower_word, found ? "OK" : "MISSPELLED");

        // get the next word in the sentence
        pch = strtok(NULL, " ");
    }

    return 0;
}