#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *input, char *key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        input[i] += key[i % strlen(key)];
    }
}

int main() {
    char input[10];
    char key[10];

    printf("Enter plaintext: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(input, key);

    printf("Encrypted: %s\n", input);

    return 0;
}
