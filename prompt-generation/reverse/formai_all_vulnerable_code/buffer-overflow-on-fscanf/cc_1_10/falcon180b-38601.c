//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

    // Load dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s\n", dictionary[num_words].english, dictionary[num_words].alien)!= EOF) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary too large.\n");
            return 1;
        }
    }

    fclose(fp);

    // Translate input
    printf("Enter text to translate:\n");
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