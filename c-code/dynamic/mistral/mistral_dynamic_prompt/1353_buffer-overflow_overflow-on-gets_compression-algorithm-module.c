#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Pseudo compression algorithm function with buffer overflow vulnerability
void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    char *ptr = buffer;
    int count = 0;

    // Vulnerable to buffer overflow because 'gets' is a dangerous function and should not be used
    gets(ptr);
    strcpy(ptr, input);

    while (*ptr) {
        if (*ptr == *input) {
            count++;
        } else if (count > 0) {
            sprintf(ptr, "%d%c", count, *ptr);
            count = 1;
        }
        ptr++;
    }

    strcpy(output, buffer);
}

int main() {
    char input[100];
    char output[100];

    printf("Enter a string to compress:\n");
    gets(input);

    compress(input, output);
    printf("Compressed string:\n%s\n", output);

    return 0;
}
