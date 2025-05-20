//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char french[MAX_WORD_LENGTH];
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s\n", line, line) == 2) {
        strcpy(words[num_words].english, line);
        strcpy(words[num_words].french, line);
        num_words++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <english_sentence>\n", argv[0]);
        return 1;
    }

    load_words("words.txt");

    char sentence[MAX_WORD_LENGTH];
    strcpy(sentence, argv[1]);

    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].french);
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