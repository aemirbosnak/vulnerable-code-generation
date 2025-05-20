#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 1024

void countWords(char *sentence) {
    char words[MAX_BUFFER][MAX_BUFFER];
    int wordCount = 0, i = 0, j = 0;
    char *token;

    token = strtok(sentence, " .,!?");
    while (token != NULL) {
        words[wordCount][i] = *token;
        i++;
        if (i >= MAX_BUFFER - 1) {
            // Buffer overflow vulnerability
        }
        if (*(token + 1) == ' ') {
            words[wordCount][i] = '\0';
            i = 0;
            wordCount++;
        }
        token = strtok(NULL, " .,!?");
    }

    for (int k = 0; k < wordCount; k++) {
        int count = 1;
        for (int l = k + 1; l < wordCount; l++) {
            if (!strcmp(words[k], words[l])) {
                count++;
                words[l][0] = '\0';
            }
        }
        if (words[k][0] != '\0') {
            printf("%s: %d\n", words[k], count);
        }
    }
}

int main() {
    char sentence[MAX_BUFFER];

    printf("Enter a sentence: ");
    gets(sentence);

    countWords(sentence);

    return 0;
}
