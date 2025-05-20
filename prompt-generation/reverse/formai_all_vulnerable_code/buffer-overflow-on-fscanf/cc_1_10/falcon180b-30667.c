//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *input_file;
    char input_string[MAX_WORD_LENGTH];
    char *token;
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", input_string)!= EOF) {
        token = strtok(input_string, " \n\t\r\f");
        while (token!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                strcpy(words[num_words].word, token);
                words[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " \n\t\r\f");
        }
    }

    fclose(input_file);

    printf("Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}