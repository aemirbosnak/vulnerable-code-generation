//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 1000

struct word_frequency {
    char *word;
    int frequency;
};

int main() {
    char input_string[MAX_LENGTH];
    char *delimiters = " ,.;:\"()[]{}!?";
    char *word_tokens[MAX_WORDS];
    int frequency_counter[MAX_WORDS] = {0};
    int num_tokens = 0;
    int i, j, max_frequency = 0, max_index = -1;
    struct word_frequency wf[MAX_WORDS];

    printf("Enter a string:\n");
    fgets(input_string, MAX_LENGTH, stdin);

    word_tokens[0] = strtok(input_string, delimiters);
    num_tokens++;

    while ((word_tokens[num_tokens] = strtok(NULL, delimiters)) != NULL) {
        num_tokens++;
    }

    for (i = 0; i < num_tokens; i++) {
        char lowercase_word[MAX_LENGTH];
        int is_duplicate = 0;

        for (j = 0; word_tokens[i][j]; j++) {
            lowercase_word[j] = tolower(word_tokens[i][j]);
        }
        lowercase_word[j] = '\0';

        for (j = 0; j < i; j++) {
            if (strcmp(lowercase_word, word_tokens[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            wf[i].word = (char *) malloc(sizeof(char) * strlen(lowercase_word));
            strcpy(wf[i].word, lowercase_word);
            wf[i].frequency = 1;

            for (j = i+1; j < num_tokens; j++) {
                char temp_lower[MAX_LENGTH];
                int k;

                for (k = 0; word_tokens[j][k]; k++) {
                    temp_lower[k] = tolower(word_tokens[j][k]);
                }
                temp_lower[k] = '\0';

                if (strcmp(temp_lower, lowercase_word) == 0) {
                    wf[i].frequency++;
                }
            }
        }
    }

    printf("\nWord\t\tFrequency\n");
    printf("----\t\t---------\n");

    for (i = 0; i < num_tokens; i++) {
        if (wf[i].word != NULL) {
            printf("%-16s %d\n", wf[i].word, wf[i].frequency);

            if (wf[i].frequency > max_frequency) {
                max_frequency = wf[i].frequency;
                max_index = i;
            }
        }
    }

    printf("\nThe most frequently occurring word is \"%s\" with a frequency of %d\n", wf[max_index].word, max_frequency);

    return 0;
}