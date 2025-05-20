//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Alan Turing
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
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %s\n", words[num_words].english, words[num_words].cat) == 2) {
        num_words++;
        if (num_words == MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        int num_words = 0;
        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].cat);
                    break;
                }
            }
            if (i == num_words) {
                printf("unknown word: %s\n", token);
            }
            num_words++;
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}