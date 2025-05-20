//FormAI DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 50
#define MAX_INPUT_LENGTH 500

int isSpam(char *input, char *spamWords[], int nWords) {
    int i, j, k, badFlag;
    char *word, *pos;

    for (i = 0; i < nWords; i++) {
        word = spamWords[i];
        pos = input;

        while ((pos = strstr(pos, word)) != NULL) {
            badFlag = 0;

            if (pos == input || *(pos - 1) == ' ') {
                k = strlen(word);
                
                if (*(pos + k) == '\0' || *(pos + k) == ' ' || *(pos + k) == '.' 
                || *(pos + k) == ',' || *(pos + k) == ':' || *(pos + k) == ';'
                || *(pos + k) == '?' || *(pos + k) == '!') {
                    badFlag = 1;
                }
            }

            if (badFlag == 1) {
                return 1;
            }

            pos++; 
        }
    }

    return 0;
}

int main() {
    char *input;
    char *spamWords[MAX_SPAM_WORDS];
    int nWords = 0;
    int spamFlag = 0;

    printf("Enter the spam words (one per line, max %d words; use an empty line to finish):\n", MAX_SPAM_WORDS);
    scanf("%*[^\n]"); scanf("%*c");

    while (nWords < MAX_SPAM_WORDS) {
        spamWords[nWords] = (char*) malloc(100 * sizeof(char));
        fgets(spamWords[nWords], 100, stdin);

        if (strlen(spamWords[nWords]) == 1) {
            free(spamWords[nWords]);
            break;
        }

        if (strlen(spamWords[nWords]) > 0 && spamWords[nWords][strlen(spamWords[nWords]) - 1] == '\n') {
            spamWords[nWords][strlen(spamWords[nWords]) - 1] = '\0';
        }

        nWords++;
    }

    input = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));
    printf("Enter the input string:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    spamFlag = isSpam(input, spamWords, nWords);

    if (spamFlag == 1) {
        printf("The input string contains spam words!\n");
    } else {
        printf("The input string is clean!\n");
    }

    free(input);
    for (int i = 0; i < nWords; i++) {
        free(spamWords[i]);
    }
    return 0;
}