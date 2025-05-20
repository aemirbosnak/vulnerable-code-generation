#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *input, char *key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        input[i] ^= key[i % strlen(key)];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data> <key>\n", argv[0]);
        return 1;
    }

    char data[256];
    char key[128];

    // Vulnerability: Buffer overflow due to insufficient bounds checking
    sscanf(argv[1], "%255s", data);
    sscanf(argv[2], "%127s", key);

    encrypt(data, key);

    printf("Encrypted data: %s\n", data);

    return 0;
}
