#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024
#define MAX_WORDS 100

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int wordCount(const char *str) {
    int count = 0;
    int inWord = 0;
    while (*str) {
        if (isalpha(*str)) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        str++;
    }
    return count;
}

void summarizeText(const char *input, char *output, int maxChars) {
    toLowerCase(input);
    int len = strlen(input);
    int wordNum = wordCount(input);
    if (wordNum == 0 || len > maxChars) {
        strcpy(output, "Input too short or exceeds buffer limit.");
        return;
    }

    // Simplified approach: just copy the first sentence as a placeholder
    const char *firstSentenceEnd = strchr(input, '.');
    if (firstSentenceEnd != NULL && firstSentenceEnd - input + 2 <= maxChars) {
        strncpy(output, input, firstSentenceEnd - input + 2);
        output[firstSentenceEnd - input + 2] = '\0';
    } else {
        strncpy(output, input, maxChars - 1);
        output[maxChars - 1] = '\0';
    }
}

int main() {
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    printf("Enter text to summarize: ");
    fgets(input, sizeof(input), stdin);

    summarizeText(input, output, sizeof(output));

    printf("Summary: %s\n", output);

    return 0;
}
