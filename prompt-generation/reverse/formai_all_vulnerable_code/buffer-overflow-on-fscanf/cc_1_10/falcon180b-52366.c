//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

int load_words(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return -1;
    }

    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

int main() {
    Word words[MAX_WORDS];
    int num_words;

    num_words = load_words(words);

    if (num_words <= 0) {
        return -1;
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

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
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}