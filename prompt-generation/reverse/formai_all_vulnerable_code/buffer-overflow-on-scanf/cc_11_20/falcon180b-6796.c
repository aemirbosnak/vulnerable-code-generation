//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    char input[MAX_WORD_LENGTH];
    char delimiters[] = ",.!?;:";
    int i, j, k, n, word_count = 0;
    struct word words[MAX_WORDS];

    printf("Enter a sentence: ");
    scanf("%[^\n]", input);

    for (i = 0; input[i]!= '\0'; i++) {
        if (strchr(delimiters, tolower(input[i]))!= NULL) {
            input[i] = '\0';
        }
    }

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i]) || input[i] == '\'') {
            for (j = i; j < strlen(input) && (isalpha(input[j]) || input[j] == '\''); j++) {
                input[j] = tolower(input[j]);
            }
            input[j] = '\0';

            for (k = 0; k < word_count; k++) {
                if (strcmp(input, words[k].word) == 0) {
                    words[k].count++;
                    break;
                }
            }

            if (k == word_count) {
                strcpy(words[word_count].word, input);
                words[word_count].count = 1;
                word_count++;
            }
        }
    }

    printf("Word count:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}