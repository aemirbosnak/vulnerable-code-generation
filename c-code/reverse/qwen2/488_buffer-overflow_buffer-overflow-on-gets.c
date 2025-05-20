#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 256

int main() {
    char sentence[MAX_LEN];
    int pos_count = 0, neg_count = 0;
    printf("Enter a sentence: ");
    gets(sentence);
    
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            sentence[i] = tolower(sentence[i]);
        }
    }

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, "happy") == 0 || strcmp(token, "good") == 0 || strcmp(token, "excited") == 0) {
            pos_count++;
        } else if (strcmp(token, "sad") == 0 || strcmp(token, "bad") == 0 || strcmp(token, "angry") == 0) {
            neg_count++;
        }
        token = strtok(NULL, " ");
    }

    printf("Positive words: %d\n", pos_count);
    printf("Negative words: %d\n", neg_count);

    return 0;
}
