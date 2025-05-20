//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    char input[MAX_WORD_LENGTH];
    char *token;

    printf("Enter English word (or type 'quit' to finish): ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    while (strcmp(input, "quit")!= 0) {
        token = strtok(input, " ");
        strcpy(dictionary[num_words].english, token);
        strcpy(dictionary[num_words].alien, "");
        num_words++;

        printf("Enter corresponding alien word (or press enter to skip): ");
        fgets(input, MAX_WORD_LENGTH, stdin);
    }

    printf("\nEnglish to Alien Translator\n");
    printf("Enter English sentence to translate: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}