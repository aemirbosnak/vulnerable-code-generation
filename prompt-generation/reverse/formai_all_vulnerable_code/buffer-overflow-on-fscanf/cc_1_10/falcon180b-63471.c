//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20

struct word {
    char english[WORD_LENGTH];
    char alien[WORD_LENGTH];
};

int main() {
    FILE *file;
    struct word words[MAX_WORDS];
    int num_words = 0;

    file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", words[num_words].english, words[num_words].alien)!= EOF) {
        num_words++;
    }

    fclose(file);

    printf("Enter a sentence to translate:\n");

    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
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