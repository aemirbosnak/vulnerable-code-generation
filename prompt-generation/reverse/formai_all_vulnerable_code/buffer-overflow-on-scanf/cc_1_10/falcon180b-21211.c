//Falcon-180B DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000 //maximum size of input string

void encrypt(char message[], int key) {
    int length = strlen(message);
    char encrypted_message[MAX_SIZE] = {0}; //initialize encrypted message to null

    int i = 0;
    int j = 0;
    while (i < length) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[j] = ((message[i] - 'a' + key) % 26) + 'a'; //encrypt lowercase letters
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[j] = ((message[i] - 'A' + key) % 26) + 'A'; //encrypt uppercase letters
        }
        else {
            encrypted_message[j] = message[i]; //copy non-letter characters
        }
        i++;
        j++;
    }
    strcpy(message, encrypted_message); //replace original message with encrypted message
}

void decrypt(char message[], int key) {
    int length = strlen(message);
    char decrypted_message[MAX_SIZE] = {0}; //initialize decrypted message to null

    int i = 0;
    int j = 0;
    while (i < length) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decrypted_message[j] = ((message[i] - 'a' - key + 26) % 26) + 'a'; //decrypt lowercase letters
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            decrypted_message[j] = ((message[i] - 'A' - key + 26) % 26) + 'A'; //decrypt uppercase letters
        }
        else {
            decrypted_message[j] = message[i]; //copy non-letter characters
        }
        i++;
        j++;
    }
    strcpy(message, decrypted_message); //replace original message with decrypted message
}

int main() {
    char message[MAX_SIZE] = {0}; //initialize message to null
    int key = 0;

    printf("Enter a message: ");
    scanf("%s", message);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key); //encrypt message
    printf("Encrypted message: %s\n", message);

    decrypt(message, key); //decrypt message
    printf("Decrypted message: %s\n", message);

    return 0;
}