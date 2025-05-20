//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char english[50];
    char alien[50];
} word_t;

int main(int argc, char **argv) {
    FILE *dict_file;
    word_t *dict;
    int num_words;
    char input_word[50];
    char *result;

    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    dict = (word_t *) malloc(MAX_WORDS * sizeof(word_t));
    num_words = 0;

    while (fscanf(dict_file, "%s %s", dict[num_words].english, dict[num_words].alien)!= EOF) {
        num_words++;
        if (num_words == MAX_WORDS) {
            break;
        }
    }

    fclose(dict_file);

    printf("Enter an English word to translate: ");
    scanf("%s", input_word);

    result = (char *) malloc(50 * sizeof(char));

    for (int i = 0; i < num_words; i++) {
        if (strcmp(dict[i].english, input_word) == 0) {
            strcpy(result, dict[i].alien);
            break;
        }
    }

    if (result == NULL) {
        printf("Error: word not found in dictionary.\n");
    } else {
        printf("Translation: %s\n", result);
    }

    free(dict);
    free(result);

    return 0;
}