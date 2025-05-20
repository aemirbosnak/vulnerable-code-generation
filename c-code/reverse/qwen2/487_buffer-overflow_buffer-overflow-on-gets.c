#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

int main() {
    char sentence[WORD_LENGTH * MAX_WORDS];
    int positiveWords[MAX_WORDS] = {0};
    int negativeWords[MAX_WORDS] = {0};
    int posCount = 0, negCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i]; i++) {
        if (sentence[i] == ' ') {
            sentence[i] = '\0';
            if (strcmp(sentence, "POSITIVE") == 0) {
                positiveWords[posCount++] = 1;
            } else if (strcmp(sentence, "NEGATIVE") == 0) {
                negativeWords[negCount++] = 1;
            }
            strcpy(sentence, &sentence[i + 1]);
        }
    }

    printf("Positive Words: %d\n", posCount);
    printf("Negative Words: %d\n", negCount);

    return 0;
}
