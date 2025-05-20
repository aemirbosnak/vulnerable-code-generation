//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 50
#define THRESHOLD 5

struct Word {
    char word[MAX_LENGTH];
    int count;
};

bool isSpam(const char *email, struct Word words[]) {
    int numWords = 0;
    int wordLen;
    char word[MAX_LENGTH];

    for (int i = 0; i < strlen(email); i++) {
        if (isalnum(email[i])) {
            if (i > 0 && isspace(email[i - 1])) {
                wordLen = 1;
                word[wordLen++] = tolower(email[i]);
                i++;

                while (isalnum(email[i]) && i < strlen(email) && wordLen < MAX_LENGTH) {
                    word[wordLen++] = tolower(email[i]);
                    i++;
                }

                i--;

                for (int j = 0; j < numWords; j++) {
                    if (strcasecmp(words[j].word, word) == 0) {
                        words[j].count++;
                        break;
                    }
                }

                for (int j = numWords; j < MAX_WORDS && words[j].count < THRESHOLD; j++) {
                    strcpy(words[j].word, word);
                    words[j].count = 1;
                    numWords++;
                    if (numWords >= MAX_WORDS) {
                        return true;
                    }
                    break;
                }
            }
        }
    }

    return numWords > 0 && (double)numWords / strlen(email) > 0.1;
}

int main() {
    struct Word words[MAX_WORDS];
    char email[1000];
    int numWords = 0;
    clock_t start = clock();

    printf("Enter an email address:\n");
    scanf("%s", email);

    if (isSpam(email, words)) {
        printf("This email is likely spam.\n");
    } else {
        printf("This email is not likely spam.\n");
    }

    clock_t end = clock();
    double timeTaken = (end - start) / (double)CLOCKS_PER_SEC;
    printf("Time taken: %.6fs\n", timeTaken);

    return 0;
}