//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

// Function to perform left rotation on character array by given number of positions
void rotate_array(char arr[], int key) {
    char temp;
    for (int i = 0; i < key; i++) {
        temp = arr[0];
        for (int j = 0; j < strlen(arr) - 1; j++)
            arr[j] = arr[j + 1];
        arr[strlen(arr) - 1] = temp;
    }
}

// Function to perform modern encryption using Caesar Cipher and Left Rotation
void encrypt(char message[], int key) {
    int length = strlen(message);

    // Encrypt using Caesar Cipher
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            message[i] = (char)(((isupper(message[i]) ? 'A' : 'a') + key - 'A' - 1) % 26 + 'A');
        }
    }

    // Perform left rotation based on key value
    rotate_array(message, key % 26);
}

// Function to display the encrypted message in a romantic way
void print_message(char message[]) {
    printf("\nIn the stillness of the night,\n");
    printf("Whispers of love are sent alight,\n");
    printf("A secret message, a precious sight,\n");
    printf("As the stars above shine ever so bright.\n\n");
    printf("Your message, dear, now encrypted,\n\n");
    printf("%s\n", message);
}

int main(void) {
    char message[100];
    int key;

    printf("Enter the message to be encrypted (max 100 characters): ");
    scanf("%s", message);

    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("\nPress Enter to display the encrypted message...");
    getchar();

    print_message(message);

    return EXIT_SUCCESS;
}