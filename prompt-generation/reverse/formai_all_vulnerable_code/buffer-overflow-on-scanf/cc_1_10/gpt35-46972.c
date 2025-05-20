//FormAI DATASET v1.0 Category: modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to encrypt the message using a synchronous encryptor
void synchronous_encryption(char* message, int key) {
    int message_len = strlen(message);

    // Generate a pseudo-random key using the given key
    int prn_key = key * 2 + 1;
    while(prn_key > 10) {
        int prn_sum = 0;
        while(prn_key > 0) {
            prn_sum += prn_key % 10;
            prn_key /= 10;
        }
        prn_key = prn_sum;
    }

    // Convert message characters to their ASCII values
    int* msg_vals = (int*) malloc(MAX_SIZE * sizeof(int));
    for(int i=0; i<message_len; i++) {
        msg_vals[i] = (int) message[i];
    }

    // Encrypt the message using the pseudo-random key
    for(int i=0; i<message_len; i++) {
        msg_vals[i] ^= prn_key;
        prn_key = (prn_key * 2) % 10;
    }

    // Convert ASCII values back to characters and print the encrypted message
    printf("Encrypted message: ");
    for(int i=0; i<message_len; i++) {
        printf("%c", (char) msg_vals[i]);
    }
    printf("\n");

    free(msg_vals);
}

int main() {
    char message[MAX_SIZE];
    int key;

    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;  // remove newline character

    printf("Enter key: ");
    scanf("%d", &key);
    getchar();  // remove newline character from input buffer

    synchronous_encryption(message, key);

    return 0;
}