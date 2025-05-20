#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void summarize(char *text) {
    int freq[MAX_LEN] = {0};
    char word[MAX_LEN];
    int i, j;

    // Tokenize and count frequency of each word
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            word[i] = '\0';
            for (j = 0; j <= i; j++) {
                freq[j]++;
            }
        } else {
            word[i] = text[i];
        }
    }

    // Print summarized words with their frequencies
    printf("Summarized Text:\n");
    for (i = 0; i < MAX_LEN; i++) {
        if (freq[i] > 0) {
            printf("%s: %d\n", &word[i], freq[i]);
        }
    }
}

int main() {
    char text[MAX_LEN];

    printf("Enter text to summarize:\n");
    gets(text);

    summarize(text);

    return 0;
}
