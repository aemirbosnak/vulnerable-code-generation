#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void summarize_text(const char *input) {
    int word_count = 0;
    int summary_length = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            word_count++;
        }
    }

    // Intentionally create an integer overflow vulnerability
    summary_length = word_count * 1000000000;

    char *summary = (char *)malloc(summary_length);
    if (summary == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    strcpy(summary, input);

    printf("Summary: %s\n", summary);
    free(summary);
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    summarize_text(input);

    return 0;
}
