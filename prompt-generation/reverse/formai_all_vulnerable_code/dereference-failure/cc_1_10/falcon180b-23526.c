//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

int main() {
    FILE *fp;
    char filename[20];
    char word[MAX_WORD_LENGTH];
    char *words[MAX_NUM_WORDS];
    int num_words = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int word_count = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    while ((fscanf(fp, "%s", word))!= EOF) {
        if (num_words == MAX_NUM_WORDS) {
            printf("Maximum number of words reached\n");
            exit(2);
        }

        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Maximum word length exceeded\n");
            exit(3);
        }

        words[num_words] = malloc(strlen(word) + 1);
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(fp);

    printf("Number of words: %d\n", num_words);

    for (i = 0; i < num_words; i++) {
        word_count = 0;
        for (j = 0; j < strlen(words[i]); j++) {
            if (isalpha(words[i][j])) {
                word_count++;
            }
        }
        printf("Word %d: %s\nWord length: %d\n", i+1, words[i], word_count);
    }

    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}