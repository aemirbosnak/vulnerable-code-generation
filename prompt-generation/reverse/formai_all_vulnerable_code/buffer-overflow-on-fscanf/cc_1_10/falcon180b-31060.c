//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct word {
    char *english;
    char *cat;
};

int load_words(struct word *words) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open words file.\n");
        return 1;
    }

    int count = 0;
    while (fscanf(fp, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int main() {
    struct word words[MAX_WORDS];
    if (load_words(words)) {
        return 1;
    }

    char input[MAX_WORD_LEN];
    printf("Enter a sentence in English:\n");
    fgets(input, MAX_WORD_LEN, stdin);

    int len = strlen(input);
    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}