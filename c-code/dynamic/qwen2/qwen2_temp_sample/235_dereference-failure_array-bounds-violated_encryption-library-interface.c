#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int key) {
    int i;
    char *buffer = malloc(1024);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    for (i = 0; data[i] != '\0'; ++i) {
        buffer[i] = data[i];
    }
    
    for (i = 0; data[i] != '\0'; ++i) {
        data[i] = buffer[i] + key;
    }
    
    free(buffer);
}

int main() {
    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    int key = 3;
    encrypt(message, key);
    
    printf("Encrypted message: %s", message);
    
    return 0;
}
