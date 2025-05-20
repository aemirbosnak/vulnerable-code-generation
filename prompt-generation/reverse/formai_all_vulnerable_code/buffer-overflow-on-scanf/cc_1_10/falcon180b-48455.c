//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

int main() {
    int num_words;
    scanf("%d", &num_words);

    struct word words[MAX_WORDS];
    for (int i = 0; i < num_words; i++) {
        char english[MAX_WORD_LENGTH];
        char alien[MAX_WORD_LENGTH];

        printf("Enter English word %d: ", i+1);
        scanf("%s", english);

        printf("Enter Alien word %d: ", i+1);
        scanf("%s", alien);

        strcpy(words[i].english, english);
        strcpy(words[i].alien, alien);
    }

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a sentence to translate: ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        int len = strlen(input);
        for (int i = 0; i < len; i++) {
            if (isspace(input[i])) {
                input[i] = '\0';
            }
        }

        char *token = strtok(input, " ");
        while (token!= NULL) {
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].alien);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("%s ", token);
            }

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    return 0;
}