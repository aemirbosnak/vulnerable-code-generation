//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

int load_words(word_pair words[]) {
    FILE *file;
    int count = 0;
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return -1;
    }
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien)!= EOF) {
        count++;
    }
    fclose(file);
    return count;
}

int main() {
    word_pair words[MAX_WORDS];
    int num_words;
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];

    num_words = load_words(words);
    if (num_words <= 0) {
        return -1;
    }

    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcpy(output, words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            strcpy(output, token);
        }
        printf("%s ", output);
        token = strtok(NULL, " ");
    }

    return 0;
}