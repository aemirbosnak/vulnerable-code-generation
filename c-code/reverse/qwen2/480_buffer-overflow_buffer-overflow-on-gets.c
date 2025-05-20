#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char sentence[MAX_LEN];
    int pos_count = 0, neg_count = 0;

    printf("Enter a sentence: ");
    gets(sentence);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, "happy") == 0 || strcmp(token, "good") == 0 || strcmp(token, "excited") == 0) {
            pos_count++;
        } else if (strcmp(token, "sad") == 0 || strcmp(token, "bad") == 0 || strcmp(token, "angry") == 0) {
            neg_count++;
        }
        token = strtok(NULL, " ");
    }

    if (pos_count > neg_count) {
        printf("Positive sentiment.\n");
    } else if (neg_count > pos_count) {
        printf("Negative sentiment.\n");
    } else {
        printf("Neutral sentiment.\n");
    }

    return 0;
}
