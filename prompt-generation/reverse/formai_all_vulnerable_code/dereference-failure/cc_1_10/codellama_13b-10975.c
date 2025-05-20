//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, j, k, l;
    int word_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '.') {
            word_count++;
        }
    }

    char* words[word_count];

    for (i = 0, j = 0, k = 0; i < strlen(sentence); i++) {
        if (sentence[i] != ' ' && sentence[i] != '.') {
            word[j++] = sentence[i];
        } else {
            word[j] = '\0';
            words[k++] = strdup(word);
            j = 0;
        }
    }

    for (i = 0; i < word_count; i++) {
        if (is_word_spelled_correctly(words[i]) == 0) {
            printf("Incorrect spelling: %s\n", words[i]);
        }
    }

    return 0;
}

int is_word_spelled_correctly(char* word) {
    int i, j, k;
    int word_length = strlen(word);

    for (i = 0; i < word_length; i++) {
        for (j = 0; j < word_length; j++) {
            if (word[i] == word[j]) {
                for (k = 0; k < word_length; k++) {
                    if (word[k] == word[i] && k != i && k != j) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}