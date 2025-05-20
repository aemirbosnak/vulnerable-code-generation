//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char *english;
    char *alien;
};

bool load_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return false;
    }

    int num_words = 0;
    while (fscanf(file, "%s %s\n", words[num_words].english, words[num_words].alien) == 2) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

int main() {
    struct word words[MAX_WORDS];
    if (!load_words(words)) {
        return 1;
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    char output[MAX_WORD_LENGTH * 2];
    output[0] = '\0';

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcat(output, words[i].alien);
                strcat(output, " ");
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Error: unknown word '%s'\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("Alien translation: %s\n", output);

    return 0;
}