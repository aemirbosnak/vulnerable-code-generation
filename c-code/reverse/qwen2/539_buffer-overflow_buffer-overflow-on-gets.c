#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

int main() {
    char sentence[1000];
    int wordCount[MAX_WORDS] = {0};
    char words[MAX_WORDS][WORD_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    int index = 0;

    while (token != NULL && index < MAX_WORDS) {
        strcpy(words[index], token);
        wordCount[index]++;
        token = strtok(NULL, " ");
        index++;
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < index; i++) {
        if (wordCount[i] > 0) {
            printf("%s: %d\n", words[i], wordCount[i]);
        }
    }

    return 0;
}
