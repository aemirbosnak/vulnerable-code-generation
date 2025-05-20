//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
};

int main() {
    FILE *dict;
    char line[MAX_WORD_LEN];
    int num_words = 0;
    struct word dictionary[MAX_WORDS];

    dict = fopen("dictionary.txt", "r");

    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(dict, "%s", line)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary too large.\n");
            exit(1);
        }
        strcpy(dictionary[num_words].english, line);
        strcpy(dictionary[num_words].alien, "");
        num_words++;
    }

    fclose(dict);

    printf("Enter a sentence to translate:\n");
    char sentence[MAX_WORD_LEN * 100];
    fgets(sentence, sizeof(sentence), stdin);

    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}