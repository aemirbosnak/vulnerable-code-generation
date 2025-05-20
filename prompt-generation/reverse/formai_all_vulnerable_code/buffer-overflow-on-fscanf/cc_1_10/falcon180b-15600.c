//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} word_pair;

void load_words(word_pair words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    word_pair words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    int output_index = 0;

    int word_start = 0;
    while (isspace(input[word_start])) {
        word_start++;
    }

    int word_end = word_start;
    while (!isspace(input[word_end])) {
        word_end++;
        if (word_end >= strlen(input)) {
            break;
        }
    }

    char word[MAX_WORD_LENGTH];
    strncpy(word, &input[word_start], word_end - word_start);
    word[word_end - word_start] = '\0';

    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].english, word) == 0) {
            strcpy(output, words[i].alien);
            break;
        }
    }

    printf("Translation: %s\n", output);

    return 0;
}