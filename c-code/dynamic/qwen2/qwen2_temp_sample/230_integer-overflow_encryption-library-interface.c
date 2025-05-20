#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function that could potentially suffer from integer overflow
void encrypt(char *data, int length) {
    for (int i = 0; i <= length; i++) { // Notice the off-by-one error here
        data[i] += 3;
    }
}

int main() {
    char buffer[10];
    printf("Enter a string to encrypt: ");
    fgets(buffer, sizeof(buffer), stdin);

    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0'; // Remove newline character
    }

    encrypt(buffer, len);

    printf("Encrypted string: %s\n", buffer);
    return 0;
}
