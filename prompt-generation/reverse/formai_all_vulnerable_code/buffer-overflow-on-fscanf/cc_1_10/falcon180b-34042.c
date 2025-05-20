//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", words[count].english, words[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter an English word: ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        int length = strlen(input);
        if (length == 0 || input[length - 1]!= '\n') {
            printf("Invalid input.\n");
            continue;
        }

        input[--length] = '\0';

        struct word *translation = NULL;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].english, input) == 0) {
                translation = &words[i];
                break;
            }
        }

        if (translation == NULL) {
            printf("No translation found.\n");
        } else {
            printf("Translation: %s\n", translation->alien);
        }
    }

    return 0;
}