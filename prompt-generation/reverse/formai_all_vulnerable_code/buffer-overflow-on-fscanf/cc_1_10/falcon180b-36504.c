//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char english[50];
    char alien[50];
} word_t;

int main() {
    FILE *dict;
    word_t words[MAX_WORDS];
    int num_words = 0;
    char input[100];
    char *token;

    // Open dictionary file
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    // Read words from dictionary
    while (fscanf(dict, "%s %s\n", words[num_words].english, words[num_words].alien)!= EOF) {
        num_words++;
        if (num_words == MAX_WORDS) {
            printf("Dictionary is too large.\n");
            exit(1);
        }
    }

    // Close dictionary file
    fclose(dict);

    // Get input from user
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    // Tokenize input
    token = strtok(input, " ");
    while (token!= NULL) {
        // Search for word in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Word found, print alien translation
                printf("%s ", words[i].alien);
                break;
            }
        }

        // Word not found, print original word
        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}