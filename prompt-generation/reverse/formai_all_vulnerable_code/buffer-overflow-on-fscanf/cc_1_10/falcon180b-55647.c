//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2 && count < MAX_WORDS) {
        count++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];

    load_words(words);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].english, input) == 0) {
                printf("%s -> %s\n", input, words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Word not found.\n");
        }
    }

    return 0;
}