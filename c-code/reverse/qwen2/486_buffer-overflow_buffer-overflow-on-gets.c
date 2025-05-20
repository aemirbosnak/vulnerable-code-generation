#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_LEN 100

int main() {
    char sentence[MAX_LEN];
    printf("Enter a sentence: ");
    gets(sentence); // Vulnerable to buffer overflow

    char *positive_words[] = {"good", "great", "happy"};
    char *negative_words[] = {"bad", "terrible", "sad"};

    int pos_count = 0, neg_count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            if (sentence[j] == '\0') break;
            if (strncmp(&sentence[j], positive_words[i], strlen(positive_words[i])) == 0) {
                pos_count++;
                j += strlen(positive_words[i]) - 1;
            } else if (strncmp(&sentence[j], negative_words[i], strlen(negative_words[i])) == 0) {
                neg_count++;
                j += strlen(negative_words[i]) - 1;
            }
        }
    }

    if (pos_count > neg_count) {
        printf("Positive sentiment\n");
    } else if (neg_count > pos_count) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}
