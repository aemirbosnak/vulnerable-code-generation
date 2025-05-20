#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Simulated encryption function
void encrypt(char *data, int key) {
    int len = strlen(data);
    for (int i = 0; i <= len; i++) { // Out of bounds write
        data[i] += key;
    }
}

// Simulated decryption function
void decrypt(char *data, int key) {
    int len = strlen(data);
    for (int i = 0; i <= len; i++) { // Out of bounds write
        data[i] -= key;
    }
}

// Interface function to use the encryption/decryption functions
void process_data(char *data, int mode, int key) {
    if (mode == 1) {
        encrypt(data, key);
    } else if (mode == 2) {
        decrypt(data, key);
    } else {
        printf("Invalid mode\n");
    }
}

int main() {
    char data[10];
    strcpy(data, "Hello");

    // Encrypt the data
    process_data(data, 1, 3);

    // Decrypt the data
    process_data(data, 2, 3);

    return 0;
}
