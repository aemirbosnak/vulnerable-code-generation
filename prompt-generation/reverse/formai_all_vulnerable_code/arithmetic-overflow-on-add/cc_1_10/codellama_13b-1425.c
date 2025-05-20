//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
/*
 * C Word Frequency Counter
 *
 * This program takes a string as input and counts the frequency of each word in it.
 *
 * Author: [Your Name]
 * Date:   [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    char input[1000];
    int i, j, nwords;
    WordCount words[MAX_WORDS];

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(input, 1000, stdin);

    // Tokenize the input string and count the frequency of each word
    nwords = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
            nwords++;
        }
    }
    nwords++;

    for (i = 0; i < nwords; i++) {
        int len = strlen(input + i);
        if (len > 0) {
            for (j = 0; j < nwords; j++) {
                if (strcmp(input + i, words[j].word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            if (j == nwords) {
                strcpy(words[j].word, input + i);
                words[j].count = 1;
            }
        }
    }

    // Print the frequency of each word
    for (i = 0; i < nwords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}