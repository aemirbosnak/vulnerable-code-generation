//Code Llama-13B DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct word {
    char word[MAX_LEN];
    char translation[MAX_LEN];
};

int main() {
    struct word words[100];
    int num_words = 0;
    char input[MAX_LEN];

    while (1) {
        printf("Enter a word or sentence (q to quit): ");
        fgets(input, MAX_LEN, stdin);

        if (input[0] == 'q') {
            break;
        }

        // remove newline character
        input[strlen(input) - 1] = '\0';

        // check if word is already in dictionary
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(input, words[i].word) == 0) {
                found = 1;
                break;
            }
        }

        // if word is not in dictionary, add it
        if (!found) {
            strcpy(words[num_words].word, input);
            printf("Enter translation: ");
            fgets(words[num_words].translation, MAX_LEN, stdin);
            // remove newline character
            words[num_words].translation[strlen(words[num_words].translation) - 1] = '\0';
            num_words++;
        }
    }

    // print all words and their translations
    for (int i = 0; i < num_words; i++) {
        printf("%s = %s\n", words[i].word, words[i].translation);
    }

    return 0;
}