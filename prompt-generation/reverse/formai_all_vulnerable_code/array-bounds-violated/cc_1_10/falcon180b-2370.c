//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 4

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int difficulty;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH + 1, fp)!= NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) >= MIN_WORD_LENGTH && strlen(line) <= MAX_WORD_LENGTH) {
            char* word = strdup(line);
            if (word == NULL) {
                printf("Error: out of memory\n");
                exit(1);
            }

            int length = strlen(word);
            int difficulty = 0;

            for (int i = 0; i < length; i++) {
                if (isalpha(word[i])) {
                    difficulty += (int)word[i] - (int)'a' + 1;
                } else {
                    difficulty += 10;
                }
            }

            words[num_words++] = (word_t){.word = word,.length = length,.difficulty = difficulty};
        }
    }

    fclose(fp);
}

void generate_test(int num_words, int length, int difficulty) {
    srand(time(NULL));

    printf("Typing test:\n");
    printf("Words: %d\n", num_words);
    printf("Length: %d\n", length);
    printf("Difficulty: %d\n", difficulty);

    for (int i = 0; i < num_words; i++) {
        word_t* word = &words[i];
        printf("%s ", word->word);

        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <filename> <num_words> <length> [difficulty]\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int num_words = atoi(argv[2]);
    int length = atoi(argv[3]);
    int difficulty = (argc >= 5)? atoi(argv[4]) : 0;

    load_words(filename);

    generate_test(num_words, length, difficulty);

    return 0;
}