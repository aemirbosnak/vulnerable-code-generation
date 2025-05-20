#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter text to summarize:\n");
    read = getline(&input, &len, stdin);
    if (read != -1) {
        printf("Summarized text: %s\n", input);
    } else {
        perror("getline");
    }

    free(input);
    return 0;
}
