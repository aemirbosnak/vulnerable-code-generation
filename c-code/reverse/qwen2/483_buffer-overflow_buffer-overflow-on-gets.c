#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char sentence[MAX_LEN];
    int pos_count = 0, neg_count = 0;
    const char *pos_words[] = {"GOOD", "AWESOME", "EXCELLENT"};
    const char *neg_words[] = {"BAD", "SAD", "FAIL"};
    int i, j;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Convert to uppercase
    for (i = 0; sentence[i]; i++) {
        sentence[i] = toupper(sentence[i]);
    }

    // Remove newline character if present
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Count positive and negative words
    for (i = 0; i < len; i++) {
        for (j = 0; pos_words[j]; j++) {
            if (strncmp(&sentence[i], pos_words[j], strlen(pos_words[j])) == 0) {
                pos_count++;
                break;
            }
        }
        for (j = 0; neg_words[j]; j++) {
            if (strncmp(&sentence[i], neg_words[j], strlen(neg_words[j])) == 0) {
                neg_count++;
                break;
            }
        }
    }

    // Determine sentiment
    if (pos_count > neg_count) {
        printf("Sentiment: Positive\n");
    } else if (neg_count > pos_count) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }

    return 0;
}
