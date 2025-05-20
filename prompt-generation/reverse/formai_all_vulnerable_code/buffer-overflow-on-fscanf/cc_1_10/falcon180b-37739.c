//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return 1;
    }

    int count = 0;
    while (fscanf(file, "%s %s", words[count].english, words[count].alien) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int main() {
    struct word words[MAX_WORDS];
    if (load_words(words)) {
        return 1;
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

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
            return 1;
        }

        token = strtok(NULL, " ");
    }

    printf("Alien translation: %s\n", output);

    return 0;
}