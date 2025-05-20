//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char english_word[MAX_WORD_LEN];
    char alien_word[MAX_WORD_LEN];
} word_pair;

void load_dictionary(word_pair dictionary[MAX_WORDS]) {
    FILE *file = fopen("dictionary.txt", "r");
    int count = 0;
    while (fscanf(file, "%s %s\n", dictionary[count].english_word, dictionary[count].alien_word)!= EOF && count < MAX_WORDS) {
        count++;
    }
    fclose(file);
}

int main() {
    char input_sentence[1000];
    char *word;
    word_pair dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    printf("Enter a sentence to translate:\n");
    fgets(input_sentence, sizeof(input_sentence), stdin);

    char output_sentence[2000];
    strcpy(output_sentence, "");
    word = strtok(input_sentence, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, dictionary[i].english_word) == 0) {
                strcat(output_sentence, dictionary[i].alien_word);
                strcat(output_sentence, " ");
                break;
            }
        }
        if (i == MAX_WORDS) {
            strcat(output_sentence, "UNKNOWN_WORD ");
        }
        word = strtok(NULL, " ");
    }

    printf("Translated sentence: %s\n", output_sentence);

    return 0;
}