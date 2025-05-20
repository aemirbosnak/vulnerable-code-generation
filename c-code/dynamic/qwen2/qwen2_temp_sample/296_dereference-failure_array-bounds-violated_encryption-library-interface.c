#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void encrypt(char *data, int key) {
    while (*data) {
        *data = (*data - 'A' + key) % 26 + 'A';
        data++;
    }
}

int main() {
    char buffer[10];
    int i;

    printf("Enter a string to encrypt: ");
    fgets(buffer, sizeof(buffer), stdin);

    for (i = 0; buffer[i] && buffer[i] != '\n'; i++) {
        if ((buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < 'a' || buffer[i] > 'z')) {
            printf("Error: Invalid character in input.\n");
            return 1;
        }
    }

    int key = 3;
    encrypt(buffer, key);

    printf("Encrypted string: %s\n", buffer);

    // Intentional array bounds violation
    buffer[10] = 'X';

    return 0;
}
