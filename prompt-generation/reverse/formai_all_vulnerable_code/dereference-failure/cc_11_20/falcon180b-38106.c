//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

struct word {
    char *english;
    char *alien;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;
    char line[100];

    // Load dictionary
    FILE *dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), dict)!= NULL) {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");

        if (english == NULL || alien == NULL) {
            printf("Error: Invalid line in dictionary file.\n");
            return 1;
        }

        words[num_words].english = strdup(english);
        words[num_words].alien = strdup(alien);
        num_words++;

        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary too large.\n");
            return 1;
        }
    }

    fclose(dict);

    // Translate input
    printf("Enter a sentence to translate: ");
    fgets(line, sizeof(line), stdin);

    char *sentence = strdup(line);
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

    for (int i = 0; i < num_words; i++) {
        free(words[i].english);
        free(words[i].alien);
    }

    free(sentence);

    return 0;
}