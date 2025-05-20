//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1000], word[100];
    int frequency[1000] = {0}, i, j, total = 0;

    printf("Hello there! I hope you're ready for some word counting fun.\n");
    printf("Please enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    int length = strlen(sentence);
    if (sentence[length-1] == '\n') {
        sentence[length-1] = '\0';
    }

    printf("\nGreat! Let me count the frequency of each word for you...\n\n");

    for (i = 0, j = 0; i <= strlen(sentence); i++) {
        // if space or NULL found, add word to array
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            word[j] = '\0';
            j = 0;
            // compare the word with all words in the array
            for (int k = 0; k < total; k++) {
                if (strcmp(word, sentence[k]) == 0) {
                    frequency[k]++;
                    break;
                }
            }
            strcpy(sentence[total], word);
            frequency[total] = 1;
            total++;
        }
        else {
            word[j] = sentence[i];
            j++;
        }
    }

    printf("Here are the results:\n");

    for (i = 0; i < total; i++) {
        printf("%s: %d\n", sentence[i], frequency[i]);
    }

    printf("\nHope you enjoyed this program! Goodbye.\n");

    return 0;
}