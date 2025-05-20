//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict;
    struct word words[MAX_WORDS];
    int num_words = 0;

    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(dict, "%s %s", words[num_words].english, words[num_words].alien) == 2 && num_words < MAX_WORDS) {
        num_words++;
    }

    fclose(dict);

    char input[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word to translate: ");
        fgets(input, MAX_WORD_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(input, words[i].english) == 0) {
                printf("Alien translation: %s\n", words[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("Word not found in dictionary.\n");
        }
    }

    return 0;
}