//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to calculate entropy
double calculateEntropy(char* data, int length) {
    double entropy = 0;
    int histogram[256] = {0};

    // Calculate frequency of each character
    for (int i = 0; i < length; i++) {
        histogram[data[i]]++;
    }

    // Calculate entropy using frequency
    for (int i = 0; i < 256; i++) {
        if (histogram[i] > 0) {
            double probability = (double) histogram[i] / length;
            entropy -= probability * log2(probability);
        }
    }

    return entropy;
}

// Function to encrypt data using XOR encryption
void xorEncrypt(char* data, int length, char* key) {
    srand(time(NULL));
    int keyLength = strlen(key);

    // Generate random starting point for key
    int keyIndex = rand() % keyLength;

    // Apply XOR encryption for each character
    for (int i = 0; i < length; i++) {
        data[i] ^= key[keyIndex];

        // Generate next key index
        keyIndex = (keyIndex + 1) % keyLength;
    }
}

int main() {
    // Read input data from user
    char input[1000];
    printf("Enter input data: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    int length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

    // Calculate entropy of input before encryption
    double entropyBefore = calculateEntropy(input, length);
    printf("Entropy before encryption: %f\n", entropyBefore);

    // Encrypt input using XOR encryption
    char key[] = "secret";
    xorEncrypt(input, length, key);

    // Calculate entropy of input after encryption
    double entropyAfter = calculateEntropy(input, length);
    printf("Entropy after encryption: %f\n", entropyAfter);

    // Decrypt input using same key
    xorEncrypt(input, length, key);

    // Print decrypted input and original entropy
    printf("Decrypted input: %s\n", input);
    printf("Original entropy: %f\n", entropyBefore);

    return 0;
}