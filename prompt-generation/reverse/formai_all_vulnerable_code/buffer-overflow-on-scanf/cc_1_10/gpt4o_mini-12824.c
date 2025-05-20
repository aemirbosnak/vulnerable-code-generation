//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

typedef struct {
    char *input;
    int shift;
    char *output;
} CipherData;

void *encrypt(void *arg) {
    CipherData *data = (CipherData *)arg;
    for (size_t i = 0; data->input[i] != '\0'; i++) {
        char c = data->input[i];
        if (c >= 'A' && c <= 'Z') {
            data->output[i] = (c - 'A' + data->shift) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            data->output[i] = (c - 'a' + data->shift) % 26 + 'a';
        } else {
            data->output[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    data->output[strlen(data->input)] = '\0'; // Null-terminate the output
    return NULL;
}

void *decrypt(void *arg) {
    CipherData *data = (CipherData *)arg;
    for (size_t i = 0; data->input[i] != '\0'; i++) {
        char c = data->input[i];
        if (c >= 'A' && c <= 'Z') {
            data->output[i] = (c - 'A' - data->shift + 26) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            data->output[i] = (c - 'a' - data->shift + 26) % 26 + 'a';
        } else {
            data->output[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    data->output[strlen(data->input)] = '\0'; // Null-terminate the output
    return NULL;
}

int main() {
    char input[BUFFER_SIZE];
    int shift;

    printf("Enter a string to encrypt (max 255 characters): ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);

    // Input validation
    if (shift < 0 || shift > 25) {
        fprintf(stderr, "Shift value must be between 0 and 25.\n");
        return 1;
    }

    char encrypted[BUFFER_SIZE];
    char decrypted[BUFFER_SIZE];

    CipherData encryptData = {input, shift, encrypted};
    CipherData decryptData = {input, shift, decrypted};

    pthread_t encryptThread, decryptThread;

    // Create threads for encryption and decryption
    pthread_create(&encryptThread, NULL, encrypt, (void *)&encryptData);
    pthread_create(&decryptThread, NULL, decrypt, (void *)&decryptData);

    // Wait for both threads to finish
    pthread_join(encryptThread, NULL);
    pthread_join(decryptThread, NULL);

    printf("Original String: %s\n", input);
    printf("Encrypted String: %s\n", encrypted);
    printf("Decrypted String: %s\n", decrypted);

    return 0;
}