#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *summarize_text(char *input) {
    size_t input_len = strlen(input);
    char *summary = (char *)malloc(input_len * 0.1); // Allocate 10% of the input length for the summary
    if (!summary) {
        perror("Memory allocation failed");
        return NULL;
    }

    // Vulnerable to buffer overflow
    strcpy(summary, input);
    // Summarization logic here (e.g., word frequency analysis, etc.)

    return summary;
}

int main() {
    char input[1024];
    printf("Enter text: ");
    gets(input);
    char *summary = summarize_text(input);
    printf("Summary: %s\n", summary);
    free(summary);
    return 0;
}
