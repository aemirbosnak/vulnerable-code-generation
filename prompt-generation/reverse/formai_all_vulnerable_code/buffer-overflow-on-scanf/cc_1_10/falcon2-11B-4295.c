//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

int main() {
    char string[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;

    printf("Enter a string to check for spelling errors: ");
    scanf("%s", string);

    char* word = strtok(string, " ");
    while (word!= NULL) {
        words[num_words][0] = word;
        num_words++;
        word = strtok(NULL, " ");
    }

    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], "I am Sorry") == 0) {
            printf("I am Sorry, but I cannot spell check this word.\n");
            continue;
        }

        if (strcmp(words[i], "c") == 0) {
            printf("Spell checking complete.\n");
            break;
        }

        bool exists = false;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            printf("Spell checking error: %s\n", words[i]);
        }
    }

    return 0;
}