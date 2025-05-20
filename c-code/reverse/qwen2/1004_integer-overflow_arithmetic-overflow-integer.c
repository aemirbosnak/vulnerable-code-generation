#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void summarize(const char* input) {
    int len = strlen(input);
    int summary_len = (len * 3) / 4; // Intentional integer overflow vulnerability

    if (summary_len > 1000) {
        printf("Summary too long\n");
        return;
    }

    char* summary = (char*)malloc(summary_len + 1);
    if (!summary) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < summary_len; i++) {
        summary[i] = input[i];
    }
    summary[summary_len] = '\0';

    printf("Summary: %s\n", summary);
    free(summary);
}

int main() {
    const char* input = "This is a sample text that will be summarized. It contains multiple sentences and words to demonstrate the summarization process.";
    summarize(input);
    return 0;
}
