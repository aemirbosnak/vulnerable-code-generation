#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    char sentence[MAX_WORDS * (MAX_WORD_LENGTH + 1)];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_WORDS] = {0};
    int current_word_index = 0;
    int i, j;

    printf("Enter a sentence: ");
    gets(sentence);

    char* token = strtok(sentence, " ");
    while (token != NULL && current_word_index < MAX_WORDS) {
        strcpy(words[current_word_index], token);
        word_count[current_word_index]++;
        current_word_index++;
        token = strtok(NULL, " ");
    }

    printf("\nWord frequencies:\n");
    for (i = 0; i < current_word_index; i++) {
        printf("%s: %d\n", words[i], word_count[i]);
    }

    return 0;
}
