//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

typedef struct {
    char word[MAX_LEN];
    int count;
} WordCount;

WordCount *words = NULL;
int num_words = 0;

int main() {
    char filename[MAX_LEN];
    printf("Enter the name of the text file to analyze: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            line[i] = tolower(line[i]);
        }

        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (strlen(word) > 0 && isspace(word[strlen(word) - 1])) {
                strcat(word, " ");
            }

            if (num_words == MAX_LEN) {
                WordCount *new_word = (WordCount *) realloc(words, (MAX_LEN + 1) * sizeof(WordCount));
                if (new_word == NULL) {
                    printf("Error reallocating memory.\n");
                    return 1;
                }
                words = new_word;
            }

            words[num_words].word[0] = '\0';
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;

            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word Count Report:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 1) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}