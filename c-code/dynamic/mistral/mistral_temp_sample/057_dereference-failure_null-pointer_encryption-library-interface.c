#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Fake encryption function with a null pointer vulnerability
void encrypt(char *input, char **output) {
    char *key = malloc(10);
    if (!key) {
        fprintf(stderr, "Error: Out of memory\n");
        *output = NULL;
        return;
    }

    for (int i = 0; i < 10; ++i) {
        key[i] = rand() % 26 + 'A';
    }

    int len = strlen(input);
    *output = malloc(len * sizeof(char));
    if (!*output) {
        fprintf(stderr, "Error: Out of memory\n");
        free(key);
        return;
    }

    for (int i = 0; i < len; ++i) {
        (*output)[i] = toupper(input[i]) + (int)key[i % 10] - (int)'A' - (int)'A' + (int)'Z' + 1;
        if ((*output)[i] > 'Z' && (*output)[i] < 'z') {
            // Null pointer dereference vulnerability
            printf("%c\n", (*output)[i] - 'a' + 'A');
        }
    }
}

int main() {
    char input[100];
    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);

    char *output;
    encrypt(input, &output);

    printf("Encrypted: %s\n", output);
    free(output);
    free(input);
    return 0;
}
