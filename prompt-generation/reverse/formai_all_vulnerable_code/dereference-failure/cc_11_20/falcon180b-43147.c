//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    struct word words[MAX_WORDS];
    int num_words = 0;

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, dict_file)!= NULL) {
        char *english_word = strtok(line, " ");
        char *alien_word = strtok(NULL, " ");

        if (english_word == NULL || alien_word == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            fclose(dict_file);
            return 1;
        }

        struct word *new_word = &words[num_words++];
        new_word->english = strdup(english_word);
        new_word->alien = strdup(alien_word);
    }

    fclose(dict_file);

    char input_line[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(input_line, MAX_WORD_LEN, stdin);

    char *input_ptr = input_line;
    while (*input_ptr!= '\0') {
        char c = *input_ptr;
        if (isalpha(c)) {
            char *english_word = input_ptr;
            while (isalpha(*input_ptr)) {
                input_ptr++;
            }
            *input_ptr = '\0';

            struct word *match = NULL;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(words[i].english, english_word) == 0) {
                    match = &words[i];
                    break;
                }
            }

            if (match == NULL) {
                printf("Error: unknown word '%s'.\n", english_word);
                return 1;
            }

            printf("%s", match->alien);

            input_ptr = input_ptr + 1;
        } else {
            printf("%c", c);
            input_ptr++;
        }
    }

    printf("\n");

    return 0;
}