#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char sentence[MAX_LENGTH];
    int wordCount[256] = {0};
    int i, j;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; sentence[i]; i++) {
        if (isalpha(sentence[i])) {
            sentence[i] = tolower(sentence[i]);
        }
    }

    for (i = 0; sentence[i]; i++) {
        if (isalpha(sentence[i])) {
            wordCount[sentence[i]]++;
        } else if (sentence[i] == ' ') {
            for (j = 0; j < 256; j++) {
                if (wordCount[j] > 0) {
                    printf("%c: %d\n", j, wordCount[j]);
                    wordCount[j] = 0;
                }
            }
        }
    }

    for (j = 0; j < 256; j++) {
        if (wordCount[j] > 0) {
            printf("%c: %d\n", j, wordCount[j]);
        }
    }

    return 0;
}
