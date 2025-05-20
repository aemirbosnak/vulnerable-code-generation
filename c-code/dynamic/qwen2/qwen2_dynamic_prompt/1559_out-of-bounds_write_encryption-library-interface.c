#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char buffer[10];
    printf("Enter a string to encrypt: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    int key = 3;
    encrypt(buffer, key);

    printf("Encrypted string: %s\n", buffer);

    // Out-of-bounds write vulnerability
    buffer[20] = 'X'; // This will overwrite memory beyond the buffer

    return 0;
}
