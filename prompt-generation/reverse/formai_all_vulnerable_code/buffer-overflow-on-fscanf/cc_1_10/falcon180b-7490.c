//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %s\n", words[num_words].english, words[num_words].alien)!= EOF) {
        num_words++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].alien);
                    break;
                }
            }

            if (i == MAX_WORDS) {
                printf("unknown word: %s ", token);
            }

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    return 0;
}