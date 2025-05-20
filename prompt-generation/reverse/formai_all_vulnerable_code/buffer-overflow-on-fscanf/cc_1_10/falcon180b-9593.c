//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH + 1];
    char cat[MAX_WORD_LENGTH + 1];
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2) {
        count++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH + 1];
    while (1) {
        printf("Enter a word to translate (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(input, words[i].english) == 0) {
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