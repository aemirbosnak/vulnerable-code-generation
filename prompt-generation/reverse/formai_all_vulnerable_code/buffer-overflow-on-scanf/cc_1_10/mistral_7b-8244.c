//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 26
#define BLOCK_SIZE 8

// Function to calculate the position of a letter in the alphabet
int get_position(char letter) {
    return letter - 'A';
}

// Function to perform left circular shift
void shift_array(int arr[], int shift) {
    int temp = arr[0];
    for (int i = 0; i < KEY_SIZE - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[KEY_SIZE - 1] = temp;
    for (int i = 0; i < shift % KEY_SIZE; i++) {
        shift_array(arr, 1);
    }
}

// Function to apply the encryption algorithm
void encrypt(char plaintext[], int key[]) {
    int index;
    for (int i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        int block[BLOCK_SIZE];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = get_position(plaintext[i + j]);
        }
        shift_array(key, block[0]);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            index = (get_position(plaintext[i + j]) + key[j]) % KEY_SIZE;
            plaintext[i + j] = (char) ('A' + index);
        }
    }
}

// Function to generate a random key
void generate_key(int key[]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % KEY_SIZE;
    }
}

// Main function
int main() {
    char plaintext[100];
    int key[KEY_SIZE];

    printf("Enter the message to encrypt: ");
    scanf("%s", plaintext);

    generate_key(key);

    printf("Your key is: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    encrypt(plaintext, key);

    printf("Encrypted message: %s\n", plaintext);

    return 0;
}