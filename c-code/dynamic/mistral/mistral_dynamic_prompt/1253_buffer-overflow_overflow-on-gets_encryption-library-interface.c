#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 10

void encrypt(char *input) {
    char output[MAX_BUFFER];
    strcpy(output, input);
    int i;
    for (i = 0; output[i] != '\0'; i++) {
        output[i] += 3;
    }
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    if (argc > 1) {
        strcpy(buffer, argv[1]);
        encrypt(buffer);
        printf("Encrypted message: %s\n", buffer);
    } else {
        printf("Usage: %s message_to_encrypt\n", argv[0]);
    }
    return 0;
}
