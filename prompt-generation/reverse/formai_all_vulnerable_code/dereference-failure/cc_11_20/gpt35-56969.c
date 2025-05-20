//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input_text[1000];
    int word_count = 0;
    int i, j, k;

    printf("Enter the text to count word frequency: ");
    fgets(input_text, sizeof(input_text), stdin);

    for (i = 0; i < strlen(input_text); i++) {
        if (input_text[i] == ' ' || input_text[i] == '\t' || input_text[i] == '\n') {
            word_count++;
        }
    }

    char **words = (char**) malloc(word_count * sizeof(char*));
    for (i = 0, j = 0, k = 0; i < strlen(input_text); i++) {
        if (input_text[i] == ' ' || input_text[i] == '\t' || input_text[i] == '\n') {
            words[j] = (char*) malloc((k+1) * sizeof(char));
            strncpy(words[j], input_text + i - k, k);
            words[j][k] = '\0';
            j++;
            k = 0;
        }
        else {
            k++;
        }
    }

    int frequency[word_count];
    for (i = 0; i < word_count; i++) {
        frequency[i] = 1;
    }

    for (i = 0; i < word_count - 1; i++) {
        for (j = i+1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
            }
        }
    }

    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    for (i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}