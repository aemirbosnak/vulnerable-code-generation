//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    printf("Enter a message: ");
    gets(str);

    int spam_score = 0;
    char *p = str;

    // Check for common spam words
    char *spam_words[] = {"free", "lottery", "miracle", "prize", "urgent"};
    int num_spam_words = 5;

    for (int i = 0; i < num_spam_words; i++) {
        if (strstr(str, spam_words[i]) != NULL) {
            spam_score++;
        }
    }

    // Check for exclamation marks
    if (strchr(str, '!') != NULL) {
        spam_score++;
    }

    // Check for capital letters
    if (strpbrk(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL) {
        spam_score++;
    }

    // Check for numbers
    if (strpbrk(str, "0123456789") != NULL) {
        spam_score++;
    }

    // Check for unusual punctuation
    if (strchr(str, '$') || strchr(str, '%') || strchr(str, '^') || strchr(str, '&')) {
        spam_score++;
    }

    // Calculate spam probability
    int spam_probability = (spam_score / num_spam_words) * 100;

    // Display results
    printf("Spam probability: %d%%", spam_probability);

    return 0;
}