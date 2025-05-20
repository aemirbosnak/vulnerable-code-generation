#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void summarize_text() {
    char *sentence = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter your text: ");
    read = getline(&sentence, &len, stdin);
    if (read == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    // Simulate summarization by copying the entire text
    char *summary = malloc(read + 1);
    if (summary == NULL) {
        perror("malloc");
        free(sentence);
        exit(EXIT_FAILURE);
    }
    strcpy(summary, sentence);

    printf("Summary: %s", summary);

    free(summary);
    free(sentence);
}

int main() {
    summarize_text();
    return 0;
}
