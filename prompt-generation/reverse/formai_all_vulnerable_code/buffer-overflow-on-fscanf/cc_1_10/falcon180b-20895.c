//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

int main() {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    word_pair dictionary[MAX_WORDS];
    int num_words = 0;

    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];

    while (fscanf(dictionary_file, "%s %s", english_word, alien_word) == 2) {
        if (num_words == MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            fclose(dictionary_file);
            return 1;
        }

        strcpy(dictionary[num_words].english, english_word);
        strcpy(dictionary[num_words].alien, alien_word);

        num_words++;
    }

    fclose(dictionary_file);

    char input_sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);

    char *token = strtok(input_sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("unknown word: %s", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}