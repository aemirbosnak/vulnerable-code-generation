//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

void spell_check(char* sentence);
void recursive_spell_check(char* sentence, int start, int end);

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    spell_check(sentence);
    return 0;
}

void spell_check(char* sentence) {
    int i, j, word_length, start, end;
    char word[MAX_WORD_LENGTH];

    // Iterate through each word in the sentence
    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            // Check for spaces and newlines
            if (i > 0) {
                // Recursively spell-check the previous word
                recursive_spell_check(sentence, i - 1, i);
            }
            // Move to the next word
            i++;
            continue;
        }

        // Find the start and end of the current word
        start = i;
        for (j = i + 1; sentence[j] != ' ' && sentence[j] != '\n'; j++) {
            if (sentence[j] == ' ') {
                end = j - 1;
                break;
            }
        }

        // Check the word for spelling errors
        word_length = end - start + 1;
        if (word_length > MAX_WORD_LENGTH) {
            printf("Word %s is too long (max %d characters)\n", sentence + start, MAX_WORD_LENGTH);
        } else {
            recursive_spell_check(sentence + start, start, end);
        }
    }
}

void recursive_spell_check(char* sentence, int start, int end) {
    int i, j;
    char word[MAX_WORD_LENGTH];

    // Check the word for spelling errors
    for (i = start; i < end; i++) {
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' ||
                sentence[i] == 'o' || sentence[i] == 'u') {
            // Check for vowel repetition
            for (j = i + 1; j < end; j++) {
                if (sentence[j] == sentence[i]) {
                    printf("Word %s contains repeated vowel %c\n", sentence + start, sentence[i]);
                    break;
                }
            }
        }
    }
}