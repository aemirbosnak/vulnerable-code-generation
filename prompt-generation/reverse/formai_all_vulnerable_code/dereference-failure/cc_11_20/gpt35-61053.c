//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000

int main(int argc, char *argv[]) {
    char c;
    char word[MAX_WORD_LEN] = "";
    int i = 0, j = 0;
    int num_words = 0;
    char **word_list = (char **)malloc(MAX_NUM_WORDS * sizeof(char*));

    if (word_list == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF && num_words < MAX_NUM_WORDS) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
        } else if (isspace(c) || ispunct(c)) {
            if (i > 0) {
                word[i] = '\0';
                char *new_word = (char *)malloc(i+1);
                if (new_word == NULL) {
                    printf("Error: Unable to allocate memory\n");
                    exit(1);
                }
                strcpy(new_word, word);
                word_list[j++] = new_word;
                num_words++;
                i = 0;
                memset(word, '\0', sizeof(word));
            }
        }
    }

    fclose(fp);

    //Sort the words in alphabetical order
    for (int i = 0; i < num_words-1; i++) {
        for (int j = i+1; j < num_words; j++) {
            if (strcmp(word_list[i], word_list[j]) > 0) {
                char *tmp = word_list[i];
                word_list[i] = word_list[j];
                word_list[j] = tmp;
            }
        }
    }

    //Print the word count
    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        int count = 1;
        if (word_list[i] != NULL) {
            for (int j = i+1; j < num_words; j++) {
                if (word_list[j] != NULL) {
                    if (strcmp(word_list[i], word_list[j]) == 0) {
                        count++;
                        free(word_list[j]);
                        word_list[j] = NULL;
                    }
                }
            }
            printf("%s: %d\n", word_list[i], count);
            free(word_list[i]);
            word_list[i] = NULL;
        }
    }

    free(word_list);
    return 0;
}