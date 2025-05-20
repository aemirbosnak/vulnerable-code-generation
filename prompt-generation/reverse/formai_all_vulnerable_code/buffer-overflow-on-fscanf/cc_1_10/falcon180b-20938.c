//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

word_pair dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(FILE *dict_file) {
    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];

    while (fscanf(dict_file, "%s %s", english_word, alien_word)!= EOF) {
        strcpy(dictionary[num_words].english, english_word);
        strcpy(dictionary[num_words].alien, alien_word);
        num_words++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        exit(1);
    }

    FILE *dict_file = fopen(argv[1], "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    load_dictionary(dict_file);
    fclose(dict_file);

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
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}