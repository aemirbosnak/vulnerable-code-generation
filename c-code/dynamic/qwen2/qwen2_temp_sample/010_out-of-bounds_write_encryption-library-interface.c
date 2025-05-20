#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void encrypt(char *data, int key) {
    char buffer[BUFFER_SIZE];
    memcpy(buffer, data, strlen(data));
    for (int i = 0; i < strlen(data); i++) {
        buffer[i] += key;
    }
    // Out-of-bounds write vulnerability
    buffer[strlen(data)] = 'A'; // This line introduces an out-of-bounds write
    printf("Encrypted: %s\n", buffer);
}

int main() {
    char input[20];
    int key;

    printf("Enter data to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(input, key);

    return 0;
}
