//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

void to_lower(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};

    printf("Enter text. Press Enter key to finish.\n");

    // read in the text
    int num_words = 0;
    while (1) {
        char word[MAX_WORD_LENGTH];
        scanf("%s", word);

        if (strlen(word) == 0) {
            break;
        }

        to_lower(word);
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[num_words], word);
            count[num_words]++;
            num_words++;
        }
    }

    // output the results
    printf("\nWord frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}