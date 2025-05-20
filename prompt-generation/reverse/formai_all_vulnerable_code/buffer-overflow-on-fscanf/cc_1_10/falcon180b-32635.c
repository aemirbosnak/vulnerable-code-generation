//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

struct Word {
    char english[50];
    char cat[50];
};

void loadWords(struct Word words[]) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    struct Word words[MAX_WORDS];
    loadWords(words);

    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

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
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    return 0;
}