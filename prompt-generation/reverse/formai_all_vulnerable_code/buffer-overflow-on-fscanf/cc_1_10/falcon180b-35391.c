//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words;

void load_words(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    num_words = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(fp);
}

void translate(const char* input) {
    char* output = malloc(strlen(input) + 1);
    strcpy(output, input);

    for (int i = 0; i < num_words; i++) {
        char* pos = strstr(output, words[i]);
        while (pos!= NULL) {
            char* tmp = pos;
            *pos = '\0';
            pos = strstr(pos + 1, words[i]);

            char* new_word = malloc(strlen(words[i]) + 1);
            strcpy(new_word, words[i]);

            strcat(output, new_word);
            strcat(output, " ");

            free(new_word);
            free(tmp);
        }
    }

    printf("%s\n", output);
    free(output);
}

int main() {
    load_words("words.txt");

    char input[1000];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        translate(input);
    }

    return 0;
}